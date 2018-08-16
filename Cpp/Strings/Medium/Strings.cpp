#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
    cin >> a >> b;
    cout << a.size() << ' ' << b.size() << '\n';
    cout << a << b << '\n';
    cout << b.at(0) << a.substr(1) << ' ' << a.at(0) << b.substr(1) << '\n';
    return 0;
}
