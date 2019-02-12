#!/bin/bash
# This is a crude script to compile the shared library and the test application.
# A makefile to invoke the sub makes would be a better solution but sat this point is overkill.
# If there is an error and compilation fails this script will leave the console in the directory 
# of the makefile that received the error. 

cd sharedlib/ && make clean ; make && cd ../test && make clean ; make && cd ..
