#include <bits/stdc++.h>
using namespace std;


#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef vector<int> vi;
typedef pair<int, int> pii;

int position(vi arr, int target, int n, int excluding) {
    for (int i = 0; i < n; i++) {
        if (i == excluding) {
            continue;
        }
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

pii find_values(vi sorted_arr, vi arr, int target, int n) {
    int lo = 0;
    int hi = n - 1;
    while(lo < hi) {
        int curr_sum = sorted_arr[lo] + sorted_arr[hi];
        if (curr_sum < target) {
            lo++;
        } else if (curr_sum > target) {
            hi--;
        } else {
            // Found match.
            break;
        }
    }

    if (lo >= hi) {
        return {-1, -1};
    }

    return {sorted_arr[lo], sorted_arr[hi]};
}


int32_t main() {
    fast_io;
    int n, target;
    cin >> n;
    cin >> target;

    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vi sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());

    pii found = find_values(sorted_arr, arr, target, n);

    if (found.first == -1) {
        cout << "IMPOSSIBLE";
    } else {
        int fst = position(arr, found.first, n, -1);
        int snd = position(arr, found.second, n, fst);
        cout << fst + 1 << " " << snd + 1;
    }

    return 0;
}
