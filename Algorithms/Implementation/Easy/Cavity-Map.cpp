#include <bits/stdc++.h>

using namespace std;

// Complete the cavityMap function below.
vector<string> cavityMap(vector<string> grid) {
    for (int i = 1; i < grid.size()-1; i++) {
        for (int j = 1; j < grid.at(i).size()-1; j++) {
            int x = grid.at(i).at(j) - '0';
            int a, b, c, d;
            
            if (grid.at(i).at(j-1) == 'X')
                continue;
            else
                a = grid.at(i).at(j-1) - '0';
            
            b = grid.at(i).at(j+1) - '0';
            
            if (grid.at(i-1).at(j) == 'X')
                continue;
            else
                c = grid.at(i-1).at(j) - '0';
            
            d = grid.at(i+1).at(j) - '0';
            
            if (x > a && x > b && x > c && x > d)
                grid.at(i).at(j) = 'X';
        }
    }
    return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = cavityMap(grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
