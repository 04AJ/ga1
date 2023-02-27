#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include "ArgumentManager.h"
#include "list.h"
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
    ifstream inputfile("input2.txt");
    
    string line;
    list bar;
    node *n=nullptr;
    
    while(getline(inputfile,line)){
        if(line!="" && line[0]!='B'){
          n=bar.addtoend(n,bar.decode(line));
        }
    }
    
    bar.print(n);
}
