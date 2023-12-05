#pragma once

#include <iostream>
#include <fstream>

using namespace std;

const string FILE_PATH = "E:\\Learning\\FPT_funix\\C++\\CPP101x_ASM3_kietntFX19645\\Text_Files\\AMS03.dat";
const string Safe_distance_PATH = "E:\\Learning\\FPT_funix\\C++\\CPP101x_ASM3_kietntFX19645\\Text_Files\\Safe_distance.dat";

class Car
{
private:
	int MSCN[8];
	int SD[3];
public:
	Car();
	~Car();

	// Function to read MSCN from file
	void readMSCNFromFile();

	// Function to read SD from file
	void readSpeedRangeFromFile();

	// Function to display car information
	void displayInfo();
};

