#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int min = 1001, max = 0;
        for(int x_i = 0; x_i < n; x_i++){
            int x;
            cin >> x;
            if (x < min)
                min = x;
            if (x > max)
                max = x;
        }
        cout << max-min << endl;
    }
    return 0;
}
