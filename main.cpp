//
//  main.cpp
//  HelloWorld
//
//  Created by Kwadwo Oteng-Amoko on 14/01/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

 
#include <iostream>
#include <vector>
#include <algorithm>
#include "orbital.hpp"
#include "utilities.hpp"

using namespace std;

int main()
{
    // main file with some dummy code
    std::cout << "Hello, Kwadwo!\n";
    std::vector<int> v{1,2,3};
    orbital *orb = new orbital(12,13,14);
    utilities *util = new utilities();
    orb->getDataFile();
    
    std::cout << "\nsatellite name: \n \n" << orb -> getTLEname() << "\n";
    std::cout << "\ntle line one: \n \n" << orb -> getTLElineone() << "\n";
    std::cout << "\ntle line two: \n \n" << orb -> getTLElinetwo() << "\n";
    
    util -> setStringParser(orb -> getTLElinetwo ());
    vector<string> parsed_line = util -> getStringParser();
    orb -> set 
    cout << parsed_line[3] << "\n";
    
    //std::cout << "parses " << "\n" << util -> getStringParser(orb -> getTLElinetwo ());
    
    return 0;
}
