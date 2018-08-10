#include <bits/stdc++.h>

using namespace std;

int getTotalX(vector <int> a, vector <int> b) {
    int largestA = a.at(0);
    int smallestB = b.at(0);
    for (int i = 1; i < a.size(); i++) {
        if (a.at(i) > largestA)
            largestA = a.at(i);
    }
    for (int i = 1; i < b.size(); i++) {
        if (b.at(i) < smallestB)
            smallestB = b.at(i);
    }
    
    int count = 0;
    for (int i = largestA; i <= smallestB; i++) {
        bool flag = false;
        for (int j = 0; !flag && j < a.size(); j++) {
            if (i % a.at(j) != 0)
                flag = true;
        }
        for (int j = 0; !flag && j < b.size(); j++) {
            if (b.at(j) % i != 0)
                flag = true;
        }
        if (!flag)
            count++;
    }
    return count;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
       cin >> b[b_i];
    }
    int total = getTotalX(a, b);
    cout << total << endl;
    return 0;
}
