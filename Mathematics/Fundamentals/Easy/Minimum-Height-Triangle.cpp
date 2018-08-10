#include <bits/stdc++.h>

using namespace std;

int lowestTriangle(int base, int area){
    double d = static_cast<double>(area) / base;
    return static_cast<int>(ceil(d * 2));
}

int main() {
    int base;
    int area;
    cin >> base >> area;
    int height = lowestTriangle(base, area);
    cout << height << endl;
    return 0;
}
