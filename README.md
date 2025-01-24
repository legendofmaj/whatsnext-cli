# whatsnext cli

a cli that sorts strings randomly

## Screenshots
this section should later contain screenshots (from Android, Linux, Windows)

![whatsnext-screenshot-windows](https://github.com/user-attachments/assets/5b1403c0-93b7-4970-9407-525d029c15c5)
![whatsnext-screenshot-android](https://github.com/user-attachments/assets/05b23072-2a0e-46e8-9d05-916e22b36263)

## Features
- sort a modular number of strings in random order
- works on Windows, Linux and Android (platforms tested)

## Installation

### Windows
1. Install git (e.g. through [Scoop](https://scoop.sh/))
2. Install a C++ compiler (e.g. [MSYS2](https://www.msys2.org/)) ([guide](https://code.visualstudio.com/docs/cpp/config-mingw))
4. clone this repository with `git clone https://github.com/legendofmaj/whatsnext-cli.git`
5. go into the folder with `cd whatsnext-cli`
6. switch to the branch you want with `git checkout branchname`
7. compile the file with `g++ -o whatsnext.exe main.cpp`
8. launch the file with `start whatsnext.exe`
9. optional: move the file to bin:
-  make sure a bin directory is present e.g.: C:\Users\YourUsername\bin
-  move whatsnext.exe to the directory
- add bin directory to your PATH:
    - open settings
    - search for path and choose "edit the system environment variables"
    - click on environment variables
    - choose path and click edit
    - choose new and add the path to your bin directory
    - click ok to all the close dialogues
- launch the app with `whatsnext` in any terminal

### Android
1. Download Termux from [F-Droid](https://f-droid.org/en/packages/com.termux/) or [GitHub](https://github.com/termux/termux-app)
2. Install git using `pkg install git`
3. Install clang using `pkg install clang`
4. clone the repository with `git clone https://github.com/legendofmaj/whatsnext-cli.git`
5. go into the folder with `cd whatsnext-cli`
6. switch to the branch you want with `git checkout branchname`
7. compile the file with `clang++ main.cpp -o whatsnext`
8. launch the file with `./whatsnext`
9. optional: move the file to bin 
- move the file with `mv whatsnext /data/data/com.termux/files/usr/bin`
- launch the app with `whatsnext`
