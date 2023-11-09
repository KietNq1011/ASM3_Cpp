#include "MH1.h"
#include "MH2.h"
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

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
    FileOut.open("E:\\Learning\\FPT_funix\\C++\\ASM3\\Text_Files\\Safe_distance.txt", ios::out);

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
    FileIn.open("E:\\Learning\\FPT_funix\\C++\\ASM3\\Text_Files\\Safe_distance.txt", ios_base::in);

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
            return 2;
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                FileIn >> org_SD_arr[i]; // SD was setted in file
            }
            // Input SD -> compare SD in file and inputed
            set_SD_range(sortedSpeed);
            if (!compareArrays(sortedSpeed, org_SD_arr, 3))
            {
                writeDataToFile_MH2(sortedSpeed);
            }
            cout << "SD has been update successfully!\n";
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
        // case size == 0
    case 2:
        return true;
    }
}