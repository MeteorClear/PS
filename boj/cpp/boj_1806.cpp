// https://www.acmicpc.net/problem/1806

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, S;
    cin >> N >> S;
    
    vector<int> v(N+1, 0);
    cin >> v[1];
    for (int i=2; i<=N; ++i) {
        int temp;
        cin >> temp;
        v[i] = v[i-1] + temp;
    }
    
    int lp = 0, rp = 0, res = N+2;
    
    while (rp < N+1) {
        int now = v[rp] - v[lp];
        
        if (now >= S) {
            res = min(res, rp - lp);
            ++lp;
        } else {
            ++rp;
        }
    }
    
    if (res == N+2) res = 0;
    cout << res;

    return 0;
}
