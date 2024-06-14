#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <cstring>

#include <iostream>
#include <fstream>
#include <cstdlib> // hàm rand()

using namespace std;

int main()
{
    int n = 100000;
    int maxNumber = 100000;
    ofstream outputFile("input.txt");
    outputFile << n << endl;

    if (outputFile.is_open())
    {
        for (int i = 0; i < n; i++)
        {
            int num = rand() % maxNumber;
            outputFile << num << endl;
        }
        outputFile.close();
        cout << "Da ghi " << n << " so file input.txt\n";
    }
    else
    {
        cout << "Khong the mo file\n";
    }

    return 0;
}
