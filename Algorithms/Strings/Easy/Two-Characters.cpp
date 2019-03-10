#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the alternate function below.
int alternate(string s) {
    
    int maxLength = 0;
    for (int i = 0; i < 26; i++) {
        char c1 = 'a' + i;

        for (int j = i+1; j <= 26; j++) {
            char c2 = 'a' + j;
            bool first = true;
            bool flag = true;
            int length = 0;

            for (int k = 0; k < s.size(); k++) {
                if (first) {
                    if (s.at(k) == c1) {
                        flag = false;
                        first = false;
                        length++;
                    } else if (s.at(k) == c2) {
                        flag = true;
                        first = false;
                        length++;
                    }
                } else if (flag) {
                    if (s.at(k) == c1) {
                        length++;
                        flag = false;
                    } else if (s.at(k) == c2) {
                        length = 0;
                        break;
                    }
                } else {
                    if (s.at(k) == c1) {
                        length = 0;
                        break;
                    } else if (s.at(k) == c2) {
                        length++;
                        flag = true;
                    }
                }
            }

            maxLength = max(length, maxLength);
        }
    }
    
    if (maxLength == 1)
        return 0;
    return maxLength;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
