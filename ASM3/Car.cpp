#include "Car.h"

Car::Car() {};
Car::~Car() {};

// Function to read MSCN from file
void Car::readMSCNFromFile() {
	ifstream fileIn(FILE_PATH);
	if (fileIn.is_open()) {
		for (int i = 0; i < 8; ++i) {
			fileIn >> MSCN[i];
		}
		fileIn.close();
	}
	else {
		cerr << "Error opening file" << endl;
	}
}

// Function to read SD from file
void Car::readSpeedRangeFromFile() {
	ifstream fileIn(Safe_distance_PATH);
	if (fileIn.is_open()) {
		for (int i = 0; i < 3; ++i) {
			fileIn >> SD[i];
		}
		fileIn.close();
	}
	else {
		cerr << "Error opening file" << endl;
	}
}

// Function to display car information
void Car::displayInfo(){
	cout << "Car Information:" << endl;
	cout << "MSCN: ";
	for (int i = 0; i < 8; ++i) {
		cout << MSCN[i] << " ";
	}
	cout << endl;

	cout << "Speed Range: ";
	for (int i = 0; i < 3; ++i) {
		cout << SD[i] << " ";
	}
	cout << endl;
	system("pause");
}