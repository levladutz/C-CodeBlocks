#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "rmq.in" );
ofstream fout ( "rmq.out" );
int rmq[100005][30], n, m;
int lg[100005];
int a[100005];
void build_rmq() {
    ///cea mai mare putere a lui 2 mai mica decat i
    ///pentru distanta in interval query
    for ( int i = 2; i <= n; i++ )
        lg[i] = lg[i / 2] + 1;

    for ( int i = 1; i <= n; i++ )
        rmq[i][0] = a[i];

    for ( int j = 1; j <= lg[n]; j++ )
        for ( int i = 1; i + ( 1 << ( j - 1 ) ) <= n; i++ )
            rmq[i][j] = min ( rmq[i][j - 1], rmq[i + ( 1 << ( j - 1 ) )][j - 1] );
}
int query ( int l, int r ) {
    int d = r - l + 1;
    int k = lg[d];
    ///cea mai mare putere a lui d2 care incape in intervalul l,r
    return min ( rmq[l][k], rmq[r - ( 1 << k ) + 1][k] );
}
int main() {
    fin >> n >> m;

    for ( int i = 1; i <= n; i++ )
        fin >> a[i];

    build_rmq();

    while ( m-- ) {
        int x, y;
        fin >> x >> y;
        fout << query ( x, y ) << '\n';
    }

    return 0;
}