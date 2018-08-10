#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <vector<string> > freq (100, vector<string>());
    for(int a0 = 0; a0 < n; a0++){
        int x;
        string s;
        cin >> x >> s;
        if (a0 < n/2)
            s = "-";
        freq.at(x).push_back(s);
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < freq.at(i).size(); j++) {
            cout << freq.at(i).at(j) << ' ';
        }
    }
    cout << endl;
    return 0;
}
