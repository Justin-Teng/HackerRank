#include <bits/stdc++.h>

using namespace std;

vector < int > getRecord(vector < int > s){
    int brokeHighest = 0, brokeLeast = 0;
    int highestScore = s.at(0);
    int leastScore = s.at(0);
    for (int i = 1; i < s.size(); i++) {
        int score = s.at(i);
        if (score > highestScore) {
            brokeHighest++;
            highestScore = score;
        }
        else if (score < leastScore) {
            brokeLeast++;
            leastScore = score;
        }
    }
    vector <int> record;
    record.push_back(brokeHighest);
    record.push_back(brokeLeast);
    return record;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    vector < int > result = getRecord(s);
    string separator = "", delimiter = " ";
    for(auto val: result) {
        cout<<separator<<val;
        separator = delimiter;
    }
    cout<<endl;
    return 0;
}
