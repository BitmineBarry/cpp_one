/*
* shared.cpp  This contains content for a shared library.
*
*/

#include <iostream>
#include <string>

#include "WaracleCTestSharedLibAPI.h"
#include "WaracleCTestSharedLib.h"

using namespace std;

///
/// @brief  The namespace is used to provide separation of our definitions from the rest of the universe.
///
namespace WaracleCTestSharedLib
{
///  This is the public interface for the C_Code_Test-3_1   v1.1
/// 

/**
 * @brief	analyse is the only public function defined in the shared library API
 * 
 * The function must:
 * 		Open the file at the location specified by ​ input ​ for reading
 * 		    each line will be a standalone whole number
 * 		Open the file file at the location specified by ​ output ​ for writing
 * 		    Write the count of the numbers read to a line
 * 		    Write the sum of the numbers read to a line
 * 		    Write the average of the numbers read to a line
 * 		
 * 		Return 0 if the operation was successful, or a negative number otherwise
 * 		
 * 	@param[in]	inputFilename	Pointer to a string representing the source file to be read.
 * 	@param[in]	inputFilename	Pointer to a string representing the source file to be read.
 * 	
 * 	@return   0 = success else a -ve number. The definition of the numbers can be found in the FileAnalyser class definition.
 * 	
 */

extern "C" int analyse(const char * inputFilename, const char * outputFilename)
{

  	int				resultValue = FileAnalyser::OK; // enum - no object or bad names
	FileAnalyser	*analyser = new FileAnalyser();
	
	analyser->setFilenames(string(inputFilename), string(outputFilename));
	resultValue = analyser->analyseNumberFile(); 
	
	return resultValue;
}

} // end - namespace WaracleCTestSharedLib

