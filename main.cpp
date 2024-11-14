#include <iostream>
#include <cstdlib> //library used for random number generation
#include <map>

using namespace std;

int genRand(int max);
void getStrings(int max);

//variables to change
int globalMax = 5;

int main()
{
    cout << "How many random numbers to generate?" << endl;
    cin >> globalMax;
    cout << "generating random values..." << endl;

    genRand(globalMax);

    cout << "enter strings" << endl;
    getStrings(globalMax);
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

    //concept: map to strings
    // for (int i=0; i<max; i++)
    // {
    //     map<int, string> names = {{randNum[i], names[i]}};
    // }
}