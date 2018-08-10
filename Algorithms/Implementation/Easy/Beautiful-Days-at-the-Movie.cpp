#include <bits/stdc++.h>

using namespace std;

int reverseNum(int x) {
    string s = to_string(x);
    for (int i = 1; i < s.size(); i++) {
        if (s.at(0) == '0' && s.at(i) != '0')
            s.erase(0, i);
    }
    reverse(s.begin(), s.end());
    return stoi(s);
}

int beautifulDays(int i, int j, int k) {
    int count = 0;
    for (int x = i; x <= j; x++) {
        if (abs(x - reverseNum(x)) % k == 0)
            count++;
    }
    return count;
}

int main() {
    int i;
    int j;
    int k;
    cin >> i >> j >> k;
    int result = beautifulDays(i, j, k);
    cout << result << endl;
    return 0;
}
