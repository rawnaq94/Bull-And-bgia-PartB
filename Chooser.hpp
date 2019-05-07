#pragma once
#include <string>
using std::string;
using namespace std;

namespace bullpgia
{ 
    class Chooser
    {
        private:
        uint len;
        
        public: 
        virtual string choose(uint len) = 0;
    };
}
