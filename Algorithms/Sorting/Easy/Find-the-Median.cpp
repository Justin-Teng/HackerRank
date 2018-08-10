#include <bits/stdc++.h>

using namespace std;

int findMedian(vector <int> arr) {
    nth_element(arr.begin(), arr.begin() + arr.size()/2, arr.end());
    return arr[arr.size()/2];
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = findMedian(arr);
    cout << result << endl;
    return 0;
}
