#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef pair<int, int> pii;
typedef vector<pii> vi;

int solve(vi arr, int n) {
    // Sorted by ending times first
    int previous_ending_time = arr[0].second;
    int result = 1;
    for (int i = 1; i < n; i++) {
        pii p = arr[i];
        if (p.first >= previous_ending_time) {
            result++;
            previous_ending_time = p.second;
        }
    }
    return result;
}

int32_t main() {
    fast_io;
    int n; cin >> n;
    vi arr(n);

    for (int i = 0; i < n; i++) {
        pii p;
        cin >> p.first;
        cin >> p.second;
        arr[i] = p;
    }

    sort(arr.begin(), arr.end(), [](pii a, pii b) {
        return a.second < b.second;
    });

    cout << solve(arr, n);
    return 0;
}