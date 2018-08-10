#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, Q;
    cin >> N >> Q;
    vector <vector <long> > sequences;
    for (int i = 0; i < N; i++) {
        vector <long> sequence;
        sequences.push_back(sequence);
    }
    int lastAns = 0;
    for (int i = 0; i < Q; i++) {
        int queryType;
        long x, y;
        cin >> queryType >> x >> y;
        if (queryType == 1) {
            sequences.at((x^lastAns)%N).push_back(y);
        }
        else {
            int seq = (x^lastAns)%N;
            lastAns = sequences.at(seq).at(y%sequences.at(seq).size());
            cout << lastAns << endl;
        }
    }
    return 0;
}
