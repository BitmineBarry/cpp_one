/*
* FileAnalyser.cpp  This contains class implementation for analysing files.
*
*/

#include <iostream>
#include <fstream>
#include <string>

#include "WaracleCTestSharedLib.h"

using namespace std;

namespace WaracleCTestSharedLib
{
/***
 * @brief  Default constructor. This currently has no function.
 * 
 */
FileAnalyser::FileAnalyser()
{
	
}

/***
 * @brief	assign filenames to be used for the input and output files.
 * 			This performs no error chacking and empty strings are allowed.
 * 			
 * @param[in]	inputFilename	This is a string repersenting the input file pathname.
 * @param[in]	outputFilename	This is a string repersenting the output file pathname.
 * 
 */
void	FileAnalyser::setFilenames(string inputFilename, string outputFilename)
{
	analyserInputFilename = inputFilename;
	analyserOutputFilename = outputFilename;
}

/***
 *	@brief	This parses the specified input file. The expectation is that the input file will
 *			contain one whole number per line. For each line in the file a count of numbers is incremented 
 *			and a sum value is increased by the value of the number.
 *			
 *			There has been an assumption that numbers will be adequately represented by a variable of type long.
 *			There has been an assumption that the Sum of all numbers will not exceed the maximum value which 
 *			is storable in a long variable. On overflow detection has been implemented.
 *			It has been assumed that file handles are a valuable resource. With this in mind the file is kept 
 *			open for the shortest time possible.  
 *			
 *			This method detects bad data at the start of a line. i.e. not a valid number. In this circumstance an
 *			error message is output using cerr indicating the line of failure. It has been assumed that the 
 *			correct action is to return an error at this point. This is what currently happens.
 *			
 *	@return	0 on success or a negative error result (READ_OPEN_FAILED ; BAD_DATA_IN_FILE)
 *			 
 */

int FileAnalyser::parseNumberFile(void)
{
	// open the input file
	ifstream	inputFile(analyserInputFilename);
	if (inputFile.is_open())
	{
		string	line;
		long	value;
		
		while (getline(inputFile, line))
		{
			try 
			{
				value = stol(line);
			}
			catch (const std::invalid_argument &e)
			{
				inputFile.close();
				cerr << "BAD_DATA_IN_FILE at line " << this->numberCount + 1 << endl;
				return BAD_DATA_IN_FILE;	// we could continue here to ignore the line.
			}
			this->numberCount++;
			this->numberSum += value;
		}
		inputFile.close();
	}
	else
	{
		return READ_OPEN_FAILED;
	}
	return OK;
}

/***
 * @brief	Write the results to the output file calculating the average in the process.
 * 
 * 			The output file is intended to contain :
 * 				a line containing the count of numbers processed from the input file
 * 				a line containing the sum of all numbers in the input file.
 * 				a line containing the average of the numbers in the input file.
 * 				
 * 			The format of the average value has not been specified. It has been assumed that it should be a whole
 * 			number which is consistent with the other values.
 * 			 
 *	@return	0 on success or a negative error result (WRITE_OPEN_FAILED ; WRITE_FAILED)
 */

int FileAnalyser::writeNumberFileResults(void)
{
	ofstream	outputFile(analyserOutputFilename);
	if (outputFile.is_open())
	{
		bool failure;
		
		outputFile << this->numberCount << endl;
		outputFile << this->numberSum << endl;
		if (this->numberCount)
		{
			outputFile << (this->numberSum / this->numberCount) << endl;
		}
		else
		{
			// avoid a division by zero error
			outputFile << 0l << endl;
		}

		// check to see if there was an error
		failure = (outputFile.fail() || outputFile.bad());
		outputFile.close();

		if (failure)
		{
			// there was an error somewhere during the writing
			return WRITE_FAILED;
		}
	}
	else
	{
		return WRITE_OPEN_FAILED;
	}
	return OK;
}

/***
 * @brief	This orchestrates analysis of the number file accounting for errors along the way.
 */
int FileAnalyser::analyseNumberFile(void)
{
	int	result;
	
	// initialise the results.
	this->numberCount = 0l;
	this->numberSum = 0l;
	
	// read the content of the file.
	result = parseNumberFile();
	if (result != OK)
	{
		return result;
	}
	
	// write the results to the output file.
	return writeNumberFileResults();
}

} // end - namespace WaracleCTestSharedLib



