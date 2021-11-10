#include <bits/stdc++.h>
#define pb push_back
#define st first
#define nd second
#define ll long long
using namespace std;
int n, away = 1e18 + 5;
vector<pair<int, int>> a;
pair<int, int> p;
int main() {
    cin >> n;

    for ( int i = 1; i <= n; i++ ) {
        int x, y;
        cin >> x >> y;
        a.pb( {x, y} );
    }

    sort( a.begin(), a.end() );

    for ( auto it : a )
        cout << it.st << ' ' << it.nd << '\n';

    if ( n % 2 == 0 ) {
        int x, y;
        x = 0, y = 0;

        for ( auto it : a ) {
            x += it.st;
            y += it.nd;
        }

        x /= n;
        y /= n;
        p = make_pair( x, y );
    } else
        p = make_pair( a[n / 2].st, a[n / 2].nd );

    if ( n % 2 == 0 ) {
        cout << p.st - away << ' ' << p.nd - 1 << '\n';
        cout << p.st + away << ' ' << p.nd;
    } else {
        cout << p.st - away << ' ' << p.nd - 1 << '\n';
        cout << p.st + away << ' ' << p.nd + 1;
    }

    return 0;
}
