#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    string input;
    cin >> input;

    const char* arr = input.c_str();
    int num_letters = input.size();

    // counts
    vector<int> occurrences(26);
    // A's ascii value is 65; a is 97
    for (int i=0; i < num_letters; i++) {
        occurrences[arr[i] - 65]++;
    }

    // if more than one odd, then reject
    int odds_found = 0;
    char odd_letter = 100;

    for (int i=0; i < (int) occurrences.size(); i++) {
        if (occurrences[i] % 2 == 1) {
            odds_found++;
            odd_letter = i + 65;
            occurrences[i]--; // make it even (could be 0)
        }
    }

    // Exit if more than one odd - this means no palindrome
    if (odds_found > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    int lo = 0;
    int hi = num_letters - 1;
    vector<char> palindrome(num_letters);

    if (odds_found == 1) {
        palindrome[num_letters / 2] = odd_letter;
    }

    // O(n) where n = number of letters
    for(int i=0; i < 26; i++) {
        int repeat = occurrences[i];
        char letter = i + 65;
        // based on past updates, this will always be even.
        while (repeat != 0) {
            palindrome[lo++] = letter;
            palindrome[hi--] = letter;
            repeat -= 2;
        }
    }

    string result(palindrome.begin(), palindrome.end());
    cout << result << "\n";
    return 0;
}
