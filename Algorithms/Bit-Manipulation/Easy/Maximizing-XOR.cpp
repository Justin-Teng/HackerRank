#include <bits/stdc++.h>

using namespace std;

int maximizingXor(int l, int r) {
    int maxAns = 0;
    for (int A = l; A <= r; A++) {
        for (int B = A; B <= r; B++) {
            maxAns = max(maxAns, A^B);
        }
    }
    return maxAns;
}

int main() {
    int l;
    cin >> l;
    int r;
    cin >> r;
    int result = maximizingXor(l, r);
    cout << result << endl;
    return 0;
}
