#include <bits/stdc++.h>

using namespace std;

// Complete the marsExploration function below.
int marsExploration(string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); i+=3) {
        if (s.at(i) != 'S')
            sum++;
        if (s.at(i+1) != 'O')
            sum++;
        if (s.at(i+2) != 'S')
            sum++;
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
