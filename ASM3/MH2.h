#pragma once

void set_SD_range(int* sortedSpeed);
bool display_2(int* speed_range_sorted);
void safe_distance(int* sortedSpeed, int v);
int readDataFromFile(int* org_SD_arr, int* sortedSpeed);
void writeDataToFile_MH2(int* sortedSpeed);
