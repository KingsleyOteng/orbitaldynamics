//
//  configuration_templates.hpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 08/06/2021.
//  Copyright © 2021 Kwadwo Oteng-Amoko. All rights reserved.
//

#ifndef configuration_templates_hpp
#define configuration_templates_hpp

// api references
#include <boost/functional/hash.hpp>

// namespace directory
using namespace std;

class configuration_templates
{
    
private:
    
   // macro defining array size
   #define         ARRAY_SIZE                              50
   #define         ARRAY_LARGE_BUFFER                      256
   #define         ARRAY_EXTRA_LARGE_BUFFER                4096
   #define         JULIAN_AHEAD_OF_UTC                     68.184
   #define         JULIAN_DAY_OFFSET                       0.5
    bool load_flag;
    
    
  // members
 
public:

  // constructors  and destructors
    configuration_templates();
    ~configuration_templates();
    
    void    load();
    void    set_load_flag(bool var);
    bool    get_load_flag();
    double  check_sum();
       
};
#endif /* coordinate_transforms_hpp */
