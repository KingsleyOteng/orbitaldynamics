//
//      Overview: We implement here a tracking tool based off of NORAD Two-Line Element Sets.
//      We then propogage using SGP4 and also higher
//
//      Created by Kwadwo Oteng-Amoko on 14/01/2020.
//      Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
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
    
    // map to the TLE resoure
    // then open the resource
    orb -> SetURLData("https://celestrak.com/satcat/tle.php?CATNR=43108");
    orb -> getURLData();
    
    // summary of the current NORAD two-line elements details
    std::cout << "\nSatellite name: \n \n"      << orb ->
                                                    getTLEname() << "\n";
    std::cout << "\nNORAD TLE line one: \n \n"  << orb ->
                                                    getTLElineone() << "\n";
    std::cout << "\nNORAD TLE line two: \n \n"  << orb ->
                                                    getTLElinetwo() << "\n\n";
    
    // back out TLE parameters
    util -> setStringParser(orb -> getTLElineone ());
    vector<string> parsed_line_ones             = util ->
                                                    getStringParser();
    
    util -> setStringParser(orb -> getTLElinetwo ());
    vector<string> parsed_line_twos             = util ->
                                                    getStringParser();
    
    // store TLE parameters
    orb->SetTLEparameters(orb -> getTLEname(), parsed_line_ones, parsed_line_twos);
    
    std::cout << "\n" << "Line Number of Element Data" << "\n";
    std::cout << "Satellite Number" << "\n";
    std::cout << "Classification (U=Unclassified)" << "\n";
    std::cout << "International Designator (Last two digits of launch year)"<< "\n";
    std::cout << "International Designator (Launch number of the year)" << "\n";
    std::cout << "International Designator (Piece of the launch)" << "\n";
    std::cout << "International Designator (Epoch Year (Last two digits of year)" << "\n";
    std::cout << "International Designator (Epoch (Day of the year and fractional portion of the day))" << "\n";
    std::cout << "First Time Derivative of the Mean Motion" << "\n";
    std::cout << "Second Time Derivative of Mean Motion (Leading decimal point assumed)" << "\n";
    std::cout << "BSTAR drag term (Leading decimal point assumed)" << "\n";
    std::cout << "Ephemeris type" << "\n";
    std::cout << "Checksum (Modulo 10) (Letters, blanks, periods, plus signs = 0; minus signs = 1)" << "\n";
    
    return 0;
}
