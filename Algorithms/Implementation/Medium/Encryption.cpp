#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    int L = s.size();
    double l = sqrt(L);
    int rows = floor(l);
    int cols = ceil(l);
    
    vector<string> block;
    int i = 0;
    while (i < s.size()) {
        string temp;
        if (i + cols > s.size())
            temp = s.substr(i);
        else
            temp = s.substr(i, cols);
        block.push_back(temp);
        i += cols;
    }
    
    string answer = "";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < block.size(); j++) {
            if (i >= block.at(j).size())
                break;
            answer += block.at(j).at(i);
        }
        if (i != cols-1)
            answer += ' ';
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
