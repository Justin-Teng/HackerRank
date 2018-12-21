#include <bits/stdc++.h>

using namespace std;

char rotateCharacter(char c, int n) {
    n = n % 26;
    int x = c;
    if (x >= 65 && x <= 90) { // [A-Z]
        x += n;
        if (x > 90) {
            x = 65 + (x - 90) - 1;
        }
    } else if (x >= 97 && x <= 122) { // [a-z]
        x += n;
        if (x > 122) {
            x = 97 + (x - 122) - 1;
        }
    }
    char result = x;
    return result;
}

// Complete the caesarCipher function below.
string caesarCipher(string s, int k) {
    vector<char> result;
    for (int i = 0; i < s.size(); i++) {
        result.push_back(rotateCharacter(s.at(i), k));
    }
    string str(result.begin(), result.end());
    return str;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = caesarCipher(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
