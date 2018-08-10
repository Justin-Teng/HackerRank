#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
    string answer = "no answer";
    for (int i = w.size()-2; i >= 0; i--) {
        char A = w.at(i);
        char B = '{';
        int B_index = -1;
        for (int j = i+1; j < w.size(); j++) {
            if (w.at(j) > A && w.at(j) < B) {
                B = w.at(j);
                B_index = j;
            }
        }
        if (B_index != -1) {
            string temp = w.substr(0, i) + B + w.substr(i+1,B_index-i-1) + A + w.substr(B_index+1);
            sort(temp.begin() + i + 1, temp.end());
            return temp;
        }
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
