#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef vector<int> vi;
typedef pair<int, int> pii;

/**
 * arr = sorted array
 * n = num children
 * w = max weight
 */
int solve(vi arr, int n, int w) {
    // Pair lowest and highest weights
    // if you move hi without moving lo, then gondola++
    // if you move both, then gondola++
    int lo = 0, hi = n - 1, gondola = 0;
    while (lo < hi) {
        int weight = arr[lo] + arr[hi];
        
        // Either the weight exceeds max or falls under
        if (weight <= w) {
            lo++; // seat two children
        }

        gondola++;
        hi--;
    }

    // if we converge to the same child
    gondola += lo == hi ? 1 : 0;
    return gondola;
}

int32_t main() {
    fast_io;
    int n, w;
    cin >> n;
    cin >> w;
    vi weights(n);

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());
    cout << solve(weights, n, w);

    return 0;
}