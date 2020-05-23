/************************
* A#: A00000000
* Course: CS1400
* HW#: 4
* Fall 2017
***********************/

#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

float GetT(float v, float d);

float GetD(float v, float h);

void Report(int line, float v, float h, float d, float t) {
	cout << "On line " << right << setw(2) << line
		<< ",  v = " << setw(3) << v 
		<< ",  h = " << setw(5) << h << setprecision(5)
		<< ",  d = " << setw(6) << d << "m"
		<< ",  t = " << setw(6) << t << "s" << endl;
}

int main() {
	// TODO: Open input.txt for reading

	// TODO: Within a loop...

	//   TODO: Read a pair of (v, h) values from the file

	//   TODO: Keep track of which line of the file you've read

	//   TODO: Compute the value for d with GetD()

	//   TODO: Compute the value for t with GetT()

	//   TODO: Call the function Report()

	// TODO: Close input.txt

	return 0;
}
