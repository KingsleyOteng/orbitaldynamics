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
    orbital *orb = new orbital();
    utilities *util = new utilities();
    
    orb -> SetURLData("https://celestrak.com/satcat/tle.php?CATNR=43108");
    orb -> getURLData();
    
    util -> setStringParser(orb -> getTLElineone ());
    util -> setStringParser(orb -> getTLElinetwo ());

}
