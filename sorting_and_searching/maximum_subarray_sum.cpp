#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

int solve(vi arr, int n);

int32_t main() {
    int n;
    cin >> n;

    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << solve(arr, n);

    return 0;
}

int solve(vi arr, int n) {
    int max_sum = arr[0], curr_sum = arr[0];

    for(int i = 1; i < n; i++) {
        int curr = arr[i];
        curr_sum = max(curr_sum + curr, curr);
        max_sum = max(curr_sum, max_sum);
    }

    return max_sum;
}
