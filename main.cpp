#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include "list.cpp"
#include "ArgumentManager.h"
#include "list.cpp"
using namespace std;

string decode(string input);
string dec(string input);

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

string decode(string input)
{
    int size = input.length();

    // finds "()"
    int start, end = -1;
    start = input.find_first_of('(');
    end = input.find_last_of(')');
    string _out = input.substr(0, start) + dec(input.substr(start + 1, end - start - 1)) + input.substr(end + 1, input.length() - 1);
    cout << "Final: " << _out << endl;
    return _out;
}

// DO NOT CALL THIS FUNCTION!!! CALL "decode()"!!!
string dec(string input)
{
    list *stack = new list();

    // finds "()"
    int start, end = string::npos;
    start = input.find_first_of('(');
    end = input.find_last_of(')');

    // checks if the string contains "()" if so, calls dec
    if (start != string::npos && end != string::npos)
    {
        input = input.substr(0, start) + dec(input.substr(start + 1, end - start - 1)) + input.substr(end + 1, input.length() - 1);
    }

    // flips order in string
    for (int i = 0; i < input.length(); i++)
        stack->push(input[i]);
    input = "";
    while (!stack->isEmpty())
        input += stack->pop();
    return input;
}
