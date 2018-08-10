#include <bits/stdc++.h>

using namespace std;

long flippingBits(long N) {
    return pow(2, 32)-1 - N;
}

int main() {
    int T;
    cin >> T;
    for(int a0 = 0; a0 < T; a0++){
        long N;
        cin >> N;
        long result = flippingBits(N);
        cout << result << endl;
    }
    return 0;
}
