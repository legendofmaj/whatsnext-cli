# whatsnext cli

a cli that sorts strings randomly

## Screenshots

<img src="https://github.com/user-attachments/assets/3c9d27b4-ecf8-46ba-b960-253e33aec089" height = 375 />
<img src="https://github.com/user-attachments/assets/05b23072-2a0e-46e8-9d05-916e22b36263" width = 175 />

## Features
- sort a modular number of strings in random order
- works on Windows, Linux and Android (platforms tested)

## Build from source

### Windows
1. Install git (e.g. through [Scoop](https://scoop.sh/))
2. Install a C++ compiler (e.g. [MSYS2](https://www.msys2.org/)) ([guide](https://code.visualstudio.com/docs/cpp/config-mingw))
4. clone this repository with `git clone https://github.com/legendofmaj/whatsnext-cli.git`
5. go into the folder with `cd whatsnext-cli`
6. switch to the branch you want with `git checkout branchname`
7. compile the file with `g++ -o whatsnext.exe main.cpp`
8. launch the file with `start whatsnext.exe`
<details>
<summary>9. optional: move the file to bin:</summary>
•  make sure a bin directory is present e.g.: C:\Users\YourUsername\bin <br>
•  move whatsnext.exe to the directory <br>
• add bin directory to your PATH: <br>
    &nbsp;&nbsp;&nbsp;&nbsp;- open settings <br>
    &nbsp;&nbsp;&nbsp;&nbsp;- search for path and choose "edit the system environment variables" <br>
    &nbsp;&nbsp;&nbsp;&nbsp;- click on environment variables <br>
    &nbsp;&nbsp;&nbsp;&nbsp;- choose path and click edit <br>
    &nbsp;&nbsp;&nbsp;&nbsp;- choose new and add the path to your bin directory <br>
    &nbsp;&nbsp;&nbsp;&nbsp;- click ok to all the close dialogues <br>
• launch the app with <code>whatsnext</code> in any terminal
</details>

### Android
1. Download Termux from [F-Droid](https://f-droid.org/en/packages/com.termux/) or [GitHub](https://github.com/termux/termux-app)
2. Install git using `pkg install git`
3. Install clang using `pkg install clang`
4. clone the repository with `git clone https://github.com/legendofmaj/whatsnext-cli.git`
5. go into the folder with `cd whatsnext-cli`
6. switch to the branch you want with `git checkout branchname`
7. compile the file with `clang++ main.cpp -o whatsnext`
8. launch the file with `./whatsnext`
<details>
<summary>9. optional: move the file to bin </summary>
<br>
• move the file with <code>mv whatsnext /data/data/com.termux/files/usr/bin</code> <br>
• launch the app with <code>whatsnext</code>
</details>

### Linux
1. Install a compiler (e.g. `sudo dnf install clang` on Fedora)
2. clone the repository with `git clone https://github.com/legendofmaj/whatsnext-cli.git`
3. go into the folder with `cd whatsnext-cli`
4. switch to the branch you want with `git checkout branchname`
5. compile the file with `clang++ main.cpp -o whatsnext`
6. launch the file with `./whatsnext`
<details>
<summary>7. optional: move the file to bin </summary>
<br>
• move the file with <code>sudo mv whatsnext /usr/bin</code> <br>
• launch the app with <code>whatsnext</code>
</details>
