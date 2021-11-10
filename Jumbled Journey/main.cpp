#include <bits/stdc++.h>

using namespace std;
int n;
int a[110][110];
void royFloyd() {
    for ( int k = 1; k <= n; k++ )
        for ( int i = 1; i <= n; i++ )
            for ( int j = 1; j <= n; j++ )
                if ( i != j && a[i][k]>0 && a[k][j]>0 && ( a[i][j] > a[i][k] + a[k][j] || !a[i][j] ) )
                    a[i][j] = a[i][k] + a[k][j];
}
int main() {
    cin >> n;

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= n; j++ )
            cin >> a[i][j];

    royFloyd();

    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= n; j++ )
            cout << a[i][j] << ' ';

        cout << '\n';
    }

    return 0;
}
