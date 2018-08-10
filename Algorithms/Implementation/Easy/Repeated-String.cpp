#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    int numRem = n % s.size();
    long countABefore = 0;
    for(int i = 0; i < numRem; i++) {
        if (s.at(i) == 'a')
            countABefore++;
    }
    long countATotal = countABefore;
    for (int i = numRem; i < s.size(); i++) {
        if (s.at(i) == 'a')
            countATotal++;
    }
    return countATotal * (n / s.size()) + countABefore;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
