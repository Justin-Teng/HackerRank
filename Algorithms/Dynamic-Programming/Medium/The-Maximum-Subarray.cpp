#include <bits/stdc++.h>

using namespace std;

vector <int> maxSubarray(vector <int> arr) {
    int globalMax = arr.at(0);
    int runningMax = arr.at(0);
    int maxSubsequence = arr.at(0);
    for (int i = 1; i < arr.size(); i++) {
        runningMax = max(arr.at(i), runningMax+arr.at(i));
        globalMax = max(runningMax, globalMax);
        if (maxSubsequence < 0) {
            maxSubsequence = max(maxSubsequence, arr.at(i));
        }
        else if (arr.at(i) > 0) {
            maxSubsequence += arr.at(i);
        }
    }
    vector<int> ans;
    ans.push_back(globalMax);
    ans.push_back(maxSubsequence);
    return ans;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        vector <int> result = maxSubarray(arr);
        for (ssize_t i = 0; i < result.size(); i++) {
            cout << result[i] << (i != result.size() - 1 ? " " : "");
        }
        cout << endl;


    }
    return 0;
}
