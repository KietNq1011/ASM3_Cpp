#include <iostream>
#include "MH1.h"
#include "MH2.h"
#include "MH3.h"
#include "MH4.h"
#include "Car.h"
using namespace std;

int main() {
	int speed = 0;  // Initial speed
	int speed_range_sorted[3];

	if (display_1()) {
		if (!display_2(speed_range_sorted)) return 0;
	}
	else return 0;

	Car myCar;
	myCar.readMSCNFromFile();
	myCar.readSpeedRangeFromFile();
	myCar.displayInfo();

	while (true) {
		int choice = choice_option();
		switch (choice) {
		case 1:
			gear_P(speed);
			break;

		case 2:
			gear_R(speed);
			break;

		case 3:
			gear_N(speed);
			break;

		case 4:
			gear_D(speed);
			break;

		case 5:
			system("cls");
			cout << "XE DA DUOC TAT. TAM BIET" << endl;
			return 0;

		default:
			system("cls");
			cin.clear(); // delete error cin status
			cin.ignore();
			cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
			system("pause");
			continue;
		}

		check_speed(speed, choice, speed_range_sorted);

		system("pause");  // Pause the screen for the user to read messages
	}

	return 0;
}
