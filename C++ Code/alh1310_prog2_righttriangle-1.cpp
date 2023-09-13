/*
Name: Anne Marie Heidebreicht
NetID: alh1310
Program Description: Write a program that determines if three side lengths
					 can form a right triangle and which side length is the largest.
*/

#include <iostream>

using namespace std;


int main()
{
	int a, b, c;


	cout << "Enter Side 1: ";
	cin >> a;

	cout << "Enter Side 2: ";
	cin >> b;

	cout << "Enter Side 3: ";
	cin >> c;


		if (a * a == ((b * b) + (c * c)))
			cout << "A right triangle can be formed with a hypotenuse of " << a << ".";
		else if (b * b == ((a * a) + (c * c)))
			cout << "A right triangle can be formed with a hypotenuse of " << b << ".";
		else if (c * c == ((a * a) + (b * b)))
			cout << "A right triangle can be formed with a hypotenuse of " << c << ".";


		else if (a * a != ((b * b) + (c * c)) || (b * b != ((a * a) + (c * c))) || (c * c != ((a * a) + (b * b))))
			cout << "A right triangle can not be formed. There is no hypotenuse.";

	return 0;

}
