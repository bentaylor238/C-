#include <iostream>

using namespace std;

struct Rational {
	int n, d;
};

void printRational(Rational r) {
    if (r.d == 1) {
        cout << r.n;
    }
    else {
        cout << r.n << '/' << r.d;
    }
}

// For best results, use Eulclid's algorithm
// https://en.wikipedia.org/wiki/Greatest_common_divisor#Using_Euclid.27s_algorithm
int gcd(int n, int d);

// Each function returns false if the resulting Rational number would have a
// zero in the denominator. To get full credit you must check this result after
// every use of these functions!
bool simplify(Rational &r);
bool invert(Rational &r);
bool create(Rational &r, int num = 1, int denom = 1);

// The result of the operation between Rationals a and b is stored in c
bool add(Rational a, Rational b, Rational &c);
bool sub(Rational a, Rational b, Rational &c);
bool mul(Rational a, Rational b, Rational &c);
bool div(Rational a, Rational b, Rational &c);


int main(void) {
    // In a loop,

    //     Continually ask the user which math operation they wish to perform [+, -, *, /]
    //     Quit the program if the user enters 'q' or 'Q'
    //     Nag them until they input a valid operation or quit

    //     Ask the user to enter a numerator for the first Rational number
    //     Ask the user to enter a denominator for the first Rational number
    //     Print an error message and restart this loop if they enter 0 as the denominator

    //     Repeat the above procedure for the second Rational number

    //     Print the equation involving the Rational numbers 

    //     Perform the arithmetic operation and print the resulting Rational number
    return 0;
}
