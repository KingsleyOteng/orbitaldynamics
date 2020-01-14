//
//  orbital.cpp
//  HelloWorld
//
//  Created by Kwadwo Oteng-Amoko on 14/01/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "orbital.hpp"
#include <iostream>
#include <fstream>

using namespace std;

// Date constructor
orbital::orbital(int year, int month, int day)
{
    SetDate(year, month, day);
}
 
// Date member function
void orbital::SetDate(int year, int month, int day)
{
    m_month = month;
    m_day = day;
    m_year = year;
}

// Date member function
void orbital::getDataFile()
{
    std::string filename = "/Users/kwadwooteng-amoko/Desktop/CPP/HelloWorld/HelloWorld/TLE_File.rtf";
    std::ifstream in(filename, std::ios::out);
    std::string line;
    
    if (!in.is_open()) {
        std::cerr << "Error: Unable to open settings file \"" << filename << "\" for reading!" << std::endl;
        
    }
    
    while (std::getline(in, line)) {
           std::cout << line;
       }
    
    in.close();
}
