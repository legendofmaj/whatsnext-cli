#include <iostream>
#include <cstdlib> //library used for random number generation
#include <map>
#include <fstream>

using namespace std;

int genRand(int max);
//save system
void checkForSave();
void writeFile();
void getFileLength();
void readFile(int numStrings);
void mainMenu();

//variables
string* strings;

class SaveSystem
{
    public:
        string filename = "config.txt";
        string line;
        bool fileExists = false;
        int fileLength;
};
SaveSystem generalInfo;

int main()
{
    //config system
    checkForSave();
    if (generalInfo.fileExists == false)
    {
        writeFile();
    }
    else
    {
        getFileLength();
        readFile(generalInfo.fileLength);
    }

    mainMenu();

    //generate an array of fileLength different values
    genRand(generalInfo.fileLength);

    delete[] strings;
    return 0;
}

void checkForSave()
{
    ifstream saveFile(generalInfo.filename);
    generalInfo.fileExists = saveFile.is_open();
    saveFile.close();
}

void writeFile()
{
    string line;

	cout << "No save data exists yet." << endl;
	cout << "First enter the type of string you whish to use, then the names of each string" << endl;
	cout << "If you have entered all your strings, type esc to stop!" << endl;

	ofstream saveFile(generalInfo.filename);
	while(true)
	{
		cin >> line;
		if (line == "esc") 
		{
			break;
		}
		saveFile << line << endl;
	}
	saveFile.close();  
}

void getFileLength()
{
	string line;

	ifstream saveFile(generalInfo.filename);
	while(getline(saveFile, line)) //As soon as no new lines can be read the function is quit
	{
		generalInfo.fileLength++;
	}
	saveFile.close();
}

void readFile(int numStrings)
{
    string line;
	int i = 0;

	//Allocate memory
	strings = new string[numStrings];

	ifstream saveFile(generalInfo.filename);
	while(getline(saveFile, line))
	{
		strings[i] = line;
		i++;
	}
	saveFile.close();
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

    //map
    map<int, string> mapping;
    for (int i=0;i<max;i++)
    {
        mapping.insert(make_pair(arr[i], strings[i]));
    }

    //print map
    for(auto i : mapping)
    {
        cout << "Your " << i.first << ". " << "string type (to be added)" << " is " << i.second << endl;
    }
    return 0;
}

void mainMenu()
{
    //main menu
    cout << "Welcome to \033[1mwhatsnext-cli\033[0m" << endl;
    cout << "Type \e[3mhelp\e[0m for additional information" << endl; //maybe only on first boot

    //look for input: help
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
            cout << "start -> start the program with the default configuration" << endl;
            cout << "\e[1mmore commands will be added in the future\e[0m" << endl;
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
        //ToDo: add valid input check
    }
}