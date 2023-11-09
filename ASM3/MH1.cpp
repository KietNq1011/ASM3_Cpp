#include "MH1.h"
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

void bubbleSort(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = size - 1; j > i; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
			}
		}
	}
}

void selectionSort(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			swap(arr[i], arr[minIndex]);
		}
	}
}

void writeDataToFile_MH1(int* arr, int size) {
	ofstream FileOut;
	FileOut.open("E:\\Learning\\FPT_funix\\C++\\CPP101x_ASM3_kietntFX19645\\Text_Files\\MSCN.txt", ios::out);

	for (int i = 0; i < size; i++) {
		cout << "NHAP SO THU " << i + 1 << ": ";
		cin >> arr[i];
		FileOut << arr[i] << " ";
		cout << endl;
	}

	FileOut.close();
}

int readDataFromFile(int* org_arr, int* arr, int size) {
	ifstream FileIn;
	FileIn.open("E:\\Learning\\FPT_funix\\C++\\CPP101x_ASM3_kietntFX19645\\Text_Files\\MSCN.txt", ios_base::in);

	if (FileIn.fail()) {
		cout << "Read file fail" << endl;
		FileIn.close();
		return 0;
	}
	else {
		// check size of file
		streampos fileSize = 0;
		FileIn.seekg(0, ios::end);
		fileSize = FileIn.tellg();
		FileIn.seekg(0, ios::beg);
		// cout << "Read file success" << endl;
		if (fileSize == 0) {
			cout << "Let's set your password!\n";
			writeDataToFile_MH1(org_arr, size);
			// copy arr to org_arr
			for (int i = 0; i < size; i++) {
				org_arr[i] = arr[i];
			}
			cout << "Set password successfully!\n";
			system("pause");
			system("cls");
			FileIn.close();
			return 2;
		}
		else {
			for (int i = 0; i < size; i++) {
				FileIn >> org_arr[i];
			}

			cout << "\nNHAP MA SO CA NHAN, MANG 08 SO" << endl;
			for (int i = 0; i < size; i++) {
				cout << "NHAP SO THU " << i + 1 << ": ";
				cin >> arr[i];
				cout << endl;
			}

			system("pause");
			system("cls");
			FileIn.close();
			return 1;
		}

	}
}

bool compareArrays(const int* arr1, const int* arr2, int size) {
	for (int i = 0; i < size; i++) {
		if (arr1[i] != arr2[i]) {
			return false;
		}
	}
	return true;
}

bool display_1() {
	int size = 8;
	int arr[8]; // MSCN arr
	int original_arr[8];

	switch (readDataFromFile(original_arr, arr, size)) {
		// case file cant open
	case 0:
		return 0;
		// case	size of file != 0
	case 1:
		cout << "Mang goc truoc khi sap xep: " << endl;
		for (int i = 0; i < size; i++) {
			cout << original_arr[i] << " ";
		}
		cout << endl;

		selectionSort(original_arr, size);
		cout << "Mang goc sau khi sap xep: " << endl;
		for (int i = 0; i < size; i++) {
			cout << original_arr[i] << " ";
		}
		cout << endl;

		cout << "MSCN truoc khi sap xep: " << endl;
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;

		bubbleSort(arr, size);
		cout << "MSCN sau khi sap xep: " << endl;
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;

		if (compareArrays(arr, original_arr, size)) {
			cout << "The entered number is the same as the original.\n" << endl;
			cout << "Do you want to reset your password? (y/n)\n";
			char choice;
			cin >> choice;
			system("pause");
			system("cls");

			switch (choice) {
			case 'y':
			case 'Y':
				cout << "Let's set your password\n";
				writeDataToFile_MH1(arr, size);
				cout << "Password reset successfully!" << endl;
				system("pause");
				system("cls");
				break;
			case 'n':
			case 'N':
				break;
			default:
				cout << "Your choice is invalid!";
				break;
			}
			return 1;
		}
		else {
			cout << "The entered number isn't the same as the original." << endl;
			cout << "Goodbye!" << endl;
			return 0;
		}
	case 2:
		return 1;
	}
}