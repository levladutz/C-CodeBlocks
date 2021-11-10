#include <bits/stdc++.h>
using namespace std;

int n, co;
vector<int> a, b, sol;
int find( vector<int> a, int x ) {
    int ok = 0;

    for ( auto it : a )
        if ( x == it )
            ok = 1;

    return ok;
}
int main() {
    cin >> n;

    for ( int i = 1; i <= ( 1 << n ); i++ ) {
        int x;
        cin >> x;

        if ( x != 0 )
            a.push_back( x );
    }

    sort( a.begin(), a.end() );
    b.push_back( 0 );

    while ( !a.empty() ) {
        co++;
        int x = a.front();

        if ( !find( b, x ) ) {
            a.erase( a.begin() );
            vector<int>c;
            sol.push_back( x );

            for ( auto it : b )
                c.push_back( it + x );

            for ( auto it : c )
                b.push_back( it );
        } else continue;

        if ( co == 100 ) {
            cout << "impossible" << '\n';
            return 0;
        }
    }

    for ( auto it : sol )
        cout << it << '\n';

    return 0;
}
