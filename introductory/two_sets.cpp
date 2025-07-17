#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;

    ll sum = n * (n + 1) / 2;

    // If the sum can't be equally divided, false.
    if (sum % 2 == 1 || n == 1) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    vector<ll> chosen(n+1); // zero indexing

    ll first_sum = sum/2;
    ll first_set_nums = 0;
    for (ll i = n; i > 0LL; i--) {
        if (i <= first_sum) {
            first_sum -= i;
            chosen[i] = 1;
            first_set_nums++;
        }
    }

    cout << first_set_nums << "\n";
    for (ll i = 1; i <= n; i++) {
        if (chosen[i] == 1) {
            cout << i << " ";
        }
    }
    
    cout << "\n" << n - first_set_nums << "\n";
    for (ll i = 1; i <= n; i++) {
        if (chosen[i] == 0) {
            cout << i << " ";
        }
    }
}

