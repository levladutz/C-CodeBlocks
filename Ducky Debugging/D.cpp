#include <bits/stdc++.h>

using namespace std;
string s;
string a = "Quack!", b = "*Nod*";
int main() {
    while ( getline(cin, s ) ) {
        if ( s[s.size() - 1] == '?' ) {
            cout << a << '\n' << flush;
        } else if ( s[s.size() - 1] == '.' ) {
            cout << b << '\n' << flush;
        } else if ( s == "I quacked the code!" ) {
            return 0;
        }
    }

    return 0;
}
