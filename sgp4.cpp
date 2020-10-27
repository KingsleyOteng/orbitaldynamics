//
//  sgp4.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 10/10/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "sgp4.hpp"
#include <string>

//std::vector<int> v{1,2,3};
// constructor
void sgp4::set_model                       (orbital *model)
{

}

sgp4::sgp4                            ()
{
    orbital *orb = new orbital();

    orb -> SetSATnumber (3);
    
    cout << "satellite number: " << orb -> getSATnumber() << "\n";
    // declare the variables
}

// destructor
sgp4::~sgp4                           ()
{}

void builds()
{}
