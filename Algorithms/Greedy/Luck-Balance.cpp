#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, K;
    cin >> N >> K;
    vector<int> importantContests;
    int luck = 0;
    for (int i = 0; i < N; i++) {
        int L, T;
        cin >> L >> T;
        if (T == 1)
            importantContests.push_back(L);
        else
            luck += L;
    }
    sort(importantContests.begin(), importantContests.end());
    for (int i = 0; i < importantContests.size(); i++) {
        if (importantContests.size() > K && i < importantContests.size()-K)
            luck -= importantContests.at(i);
        else
            luck += importantContests.at(i);
    }
    cout << luck << endl;
    return 0;
}
