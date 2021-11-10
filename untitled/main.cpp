#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <iomanip>

#define st first
#define nd second
#define pb push_back
#define mp make_pair
using namespace std;

ifstream fin("in.in");
ofstream fout("out.out");

map<string, string> var;
string buffer;
int errorFlag;
int returnFlag;

void goToNextEnd() {
    int nr = 1;
    string s;
    while (nr > 0) {    //skip else
        fin>>s;
        if(s=="if" || s == "else")
            nr++;
        else if(s == "end")
            nr--;
    }
}
void print() {
    string s;
    fin>>s;

    if(var.count(s) > 0)
        buffer+=var[s];
    else
        buffer+=s;
}

void create_var() {
    string a, b;
    fin>>a>>b;
    if(var.count(a) > 0) {
        returnFlag = 1;
        errorFlag = 1;
        cout<<"+++++++"<<a<<'\n';
    }
    else if(var.count(b) > 0) {
        var[a] = var[b];
    }
    else
        var[a] = b;
}

void set_var() {
    string a, b;
    fin>>a>>b;
    if(var.count(a) == 0) {
        returnFlag = 1;
        errorFlag = 1;
        cout<<"-------"<<b<<'\n';
        return;
    }
    if(var.count(b) > 0) {
        var[a] = var[b];
    }
    else
        var[a] = b;
}

void branch() {
    string s;
    fin>>s;
    //if true
    if(s == "true" || (var.count(s) && var[s] == "true")) {
        while (true) {
            fin>>s;
            if(s=="if")
                branch();
            else if(s == "var")
                create_var();
            else if(s == "set")
                set_var();
            else if(s == "print")
                print();
            else if(s == "return") {
                fin>>s;
                returnFlag = 1;
                goToNextEnd();
                break;
            }
            else if(s=="end")
                break;
        }
        fin>>s; //read "else"
        goToNextEnd();
    }   //else is true
    else if(s=="false" || (var.count(s) && var[s] == "false")){
        //skip true;
        goToNextEnd();
        fin>>s; //read else
        while (true) {
            fin>>s;
            if(s=="if")
                branch();
            else if(s == "var")
                create_var();
            else if(s == "set")
                set_var();
            else if(s == "print")
                print();
            else if(s == "return") {
                fin>>s;
                returnFlag = 1;
                goToNextEnd();
                break;
            }
            else if(s=="end")
                break;
        }
    }
    else {
        cout<<"==========="<<s<<'\n';
        returnFlag = 1;
        errorFlag = 1;
        goToNextEnd();
        fin>>s;
        goToNextEnd();
    }
}

string function() {
    string str;
    string returnValue = "";
    while (fin>>str)   {
        if(returnFlag == 1) {
            goToNextEnd();
            break;
        }
        if(str == "print") {
            print();
        }
        else if(str == "var") {
            create_var();
        }
        else if(str == "set") {
            set_var();
        }
        else if(str == "return") {
            returnFlag = 1;
            fin>>returnValue;
        }
        else if(str == "if") {
            branch();
        }
        else if(str == "end") {
            break;
        }
    }
}

int main() {
    int nr;
    fin>>nr;
    string str;
    while (fin>>str) {
        cout<<str<<'\n';
        function();

        if(errorFlag == 1)
            fout<<"ERROR\n";
        else if(buffer != "")
            fout<<buffer<<"\n";

        buffer = "";
        var.clear();
        returnFlag = 0;
        errorFlag = 0;

    }

    return 0;
}