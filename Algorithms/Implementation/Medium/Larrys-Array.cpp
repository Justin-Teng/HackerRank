#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the larrysArray function below.
string larrysArray(vector<int> A) {
    for (int n = 1; n < A.size(); n++) {
        int index = -1;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == n) {
                index = i;
                break;
            }
            if (i == A.size() - 1)
                return "NO";
        }

        if (n == A.size() - 1 && index == A.size() - 1)
            return "NO";

        while (index != n-1) {
            if (index == n) { // Rotate once
                int first = A[index-1];
                int second = A[index];
                int third = A[index+1];
                A[index-1] = second;
                A[index] = third;
                A[index+1] = first;
                index--;
            } else { // Rotate twice
                int first = A[index-2];
                int second = A[index-1];
                int third = A[index];
                A[index-2] = third;
                A[index-1] = first;
                A[index] = second;
                index -= 2;
            }
        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string A_temp_temp;
        getline(cin, A_temp_temp);

        vector<string> A_temp = split_string(A_temp_temp);

        vector<int> A(n);

        for (int i = 0; i < n; i++) {
            int A_item = stoi(A_temp[i]);

            A[i] = A_item;
        }

        string result = larrysArray(A);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
