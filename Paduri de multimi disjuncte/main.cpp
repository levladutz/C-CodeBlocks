#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "disjoint.in" );
ofstream fout( "disjoint.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
int n, m;
int father[100005];
int find( int x )
{
    if( father[x] != x )
        father[x] = find( father[x] );

    return father[x];
}
void unite( int a, int b )
{
    int rootA, rootB;
    rootA = find( a );
    rootB = find( b );

    if( rand() % 2 )
        father[rootA] = rootB;
    else
        father[rootB] = rootA;
}
int main()
{
    fast();
    fin >> n >> m;
    for(int i=1;i<=n;i++)
        father[i]=i;
    for( int i = 1; i <= m; i++ )
    {
        int x, a, b;
        fin >> x >> a >> b;

        if( x == 1 )
            unite( a, b );
        else
        {
            int rootA, rootB;
            rootA = find( a );
            rootB = find( b );

            if( rootA == rootB )
                fout << "DA\n";
            else
                fout << "NU\n";
        }
    }

    return 0;
}
