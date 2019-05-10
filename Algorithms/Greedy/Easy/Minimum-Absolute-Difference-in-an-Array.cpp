#include <bits/stdc++.h>

using namespace std;

int minimumAbsoluteDifference(int n, vector <int> arr) {
    sort(arr.begin(), arr.end());
    int minDiff = INT_MAX;
    for (int i = 0; i < arr.size()-1; i++) {
        if (abs(arr[i]-arr[i+1]) < minDiff)
            minDiff = abs(arr[i] - arr[i+1]);
    }
    return minDiff;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = minimumAbsoluteDifference(n, arr);
    cout << result << endl;
    return 0;
}
