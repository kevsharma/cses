#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(ll row, ll col);

int main() {
    ll t;
    cin >> t;
    vector<ll> tests(t * 2LL);

    for (ll i = 0LL; i < 2LL * t; i++) {
        cin >> tests[i];
    }

    for (ll i = 0LL; i < 2LL * t; i += 2) {
        cout << solve(tests[i], tests[i+1]) << "\n";
    }

    return 0;
}

// row and col start at 1 in problem.
// diagonal = 1 + n(n-1). up and left supported.
ll solve(ll row, ll col) {
    ll n = max(row, col);
    ll diagonal_cell = 1 + n * (n - 1);

    if (row == col) {
        return diagonal_cell;
    }

    ll diff = abs(row - col);
    ll multiplier = 0;
    if (row > col) {
        // go left from diagonal
        multiplier = row % 2LL == 0LL ? 1LL : -1LL;
    } else {
        // go up from diagonal
        multiplier = col % 2LL == 0LL ? -1LL : 1LL;
    }

    return diagonal_cell + (multiplier * diff);
}
