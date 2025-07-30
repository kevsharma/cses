#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef vector<int> vi;
typedef pair<int, int> pii;

// Let w = min(n, m). O(wlog(w))
int solve(vi desired, vi aptsizes, int n, int m, int k) {
    sort(desired.begin(), desired.end()); // diff from k keeps getting worst
    sort(aptsizes.begin(), aptsizes.end());
    int accepted = 0;

    // pointer for aptsizes, pointer for desired
    int customer = 0, apt = 0;
    while (apt < m && customer < n) {
        int diff = aptsizes[apt] - desired[customer];
        if (abs(diff) <= k) {
            accepted++;
            customer++;
            apt++;
        } else {
            // diff greater than k, move either ptr forward
            if (diff < 0) { 
                apt++; // this apartment won't meet any further customer's need
            } else {
                customer++; // this apartment too big for this customer
            }
        }
    }

    return accepted;
}

int32_t main() {
    fast_io;
    int n; cin >> n; // number of applications
    int m; cin >> m; // number of apartments
    int k; cin >> k; // max allowed difference
    
    vi desired(n);
    for (int i = 0; i < n; i++) {
        cin >> desired[i];
    }

    vi aptsizes(m);
    for (int i = 0; i < m; i++) {
        cin >> aptsizes[i];
    }

    cout << solve(desired, aptsizes, n, m, k);

    return 0;
}