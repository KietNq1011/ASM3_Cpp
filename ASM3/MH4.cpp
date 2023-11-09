#include "MH4.h"
#include "MH2.h"
#include <iostream>

using namespace std;

// Option MH_4
int show_option_MH4(int& speed, int sortedSpeed[3]) {
	cout << "TOC DO HIEN TAI: " << speed << "km/h" << endl;
	safe_distance(sortedSpeed, speed);
	cout << "MOI LUA CHON" << endl;
	cout << "1. TANG TOC" << endl;
	cout << "2. GIAM TOC" << endl;
	cout << "3. PHANH" << endl;
	cout << "4. TRO VE MENU" << endl;

	int action;
	cin >> action;

	return action;
}

// Check speed and display warnings
void check_speed(int& speed, int choice, int sortedSpeed[3]) {
	if ((speed > 0) && ((choice == 2) || (choice == 4))) {
		while (true) {
			int action = show_option_MH4(speed, sortedSpeed);

			if (action == 1) {
				speed += 5;
			}
			else if (action == 2) {
				speed -= 5;
			}
			else if (action == 3) {
				system("cls");
				speed = 0;
			}
			else
				break; // Exit the loop if the user chooses to return to the menu.

			// Check speed and display warnings
			// If speed is below 60 and below 20 (for R)
			if ((choice == 4 && speed < 60 && speed > 0) || (choice == 2 && speed < 20 && speed > 0)) {
				system("cls");
			}
			// If speed > 60 km/h (for D) or 20 km/h (for R), issue a high-speed warning to the driver
			else if ((choice == 4 && speed >= 60) || (choice == 2 && speed >= 20)) {
				system("cls");
				cout << "CANH BAO: Toc do qua cao cho lai xe!" << endl;
			}
			// Check if the user decelerates to a speed below 0
			else if (speed <= 0) {
				system("cls");
				speed = 0;
			}
		}
	}
}