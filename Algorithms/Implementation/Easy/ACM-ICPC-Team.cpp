#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int knownTopics(string* a, string* b) {
    int count = 0;
    for (int i = 0; i < a->size() && i < b->size(); i++) {
        if (a->at(i) == '1' || b->at(i) == '1')
            count++;
    }
    return count;
}

// Complete the acmTeam function below.
vector<int> acmTeam(vector<string> topic) {
    int maxTopics = 0;
    int numMax = 0;
    for (int i = 0; i < topic.size() - 1; i++) {
        for (int j = i+1; j < topic.size(); j++) {
            string* a = &topic.at(i);
            string* b = &topic.at(j);
            int n = knownTopics(a, b);
            if (n > maxTopics) {
                maxTopics = n;
                numMax = 1;
            } else if (n == maxTopics)
                numMax++;
        }
    }
    vector<int> temp {maxTopics, numMax};
    return temp;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<string> topic(n);

    for (int i = 0; i < n; i++) {
        string topic_item;
        getline(cin, topic_item);

        topic[i] = topic_item;
    }

    vector<int> result = acmTeam(topic);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
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
