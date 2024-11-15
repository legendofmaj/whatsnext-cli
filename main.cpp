#include <iostream>
#include <cstdlib> //library used for random number generation
#include <map>

using namespace std;

int genRand(int max);
void getStrings(int max);

//given variables
string input [] = {"input1", "input2", "input3", "input4"};

int main()
{
    //determine the size of the array
    int c;
    for(auto i: input)
    {
        c++;
    }
    cout << "size of the array: " << c << endl;

    //generate an array of c different values
    genRand(c);
}

int genRand(int max)
{
    int arr[max];
    bool exists = false;
    srand(time(NULL));
    for (int i=0;i<max;i++)
    {
        int val = (rand() % max)+1;

        //check for val in array
        for (int i=0;i<max;i++)
        {
            if(arr[i] == val)
            {
                exists = true;
            }
        }
        if (exists == false)
        {
            arr[i] = val;
        }
        else 
        {
            i--;
        }
        exists = false;
    }

    //print
    for (int i=0;i<max;i++)
    {
        cout << arr[i] << endl;
    }

    //map
    map<int, string> mapping;
    for (int i=0;i<max;i++)
    {
        mapping.insert(make_pair(arr[i], input[i]));
    }

    //print map
    for(auto i : mapping)
    {
        cout << i.first << " maps to: " << i.second << endl;
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