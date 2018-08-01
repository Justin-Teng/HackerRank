#include <bits/stdc++.h>

using namespace std;

vector <int> climbingLeaderboard(vector <int> scores, vector <int> alice) {
    vector<int> ans;
    // alternatively, make a set of scores?
    vector<int> ranking(scores.size());
    int currRank = 1;
    ranking[0] = 1;
    for (int i = 1; i < scores.size(); i++) {
        if (scores[i] != scores[i-1])
            currRank++;
        ranking[i] = currRank;
    }
    
    for (int i = 0; i < alice.size(); i++) {
        if (alice[i] >= scores[0]){
            ans.push_back(1);
            continue;
        }
        auto it = upper_bound(scores.rbegin(), scores.rend(), alice[i]);
        size_t s_i = it - scores.rbegin();
        ans.push_back(ranking.at(scores.size()-s_i-1)+1);
    }
    
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> scores(n);
    for(int scores_i = 0; scores_i < n; scores_i++){
       cin >> scores[scores_i];
    }
    int m;
    cin >> m;
    vector<int> alice(m);
    for(int alice_i = 0; alice_i < m; alice_i++){
       cin >> alice[alice_i];
    }
    vector <int> result = climbingLeaderboard(scores, alice);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}
