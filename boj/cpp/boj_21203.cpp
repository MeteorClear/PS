// https://www.acmicpc.net/problem/21203
// https://www.geeksforgeeks.org/dsa/sum-manhattan-distances-pairs-points/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> vs;
    vector<int> va;
    
    for (int i=0; i<N; ++i) {
        int s, a;
        cin >> s >> a;
        vs.push_back(s);
        va.push_back(a);
    }
    
    sort(vs.begin(), vs.end());
    sort(va.begin(), va.end());
    long long res = 0, sum_s = 0, sum_a = 0;
    
    for (int i=0; i<N; ++i) {
        res += 1LL * vs[i] * i - sum_s;
        sum_s += vs[i];
        res += 1LL * va[i] * i - sum_a;
        sum_a += va[i];
    }
    
    cout << res;
    
    return 0;
}
