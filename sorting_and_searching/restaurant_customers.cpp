#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef vector<int> vi;
typedef pair<int, int> pii;

// Maximum subarray sum; arr contains 1s and -1s
int solve(vi arr, int n) {
    int max_sum = arr[0], curr_sum = arr[0];

    for(int i = 1; i < n; i++) {
        int curr = arr[i];
        curr_sum = max(curr_sum + curr, curr);
        max_sum = max(curr_sum, max_sum);
    }

    return max_sum;
}

// O(nlogn)
int32_t main() {
    fast_io;
    int n; cin >> n;
    n = 2LL * n;
    vi arr(n);

    for (int i = 0; i < n; i+=2) {
        cin >> arr[i];
        cin >> arr[i + 1LL];
        arr[i + 1LL] *= -1LL; // departure negative
    }

    // This helps us with summing in linear fashion
    sort(arr.begin(), arr.end(), 
        [](int a, int b) {
            return abs(a) < abs(b);
        }
    );

    // morph into arrival = 1, dept = -1
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] >= 0 ? 1LL : -1LL;
    }

    // apply maximum subarray sum to know at any time what was the 
    // maximum amount of people in the restaurant
    cout << solve(arr, n);
    return 0;
}
