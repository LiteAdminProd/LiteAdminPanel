#include <iostream>
#include <string>
#include <cmath> //hahaha, yes i know about it)
using namespace std;

string output;

void help() {
    cout << "| " << "list of commands:\n";
    cout << "| " << "help(?) - show this text\n";
    cout << "| " << "exit - exit program\n";
    cout << "| " << "info - show info about LA\n";
}

void info() {
    cout << "| LiteAdminPanel version: 0.0.1\n";
    cout << "| github: https://github.com/orgs/LiteAdminPanel/\n";
    cout << "| discord: prorok#1433, VinkyV#7660\n";
    cout << "| LiteAdminPanel by VinkW, prorok & c++\n\n";
}

void error(int code) {
    if (code == 0) {
        cout << "[warn] " << "unknown command, type 'help' for help\n";
    }
    else {
        cout << "[warn] " << "something was wrong and we can't find problem pls say us about this\n";
    }
}

int main()
{
    cout << " _      _     " << endl;
    cout << "| |    /_\\   " << endl;
    cout << "| |_  /---\\  " << endl;
    cout << "|___|/     \\ " << endl;
    cout << "              " << endl;
    cout << "[info] " << "LiteAdminPanel start type 'help' to get list of commands\n";
    cout << "[info] " << "If you have any issues pls say us about it(our contacts in /info)\n\n";

    while (output != "exit") {
        cout << "> ";
        getline(cin, output);
        if (output == "exit") {
            system("pause");
        }
        else if (output == "help") {
            help();
        }
        else if (output == "help" || output == "?") {
            help();
        }
        else if (output == "info") {
            info();
        }
        else {
            error(0);
        }
    }
};
/*Thx for spend your time and see this code, we do all to you enjoy it!*/
