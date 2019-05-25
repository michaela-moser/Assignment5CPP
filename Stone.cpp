#include "Stonewt.h"
void display(const Stonewt & st, int n);
int main() {
	Stonewt celebrity = 310;
	Stonewt detective(150.23);
	Stonewt elPresidente(21, 8);

	cout << "The celebrity weighed ";
	celebrity.setMode(Stonewt::STONE);
	cout << celebrity;
	cout << "\nThe detective weighed ";
	detective.setMode(Stonewt::STONE);
	cout << detective;
	cout << "\nThe detective weighed ";
	detective.setMode(Stonewt::INT_POUNDS);
	cout << detective;
	cout << "\nThe President weighed ";
	elPresidente.setMode(Stonewt::FLOAT_POUNDS);
	cout << elPresidente;

	Stonewt test = detective + celebrity;
	cout << "Testing + : " << test;
	test = celebrity - elPresidente;
	cout << "Testing - : " << test;
	test = celebrity * 2;
	cout << "Testing * : " << test << endl;

	cout << "No stone left unturned bitches\n";
	std::cin.get();
	return 0;
}