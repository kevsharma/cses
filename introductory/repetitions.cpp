#include <bits/stdc++.h>

using namespace std;

int main() {
    string input;
    cin >> input;

    const char* arr = input.c_str();

    int n, maxfound;
    n = 0;
    maxfound = 0;
    char prev = ' ';
    char curr;

    for (int i=0; i < (int) input.size(); i++) {
        curr = arr[i];
        if (curr != prev) {
            n = 0;
            prev = curr;
        } 
        
        n++;
        maxfound = max(n, maxfound);
    }

    cout << maxfound;
    return 0;
}