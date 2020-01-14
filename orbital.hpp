//
//  orbital.hpp
//  HelloWorld
//
//  Created by Kwadwo Oteng-Amoko on 14/01/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#ifndef orbital_hpp
#define orbital_hpp

#include <stdio.h>
#include <string>


class orbital{
    

private:
    std::string m_tle_name;
    std::string m_satellite_number;
    std::string m_classification;
    
    int m_year;
    int m_month;
    int m_day;
 
public:
    orbital(int year, int month, int day);
    void getDataFile();
    void SetTLEname(std::string name);
    void SetDate(int year, int month, int day);
    std::string getTLEname();
    int getYear() { return m_year; }
    int getMonth() { return m_month; }
    int getDay()  { return m_day; }
};


#endif /* orbital_hpp */
