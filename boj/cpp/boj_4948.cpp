// https://www.acmicpc.net/problem/4948

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    const int MAX = 246915;
    
    vector<bool> p(MAX, false);
    p[0] = p[1] = true;
    for (int i=2; i<MAX; ++i) {
        for (int j=2*i; j<MAX; j+=i) {
            p[j] = true;
        }
    }
    
    while (1) {
        int n, res = 0;
        cin >> n;
        if (!n) break;
        
        for (int i=n+1; i<=2*n; ++i) {
            if (!p[i]) ++res;
        }
        
        cout << res << '\n';
    }

    return 0;
}
