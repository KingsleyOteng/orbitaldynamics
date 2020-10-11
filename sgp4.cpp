//
//  sgp4.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 10/10/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "sgp4.hpp"
//std::vector<int> v{1,2,3};
// constructor
sgp4::sgp4                            ()
{}

// destructor
sgp4::~sgp4                           ()
{}

void builds()
{
    double perigree;
    double perigree_h;
    
    // declare the variables
    orbital
            *orb = new orbital();
    utilities
            *util = new utilities();
    vector<string>
            parsed_line_ones = util -> getStringParser();
    vector<string>
            parsed_line_twos = util -> getStringParser();

    // grab a raw TLE from the celestrak website and process it
            orb -> setURLData       ("https://celestrak.com/satcat/tle.php?CATNR=43108");
            orb -> getURLData       ();
    
    // set the TLE parameters
            orb -> SetTLEparameters (orb -> getTLEname(), parsed_line_ones, parsed_line_twos);

}
