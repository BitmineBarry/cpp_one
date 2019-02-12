###########################################################
# makefile for building the C++ test application for the shared 
# library.
#
###########################################################

TARGETNAME=testapp
LIBRARYNAME=waraclectestsharedlib


CPP         := g++
LD  		:= g++
INCLUDES	:= -I ../sharedlib/ 
CPPFLAGS    := -g -c -Wall -Werror $(INCLUDES) 
LDFLAGS     := -L../sharedlib/  -l$(LIBRARYNAME)
CPPSOURCES  := $(wildcard *.cpp)

OBJDIR      := ./obj/
OBJFILES    := $(CPPSOURCES:.cpp=.o)
OBJECTS=$(addprefix $(OBJDIR),$(OBJFILES))


all: $(CPPSOURCES) $(TARGETNAME) 

$(TARGETNAME):	$(OBJECTS) 
	$(LD)  $(OBJECTS) $(LDFLAGS) -o $(TARGETNAME)

$(OBJDIR)%.o : %.cpp
	$(CPP) $(CPPFLAGS) $< -o $@

.PHONY : clean

clean:
	rm $(OBJDIR)*.o
	rm $(TARGETNAME)
