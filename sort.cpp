/* 
File: sort.cpp
Created by Gabe Le & Danny Nguyen 4/13/17
------------------------------------------
This file tests multiple functions in order
to run multiple arguments involving the DNA
classes
*/

//Necessary Libraries
#include "swap.h"
#include "dna.h"

#include <vector>
#include <string>


/*
----------------------------------------
This functions tests the length of two parameters
and returns an appropriate bool value
----------------------------------------
*/
bool seqLenLessThan(DNA& item1, DNA& item2) {
	// compares the two dna objects and returns a bool value
	return item1.getSequence().length() < item2.getSequence().length();
}


/*
----------------------------------------
This function compares the the length of two parameters'
headers and returns an appropriate value
----------------------------------------
*/
bool headerLessThan(DNA& item1, DNA& item2) {
	// compares the two dna object headers
	return item1.getHeader() < item2.getHeader();
}


/*
----------------------------------------
This function takes in two DNA vectors and swaps
their contents (hoare algoritm is in the textbook)
----------------------------------------
*/
int partition(std::vector<DNA>& v, bool comparator(DNA&, DNA&), int start, int finish) {
	// vector is initialized
	DNA& pivot = v[finish];
	int flex = start - 1;
	// Elements are compared and swapped with comparator
	for (int i = start; i <= finish - 1; i++) {
		if (comparator(v[i], pivot)) {
			flex += 1;
			swap(v, flex, i);
		}
	}
	// Last swap
	swap(v, flex + 1, finish);
	return flex + 1;
}


/*
----------------------------------------
This function sorts the DNA vector by dividing it into smaller pieces
then each piece is sorted
----------------------------------------
*/
void quicksort(std::vector<DNA>& v, bool comparator(DNA&, DNA&), int start, int finish) {
	int flash;
	// Implementation of quicksort with a base case
	if(start >= finish) return;
	// flash is the middle of the vector and then it is sorted in smaller chunks
	flash = partition(v, comparator, start, finish);
	quicksort(v,comparator, start, flash - 1);
	// Both sides of the vector are sorted
	quicksort(v, comparator, flash+1, finish);
}


/*
----------------------------------------
Sorts a vector of DNA objects based on a comparator function.
The comparator function takes two DNA objects and returns true if and only if
the first DNA object should be ordered before the second DNA object.
----------------------------------------
*/
std::vector<DNA> sort(std::vector<DNA> v, bool comparator(DNA&, DNA&)) {
	std::vector<DNA> vcopy = v;
	quicksort(vcopy, comparator, 0, vcopy.size() - 1);
	return vcopy;
}
