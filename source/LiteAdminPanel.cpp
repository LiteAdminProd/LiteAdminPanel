#include <iostream>
#include <string>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <cmath> //hahaha, yes i know about it)
using namespace std;

string output;

void help() {
    cout << "| " << "list of commands:\n";
    cout << "| " << "help(?) - show this text\n";
    cout << "| " << "exit - exit program\n";
    cout << "| " << "info - show info about LA\n";
    cout << "| " << "gpu - approximate CPU load\n";
}

void info() {
    cout << "| LiteAdminPanel version: beta-0.0.3\n";
    cout << "| github: https://github.com/orgs/LiteAdminPanel/\n";
    cout << "| discord: prorok#1433, VinkyV#7660\n";
    cout << "| LiteAdminPanel by VinkW, prorok & c++\n\n";
}

int GetCpuUsage()
{
    static ULARGE_INTEGER TimeIdle, TimeKernel, TimeUser;
    FILETIME Idle, Kernel, User;
    ULARGE_INTEGER uIdle, uKernel, uUser;
    GetSystemTimes(&Idle, &Kernel, &User);
    memcpy(&uIdle, &Idle, sizeof(FILETIME));
    memcpy(&uKernel, &Kernel, sizeof(FILETIME));
    memcpy(&uUser, &User, sizeof(FILETIME));
    long long t;
    t = (((((uKernel.QuadPart - TimeKernel.QuadPart) + (uUser.QuadPart - TimeUser.QuadPart)) -
        (uIdle.QuadPart - TimeIdle.QuadPart)) * (100)) / ((uKernel.QuadPart -
            TimeKernel.QuadPart) + (uUser.QuadPart - TimeUser.QuadPart)));
    TimeIdle.QuadPart = uIdle.QuadPart;
    TimeUser.QuadPart = uUser.QuadPart;
    TimeKernel.QuadPart = uKernel.QuadPart;
    return(static_cast<int>(t) + (static_cast<int>(t) / 2));
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
        else if (output == "gpu") {
            cout << "[info]" << "GPU load:" << GetCpuUsage() << "%\n";
        }
        else {
            error(0);
        }
    }
};
/*Thx for spend your time and see this code, we do all to you enjoy it!*/
