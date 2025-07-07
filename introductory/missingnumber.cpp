#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    // All numbers except 1
    vector<int> v(n-1);
    for (int i=0; i < (int) v.size(); i++) {
        cin >> v[i];
    }

    ll actual_sum = 0;
    for (int i=0; i < (int) v.size(); i++) {
        actual_sum += v[i];
    }
    
    // avoid overflows.
    ll expected_sum = (n * 1LL) * (n * 1LL + 1) / 2;

    cout << (expected_sum - actual_sum);
    
    return 0;
}