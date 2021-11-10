#include <iostream>

using namespace std;
int n, k;
int main() {
    cin >> n >> k;
    int x = ( n + k - 1 ) / k;
    cout << n / x;
    return 0;
}
