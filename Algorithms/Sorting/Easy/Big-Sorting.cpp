#include <bits/stdc++.h>

using namespace std;

bool sortHelper (string a, string b) {
    int a_length = a.size();
    int b_length = b.size();
    
    if (a_length == b_length)
        return a.compare(b) < 0;
    
    return a_length < b_length;
}

// Complete the bigSorting function below.
vector<string> bigSorting(vector<string> unsorted) {
    sort(unsorted.begin(), unsorted.end(), sortHelper);
    return unsorted;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

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
