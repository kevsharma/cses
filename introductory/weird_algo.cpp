#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    for (; n != 1; n = (n % 2 == 0) ? (n/2) : (3 * n + 1)) {
        cout << n << " ";
    }

    cout << 1 << "\n";
    return 0;
}