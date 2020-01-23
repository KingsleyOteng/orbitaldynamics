//
//  utilities.hpp
//  source
//
//  Created by Kwadwo Oteng-Amoko on 22/01/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#ifndef utilities_hpp
#define utilities_hpp

#include <stdio.h>
#include <stdio.h>
#include <string>
#include <sstream>      // std::istringstream
#include <iostream>     // std::cout
#include <vector>

class utilities
{
    
private:
    
    std::string                     parse_input_phrase;

public:

    std::string                     getStringParser(std::string str);
    std::vector<std::string>        getStringParser();
    void                            setStringParser(std::string str);

};
#endif /* utilities_hpp */