// https://www.acmicpc.net/problem/2075

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> v(N*N);
    for (int i=0; i<N*N; ++i) cin >> v[i];
    
    sort(v.rbegin(), v.rend());
    
    cout << v[N-1];
    
    return 0;
}
