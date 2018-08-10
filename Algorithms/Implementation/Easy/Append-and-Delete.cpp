#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {
    int numSameFrontChars = 0;
    int index = 0;
    while (index < s.size() && index < t.size()) {
        if (s.at(index) == t.at(index))
            numSameFrontChars++;
        else
            break;
        index++;
    }
    if (k >= s.size() + t.size())
        return "Yes";
    int temp = (s.size() - numSameFrontChars) + (t.size() - numSameFrontChars);
    if (k >= temp && (k-temp) % 2 == 0)
        return "Yes";
    return "No";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
