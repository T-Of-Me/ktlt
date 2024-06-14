

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// Hàm để tráo đổi hai phần tử
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Thuật toán sắp xếp chọn
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        swap(&arr[min_idx], &arr[i]);
    }
}

// Thuật toán sắp xếp chèn
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Thuật toán sắp xếp nổi bọt
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main()
{
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open())
    {
        cout << "Khong the mo file dau vao." << endl;
        return 0;
    }

    if (!outputFile.is_open())
    {
        cout << "Khong the mo file dau ra." << endl;
        return 0;
    }

    int n;
    inputFile >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        inputFile >> arr[i];

    // Sắp xếp và đo thời gian chạy
    clock_t startTime, endTime;

    // Sắp xếp chọn
    vector<int> selectionArr(arr);
    startTime = clock();
    selectionSort(selectionArr);
    endTime = clock();
    double selectionTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    // Sắp xếp chèn
    vector<int> insertionArr(arr);
    startTime = clock();
    insertionSort(insertionArr);
    endTime = clock();
    double insertionTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    // Sắp xếp nổi bọt
    vector<int> bubbleArr(arr);
    startTime = clock();
    bubbleSort(bubbleArr);
    endTime = clock();
    double bubbleTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    // Ghi kết quả vào file đầu ra
    outputFile << "Thoi gian sap xep chon: " << selectionTime << " giay" << endl;
    outputFile << "Thoi gian sap xep chen: " << insertionTime << " giay" << endl;
    outputFile << "Thoi gian sap xep noi bot: " << bubbleTime << " giay" << endl;

    // Đóng các file
    inputFile.close();
    outputFile.close();
    cout << "done !! " << endl;

    return 0;
}
