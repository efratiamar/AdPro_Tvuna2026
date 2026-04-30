#include <iostream>
#include <fstream>
using namespace std;

int main3()
{
    ifstream file;
    file.open("grades.txt");
    if (!file) {
        cout << "File could not be opened.\n";
        return -1;
    }

    int tz; float grade; float sum = 0; int cnt = 0;

    file >> tz >> grade; //input from file	
    while (!file.eof())
    {
        sum += grade; cnt++;
        cout << tz << '\t' << grade << endl;
        file >> tz >> grade;
    }

    cout << "avg= " << sum / cnt;

    file.close();

    return 0;
}
