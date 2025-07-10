#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    // n = 1 works. n = 2 or 3 doesn't. n = 4 edge case.
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
        return 0;
    } else if (n == 4) {
        cout << "2 4 1 3\n";
        return 0;
    }

    // Take odds first, then take evens.
    for (int i = 1; i <= n; i += 2) {
        cout << i << " ";
    }

    for (int i = 2; i <= n; i +=2) {
        cout << i << " ";
    }

    cout << "\n";
    return 0;
}