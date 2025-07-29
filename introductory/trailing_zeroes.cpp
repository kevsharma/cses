#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef vector<int> vi;
typedef pair<int, int> pii;

pii last_digit_and_num_zeroes(int x) {
    int zeroes = 0;
    for (; x % 10 == 0; x /= 10) {
        zeroes++;
    }
    return {x % 10, zeroes};
}

int solve(int n) {
    int z = 0; // the number of zeroes
    int mi = 1; // the multiplicative identity
    pii p;
    for (int i = 2; i <= n; i++) {
        // Truncate multiplier and add zeroes
        p = last_digit_and_num_zeroes(i);
        z += p.second;

        mi *= p.first;

        // Truncate product and add zeroes
        p = last_digit_and_num_zeroes(mi);
        z += p.second;
        mi = p.first;
    }

    return z;
}

int32_t main() {
    fast_io;
    int n; 
    cin >> n;
    cout << solve(n);
    return 0;
}
