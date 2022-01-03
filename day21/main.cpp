#include <bits/stdc++.h>

using namespace std;
ifstream fin("in.in");
int a, b, x;
int pa, pb;
int turn = 1;
char s[1000];
long long nra=0;
long long nrb=0;
void gen(int a, int b,int tries, int turn)
{
    if(pb>=21)
    {
        nrb+=tries;
        return;
    }
    if(pa>=21)
    {
        nra+=tries;
        return;
    }
}
int main() {
    fin.getline(s, 1000);
    char *p = strtok(s, " ");
    while (p) {
        a = p[0] - '0';
        p = strtok(NULL, " ");
    }
    fin.getline(s, 1000);
    p = strtok(s, " ");
    while (p) {
        b = p[0] - '0';
        p = strtok(NULL, " ");
    }
    a--;
    b--;
    x = 0;
    while (pa < 21 && pb < 21) {
        if (turn == 1) {
            for (int i = 1; i <= 3; i++) {
                a = (a + x + 1) % 10;
                x = (x + 1) % 100;
            }
            nr+=3;
            pa+=a+1;
        } else {
            for (int i = 1; i <= 3; i++) {
                b = (b + x + 1) % 10;
                x = (x + 1) % 100;
            }
            nr+=3;
            pb+=b+1;
        }
        turn = 1 - turn;
    }
    cout<<nr<<' '<<pa<<' '<<pb<<' '<<min(pa,pb)*nr;
    return 0;
}
