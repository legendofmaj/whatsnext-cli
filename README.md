# whatsnext cli

a cli that sorts strings randomly

## Screenshots
this section should later contain screenshots (from Android, Linux, Windows)

## Features
- sort a modular number of strings in a random order
- works on Windows, Linux and Android (platforms tested)

## Installation

### Windows
1. Install git (e.g. through [Scoop](https://scoop.sh/))
2. Install a C++ compiler (e.g. [MSYS2](https://www.msys2.org/)) ([guide](https://code.visualstudio.com/docs/cpp/config-mingw))
3. optional: create folder structure
```
mkdir documents
cd documents
mkdir C++
cd C++
```
4. clone the repository with `git clone https://github.com/legendofmaj/whatsnext-cli.git`
5. go into the folder with `cd reponame`
6. switch to the branch you want with `git checkout branchname`
7. compile the file with `g++ -o whatsnext.exe main.cpp`
8. launch the file with `start whatsnext.exe`
9. optional: move the file to bin:
9.1 make sure a bin directory is present e.g.: C:\Users\YourUsername\bin
9.2 move whatsnext.exe to the directory
9.3 add bin directory to your PATH:
- open settings
- search for path and choose "edit the system environment variables"
- click on environment variables
- choose path and click edit
- choose new and add the path to your bin directory
- click ok to all the close dialogues
9.4 launch the app with "whatsnext"

### Android
1. Download Termux from F-Droid or GitHub
2. Install git using `pkg install git`
3. Install clang using `pkg install clang`
4. optional: create folder structure
```
mkdir documents
cd documents
mkdir C++
cd C++
```
5. clone the repository with `git clone https://github.com/legendofmaj/whatsnext-cli.git`
6. go into the folder with `cd reponame`
7. switch to the branch you want with `git checkout branchname`
8. compile the file with `clang++ main.cpp -o whatsnext`
9. launch the file with `./whatsnext`
10. optional: move the file to bin with `mv whatsnext /data/data/com.termux/files/usr/bin`
- launch the app with "whatsnext"