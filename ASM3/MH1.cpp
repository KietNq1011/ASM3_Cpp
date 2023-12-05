#include "MH1.h"
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

// Path to the file for storing data
const string FILE_PATH = "E:\\Learning\\FPT_funix\\C++\\CPP101x_ASM3_kietntFX19645\\Text_Files\\AMS03.dat";
const int ARRAY_SIZE = 8;

// Bubble sort algorithm
void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}

// Selection sort algorithm
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

// Compare two arrays
bool compareArrays(const int* arr1, const int* arr2, int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

// Write data to a file
void writeDataToFile_MH1(int* arr, int size) {
    ofstream FileOut;
    FileOut.open(FILE_PATH, ios::out);

    cout << "ENTER PERSONAL CODE, 8-DIGIT ARRAY" << endl;
    for (int i = 0; i < size; i++) {
        cout << "\nENTER NUMBER " << i + 1 << ": ";
        int temp;
        while (!(cin >> temp)) {
            cin.clear();
            cin.ignore();
            cout << "PLEASE ENTER A NUMBER!" << endl;
            cout << "ENTER NUMBER " << i + 1 << ": ";
        }
        arr[i] = temp;
        FileOut << arr[i] << " ";
    }

    FileOut.close();
}

// Read data from a file
int readDataFromFile(int* org_arr, int* arr, int size) {
    ifstream FileIn;
    FileIn.open(FILE_PATH, ios::in);

    if (FileIn.fail()) {
        cout << "Read file fail" << endl;
        FileIn.close();
        return 0;
    }
    else {
        streampos fileSize = 0;
        FileIn.seekg(0, ios::end);
        fileSize = FileIn.tellg();
        FileIn.seekg(0, ios::beg);

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
            cout << "ENTER PERSONAL CODE, 8-DIGIT ARRAY" << endl;
            for (int i = 0; i < size; i++) {
                cout << "\nENTER NUMBER " << i + 1 << ": ";
                int temp;
                while (!(cin >> temp)) {
                    cin.clear();
                    cin.ignore();
                    cout << "PLEASE ENTER A NUMBER!" << endl;
                    cout << "ENTER NUMBER " << i + 1 << ": ";
                }
                arr[i] = temp;
            }

            system("pause");
            system("cls");
            FileIn.close();
            return 1;
        }
    }
}

// Display information
bool display_1() {
    int arr[ARRAY_SIZE];
    int original_arr[ARRAY_SIZE];

    switch (readDataFromFile(original_arr, arr, ARRAY_SIZE)) {
    case 0:
        return 0;
    case 1:
        cout << "Mang goc truoc khi sap xep: " << endl;
        for (int i = 0; i < ARRAY_SIZE; i++) {
            cout << original_arr[i] << " ";
        }
        cout << endl;

        selectionSort(original_arr, ARRAY_SIZE);
        cout << "Mang goc sau khi sap xep: " << endl;
        for (int i = 0; i < ARRAY_SIZE; i++) {
            cout << original_arr[i] << " ";
        }
        cout << endl;

        cout << "MSCN truoc khi sap xep: " << endl;
        for (int i = 0; i < ARRAY_SIZE; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        bubbleSort(arr, ARRAY_SIZE);
        cout << "MSCN sau khi sap xep: " << endl;
        for (int i = 0; i < ARRAY_SIZE; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        if (compareArrays(arr, original_arr, ARRAY_SIZE)) {
            cout << "The entered number is the same as the original.\n" << endl;
            cout << "Do you want to reset your password? (Y/N)\n";
            char choice;
            while (!(cin >> choice) || (choice != 'Y' && choice != 'N' && choice != 'y' && choice != 'n' )){
                cin.clear();               // clear the fail state
                cin.ignore();  // discard invalid input
                cout << "PLEASE ENTER 'Y' or 'N'!" << endl;
            }
            system("pause");
            system("cls");

            switch (choice) {
            case 'y':
            case 'Y':
                cout << "Let's set your password\n";
                writeDataToFile_MH1(arr, ARRAY_SIZE);
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
