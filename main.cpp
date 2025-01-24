#include <iostream>
#include <cstdlib> //library used for random number generation
#include <map>
#include <list>

using namespace std;

//variables
string inputType;
list<string> inputs;

int genRand(int max);
void input();
void mainMenu();
void closeDialogue();

int main()
{
    //open main ui
    mainMenu();

    //get user input
    input();

    //generate an array of amount of inputs different values
    genRand(inputs.size());

    //open close dialogue
    closeDialogue();

    return 0;
}

void input()
{
    //get inputType
    cout << "please enter the type of objects you want to randomize: ";
    cin >> inputType;

    //get items to sort
    cout << "please enter the " << inputType << "s you want to randomize:" << endl; 
    cout << "type \e[3mesc\e[0m to stop" << endl;
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

    //map
    map<int, string> mapping;

    int numCounter = 0;

    for (auto i = inputs.cbegin(); i != inputs.cend(); i++)
    {
        mapping[arr[numCounter]] = *i;
        numCounter++;
    }

    //print map
    for(auto i : mapping)
    {
        cout << "Your " << i.first << ". " << inputType << " is " << i.second << endl;
    }
    return 0;
}

void mainMenu()
{
    //main menu
    cout << "Welcome to \033[1mwhatsnext-cli\033[0m" << endl;
    cout << "Type \e[3mhelp\e[0m for additional information" << endl;

    //look for input
    string in;
    while (true)
    {
        cin >> in;
        if (in == "help")
        {
            //print all commands
            cout << "\e[4mlist of help commands\e[0m: " << endl;
            cout << "help -> get a list of commands" << endl;
            cout << "exit -> quit the program" << endl;
            cout << "clear -> clear the terminal" << endl;
            cout << "start -> start the program with the default configuration" << endl;
            cin >> in;
        }
        if (in == "exit")
        {
            //close program
            exit(0);
        }
        if (in == "start")
        {
            break;
        }
        if (in == "clear")
        {
            //command that clears the console on all platforms
            cout << "\033[2J\033[1;1H";
        }
        else 
        {
            cout << "Unknown command. Type \e[3mhelp\e[0m for additional information" << endl;
        }
    }
}

void closeDialogue()
{
    while(true)
    {
        cout << "do you want to close the application? [y|n]";
        char in;
        cin >> in;
        if (in == 'y')
        {
            exit(0);
        }
        else if (in == 'n')
        {
            //clear the screen
            cout << "\033[2J\033[1;1H";
            //clear the list
            inputs.clear();
            main();
        }
        else 
        {
            cout << "invalid input" << endl;
            closeDialogue();
        }
    }
}