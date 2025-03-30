#include <iostream>
#include <string>
#include <cstdlib>  // library used for random number generation
#include <map>
#include <list>

using namespace std;

string inputType;
list<string> inputs;

int genRand(int max);
void input();
void mainMenu(string in);
void closeDialogue();

int main(int argc, const char* argv[])
{
    // check if flags were passed
    string menuInput;   
    for(int i=0; i<argc; ++i)
    {
        if (string(argv[i])=="-s" || string(argv[i])=="--start")
        {
            menuInput = "start";
        }
        else if (string(argv[i])=="-v" || string(argv[i])=="--version")
        {
            menuInput = "version";
        }
    }

    // open main ui
    mainMenu(menuInput);

    // get user input
    input();

    // generate an array of amount of inputs different values
    genRand(inputs.size());

    // open close dialogue
    closeDialogue();

    return 0;
}

void input()
{
    string line;
    bool undo = false;

    // get inputType
    cout << "please enter the type of objects you want to randomize: ";
    cin >> inputType;

    // get items to sort
    cout << "please enter the " << inputType << "s you want to randomize:" << endl;
    cout << "type \e[3mesc\e[0m to stop" << endl;

    while(true)
    {   
        undo = false;
        getline(cin, line);
        if (line == "esc")
        {
            break;
        }
        else if (line == "undo")
        {            
            inputs.pop_back();
            undo = true;
        }
        if (undo == false && line.empty() == false)
        {
            inputs.push_back(line);
        }
    }
    
    // clear the screen
    cout << "\033[2J\033[1;1H";
}

int genRand(int max)
{
    // dynamically allocate an array
    int* arr = new int [max];

    bool exists = false;
    srand(time(NULL));
    for (int i=0;i<max;i++)
    {
        int val = (rand() % max)+1;

        // check for val in array
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

    // map
    map<int, string> mapping;

    int count = 0;

    for (auto i=inputs.cbegin();i!=inputs.cend();i++)
    {
        mapping[arr[count]] = *i;
        count++;
    }

    // print map
    for(auto i : mapping)
    {
        cout << "Your " << i.first << ". " << inputType << " is " << i.second << endl;
    }

    delete[] arr;
    return 0;
}

void mainMenu(string in)
{
    // main menu
    cout << "Welcome to \033[1mwhatsnext-cli\033[0m" << endl;
    cout << "Type \e[3mhelp\e[0m for additional information" << endl;

    // look for input
    while (true)
    {
        if(in.empty()==true)
        {
            cin >> in;
        }
        else if (in == "help")
        {
            // print all commands
            cout << "\e[4mlist of help commands\e[0m: " << endl;
            cout << "help -> get a list of commands" << endl;
            cout << "exit -> quit the program" << endl;
            cout << "clear -> clear the terminal" << endl;
            cout << "start -> start the program with the default configuration" << endl;
            cin >> in;
        }
        else if (in == "exit")
        {
            // close program
            exit(0);
        }
        else if (in == "start")
        {
            break;
        }
        else if (in == "clear")
        {
            // command that clears the console on all platforms
            cout << "\033[2J\033[1;1H";
        }
        else if (in == "version")
        {
            cout << "V1.1" << endl;
            cin >> in;
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
            // clear the screen
            cout << "\033[2J\033[1;1H";
            // clear the list
            inputs.clear();
            main(0, 0); // debug: possible source for errors. 0 is not a char.
        }
        else 
        {
            cout << "invalid input" << endl;
            closeDialogue();
        }
    }
}
