#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> calories(n);
    for(int calories_i = 0; calories_i < n; calories_i++){
       cin >> calories[calories_i];
    }
    sort(calories.begin(),calories.end());
    long miles = 0;
    for (int i = n-1; i >= 0; i--) {
        miles += pow(2.0, n-1-i)*calories.at(i);
    }
    cout << miles << endl;
    return 0;
}
