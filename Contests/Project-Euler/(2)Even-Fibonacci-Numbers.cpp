#include <iostream>

using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        long x = 0, y = 2, z = 8, sum = 0;
        while (y <= n) {
            sum += y;
            x = y;
            y = z;
            z = 4*y + x;
        }
        cout << sum << '\n';
    }
    return 0;
}
