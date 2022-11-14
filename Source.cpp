#include <iostream>
#include "Header.h"

using namespace std;

void main() {
	string Inp = "-";
	while (Inp != "0") {
		cout << "Type what do you need!" << endl;
		cout << "1 - Matrix1" << endl;
		cout << "2 - Matrix23" << endl;
		cout << "3 - Matrix53" << endl;
		cout << "0 - Exit" << endl;
		cout << "-> ";
		cin >> Inp;
		if (Inp == "1") {
			Matrix1();
		}
		else if (Inp == "2") {
			Matrix23();
		}
		else if (Inp == "3") {
			Matrix53();
		}
		else if (Inp != "0") {
			cout << "Error, try again" << endl;
		}
	}
}