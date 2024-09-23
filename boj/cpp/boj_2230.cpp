// https://www.acmicpc.net/problem/2230

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> v(N);
    for (int i=0; i<N; ++i) cin >> v[i];
    
    sort(v.begin(), v.end());
    
    int lp = 0, rp = 0;
    int res = 2'000'000'001;
    
    while (rp < N) {
        int now = v[rp] - v[lp];
        
        if (now == M) {
            res = now;
            break;
        } else if (now > M) {
            res = min(res, now);
            ++lp;
        } else {
            ++rp;
        }
    }
    
    cout << res;

    return 0;
}
