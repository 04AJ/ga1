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
    node *good=nullptr;
    node *bad=nullptr;
    
    while(getline(inputfile,line)){
        if(line!="" && line[0]!='B'){
          good=bar.addtoend(good,bar.decode(line));
          bad=dupbar.addtoend(bad,line);
        }
    }
    
    bar.duplicate(good);
    dupbar.duplicate(bad);
    
    bad=dupbar.checkbool(bad,false);
    good=bar.checkbool(good,true);
    
    if(bad!=nullptr ){
      cout<<"Guilty:"<<endl;
      bar.print(bad);
    }
    
    if(good!=nullptr ){
      cout<<"Innocent:"<<endl;
      bar.print(good);
    }
}
