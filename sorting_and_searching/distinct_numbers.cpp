#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int solve(vi arr, int n);

int main() {
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
    sort(arr.begin(), arr.end());

    int distinct = 0;
    int curr;
    for(int i = 0; i < n; i++) {
        distinct++;
        curr = arr[i];
        while((i+1 < n) && arr[i+1] == curr) {
            i++;
        }
    }
    
    return distinct;
}
