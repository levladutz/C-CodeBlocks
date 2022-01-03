#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
#define st first
#define nd second
#define pb push_back
#define ins insert
ifstream fin("in.in");
int di[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dj[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int a[1005][1005];
int b[1005][1005];
int decc[10000];
char s[1005];
int ok, si, sj, n, m;

void decode(int i, int j);

int b2d(string res);

int main() {
    si = sj = 360;
    ok = 1;
    while (fin.getline(s, 1000)) {
        if (!ok) {
            n++;
            for (int i = 0; s[i]; i++) {
                a[n + si][sj + i] = ((s[i] == '#') ? 1 : 0);
                m = max(m, i);
            }
            continue;
        }
        for (int i = 0; s[i]; i++)
            decc[i] = ((s[i] == '#') ? 1 : 0);
        ok = 0;
    }
    int t=50;
    while(t--) {
        for (int i = 1; i <= 1000; i++)
            for (int j = 1; j <=1000; j++)
                decode(i, j);
            for(int i=1;i<=1000;i++)
                for(int j=1;j<=1000;j++)
                    a[i][j]=0;
        for (int i = 1; i <= 1000; i++)
            for (int j = 1; j <= 1000; j++)
                a[i][j] = b[i][j];
    }
    int sol = 0;
    for (int i = 60; i <= 800; i++)
        for (int j =60; j <= 800; j++)
            sol += a[i][j];
    cout << sol;
    return 0;
}

void decode(int i, int j) {
    string res;
    for (int d = 0; d < 9; d++)
        res += (a[i + di[d]][j + dj[d]]==0)?'0':'1';
    int no = b2d(res);
    b[i][j] = decc[no];
}

int b2d(string res) {
    int sol = 0;
    for (int i = 0; i <= 8; i++)
        sol += (1 << (8 - i)) * (res[i]-'0');
    return sol;
}
