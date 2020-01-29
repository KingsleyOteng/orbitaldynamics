//
//  Overview: We implement here a tracking tool based off of NORAD Two-Line Element Sets.
//
//  Created by Kwadwo Oteng-Amoko on 14/01/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

 
#include <iostream>
#include <vector>
#include <algorithm>
#include "orbital.hpp"              // header files
#include "utilities.hpp"            // my own routines for processing data
#include <boost/any.hpp>            // boost standard library
#include <boost/asio.hpp>           // io streaming headers

using namespace std;

int main()
{
    
    std::vector<int> v{1,2,3};
    orbital *orb = new orbital(12,13,14);
    utilities *util = new utilities();
    orb ->
            getDataFile();
    
    // summary of the current NORAD two-line elements details
    std::cout << "\nSatellite name: \n \n" << orb ->
                                                    getTLEname() << "\n";
    std::cout << "\nNORAD TLE line one: \n \n" << orb ->
                                                    getTLElineone() << "\n";
    std::cout << "\nNORAD TLE line two: \n \n" << orb ->
                                                    getTLElinetwo() << "\n\n";
    
    // back out TLE parameters
    util -> setStringParser(orb -> getTLElineone ());
    vector<string> parsed_line_ones = util -> getStringParser();
    
    util -> setStringParser(orb -> getTLElinetwo ());
    vector<string> parsed_line_twos = util -> getStringParser();
    
    // store TLE parameters
    orb->SetTLEparameters(orb -> getTLEname(), parsed_line_ones, parsed_line_twos);
    
    return 0;
}
