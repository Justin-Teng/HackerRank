#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int m;
        cin >> n >> m;
        vector<vector<int>> adjMatrix (n, vector<int> (n));
        for(int a1 = 0; a1 < m; a1++){
            int u;
            int v;
            
            cin >> u >> v;
            adjMatrix.at(u-1).at(v-1) = 1;
            adjMatrix.at(v-1).at(u-1) = 1;
        }

        int s;
        cin >> s;
        vector<int> distances;
        vector<bool> visitedNodes;
        for (int i = 0; i < n; i++) {
            if (i+1 == s)
                distances.push_back(0);
            else
                distances.push_back(-1);
            visitedNodes.push_back(false);
        }
        
        queue<int> q;
        q.push(s);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visitedNodes.at(node-1) = true;
            for (int col = 0; col < n; col++) {
                if (adjMatrix.at(node-1).at(col) == 1) {
                    if (distances.at(node-1) + 1 < distances.at(col) || distances.at(col) == -1) {
                        distances.at(col) = distances.at(node-1) + 1;
                    }
                    if (visitedNodes.at(col) == false) {
                        q.push(col+1);
                        visitedNodes.at(col) = true;
                    }
                }
            }
        }
        
        for (int i = 0; i < distances.size(); i++) {
            if (i != s-1) {
                if (distances.at(i) == -1)
                    cout << -1 << ' ';
                else
                    cout << distances.at(i)*6 << ' ';
            }
        }
        cout << endl;
    }
    
    return 0;
}
