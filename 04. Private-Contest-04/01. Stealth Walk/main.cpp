// [Link]="https://www.hackerrank.com/contests/iiit-hyd-private-contest-4/challenges/stealth-walk"

#include <bits/stdc++.h>
using namespace std;

void minimum_road_width(void) {

    int n, h, width = 0;
    cin >> n >> h;
    vector<int> heights(n);

    for (int i = 0; i < n; i++) {
        cin >> heights[i];

        if (heights[i] > h) {
            width += 2;
        } else { 
            width++; 
        }
    }

    cout << width << "\n";
    return;
}

// driver function
int main(void) {
    minimum_road_width();
    return 0;
}

