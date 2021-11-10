#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
int n, x, minSum = 1e9, ant, sola, solb;
set<pair<int, int>> s;

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        s.insert({x, i});
    }
    ant = -1;
    int antPos = -1;
    for (auto it: s) {
        int sum = it.first - ant;
        if (sum < minSum) {
            minSum = sum;
            sola = antPos;
            solb = it.second;
        }
        antPos = it.second;
        ant = it.first;
    }
    cout << minSum<<'\n'<< sola<<' '<<solb;
    return 0;
}
