#include <bits/stdc++.h>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {
    int total = 0;
    int i = 0;
    while (i < s.size()) {
        char c = s.at(i);
        int j = i+1;
        for (; j < s.size(); j++, total++) {
            if (s.at(j) != c)
                break;
        }
        i = j;
    }
    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);
        if (s.size() > 0 && s.at(0) != '\n') {
            int result = alternatingCharacters(s);

            fout << result << "\n";
        }
    }

    fout.close();

    return 0;
}
