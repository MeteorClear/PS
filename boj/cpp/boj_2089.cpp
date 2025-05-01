// https://www.acmicpc.net/problem/2089

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long n, g;
    cin >> n;
    
    if (!n) cout << 0;
    
    vector<int> res;
    
    while (n != 0) {
        if (n % -2 == -1) {
            g = 1;
            n = (n-1) / -2;
        } else {
            g = n % -2;
            n = n / -2;
        }
        res.push_back(g);
    }
    
    for (auto i=res.rbegin(); i<res.rend(); ++i) {
        cout << *i;
    }
    
    return 0;
}
