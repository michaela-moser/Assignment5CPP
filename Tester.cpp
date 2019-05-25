
#include <iostream>
#include <fstream>
#include <cstdlib>     
#include <ctime>      
#include <iomanip>
#include "Vector.h"
int main() {
	using namespace std;
	using VECTOR::Vector;
	srand((int)time(0));   
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	ofstream outFile;
	outFile.open("randwalk.txt");
	cout << "Enter target distance (q to quit): ";
	while (cin >> target) {
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		outFile << "Target Distance: " << target << ", Step Size: " << dstep << endl;
		while (result.magval() < target) {
			outFile << setw(10) << steps << ": (x,y) = " << "(" << step.xval() << ", " << step.yval() << ")\n";
			direction = rand() % 360;
			step.reset(dstep, direction, VECTOR::Vector::Mode::POL);
			result = result + step;
			steps++;
		}
		cout << "After " << steps << " steps, the subject "
			"has the following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = "
			<< result.magval() / steps << endl;

		result.rect_mode();
		outFile << "\nAfter " << steps << " steps, the subject has the following location:\n" << result << endl;
		result.polar_mode();
		outFile << " or\n" << result << endl;
		outFile << "Average outward distance per step = " << result.magval() / steps << endl;
		outFile << endl;


		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	outFile.close();

	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}