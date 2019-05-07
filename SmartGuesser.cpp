#include <iostream>
#include "SmartGuesser.hpp"
#include "Guesser.hpp"

using std::string;
using namespace std;


void bullpgia::SmartGuesser::swap(char &a, char &b) 
{  
    char next;  
    next=a;  
    a=b;  
    b=next;  
} 



void bullpgia::SmartGuesser::combinations(string x ,int y, int z)
{
    if(y == 1) 
    {
        comb.push_back(x); 
        return;
    } // size = 1 then push x to the list "the type of parmeter x is string"
    
    for(int i = 0; i < y; i++)
    {
        combinations(x,y-1,z);
        if(y % 2 == 1)
        {
            swap(x.at(0),x.at(y - 1));
        } // make option list
        else
        {
            swap(x.at(i),x.at(y - 1));
        }
    }
} //list of optional combinations 



void bullpgia::SmartGuesser::startNewGame(uint length)
{   
    if (!comb.empty())
    {
        comb.clear();
    }
    
    first = "";            
    for(int i = 0; i < length; i++)
    { 
        first = first+'0';
    } // Must start with zeros
    
    num = 0; 
    cout = 0; 
    cout<<"starts a new game"<<endl;
}



string bullpgia::SmartGuesser::guess()
{ 
    if(count == 0)
    {
      count++; 
      return first;
    }
    else if(count < 10 && num != 4)
    {
       count++;
       return first;
    }
    return first;
} // After we made a count for guesses, it should not exceed 10 and the sum of bull+pgia not a 4




void bullpgia::SmartGuesser::learn(string calculate)
{
    num = (calculate.at(0)-48)+(calculate.at(2)-48); 
    if(num == first.length() && comb.size() == 0)
    {
        int str = sizeof first/sizeof first.at(0);
        combinations(first,num,str);
	}
    
	if(num == first.length())
    {
        auto it = comb.begin();
        advance(it,0);
        first=*it;
        comb.pop_front();
        return ;
    }
    
    if(num < first.length())
    {
        for(int i = num; i < first.length(); i++)
        {
            first.at(i) = first.at(i)+1; 
        }
        return;
    }    
}
