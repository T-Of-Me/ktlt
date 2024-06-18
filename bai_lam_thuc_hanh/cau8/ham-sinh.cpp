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
    int n = 200;
    int num[200];
    int maxNumber = 200;
    ofstream outputFile("input.txt");
    int so = 0;
    if (outputFile.is_open())
    {
        for (int i = 0; i < n; i++)
        {
            num[i] = rand() % maxNumber;

            if (num[i] >= so)
            {
                outputFile << num[i] << " ";
                so = num[i];
            }
        }
        outputFile.close();
        cout << "Da ghi " << n << " so file sapxep.inp \n";
    }
    else
    {
        cout << "Khong the mo file\n";
    }

    return 0;
}
