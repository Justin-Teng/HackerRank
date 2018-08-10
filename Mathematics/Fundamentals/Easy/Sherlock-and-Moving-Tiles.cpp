#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the movingTiles function below.
 */
vector<double> movingTiles(long l, long s1, long s2, vector<long> queries) {
    vector<double> answer(queries.size(), -1);
    for (int i = 0; i < queries.size(); i++) {
        double q = static_cast<double>(queries[i]);
        answer[i] = (static_cast<double>(l) - sqrt(q)) / abs(s1 - s2) * sqrt(2);
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string lS1S2_temp;
    getline(cin, lS1S2_temp);

    vector<string> lS1S2 = split_string(lS1S2_temp);

    long l = stol(lS1S2[0]);

    long s1 = stol(lS1S2[1]);

    long s2 = stol(lS1S2[2]);

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<long> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        long queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<double> result = movingTiles(l, s1, s2, queries);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << fixed << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
