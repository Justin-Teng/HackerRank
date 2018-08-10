#include <bits/stdc++.h>

using namespace std;

string numberToWord(int n) {
    switch (n) {
        case 1: return "one ";
        case 2: return "two ";
        case 3: return "three ";
        case 4: return "four ";
        case 5: return "five ";
        case 6: return "six ";
        case 7: return "seven ";
        case 8: return "eight ";
        case 9: return "nine ";
        case 10: return "ten ";
        case 11: return "eleven ";
        case 12: return "twelve ";
        case 13: return "thirteen ";
        case 14: return "fourteen ";
        case 16: return "sixteen ";
        case 17: return "seventeen ";
        case 18: return "eighteen ";
        case 19: return "nineteen ";
        case 20: return "twenty ";
        case 21: return "twenty one ";
        case 22: return "twenty two ";
        case 23: return "twenty three ";
        case 24: return "twenty four ";
        case 25: return "twenty five ";
        case 26: return "twenty six ";
        case 27: return "twenty seven ";
        case 28: return "twenty eight ";
        case 29: return "twenty nine ";
    }
    return "FAIL ";
}

// Complete the timeInWords function below.
string timeInWords(int h, int m) {
    if (m == 0)
        return numberToWord(h) + "o' clock";
    else if (m <= 30) {
        if (m == 1)
            return "one minute past " + numberToWord(h);
        else if (m == 15)
            return "quarter past " + numberToWord(h);
        else if (m == 30)
            return "half past " + numberToWord(h);
        else
            return numberToWord(m) + "minutes past " + numberToWord(h);
    } else {
        if (m == 59) {
            if (h == 12)
                return "one minute to one";
            else
                return "one minute to " + numberToWord(h+1);
        } else if (m == 45) {
            if (h == 12)
                return "quarter to one";
            else
                return "quarter to " + numberToWord(h+1);
        } else {
            if (h == 12)
                return numberToWord(60-m) + "minutes to one";
            else
                return numberToWord(60-m) + "minutes to " + numberToWord(h+1);
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}
