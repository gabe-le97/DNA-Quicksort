#include "dna.h"
#include "swap.h"
#include "sort.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  // making dna objects to hold headers and strings
  DNA::DNA dna1 = DNA::DNA(">The big dog", "GATTACA");
  DNA::DNA dna2 = DNA::DNA(">Apple land", "ATTAATTAGC");
  DNA::DNA dna3 = DNA::DNA(">Car show", "ATTAATAGCGGATN");
  DNA::DNA dna4 = DNA::DNA(">Laptop sale", "NNAGG");
  DNA::DNA dna5 = DNA::DNA(">Chicken dinner", "AT");

  // pushing all the dna objects into a vector
  vector<DNA> v = {dna1, dna2, dna3, dna4, dna5};
  // calling the sort function
  vector<DNA> comp = sort(v, seqLenLessThan);
  vector<DNA> comp2 = sort(v, headerLessThan);
  
  string sortedDNAbysequence;
  for(unsigned long i = 0; i <= comp.size()-1; i++){
    DNA a = comp[i];
    sortedDNAbysequence += a.getSequence();
    sortedDNAbysequence += '\n';
  } 
  cout << endl << "Sorted by Sequence Length:" << endl << sortedDNAbysequence << endl;
  string sortedDNAbyheader;

  for(unsigned long j = 0; j <= comp2.size()-1; j++){
    DNA a = comp2[j];
    sortedDNAbyheader += a.getHeader();
    sortedDNAbyheader += '\n';
  } 
  cout << "Sorted by Header Alphabetically:" << endl << sortedDNAbyheader << endl;
  return 0;
}
