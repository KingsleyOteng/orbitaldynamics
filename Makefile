#makefile for the boost project
#You must modify the environment variables at the start of the file
#in order to work!
#example: Consider the 1_34_1 boost distribution, which installs all the
#stuff by default in usr/local/lib (for the libraries) and in
#usr/local/boost_1_34_1/boost (for the headers to be included).
# The following setup is for loading the libraries from this location.
#If you want to load them from a custom location, modify the variables
#below accordingly.
    
BOOST_ROOT=/Users/kwadwooteng-amoko/Documents/Libraries/boost_1_72_0/path/to/installation/prefix/include/
QT_ROOT=/Users/kwadwooteng-amoko/Qt5.14.0/5.14.0/clang_64/
PRODUCT_NAME=example
BOOST_INCLUDE_DIR=$(BOOST_ROOT)boost
CFLAGS=-/Users/kwadwooteng-amoko/qt5.14/5.14.0/clang_64/lib/QtGui.framework/QtGui/
LIBS=/Users/kwadwooteng-amoko/qt5.14/5.14.0/clang_64/lib/QtGui.framework/QtGui/
BOOST_LIB_DIR=$(BOOST_ROOT)/lib
   main: main.cpp
       g++ main.cpp -I$(BOOST_INCLUDE_DIR;CFLAGS) -L$(BOOST_LIB_DIR;LIBS) -o $(PRODUCT_NAME)
clean:
       rm -f main
