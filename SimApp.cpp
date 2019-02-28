
#include "Queue.h"
#include "Event.h"
#include "PriorityQueue.h"
#include "EmptyDataCollectionException.h"

#include <fstream>
#include <string>

#include <iostream>

using namespace std;

#define Teller_number 1;  // change to different number in order to compare their waiting time, and to decide if hire more tellers

int main () {

string STRING;	//create a string to kepp tracking the file from input file
ifstream infile;
infile.open ("simulationShuffled1.in"); // read the file based on name 
	while(!infile.eof) // To get all the lines.
	{
		getline(infile,STRING); // Saves the line in STRING.
		cout<<STRING; // Prints our STRING.
	}
infile.close();
system ("pause");




	
	
	
	


	
	return 0;
} // main
