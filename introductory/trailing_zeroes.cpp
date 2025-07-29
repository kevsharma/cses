#include <bits/stdc++.h>
using namespace std;

// I didn't get this problem. I realized 2 * 5 = 10 but that wasn't enough.
// Based on large factorials, I also noticed answer * 4 = large number!
// https://japlslounge.com/posts/cses/trailing_zeros/1.htm
int main() {
    long n, current = 5, answer = 0;
    cin >> n;

    for (; current <= n; current *= 5) {
        answer += n / current;
    }

    cout << answer << endl;
    return 0;
}
