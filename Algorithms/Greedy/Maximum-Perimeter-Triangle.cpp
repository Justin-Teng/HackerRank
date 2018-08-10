#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<long> sticks;
    for (int i = 0; i < n; i++) {
        long s;
        cin >> s;
        sticks.push_back(s);
    }
    sort(sticks.begin(), sticks.end(), greater<long>());
    for (int i = 0; i < sticks.size()-2; i++) {
        long s1 = sticks.at(i);
        long s2 = sticks.at(i+1);
        long s3 = sticks.at(i+2);
        if (s1 < s2 + s3) {
            cout << s3 << ' ' << s2 << ' ' << s1 << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}
