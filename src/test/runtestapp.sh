#!/bin/bash
# This script sets the library path for the test app so the shared library can be opened.
# It then executes the test application.

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../sharedlib/
./testapp
