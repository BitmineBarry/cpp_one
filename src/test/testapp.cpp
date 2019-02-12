/*
* testapp.cpp  This contains content for a test app that will exercise 
*			   the shared library from C++.
*
*/

#include <iostream>
#include "WaracleCTestSharedLibAPI.h"

using namespace std;
using namespace WaracleCTestSharedLib;


/**
 * 	This is the main function of the test software.
 * 	
 * 	The point here is to call the analyse function of the shared library with credible parameters.
 * 	The return value is displayed with cout and the value returned so that it may be used in scripts.
 * 	
 * 	@param[in]		argc	ignored.
 * 	@param[in]		argv	ignored.
 * 	
 * 	@return			return the value from analyse. The meaning of this is defined in the shared library.
 * 	
 */
int main(int argc, char * argv[])
{
	int	value;

	value = analyse("/tmp/infile", "/tmp/output");
	cout << endl << "analyse returned a value of " << value << endl << endl;
	return value;
}
