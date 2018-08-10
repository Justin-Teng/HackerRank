#include <vector>
#include <iostream>

using namespace std;

int main(){
    int s;
    int t;
    cin >> s >> t;
    int a;
    int b;
    cin >> a >> b;
    int m;
    int n;
    cin >> m >> n;
    vector<int> apple(m);
    for(int apple_i = 0;apple_i < m;apple_i++){
       cin >> apple[apple_i];
    }
    vector<int> orange(n);
    for(int orange_i = 0;orange_i < n;orange_i++){
       cin >> orange[orange_i];
    }
    
    int appleCount = 0;
    int orangeCount = 0;
    
    for (int i = 0; i < m; i++) {
        if (apple[i] + a >= s && apple[i] + a <= t)
            appleCount++;
    }
    for (int i = 0; i < n; i++) {
        if (orange[i] + b >= s && orange[i] + b <= t)
            orangeCount++;
    }
    
    cout << appleCount << endl;
    cout << orangeCount << endl;
    return 0;
}
