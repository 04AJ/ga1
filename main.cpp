#include <iostream>
#include <fstream>
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
    // ArgumentManager an(argc, argv);
    // const string input = an.get("input");
    // const string command = an.get("command");
    // const string output = an.get("output");
    // // ifstream inputfile(input);
    // ofstream outfile(output);

    // delete when done
    ifstream inputfile("input2.txt");

    list test;

    test.addtoend(3120);
    test.addtoend(1010);
    test.addtoend(221);
    test.addtoend(202);
    test.addtoend(1234);

    test.print();

    cout << endl;

    node *head = test.getHead();
    test.msort(&head);

    test.print();
}
