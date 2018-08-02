#include <bits/stdc++.h>

using namespace std;

void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
    // Priority: UL, UR, R, LR, LL, L
    if (i_end>=n || i_start>=n || j_start>=n || j_end>=n || i_start<0 || i_end<0 || j_start<0 || j_end<0) {
        cout << "Impossible" << endl;
        return;
    }
    if (abs(i_end-i_start)%2 == 1 || ( abs(i_end-i_start)%4 == 0 && abs(j_end-j_start)%2 == 1 )
        || ( abs(i_end-i_start)%4 == 2 && abs(j_end-j_start)%2 == 0 )) {
        cout << "Impossible" << endl;
        return;
    }
    vector<string> moves;
    while (j_start != j_end || i_start != i_end) {
        if (j_start>j_end && i_start==i_end) {
            moves.push_back("L");
            j_start-=2;
        }
        else if (j_start<j_end && i_start==i_end) {
            moves.push_back("R");
            j_start+=2;
        }
        else if (j_start>=j_end && i_start>i_end && j_start>0) {
            moves.push_back("UL");
            j_start--;
            i_start-=2;
        }
        else if (i_start>i_end) {
            moves.push_back("UR");
            j_start++;
            i_start-=2;
        }
        else if (j_start<=j_end && j_start<n-1 && j_end-j_start>i_end-i_start) {
            moves.push_back("R");
            j_start+=2;
        }
        else if (j_start<=j_end && j_start<n-1) {
            moves.push_back("LR");
            j_start++;
            i_start+=2;
        }
        else {
            moves.push_back("LL");
            j_start--;
            i_start+=2;
        }
    }
    cout << moves.size() << endl;
    
    sort(moves.begin(), moves.end());
    for (int i = moves.size()-1; i >= 0; i--) {
        cout << moves.at(i) << ' ';
    }
    if (moves.size() > 0)
        cout << endl;
}

int main() {
    int n;
    cin >> n;
    int i_start;
    int j_start;
    int i_end;
    int j_end;
    cin >> i_start >> j_start >> i_end >> j_end;
    printShortestPath(n, i_start, j_start, i_end, j_end);
    return 0;
}
