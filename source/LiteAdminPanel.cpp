#include <iostream>
#include <string>
#include <direct.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <fstream>
#include "dir.h"
#include <cmath> //hahaha, yes i know about it)
using namespace std;

const string version = "beta-0.0.3";
string output;
char buff[50];
string buf;
string server_name;
int yes = 1;


void help() {
    cout << "| " << "list of commands:\n";
    cout << "| " << "help(?) - show this text\n";
    cout << "| " << "info - show info about LA\n";
    cout << "| " << "setup - change or setup config\n";
    cout << "| " << "exit - exit program\n";
}

void info() {
    cout << "| LiteAdminPanel version: " << version << endl;
    cout << "| github: https://github.com/orgs/LiteAdminPanel/\n";
    cout << "| discord: prorok#1433, VinkyV#7660\n";
    cout << "| LiteAdminPanel by prorok, VinkW & c++\n";
}


void config() {
    system("mkdir LiteAdmin");
    ofstream fout(".\\LiteAdmin\\config.txt");
    ofstream fout1(".\\LiteAdmin\\version.txt");
    fout << "no" << endl;
    fout << "server";
    fout.close();
    fout1.close();
}

void setup() {
    cout << "type name of your server:\n";
    cin >> server_name;
    ofstream fout(".\\LiteAdmin\\config.txt");
    fout << "yes" << endl;
    fout << server_name;
    fout.close();
    cout << "[info] " << "the config was successfully changed\n";
    yes = 0;
}

/*int GetCpuUsage()
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
}*/


void error(int code) {
    if (code == -1) {
        //cout << "[warn] " << "unknown command, type 'help' for help\n";
    }
    if (code == 0) {
        cout << "[warn] " << "unknown command, type 'help' for help\n";
    }
    else if (code == 1) {
        cout << "[warn] " << "error when open config\n";
        system("pause");
        output = "exit";
    }
    else {
        cout << "[warn] " << "something was wrong and we can't find problem pls say us about this\n";
    }
}

int main()
{
    system("curl https://raw.githubusercontent.com/LiteAdminPanel/LiteAdminPanel/beta/source/version.txt > .\\LiteAdmin\\version.txt");
    system("cls");

    cout << " _      _     " << endl;
    cout << "| |    /_\\   " << endl;
    cout << "| |_  /---\\  " << endl;
    cout << "|___|/     \\ " << endl;
    cout << "              " << endl;
    cout << "[info] " << "LiteAdminPanel start type 'help' to get list of commands\n";
    cout << "[info] " << "If you have any issues pls say us about it(our contacts in /info)\n\n";

    ifstream fin(".\\LiteAdmin\\config.txt");
    ifstream fin1(".\\LiteAdmin\\version.txt");
    if (!fin.is_open() || !fin1.is_open()) {
        config();
    }

    fin.getline(buff, 50);
    buf = buff;
    if (!(buf == "yes")) {
        cout << "[info] " << "LiteAdminPanel don't config now, type '/setup' to fix it\n";
    }
    else {
        fin.getline(buff, 50);
        buf = buff;
        cout << "[info] " << "LiteAdminPanel load config for '" << buf << "', version: " << version << endl;
    }
    fin1.getline(buff, 50);
    buf = buff;
    if (version == buf) {
        cout << "[info] " << "you use last version of LiteAdmin!\n";
    }
    else {
        cout << "[warn] " << "version: " << buf << " is available!\n";
    }

    while (output != "exit") {
        if (yes == 1) {
            cout << "> ";
        }
        yes = 1;
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
        else if (output == "setup") {
            setup();
        }
        else if (output == "") {

        }
        else {
            error(0);
        }
    }
};
/*Thx for spend your time and see this code, we do all to you enjoy it!)*/
