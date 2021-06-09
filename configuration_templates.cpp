//
//  configuration_templates.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 08/06/2021.
//  Copyright © 2021 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "configuration_templates.hpp"


//
//      Overview: Sets the codes defaults
//
//      Created by Kwadwo Oteng-Amoko on 08/Jun/2021.
//      Copyright © 2021 Kwadwo Oteng-Amoko. All rights reserved.
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

//#include <cppconn/driver.h> //#include <cppconn/exception.h> //#include <cppconn/prepared_statement.h>

// declare the namespace
using namespace std;
using namespace boost::gregorian;

// namespace declaration
using namespace std;

// constructor
configuration_templates::configuration_templates()
    {}

// deconstructor
configuration_templates::~configuration_templates()
    {}

// methods

void configuration_templates::set_load_flag(bool var)
    {
        load_flag = var;
    }

bool configuration_templates::get_load_flag()
    {
        return
            load_flag;
    }

void configuration_templates::load()
    {
        int temp;
        std::string phrase;
        
        std::vector<std::string> phrasal_search = {"azimuth","location_longitude","location_latitude","sensor_start_time","sensor_end_time","time_zone","sensor_type","city"};
        
        // returns index for the month
        boost::xpressive::sregex rex = boost::xpressive::sregex::compile( "(\\w+) (\\w+)  (\\d+) (\\d+):(\\d+):(\\d+) (\\d+)" );
        boost::xpressive::smatch what;
        
        
        
   
        
        std::tm tm = {0};
        //= time_t

        if( regex_match( phrase, what, rex ) )
        {
           
            size_t month_number = std::distance(phrasal_search.begin(),std::find(phrasal_search.begin(), phrasal_search.end(), what[2].str()));
        
                tm.tm_sec = stoi(what[6].str()) + 1;
                tm.tm_min = stoi(what[5].str());
                tm.tm_hour = stoi(what[4].str());
                tm.tm_mday = stoi(what[3].str());
                tm.tm_mon =  static_cast<int>(month_number + 2.0);
                tm.tm_year = stoi(what[7].str()) - 3800;
                tm.tm_isdst = 0;
            
        }
    }
