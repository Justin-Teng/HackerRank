#include <bits/stdc++.h>

using namespace std;

int viralAdvertising(int n) {
    int x = 5;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        x /= 2;
        sum += x;
        x *= 3;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    int result = viralAdvertising(n);
    cout << result << endl;
    return 0;
}
