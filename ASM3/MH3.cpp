#include "MH3.h"
#include <iostream>

using namespace std;

// choose gear
int choice_option() {
	system("cls");  // Clear the screen

	cout << "XIN MOI LUA CHON:" << endl;
	cout << "1. P" << endl;
	cout << "2. R" << endl;
	cout << "3. N" << endl;
	cout << "4. D" << endl;
	cout << "5. POWER OFF" << endl;

	int choice;
	cout << "Choice: ";
	cin >> choice;

	return choice;
}

// Gear P
void gear_P(int& speed) {
	if (speed == 0) {
		system("cls");
		cout << "Da ve so P." << endl;
		cout << "CHU Y SU DUNG PHANH TAY DE DAM BAO AN TOAN" << endl << endl;
	}
	else {
		system("cls");
		cout << "HAY CHAC CHAN XE DA DUNG VA VAN TOC LA 0KM/H" << endl;
	}
}

// Gear N
void gear_N(int& speed) {
	if (speed == 0) {
		system("cls");
		cout << "Da ve so N (Tam dung xe)." << endl;
	}
	else {
		system("cls");
		cout << "HAY CHAC CHAN XE DA DUNG VA VAN TOC LA 0KM/H" << endl;
	}
}

// Gear R
void gear_R(int& speed) {
	system("cls");
	cout << "Da ve so R." << endl;
	speed = 7;
}

// Gear D
void gear_D(int& speed) {

	system("cls");
	cout << "Da ve so D." << endl;
	speed = 7;
}