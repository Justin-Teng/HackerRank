#include <vector>
#include <iostream>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> a(100, 0);
    for(int a_i = 0;a_i < n;a_i++){
        int x;
        cin >> x;
        a[x]++;
    }
    int maxSequence = 2;
    for (int i = 1; i < 99; i++)
        if (a.at(i) + a.at(i+1) > maxSequence)
            maxSequence = a.at(i) + a.at(i+1);
    cout << maxSequence << endl;
    return 0;
}
