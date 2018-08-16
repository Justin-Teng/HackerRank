#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x;
    string s = "";
    while (cin >> x)
        s = to_string(x) + ' ' + s;
    cout << s << endl;
    return 0;
}
