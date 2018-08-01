#include <bits/stdc++.h>

using namespace std;

string super_reduced_string(string s){
    int i = 0;
    bool flag = false;
    while (i < s.size()-1) {
        if (s.at(i) == s.at(i+1)) {
            if (i < s.size()-1) {
                if (i == 0) {
                    s = s.substr(i+2);
                }
                else
                    s = s.substr(0,i) + s.substr(i+2);
            }
            else
                s = s.substr(0, i);
            flag = true;
        }
        else {
            i++;
        }
        if (s.size()==0) {
            cout << "Empty String" << endl;
            break;
        }
        if (i >= s.size()-2 && flag) {
            i = 0;
            flag = false;
        }
    }
    return s;
}

int main() {
    string s;
    cin >> s;
    string result = super_reduced_string(s);
    cout << result << endl;
    return 0;
}
