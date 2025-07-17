#include <bits/stdc++.h>

using namespace std;

int solve(int n);

int main() {
    int n;
    cin >> n;

    cout << solve(n);
}

int solve(int n) {
    int z = 0; // num zeroes
    int f = 1; // factorial last digits
    for (int i = 1; i <= n; i++) {
        f *= i;
        // if 5! = 5 * last_digit(4!) = 5 * 4 = 20
        if (f % 10 == 0) {
            z++;
            f /= 10;
        }

        f = f % 10; // keep last digit handy
    }

    return z;
}
