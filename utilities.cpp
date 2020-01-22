//
//  utilities.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoko on 22/01/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "utilities.hpp"

using namespace std;

std::string stringparser(std::string str)
{
    // Used to split string around spaces.
    std::istringstream ss(str);
    string final;
    // Traverse through all words
    do
        {
            // Read a word
            string word;
            ss >> word;
      
            // Print the read word
            cout << word << endl;
            final = final + "\n" + word;
      
        }
    while (ss); // While there is more to read
    
    return final;
}
  
