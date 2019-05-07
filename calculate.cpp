#include "calculate.hpp"
#include <iostream>
#include <exception>
using namespace std;
using std::string;

namespace bullpgia
{
    string bullpgia::calculateBullAndPgia(string choice, string guess)
    {
      int bull = 0;
      int pgia = 0;
      int arr[10] = {0};
      string _str = "0,0";
      // Initialize variables 
        
       
      if(choice.length() != guess.length()) 
      {
          return "technical is win!";
      }
        
       
      for(int i = 0; i < choice.length(); i++)
      {
           if(choice.at(i) == guess.at(i)) //perfect guess
           {
               bull = bull+1; 
           }
           else
           {   
               if(arr[guess.at(i)-'0']++ < 0)
               {
                   pgia = pgia+1;
               } 
               if(arr[choice.at(i)-'0']-- > 0)
               {
                   pgia = pgia+1;
               }
           }
        } // checking pgia
        
      
        _str = to_string(bull) + "," + to_string(pgia);
        return _str;
    }
}
