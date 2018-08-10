#include <cstdlib>
#include <iostream>

using namespace std;


int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int x;
        int y;
        int z;
        cin >> x >> y >> z;
        int distanceA = abs(x-z);
        int distanceB = abs(y-z);
        if (distanceA > distanceB)
            cout << "Cat B" << endl;
        else if (distanceA < distanceB)
            cout << "Cat A" << endl;
        else
            cout << "Mouse C" << endl;
    }
    return 0;
}
