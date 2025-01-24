#include <iostream>
#include <cstdlib> //library used for random number generation
#include <map>
#include <list>

using namespace std;

//To-Do:
// - replace input logic [Done]
// - rework mapping part of genRand [currently stuck]
// - rework / replace main menu logic

//variables
list<string> inputs;

int genRand(int max);
void input();
void mainMenu();

class SaveSystem
{
    public:
        string inputType;
};
SaveSystem generalInfo;

int main()
{
    //open main ui
    //mainMenu();

    //get user input
    input();
    
    //generate an array of inLength different values
    genRand(inputs.size());

    return 0;
}

void input()
{
    //get inputType
    cout << "please enter the type of objects you want to randomize: ";
    cin >> generalInfo.inputType;

    //get items to sort
    cout << "please enter the objects you want to randomize:" << endl;
    string line;

    while(true)
    {
        cin >> line;
        if (line == "esc")
        {
            break;
        }
        inputs.push_back(line);
    }
    // //debug
    // cout << "print list of inputs:" << endl;
    // for (string element : inputs)
    // {
    //     cout << element << "; ";
    // }
    // cout << endl;
}

int genRand(int max)
{
    //dynamically allocate an array
    int* arr = new int [max];

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
    // //debug
    // cout << "print array of numbers" << endl;
    // for (int i = 0; i < max; i++)
    // {
    //     cout << arr[i] << "; ";
    // }
    // cout << endl;

    //map 
    map<int, string> mapping;

    int numCounter = 0;
    int arrVal = arr[numCounter];

    for (auto i = inputs.cbegin(); i != inputs.cend(); i++)
    {
        mapping[arrVal] = *i;
        numCounter++;
        arrVal = arr[numCounter];
    }

    //print map
    for(auto i : mapping)
    {
        cout << "Your " << i.first << ". " << generalInfo.inputType << " is " << i.second << endl;
    }
    return 0;
}

// void mainMenu()
// {
//     //main menu
//     cout << "Welcome to \033[1mwhatsnext-cli\033[0m" << endl;
//     cout << "Type \e[3mhelp\e[0m for additional information" << endl;

//     //look for input
//     string in;
//     while (true)
//     {
//         cin >> in;
//         if (in == "help")
//         {
//             //print all commands
//             cout << "\e[4mlist of help commands\e[0m: " << endl;
//             cout << "help -> get a list of commands" << endl;
//             cout << "exit -> quit the program" << endl;
//             cout << "clear -> clear the terminal" << endl;
//             cout << "start -> start the program with the default configuration" << endl;
//             cout << "delete -> delete the current configuration" << endl;
//             cout << "\e[1mmore commands will be added in the future\e[0m" << endl;
//             cin >> in;
//         }
//         if (in == "exit")
//         {
//             //close program
//             exit(0);
//         }
//         if (in == "start")
//         {
//             break;
//         }
//         if (in == "clear")
//         {
//             //command that clears the console on all platforms
//             cout << "\033[2J\033[1;1H";
//         }
//         else 
//         {
//             cout << "Unknown command. Type \e[3mhelp\e[0m for additional information" << endl;
//         }
//     }
// }