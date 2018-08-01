#include <string>
#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int count = 1;
    for (int i = 0; i < s.size(); i++)
        if (s.at(i) >= 'A' && s.at(i) <= 'Z')
            count++;
    cout << count << endl;
    return 0;
}
