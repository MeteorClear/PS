// https://www.acmicpc.net/problem/11399

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> P(N);
    for (int i=0; i<N; ++i) cin >> P[i];
    
    sort(P.begin(), P.end());
    
    int res = 0, sum = 0;
    for (int i=0; i<N; ++i) {
        sum += P[i];
        res += sum;
    }
    
    cout << res;
    
    return 0;
}
