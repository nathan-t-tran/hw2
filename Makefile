# Compiler and flags
CXX = g++
CXXFLAGS = -g -Wall -std=c++11

# Executable name
EXE = amazon

# Object files
OBJS = amazon.o mydatastore.o product.o book.o clothing.o movie.o user.o \
       db_parser.o product_parser.o util.o

# Default target: Build the executable
$(EXE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(OBJS)

# Compile individual .cpp files into .o files
amazon.o: amazon.cpp mydatastore.h product.h user.h util.h
	$(CXX) $(CXXFLAGS) -c amazon.cpp

mydatastore.o: mydatastore.cpp mydatastore.h product.h user.h util.h
	$(CXX) $(CXXFLAGS) -c mydatastore.cpp

product.o: product.cpp product.h
	$(CXX) $(CXXFLAGS) -c product.cpp

book.o: book.cpp book.h product.h
	$(CXX) $(CXXFLAGS) -c book.cpp

clothing.o: clothing.cpp clothing.h product.h
	$(CXX) $(CXXFLAGS) -c clothing.cpp

movie.o: movie.cpp movie.h product.h
	$(CXX) $(CXXFLAGS) -c movie.cpp

user.o: user.cpp user.h
	$(CXX) $(CXXFLAGS) -c user.cpp

db_parser.o: db_parser.cpp db_parser.h product.h user.h
	$(CXX) $(CXXFLAGS) -c db_parser.cpp

product_parser.o: product_parser.cpp product_parser.h product.h
	$(CXX) $(CXXFLAGS) -c product_parser.cpp

util.o: util.cpp util.h
	$(CXX) $(CXXFLAGS) -c util.cpp

# Clean up compiled files
clean:
	rm -f $(EXE) $(OBJS)
