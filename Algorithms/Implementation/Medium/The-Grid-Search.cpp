#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d\n", &t);
    for (int i = 0; i < t; i++) {
        
        int R, C;
        scanf("%d %d\n", &R, &C);
        vector<string> grid(R);
        for (int j = 0; j < R; j++) {
            string temp;
            getline(cin, temp);
            grid.at(j) = temp;
        }
        int r, c;
        cin >> r >> c;
        scanf("\n");
        vector<string> p(r);
        for (int j = 0; j < r; j++) {
            string temp;
            getline(cin, temp);
            p.at(j) = temp;
        }
        
        bool flag = false;
        
        for (int j = 0; j <= grid.size() - r; j++) {
            string s = grid.at(j);
            int startIndex = 0;
            size_t index = s.find(p.at(0), startIndex);
            while (index != string::npos) {
                startIndex = index+1;
                if (r == 1)
                    flag = true;
                for (int k = 1; k < r; k++) {
                    string s2 = grid.at(j+k);
                    if (s2.substr(index, p.at(k).size()).compare(p.at(k)) != 0) {
                        break;
                    }
                    if (k == r-1)
                        flag = true;
                }
                if (flag)
                    break;
                index = s.find(p.at(0), startIndex);
            }
        }
        
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
