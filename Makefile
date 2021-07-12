# vim: set noet:
CC=clang++-7
CFLAGS=-I. -I./include -pthread -std=c++17
OUTDIR=build
SOURCES=main.cpp 
#src/file.cpp src/locale.cpp src/reader.cpp src/vscan.cpp
EXE=main
# strip the src/ from the sources 
#SOURCESNOFOLDERS=main.cpp $(patsubst src/%.cpp, %.cpp, $(SROUCES))
OBJ=$(patsubst %.cpp, $(OUTDIR)/%.o, $(SOURCES))

all: build $(EXE)

# $@ is a variable for whatever is on left of rule
# $^ is first thing on right of it, I guess $> is the rest?

$(EXE): $(OBJ) 
	$(CC) $(CFLAGS) -o $@ $^ lib/libscn.a lib/libfmt.a

$(OUTDIR)/%.o : %.cpp 
	$(CC) $(CFLAGS) -c -o $@ $< 

$(OUTDIR)/src/%.o : src/%.cpp 
	$(CC) $(CFLAGS) -c -o $@ $< 

build:
	@echo OBJ = $(OBJ)
	@mkdir -p build/src

clean:
	@rm -rf build
	
cleanlibs:
	@rm build/*.o
	