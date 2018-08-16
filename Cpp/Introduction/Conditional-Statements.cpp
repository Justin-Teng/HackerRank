#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<string> v = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    if (n <= 9)
        cout << v[n-1] << endl;
    else
        cout << "Greater than 9" << endl;
    return 0;
}
