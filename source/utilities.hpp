//
//  Overview: We implement here a tracking tool based off of NORAD Two-Line Element Sets.
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
   
    
  // constructors  and destructors
  utilities();
 ~utilities();
    
    
  // members
  std::string              parse_input_phrase;

public:
    

  // getters and setters
  // setters
  void                      setStringParser                 (std::string str);
    
  // getters
  std::string               getStringParser                 (std::string str);
  std::vector<std::string>  getStringParser                 ();


};
#endif /* utilities_hpp */
