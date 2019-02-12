# cpp_one

This is a working space for a c++ test question. C_Code_Test-3_1  v1.1


# Files :

    .
    ├── C_Code_Test-3_1.pdf
    ├── README.md
    └── src
        ├── buildall.sh
        ├── sharedlib
        │     ├── FileAnalyser.cpp
        │     ├── FileAnalyser.h
        │     ├── makefile
        │     ├── obj
        │     ├── WaracleCTestSharedLibAPI.h
        │     ├── WaracleCTestSharedLib.cpp
        │     └── WaracleCTestSharedLib.h
        └── test
              ├── makefile
              ├── obj
              ├── runtestapp.sh
              └── testapp.cpp

###To build the library :    
**   cd ./src/sharedlib**  
**   make**  
   
###To build the test application :  
**   cd ./src/test**    
**   make**  
   
###Then execute the test application using       
**   ./runtestapp.sh**  
   
The test application expects an input file /tmp/input  and creates  /tmp/output  on a successful execution.  

