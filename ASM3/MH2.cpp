#include "MH1.h"
#include "MH2.h"
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

const string Safe_distance_PATH = "E:\\Learning\\FPT_funix\\C++\\CPP101x_ASM3_kietntFX19645\\Text_Files\\Safe_distance.dat";

void set_SD_range(int* sortedSpeed)
{
	int speed[3];
	cout << "CAI DAT VAN TOC CANH BAO KHOANG CACH AN TOAN VOI 3 MUC VAN TOC" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "VAN TOC MUC " << i + 1 << ": ";
		cin >> speed[i];
		cout << endl;
	}

	bubbleSort(speed, 3);

	// copy speed array sorted
	for (int i = 0; i < 3; i++)
	{
		sortedSpeed[i] = speed[i];
	}
}

void writeDataToFile_MH2(int* sortedSpeed)
{
	ofstream FileOut;
	FileOut.open(Safe_distance_PATH, ios::out);

	bubbleSort(sortedSpeed, 3);

	for (int i = 0; i < 3; i++)
	{
		FileOut << sortedSpeed[i] << " ";
	}
	FileOut.close();
}

int readDataFromFile(int* org_SD_arr, int* sortedSpeed)
{
	ifstream FileIn;
	FileIn.open(Safe_distance_PATH, ios_base::in);

	if (FileIn.fail())
	{
		cout << "Read file fail" << endl;
		FileIn.close();
		return 0;
	}
	else
	{
		// check size of file
		streampos fileSize = 0;
		FileIn.seekg(0, ios::end);
		fileSize = FileIn.tellg();
		FileIn.seekg(0, ios::beg);

		if (fileSize == 0)
		{
			// Set safe distance (SD)
			cout << "Let's set your SD!\n";
			cout << "NHAP 3 MUC AN TOAN \n";
			for (int i = 0; i < 3; i++)
			{
				cout << "MUC AN TOAN THU " << i + 1 << ": ";
				cin >> sortedSpeed[i];
				cout << endl;
			}
			writeDataToFile_MH2(sortedSpeed);
			for (int i = 0; i < 3; i++)
			{
				org_SD_arr[i] = sortedSpeed[i];
			}
			cout << "Set SD successfully!\n";
			system("pause");
			system("cls");
			FileIn.close();
			return 1;
		}
		else
		{
			cout << "\nSD was setted in memory" << endl;
			for (int i = 0; i < 3; i++)
			{
				FileIn >> org_SD_arr[i]; // SD was setted in file
				cout << org_SD_arr[i] << " ";
			}
			cout << "\nDo you want update it? (Y/N)" << endl;
			// Input SD -> compare SD in file and inputed
			char choice;
			while (!(cin >> choice) || (choice != 'Y' && choice != 'N' && choice != 'y' && choice != 'n')) {
				cin.clear();               // clear the fail state
				cin.ignore();  // discard invalid input
				cout << "PLEASE ENTER 'Y' or 'N'!" << endl;
			}
			if (choice == 'y' || choice == 'Y') {
				system("cls");
				set_SD_range(sortedSpeed);

				if (!compareArrays(sortedSpeed, org_SD_arr, 3))
				{
					writeDataToFile_MH2(sortedSpeed);
				}
				cout << "SD has been update successfully!\n";
			}
			system("pause");
			system("cls");
			FileIn.close();
			return 1;
		}
	}
}

// setting safe distance
void safe_distance(int* sortedSpeed, int v)
{
	if (v <= sortedSpeed[0])
	{
		cout << "BAN GIU KHOANG CACH TOI THIEU LA 20m" << endl;
	}
	else if (v > sortedSpeed[0] && v <= sortedSpeed[1])
	{
		cout << "BAN GIU KHOANG CACH TOI THIEU LA 55m" << endl;
	}
	else if (v > sortedSpeed[1] && v <= sortedSpeed[2])
	{
		cout << "BAN GIU KHOANG CACH TOI THIEU LA 70m" << endl;
	}
	else
	{
		cout << "BAN GIU KHOANG CACH TOI THIEU LA 100m" << endl;
	}
}


bool display_2(int* speed_range_sorted) {
	int original_arr[3];

	switch (readDataFromFile(original_arr, speed_range_sorted)) {
		// case file cant open
	case 0:
		return false;
		// case	size of file != 0
	case 1:
		return true;
	}
}