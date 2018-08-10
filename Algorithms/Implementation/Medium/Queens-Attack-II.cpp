#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, rq, cq;
    cin >> n >> k >> rq >> cq;
    int U = n-rq, D = rq-1, L = cq-1, R = n-cq, UL = min(U, L), UR = min(U, R), DL = min(D, L), DR = min(D, R);
    
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        if (c == cq) { // if obstacle is in the same column as queen
            if (r > rq)
                U = min(U, r-rq-1);
            else
                D = min(D, rq-r-1);
        } else if (r == rq) { // if obstacle is in the same row as queen
            if (c > cq)
                R = min(R, c-cq-1);
            else
                L = min(L, cq-c-1);
        } else if (c - cq > 0) { // if obstacle is to the right of queen
            if (c - cq == r - rq) // if obstacle is to the up-right of queen   
                UR = min(UR, c-cq-1);
            else if (c - cq == rq - r) // if obstacle is to the down-right of queen
                DR = min(DR, c-cq-1);
        } else { // if obstacle is to the left of queen
            if (cq - c == r - rq) // if obstacle is to the up-left of queen
                UL = min(UL, cq-c-1);
            else if (cq - c == rq - r)// if obstacle is to the down-left of queen
                DL = min(DL, cq-c-1);
        }
    }
    
    int sum = U + D + L + R + UL + UR + DL + DR;

    cout << sum << endl;
}
