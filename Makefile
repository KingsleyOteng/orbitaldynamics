#the makefile was primarily created to support C++ with Boost in a Xcode ide
    
BOOST_ROOT=/Users/kwadwooteng-amoko/Documents/Libraries/boost_1_74_0/path/to/installation/prefix/include/
#BOOST_ROOT=/usr/local/boost_1_72_0/
QT_ROOT=/Users/kwadwooteng-amoko/Qt5.14.0/5.14.0/clang_64/
SOCI_ROOT=/Users/kwadwooteng-amoko/soci/include/
SOCI_ROOT3=/Users/kwadwooteng-amoko/soci/include/soci/
SQL_ROOT=/Applications/XAMPP/xamppfiles/include/
PRODUCT_NAME=example
BOOST_INCLUDE_DIR=$(BOOST_ROOT)boost/
CFLAGS=-/Users/kwadwooteng-amoko/qt5.14/5.14.0/clang_64/lib/QtGui.framework/QtGui/
LIBS=/Users/kwadwooteng-amoko/qt5.14/5.14.0/clang_64/lib/QtGui.framework/QtGui/
BOOST_LIB_DIR=$(BOOST_ROOT)/lib
BOOST_REGEX_LIB_DIR=boost_regex
   main: main.cpp
       g++ main.cpp -I$(BOOST_INCLUDE_DIR) -L$(BOOST_LIB_DIR;BOOST_REGEX_LIB_DIR;SOCI_ROOT;SOCI_ROOT3;SQL_ROOT) -o $(PRODUCT_NAME)
       #g++ main.cpp -I$(BOOST_INCLUDE_DIR;CFLAGS) -L$(BOOST_LIB_DIR;LIBS) -o $(PRODUCT_NAME)
       # g++ main.cpp -I$(BOOST_INCLUDE_DIR;CFLAGS) -L$(BOOST_LIB_DIR;LIBS;BOOST_REGEX_LIB_DIR;SOCI_ROOT;SOCI_ROOT3;SQL_ROOT) -o $(PRODUCT_NAME)
clean:
       rm -f main
