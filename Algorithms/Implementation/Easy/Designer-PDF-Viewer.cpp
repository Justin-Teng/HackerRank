#include <bits/stdc++.h>

using namespace std;

int designerPdfViewer(vector <int> h, string word) {
    int maxHeight = 1;
    for (int i = 0; i < word.size(); i++) {
        char c = word.at(i);
        int height = h[c - 'a'];
        if (height > maxHeight)
            maxHeight = height;
    }
    return maxHeight * word.size();
}

int main() {
    vector<int> h(26);
    for(int h_i = 0; h_i < 26; h_i++){
       cin >> h[h_i];
    }
    string word;
    cin >> word;
    int result = designerPdfViewer(h, word);
    cout << result << endl;
    return 0;
}
