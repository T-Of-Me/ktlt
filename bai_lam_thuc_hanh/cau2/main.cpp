#include <iostream>
#include <fstream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);

        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void writeArrayToFile(int arr[], int size, const string &filename)
{
    ofstream outputFile(filename);
    if (outputFile.is_open())
    {
        for (int i = 0; i < size; i++)
        {
            outputFile << arr[i] << " ";
        }
        outputFile.close();
        cout << "Đã ghi mảng vào file " << filename << endl;
    }
    else
    {
        cout << "Không thể mở file " << filename << " để ghi" << endl;
    }
}

int binarySearch(int arr[], int low, int high, int target)
{
    int result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            result = mid;
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }

    return result;
}

int main()
{
    ifstream inputFile("sapxep.inp");
    int n;
    inputFile >> n;

    int arr[100000];
    for (int i = 0; i < n; i++)
    {
        inputFile >> arr[i];
    }

    cout << "Mang truoc khi sap xep: \n";
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    cout << "Mang sau khi sap xep: \n";
    printArray(arr, n);
    ofstream outputFile("sapxep.out");
    for (int i = 0; i < n; i++)
    {
        outputFile << arr[i] << " ";
    }
    int target;
    cout << "Nhap gia tri can tim: ";
    cin >> target;
    int result = binarySearch(arr, 0, n - 1, target);
    if (result == -1)
    {
        cout << "Khong tim thay\n";
    }
    else
    {
        cout << "Phan tu " << target << " duoc tim thay tai vi tri " << result << "\n";
    }
    return 0;
}
