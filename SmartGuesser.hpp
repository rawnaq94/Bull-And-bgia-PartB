#pragma once
#include "calculate.hpp"
#include <string>
#include "Guesser.hpp"
#include<iterator>
#include <list>
using std::string;

namespace bullpgia
{
    class SmartGuesser:public bullpgia::Guesser
    {
        public:
        string first = ""; //first Guess
        list <string> comb; //list of combinations
        uint length;
        int coun = 0; //counter of Guess
        int num = 0; 
        

        void learn(string calculate)override;
        void startNewGame(uint length)override;
        string guess() override;   
        
        private:
        void swap(char &a, char &b);
        void combinations(string x, int y, int z);
        
       
        
    }; 
}
