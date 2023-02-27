#include <iostream>
#include <fstream>
#include <algorithm>
#include <array>
#include <string>
#include "ArgumentManager.h"
#include "list.h"
#include "list.cpp"
using namespace std;

int decode(string input);
void print(node *head, ofstream &output);

int main(int argc, char *argv[])
{
    ArgumentManager an(argc, argv);
    const string input = an.get("input");
    const string command = an.get("command");
    const string output = an.get("output");
    // ifstream inputfile(input);
    ofstream outfile(output);

    // delete when done
    ifstream inputfile("input4.txt");

    string line;
    list bar;

    while (getline(inputfile, line))
    {
        line.erase(remove(line.begin(), line.end(), '\n'), line.end());
        line.erase(remove(line.begin(), line.end(), '\r'), line.end());
        if (line != "" && line[0] != 'B')
        {
            bar.addtoend(stoi(line));
        }
    }

    cout << "Original list created by input3" << endl;
    bar.print();

    node *head = bar.getHead();
    bar.msort(&head);

    cout << endl;
    cout << "Sorted list" << endl;

    bar.print();
}
