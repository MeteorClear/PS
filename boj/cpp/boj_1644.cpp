// https://www.acmicpc.net/problem/1644

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<bool> p(4'000'002, false);
    vector<int> v;
    v.push_back(0);
    
    for (int i=2; i<=4'000'000; ++i) {
        if (!p[i]) {
            v.push_back(v.back() + i);
            for (int j=2*i; j<=4'000'000; j+=i) {
                p[j] = true;
            }
        }
    }
    
    int N;
    cin >> N;
    
    int res = 0, lp = 0, rp = 0, m = v.size();
    
    while (rp < m) {
        int now = v[rp] - v[lp];
       
        if (now == N) ++res;
       
        if (now >= N) {
            ++lp;
        } else {
            ++rp;
        }
    }
    
    cout << res;

    return 0;
}
