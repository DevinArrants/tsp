//performs search
#include "cities.hh"
#include <iostream>
#include <fstream>
#include <ostream>
int main(int argc,char *argv[]){ 
  //ensure filename is provided 
  if(argc<2){ 
 	  std::cerr<<"Need input filename\n";
	  return -1;
  }
  //read in cities file
  std::ifstream fin(std::string(argv[1]), std::ios::in);
 
  //make sure file can be opened
  if(!fin.is_open()){
    std::cerr<<"Can't open input file "<<argv[1]<<"\n";
    return -2; 
  } 

  Cities cities;
  fin>>cities;
  auto cities_size = cities.get_list().size();

  Cities::permutation_t permutation;

  //initial permutation 
  for(unsigned int i=0; i<cities_size; i++){permutation.push_back(i);}
  auto shortest = cities.total_path_distance(permutation);

  //for each iteration, generate a new random permutation
  //evaluate distance to travel the cities in said ordering 
  for(int i=0; i<1000000; i++){ 
    auto new_permutation = random_permutation(cities_size);
    auto new_distance = cities.total_path_distance(new_permutation);
    //compares to shortest distance thus far
    //if shorter then replace city object with newly reorder cities	
    if(new_distance<shortest){
      shortest = new_distance;
      cities = cities.reorder(new_permutation);
      std::cout<<i<<"\t"<<new_distance<<"\n";
	  }
  }
  
  //output file   
  std::ofstream ordering(std::string("shortest.tsv"), std::ios::out);
  ordering<<cities;
  return 0;
}
