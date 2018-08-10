#include <bits/stdc++.h>

using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
    vector<int> types(container.size());
    vector<int> containerCap(container.size());
    
    for (int i = 0; i < container.size(); i++) {
        int sum = 0;
        for (int j = 0; j < container.at(i).size(); j++) {
            types.at(j) += container.at(i).at(j);
            sum += container.at(i).at(j);
        }
        containerCap.at(i) = sum;
    }
    
    sort(types.begin(), types.end());
    sort(containerCap.begin(), containerCap.end());
    
    for (int i = 0; i < types.size(); i++) {
        if (types.at(i) != containerCap.at(i))
            return "Impossible";
    }
    
    return "Possible";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
