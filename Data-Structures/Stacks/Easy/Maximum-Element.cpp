#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct stackNode{
    long value;
    long currentMax;
    stackNode(long v, long cMax) {
        value = v;
        currentMax = cMax;
    }
};

int main() {
    int N;
    cin >> N;
    long maxValue = 0;
    stack<stackNode> s;
    
    for (int i = 0; i < N; i++) {
        int query;
        cin >> query;
        if (query == 1) {
            long x;
            cin >> x;
            if (x > maxValue)
                maxValue = x;
            stackNode n(x, maxValue);
            s.push(n);
        }
        else if (query == 2) {
            s.pop();
            if (s.empty())
                maxValue = 0;
            else
                maxValue = s.top().currentMax;
        }
        else {
            
            cout << s.top().currentMax << endl;
        }
    }
    return 0;
}
