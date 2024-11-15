#include <iostream>
#include <cstdlib> //library used for random number generation
#include <map>

using namespace std;

int genRand(int max);
void getStrings(int max);
void test();

//given variables
string input [] = {"input1", "input2", "input3", "input4"};

int main()
{
    
}

int genRand(int max)
{
    int arr[max];
    srand(time(NULL));
    for (int i=0;i<max;i++)
    {
        arr[i] = rand() % (max+1);
    }

    //print
    for (int i=0;i<max;i++)
    {
        cout << arr[i] << endl;
    }

    return 0; //later on this should return the array
}

void getStrings(int max)
{
    string names[max];
    for (int i=0; i<max; i++)
    {
        cin >> names[i];
    }

    //print
    for (int i=0; i<max; i++)
    {
        cout << names[i] << endl;
    }
}

void test()
{
    int localMax = 4;

    int randNum[localMax] = {3, 1, 2, 0};
    string names[localMax] = {"test1", "test2", "test3", "test4"};

    for (int i=0; i<localMax; i++)
    {
        map<int, string> names = {{randNum[i], names[i]}};
    }
}