// [Link]="https://www.hackerrank.com/contests/iiit-hyd-private-contest-4/challenges/nikhils-parallelepiped"

#include <bits/stdc++.h>
using namespace std;

int main(void) {

    int area1, area2, area3;
    cin >> area1 >> area2 >> area3;
    int edge1 = sqrt((area1 * area2) / area3);
    int edge2 = sqrt((area1 * area3) / area2);
    int edge3 = sqrt((area2 * area3) / area1);
    int result = (edge1 + edge2 + edge3) * 4;
    cout << result << "\n";
    return 0;
}
