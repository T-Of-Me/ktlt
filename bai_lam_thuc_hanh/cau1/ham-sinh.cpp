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
    int n = 1000000;
    int maxNumber = 1000000;
    ofstream outputFile("sapxep.inp");
    outputFile << n << endl;

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
