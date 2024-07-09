// [Link]="https://www.hackerrank.com/contests/iiit-hyd-private-contest-4/challenges/color-my-array"

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    unsigned int m = 0;
    cin >> m;

    while (m--) {

        int n = 0; cin >> n;

        // To count the number of odd elements
        int odd_count = 0; 

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            if (num % 2 != 0) {
                odd_count++;
            }
        }

        if (odd_count % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
