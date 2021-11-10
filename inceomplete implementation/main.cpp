#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, x, k;
int a[100005], b[100005];
vector<int> sol[4];
int use[100005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        a[x] = i;
        b[i] = x;
    }

    int ok = 0;

    while (k < 3 && ok == 0) {
        int d = n / 4;
        vector<int> v, pos;
        for (int i = 1; i <= n; i++)
            use[i] = 0;

        for (int i = n; i >= 0 && d; i--) {
            if (i == 0)
                ok = 1;

            if (a[i] != i && !use[i]) {
                d--;
                use[i] = 1;
                if(!use[b[i]])
                use[b[i]] = 1;
                v.push_back(i);
                v.push_back(b[i]);
                pos.push_back(i);
                pos.push_back(a[i]);
            }
        }

            int aux=n;
            while(d)
            {
                v.push_back(aux);
                v.push_back(aux-1);
                pos.push_back(aux);
                pos.push_back(aux-1);
                d--;
                aux-=2;
            }

        if (ok)
            break;

        sort(v.begin(), v.end());
        sort(pos.begin(), pos.end());


        for (int i = 0; i < n / 2; i++) {
            b[pos[i]] = v[i];
            a[v[i]] = pos[i];
        }

        sol[k] = pos;
        k++;
    }
    cout << k << '\n';
    for (int i = 0; i < k; i++) {
        for (auto it: sol[i])
            cout << it << ' ';

        cout << '\n';
    }

    return 0;
}
