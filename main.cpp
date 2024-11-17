#include <iostream>
#include <cstdlib> //library used for random number generation
#include <map>
#include <fstream>
#include <sys/stat.h> //for mkdir
#include <filesystem> //to list files in a directory

using namespace std;
namespace fs = std::filesystem;

int genRand(int max);
//save system
void getFileName();
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
        string inputtype;
        const char* filepath = "/home/michi/Documents/.whatsnext-config/";
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
        getFileLength();
        readFile(generalInfo.fileLength);
    }
    else
    {
        getFileName();
        getFileLength();
        readFile(generalInfo.fileLength);
    }

    mainMenu();

    //generate an array of fileLength different values
    genRand(generalInfo.fileLength);

    delete[] strings;
    return 0;
}

void getFileName()
{
    int i = 0;
    string pathName;
    
    for (const auto & entry : fs::directory_iterator(generalInfo.filepath))
    {
        //cout << entry.path() << endl; //output files in the directory
        pathName = entry.path();
        i++;
    }
    pathName.erase(pathName.begin(), pathName.begin()+40); //delete the first 40 letters (leave only filename)
    cout << "Your current config is " << pathName << endl;
    cout << "There is/are " << i -1 << " other files in the config folder. Their usage will be implemented later" << endl;
    generalInfo.inputtype = pathName;
}

void checkForSave()
{
    //limitation: doesn't work if the folder is empty
    struct stat sb;
    if (stat(generalInfo.filepath, &sb) == 0) 
    {
        //check if folder is empty here
        generalInfo.fileExists = true;
    }
    else 
    {
        generalInfo.fileExists = false;
    }
}

void writeFile()
{
    string line;

	cout << "No save data exists yet." << endl;
	cout << "If you have entered all your strings, type esc to stop!" << endl;

    //create folder
    if(mkdir(generalInfo.filepath, 0777) == -1)
    {
        cout << "Failed to create folder." << endl;
    }
    //get name
    cout << "Enter the type of input you wish to use ";
    cin >> generalInfo.inputtype;

    cout << "Now enter the names of each " << generalInfo.inputtype << endl;

	ofstream saveFile(generalInfo.filepath + generalInfo.inputtype);
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

	ifstream saveFile(generalInfo.filepath + generalInfo.inputtype);
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

	ifstream saveFile(generalInfo.filepath + generalInfo.inputtype);
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
        cout << "Your " << i.first << ". " << generalInfo.inputtype << " is " << i.second << endl;
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
            cout << "clear -> clear the terminal" << endl;
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
        if (in == "clear")
        {
            cout << "\033[2J\033[1;1H";
        }
        //ToDo: add valid input check
    }
}