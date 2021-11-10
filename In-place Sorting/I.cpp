#include <bits/stdc++.h>

using namespace std;
int n;
int a[10005];
int b[10005];
vector<string>sol;
string toString( int a[10005], int n ) {
    string sol = "";

    for ( int i = 1; i <= n; i++ )
        sol += a[i] + '0';

    return sol;
}
void copy( int a[10005], int b[10005] ) {
    for ( int i = 0; i < a[0]; i++ )
        b[i] = a[i];
}
int main() {
    cin >> n;

    for ( int i = 1; i <= n; i++ ) {
        cin >> x;

        while ( x ) {
            a[++a[0]] = x % 10;

            if ( a[i] == 6 )
                a[i] = 9;

            x /= 10;
        }

        if ( i == 1 ) {
            for ( int j = 0; j <= a[0]; j++ ) {
                b[i] = a[i];

                if ( b[i] == '9' ) b[i] = 6;
            }

            sol.push_back( toString( b, b[0] ) );
            continue;
        }

        if ( a[0] > b[0] ) {
            sol.push_back( toString( a, a[0] ) );
            copy( a, b );
            continue;
        }

        int flag = 0;
    }

    return 0;
}
