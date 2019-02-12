###########################################################
# makefile for building the shared library.
#
###########################################################


CPP         := g++
LD  		:= g++
CPPFLAGS    := -g -c -Wall -fPIC
LDFLAGS     := -shared 
CPPSOURCES  := $(wildcard *.cpp)

OBJDIR      := ./obj/
OBJFILES    := $(CPPSOURCES:.cpp=.o)
OBJECTS=$(addprefix $(OBJDIR),$(OBJFILES))

LIBRARYNAME=waraclectestsharedlib

all: $(SOURCES) $(LIBRARYNAME) 

$(LIBRARYNAME):	$(OBJECTS) 
	$(LD) $(LDFLAGS) $(OBJECTS) -o lib$(LIBRARYNAME).so

$(OBJDIR)%.o : %.cpp
	$(CPP) $(CPPFLAGS) $< -o $@

.PHONY : clean

clean:
	rm $(OBJDIR)*.o
	rm lib$(LIBRARYNAME).so
