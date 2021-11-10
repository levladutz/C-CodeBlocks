#include <iostream>
#include <cmath>

using namespace std;
#define ll long long
long long a, b, c;
int main() {
    cin >> a >> b >> c;

    if ( a != 4 || b % 2 != 0 ) {
        cout << "impossible";
        return 0;
    }

    ll side = b;
    ll center = c;
    ll h, w;
    h = w = 0;
    a = side / 2;
    b = center;

    if ( a * a - 4 * b < 0 ) {
        cout << "impossible";
        return 0;
    }

    ll delta = sqrt( a * a - 4 * b );
    h = ( a + delta ) / 2;
    w = ( a - delta ) / 2;
    h += 2;
    w += 2;

    if ( ( h - 2 ) * ( w - 2 ) != center || 2 * ( w - 2 ) + 2 * ( h - 2 ) != side ) {
        cout << "impossible";
        return 0;
    }

    cout << h << ' ' << w;
    return 0;
}
