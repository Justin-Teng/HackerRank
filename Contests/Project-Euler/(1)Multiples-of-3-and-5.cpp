#include <iostream>

using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        n--;
        long a = n / 3;
        long answer = 3 * (a)*(a+1)/2;
        long b = n / 5;
        answer += 5 * (b)*(b+1)/2;
        long c = n / 15;
        answer -= 15 * (c)*(c+1)/2;
        cout << answer << endl;
    }
    return 0;
}
