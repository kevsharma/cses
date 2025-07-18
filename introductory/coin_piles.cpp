#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
    ll t;
    cin >> t;
    vector<ll> tests(t * 2LL);

    for (ll i = 0LL; i < 2LL * t; i++) {
        cin >> tests[i];
    }

    /*
    * valid(k, n) = k (1, 2) + n (2, 1) 
    * Solving a system of linear equations we have:
    * k + 2n = hi
    * n + 2k = lo
    * = (2hi - lo) / 3
    *
    */
    for (ll i = 0LL; i < 2LL * t; i += 2) {
        ll lo = min(tests[i], tests[i+1]);
        ll hi = max(tests[i], tests[i+1]);
        ll sum = (2LL * hi - lo);
        // Test case 4, 11 breaks since k = 22 - 4 div 3 = 18 / 3 = 6 > lo.
        if (sum % 3 != 0 || (sum / 3) > lo) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

}