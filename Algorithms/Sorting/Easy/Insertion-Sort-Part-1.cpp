#include <bits/stdc++.h>

using namespace std;

void printArray (const vector <int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr.at(i);
        if (i != arr.size()-1)
            cout << ' ';
    }
    cout << endl;
}

void insertionSort1(int n, vector <int> arr) {
    int index = n-2;
    int e = arr.at(n-1);
    while (index >= 0) {
        if (arr.at(index) > e) {
            arr.at(index+1) = arr.at(index);
            printArray(arr);
        }
        else {
            arr.at(index+1) = e;
            printArray(arr);
            break;
        }
        if (index == 0) {
            arr.at(0) = e;
            printArray(arr);
        }
        index--;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    insertionSort1(n, arr);
    return 0;
}
