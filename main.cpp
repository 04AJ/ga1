#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include "ArgumentManager.h"
using namespace std;




int main(int argc, char *argv[]){
    ArgumentManager an(argc, argv);
    const string input = an.get("input");
    const string command = an.get("command");
    const string output = an.get("output");
    //ifstream inputfile(input);
    ofstream outfile(output);

    //delete when done
    ifstream inputfile("input2.txt");

}