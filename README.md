# SNHU Portfolio

This repository contains selected coursework from Southern New Hampshire University's Computer Science program. The featured artifact is my CS 210 Corner Grocer Item-Tracking Program, a C++ application that demonstrates object-oriented design, file processing, input validation, and readable console reporting.

## Corner Grocer Item-Tracking Program

### Project summary

The Corner Grocer needed a program that could analyze a daily sales record and show how often each grocery item was purchased. The application reads item names from a text file, counts the occurrences with a C++ `map`, and creates a `frequency.dat` backup automatically. A console menu lets the user search for one item's frequency, display every item and its count, display a histogram made from asterisks, or exit the program.

### What I did well

I separated the program into an `ItemTracker` class and a small menu-driven `main` function. This kept the file-processing and reporting logic separate from user interaction. I also added validation for menu selections, clear error messages for file failures, case-insensitive item searches, descriptive names, and comments where the purpose of the code was not immediately obvious. The program meets all four menu requirements and produces the required backup without user intervention.

### Opportunities for improvement

The program currently expects the input file to be in the working directory. A future version could accept a file path as a command-line argument or configuration setting. I could also add automated unit tests for name normalization, frequency counting, and backup-file output. These changes would make the application easier to reuse and safer to modify. For a larger dataset, I would consider an `unordered_map` for faster average lookups, although the ordered `map` is useful here because it keeps reports alphabetized.

### Challenges and resources

The most challenging parts were validating console input without leaving the input stream in a failed state and making sure the histogram matched the numeric frequency report. I worked through these issues by separating the operations into focused methods, testing every menu option, and comparing `frequency.dat` with counts calculated directly from the source data. Helpful resources included the C++ documentation for file streams and maps, course examples, compiler warnings, and step-by-step testing in the terminal.

### Transferable skills

This project strengthened my ability to design a class with public and private sections, choose an appropriate data structure, process files safely, validate user input, and break a problem into smaller functions. Those skills transfer directly to later programming courses and to real applications that need to import, organize, validate, and report data.

### Maintainability, readability, and adaptability

I used separate header and implementation files, consistent naming conventions, small single-purpose functions, and private member data. Constants in `main` identify the required file names, while reporting and lookup behavior remain inside the class. The included CMake and VS Code configurations provide repeatable builds with compiler warnings enabled. This structure makes the program easier to understand and allows individual features to be changed without rewriting the whole application.

## Build and run

From the `CornerGrocer` directory:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp ItemTracker.cpp -o CornerGrocer
./CornerGrocer
```

The file `CS210_Project_Three_Input_File.txt` must be in the working directory. The application creates or refreshes `frequency.dat` when it starts.
