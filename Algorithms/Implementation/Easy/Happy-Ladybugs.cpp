#include <bits/stdc++.h>

using namespace std;

// Complete the happyLadybugs function below.
string happyLadybugs(string b) {
    bool hasEmpty = false;
    bool currentlyUnhappy = false;
    bool flag = false;
    vector<int> v(26, 0);
    for (int i = 0; i < b.size(); i++) {
        char c = b.at(i);
        if (c == '_') {
            hasEmpty = true;
            continue;
        }
        v[c - 'A']++;
        if (currentlyUnhappy)
            continue;
        if (i < b.size()-1) {
            if (!flag) {
                if (c != b.at(i+1))
                    currentlyUnhappy = true;
                else {
                    flag = true;
                }
            } else {
                if (c != b.at(i+1))
                    flag = false;
            }
        }
    }
    if (!hasEmpty && currentlyUnhappy)
        return "NO";
    for (int i = 0; i < 26; i++) {
        if (v[i] == 1)
            return "NO";
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
