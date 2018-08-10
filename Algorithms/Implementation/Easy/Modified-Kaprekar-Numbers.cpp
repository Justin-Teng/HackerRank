#include <bits/stdc++.h>

using namespace std;

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
    bool validRange = false;
    for (long x = p; x <= q; x++) {
        long temp = x*x;
        vector<int> v;
        while (temp > 0) {
            v.push_back(temp % 10);
            temp /= 10;
        }
        
        reverse(v.begin(), v.end());
        
        int sum1 = 0, sum2 = 0;
        int factor = 1;
        
        for (int i = v.size()/2-1; i >= 0; i--) {
            sum1 += v[i]*factor;
            factor *= 10;
        }
        factor = 1;
        for (int i = v.size()-1; i >= v.size()/2 && i >= 0; i--) {
            sum2 += v[i]*factor;
            factor *= 10;
        }
        
        if (sum1 + sum2 == x) {
            cout << x << ' ';
            validRange = true;
        }
    }
    if (!validRange)
        cout << "INVALID RANGE";
    cout << '\n';
}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
