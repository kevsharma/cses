#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef vector<int> vi;
typedef pair<int, int> pii;

int solve(int n, int i, vi arr, int sum, int complement) {
    if (i >= n) {
        return abs(sum - complement);
    }

    int a = solve(n, i+1, arr, sum + arr[i], complement); // keep in set
    int b = solve(n, i+1, arr, sum, complement + arr[i]); // not in set
    return min(a, b);
}

int32_t main() {
    fast_io;
    
    int n; 
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = solve(n, 0, arr, 0, 0);
    cout << result;

    return 0;
}
