#include <bits/stdc++.h>
using namespace std;
int n;
string sus = "suspicious", sol;
string a[1004];
string b[1004];
int pred[1004];
int fin[1004];
map<string, int>m;
int cmax = INT_MAX, rmax = INT_MAX;
int main() {
    cin >> n;

    for ( int i = 1; i <= n; i++ ) {
        cin >> a[i];
        m[a[i]] = i;
        pred[i] = i;
    }

    for ( int i = 1; i <= n; i++ ) {
        cin >> b[i];
        fin[ m[ b[i] ] ] = i;
    }

    for ( int i = 1; i <= n; i++ ) {
        cout << fin[i] << ' ' << pred[i] << '\n';
    }

    int ok = 1;

    for ( int i = 1; i <= n; i++ )
        if ( a[i] != b[i] ) {
            ok = 0;
            break;
        }

    if ( ok ) {
        cout << sus;
        return 0;
    }

    cmax = INT_MAX;

    for ( int i = 1; i <= n; i++ ) {
        if ( fin[i] - pred[i] < cmax ) {
            cmax = fin[i] - pred[i];
            rmax = fin[i];
            sol = a[i];
        } else if ( fin[i] - pred[i] == cmax && fin[i] < rmax ) {
            rmax = fin[i];
            sol = a[i];
        }
    }

    cout << sol;
    return 0;
}
