#include <bits/stdc++.h>

using namespace std;

int sockMerchant(int n, vector <int> ar) {
    unordered_map<int, int> socks;
    int count = 0;
    for (int i = 0; i < n; i++) {
        auto it = socks.find(ar[i]);
        if (it != socks.end()) {
            count++;
            socks.erase(it);
        }
        else {
            socks.emplace(ar[i], 0);
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = sockMerchant(n, ar);
    cout << result << endl;
    return 0;
}
