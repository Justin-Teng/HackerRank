#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    int N, Q;
    cin >> N >> Q;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    unordered_map<string, unordered_map<string, string>> tags;
    
    string currTag = "";
    
    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        string tagName;
        int spacePos = line.find(' ');
        if (spacePos == string::npos) {
            if (line.at(1) == '/') {
                if (currTag.size() < line.size()-1) {
                    currTag = "";
                } else {
                    currTag = currTag.substr(0, currTag.size()-line.size()+2);
                }
                continue;
            }
            tagName = line.substr(1, line.size() - 2);
            if (currTag.size() == 0)
                currTag = tagName;
            else
                currTag += "." + tagName;
            auto it = tags.find(currTag);
            if (it == tags.end()) {
                tags.emplace(currTag, unordered_map<string, string>());
            }
        } else {
            tagName = line.substr(1, spacePos - 1);
            if (currTag.size() == 0)
                currTag = tagName;
            else
                currTag += "." + tagName;
            auto it = tags.find(currTag);
            if (it == tags.end()) {
                tags.emplace(currTag, unordered_map<string, string>());
                it = tags.find(currTag);
            }
            int equalsPos = line.find('=', spacePos+1);
            string attr;
            string attrValue;
            while (equalsPos != string::npos) {
                attr = line.substr(spacePos+1, equalsPos-spacePos-2);
                int parenPos = equalsPos+2;
                int parenPos2 = line.find('\"', parenPos+1);
                attrValue = line.substr(parenPos+1, parenPos2-parenPos-1);
                auto it2 = it->second.find(attr);
                if (it2 == it->second.end())
                    it->second.emplace(attr, attrValue);
                spacePos = parenPos2 + 1;
                equalsPos = line.find('=', spacePos);
            }
        }
    }
    
    for (int i = 0; i < Q; i++) {
        string line;
        getline(cin, line);
        int tildePos = line.find('~');
        if (tildePos == string::npos) {
            cout << "Not Found!" << endl;
            continue;
        }
        string tagName = line.substr(0, tildePos);
        string attr = line.substr(tildePos+1);
        auto it = tags.find(tagName);
        if (it == tags.end())
            cout << "Not Found!" << endl;
        else {
            auto it2 = it->second.find(attr);
            if (it2 == it->second.end())
                cout << "Not Found!" << endl;
            else
                cout << it2->second << endl;
        }
    }
    
    return 0;
}
