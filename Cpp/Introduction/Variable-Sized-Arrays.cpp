#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> v(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<int> temp(k);
        v.at(i) = temp;
        for (int j = 0; j < k; j++) {
            int t;
            cin >> t;
            v.at(i).at(j) = t;
        }
    }
    for (int i = 0; i < q; i++) {
        int qi, qj;
        cin >> qi >> qj;
        cout << v.at(qi).at(qj) << endl;
    }
    return 0;
}
