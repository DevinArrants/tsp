#include "cities.hh"
#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <assert.h>
//Implement operator<< (std::istream&, Cities&) to allow for the outputting of a Cities object to a stream
std::ostream& operator<<(std::ostream& os, const Cities &cities)
{
 Cities::city_list_t cityList;	
 for(auto i: cityList){
     os << i.first << "\t" << i.second << "\n";
 }
 return os;
}

//Implement operator >> (std::istream&, Cities&) to allow for the reading  / filling of a Cities object from a stream.
std::istream& operator>>(std::istream& is, Cities &cities)
{
 int x;
 int y;
 Cities::city_list_t cityList; 
 while(is >> x){
     is >> y;
     Cities::coord_t loc = {x, y};
     cityList.push_back(loc);
 }
 return is;
}

int main(){
 auto in = std::ifstream("linear.tsv", std::ios::in);
 Cities city;
 in >> city; 
 auto out = std::ofstream("output", std::ios::out);
 out << city;
 return 0;
}

