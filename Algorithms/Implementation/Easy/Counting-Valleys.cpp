#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    string steps;
    cin >> steps;
    int currentHeight = 0;
    bool inValley = false;
    int numValleys = 0;
    for (int i = 0; i < n; i++) {
        if (steps.at(i) == 'U')
            currentHeight++;
        else
            currentHeight--;
        if (currentHeight == -1 && !inValley) {
            inValley = true;
            numValleys++;
        }
        if (currentHeight == 0 && inValley)
            inValley = false;
    }
    cout << numValleys << endl;
    return 0;
}
