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
    int n = 10;
    int maxNumber = 10;
    ofstream outputFile("sapxep.inp");

    if (outputFile.is_open())
    {
        for (int i = 0; i < n; i++)
        {
            int num = rand() % maxNumber;
            outputFile << num << " ";
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
