//
//  configuration_templates.hpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 08/06/2021.
//  Copyright © 2021 Kwadwo Oteng-Amoko. All rights reserved.
//

#ifndef configuration_templates_hpp
#define configuration_templates_hpp

#include <stdio.h>

#endif /* configuration_templates_hpp */

//
//      Overview: Sets the codes defaults
//
//      Created by Kwadwo Oteng-Amoko on 14/01/2020.
//      Copyright © 2020,2021 Kwadwo Oteng-Amoko. All rights reserved.
//
#define Re                      6378.1370               // the earths radius; from Kelso
#define we                      0.0000729211510        // Earth's rotation rate in radians/second; from Kelso

// system files and preprocessor instructions
#include <algorithm>                  // c-11 algoithm, vector libraries are used
#include <array>
#include <cmath>
#include <fstream>
#include <iterator>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <limits>
#include <cctype>
#include <iomanip>

// third party apis
#include <boost/any.hpp>               // boost standard library
#include <boost/asio.hpp>              // io streaming headers
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/xpressive/xpressive.hpp>

// user defined classes
#include "orbital.hpp"                 // header files
#include "BenchMarking.hpp"            // benchmarking routines
#include "time_files.hpp"
#include "sgp4.hpp"
#include "sdp4.hpp"
#include "coordinate_transforms.hpp"   // coordinate transforms library
#include "configuration_system.hpp"
#include "utilities.hpp"               // my own routines for processing data

//#include <cppconn/driver.h> //#include <cppconn/exception.h> //#include <cppconn/prepared_statement.h>

// declare the namespace
using namespace std;
using namespace boost::gregorian;
