//      Headers
//      Overview: Extraction of object tracking data from NORAD TLE
//
//      Created by Kwadwo Oteng-Amoko on 22/01/2020.
//      Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
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
    
   // macro defining array size
   #define ARRAY_SIZE 50
    
  // members
  char             parse_input_phrase                       [ARRAY_SIZE];
  char             parsed_string                            [ARRAY_SIZE];
    
public:

  // constructors  and destructors
  utilities();
 ~utilities();
       

  // getters and setters
  // setters
  void                      setStringParser                 (std::string str);
  // getters
  char*                     getStringParser                 (std::string str);
  std::vector<std::string>  getStringParser                 ();


};
#endif /* utilities_hpp */
