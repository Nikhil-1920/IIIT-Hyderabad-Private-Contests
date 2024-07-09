// [Link]="https://www.hackerrank.com/contests/iiit-hyd-private-contest-4/challenges/xor-se/problem"

#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

long xorSequence(long l, long r) {
    int n_l = (l - 1) % 8;
    int n_r = r % 8;
    
    long xor_l = (n_l == 0 || n_l == 1) ? (l - 1) :
                 (n_l == 2 || n_l == 3) ? 2 :
                 (n_l == 4 || n_l == 5) ? (l - 1) + 2 : 0;

    long xor_r = (n_r == 0 || n_r == 1) ? r :
                 (n_r == 2 || n_r == 3) ? 2 :
                 (n_r == 4 || n_r == 5) ? r + 2 : 0;

    return xor_r ^ xor_l;
}

int main(void) {
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string lr_temp;
        getline(cin, lr_temp);

        vector<string> lr = split_string(lr_temp);

        long l = stol(lr[0]);

        long r = stol(lr[1]);

        long result = xorSequence(l, r);

        fout << result << "\n";
    }

    fout.close();
    
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
