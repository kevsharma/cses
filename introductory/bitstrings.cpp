#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int val = 1;
    for (int i = 0; i < n; i++) {
        val = (val * 2) % 1000000007;
    }
    cout << val;
}