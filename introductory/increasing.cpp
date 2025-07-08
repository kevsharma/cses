#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i=0; i < n; i++) {
        cin >> nums[i];
    }

    // Error handling for the loop.
    if (n == 0) {
        cout << "0\n";
        return 0;
    }

    ll additions = 0;

    // 3 2 5 1 7
    int prev_max = nums[0];
    for (int i=1; i < n; i++) {
        if (prev_max > nums[i]) {
            additions += (1LL) * (prev_max - nums[i]);
        }

        prev_max = max(nums[i], prev_max);
    }

    cout << additions << "\n";
    return 0;
}