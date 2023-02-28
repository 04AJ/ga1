#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <algorithm>
#include "list.h"
#include "ArgumentManager.h"
using namespace std;

string decode(string input);
// string dec(string input);

int main(int argc, char *argv[])
{
    ArgumentManager an(argc, argv);
    const string input = an.get("input");
    const string output = an.get("output");
    ifstream inputfile(input);
    ofstream outfile(output);

    // delete when done
    // ifstream inputfile("input9.txt");
    // ofstream outfile("output.txt");

    string line;
    list bar;
    list dupbar;
    node *good = nullptr;
    node *bad = nullptr;

    while (getline(inputfile, line))
    {
        line.erase(remove(line.begin(), line.end(), '\n'), line.end());
        line.erase(remove(line.begin(), line.end(), '\r'), line.end());
        if (line != "" && line[0] != 'B')
        {
            cout << decode(line) << endl;
            good = bar.addtoend(good, decode(line));
            bad = dupbar.addtoend(bad, decode(line));
        }
    }

    bar.msort(&good);
    dupbar.msort(&bad);

    bar.duplicate(good);
    dupbar.duplicate(bad);

    bool innocent = bar.innocent(good);
    bool guilty = dupbar.guilty(bad);

    bad = dupbar.checkbool(bad, false);
    good = bar.checkbool(good, true);

    if (guilty)
    {
        outfile << "Guilty:" << endl;
        outfile << dupbar.print(bad);
    }

    if (innocent)
    {
        outfile << "Innocent:" << endl;
        outfile << bar.print(good);
    }

    inputfile.close();
    outfile.close();
    return 0;
}

string decode (string input) {
    int size = input.length();
    list *stack = new list();
    list *line = new list();
    string out = "";
    int openp = 0;

    for (int i = 0; i < size; i++) {
        if (input[i] == '(')
                openp ++;
        if (openp <= 0)
            out += input[i];
        else if (input[i] == ')') {
            openp --;
            if (openp <= 0) {
                while (!stack->isEmpty() && stack->peek()->c != '(')
                    out += stack->pop();
            }
            else{
                while (stack->peek()->c != '(')
                    line->addend(stack->pop());
                stack->pop();
                while (!line->isEmpty())
                    stack->push(line->pop());
            }
        }
        else {
            stack->push(input[i]);
        }
    }
    return out;
}

