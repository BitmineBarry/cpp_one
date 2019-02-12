#ifndef __WARACLE_C_TEST_FILE_ANALYSER_H__
#define __WARACLE_C_TEST_FILE_ANALYSER_H__


#include <string>

using namespace std;

/*
* FileAnalyser.h
*
*/

/***
 * This class is the work horse of this library. 
 * It is intended to keep the functionality encapsulated in a way that makes it easy to 
 * extend the library functionality. Additional analysis features can be easily added to the 
 * FileAnalyser. 
 * New objects can be easily used to add unrelated functionality within the library 
 */
class FileAnalyser
{
public:
	/***
	 * @brief These enum values are used for the return codes from the FileAnalyser methods.
	 *  
	 * In the futue these may be better as a library standardised value rather than FileAnalyser specific
	 * Probably best to give them a named type of their own.
	 * 
	 */
	enum
	{
		OK = 0,
		FAILURE = -1,
		BAD_FILE_NAME_PARAMETER = -2,
		EMPTY_FILE_NAME = -3,
		BAD_FILE_NAME = -4,
		READ_OPEN_FAILED = -5,
		READ_FAILED = -6,
		WRITE_OPEN_FAILED = -7,
		WRITE_FAILED = -8,
		BAD_DATA_IN_FILE = -9
	};
			FileAnalyser();

	void 	setFilenames(string inputFilename, string outputFilename);
	int 	analyseNumberFile(void);
	
private:
	int 	writeNumberFileResults(void);
	int 	parseNumberFile(void);

	
	string	analyserInputFilename;
	string	analyserOutputFilename;
	long 	numberCount;
	long	numberSum;
};


#endif // end - __WARACLE_C_TEST_FILE_ANALYSER_H__

