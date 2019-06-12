#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

void printNumber(int fives, int threes) {
    for (int i = 0; i < fives; i++)
        printf("5");
    for (int i = 0; i < threes; i++)
        printf("3");
    printf("\n");
}

// Complete the decentNumber function below.
void decentNumber(int n) {
    int maxFives = 3 * (n/3);

    int fives = maxFives;
    while (fives >= 0) {
        if ((n - fives) % 5 == 0) {
            printNumber(fives, n-fives);
            return;
        }
        fives -= 3;
    }

    printf("-1\n");
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        decentNumber(n);
    }

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
