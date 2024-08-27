// https://www.acmicpc.net/problem/11931

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> v(N);
    for (int i=0; i<N; ++i) {
        cin >> v[i];
    }
    
    sort(v.rbegin(), v.rend());
    
    for (auto e : v) {
        cout << e << '\n';
    }
    
    return 0;
}
