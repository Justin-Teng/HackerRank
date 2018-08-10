#include <bits/stdc++.h>

using namespace std;

int migratoryBirds(int n, vector <int> ar) {
    vector <int> freq(5, 0);
    
    for (int i = 0; i < ar.size(); i++) {
        freq[ar[i]-1]++;
    }
    
    int mostFreqNumber = 1;
    int mostFreq = freq[0];
    
    for (int i = 1; i < 5; i++) {
        if (freq[i] > mostFreq) {
            mostFreq = freq[i];
            mostFreqNumber = i+1;
        }
    }
    
    return mostFreqNumber;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = migratoryBirds(n, ar);
    cout << result << endl;
    return 0;
}
