// https://www.acmicpc.net/problem/1929

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<bool> v(M+1, false);
    v[1] = true;
    for (int i=2; i<M+1; i++) {
        if (v[i]) continue;
        for (int j=i*2; j<M+1; j+=i) {
            v[j] = true;
        }
    }
    
    for (int i=N; i<M+1; ++i) {
        if (!v[i]) cout << i << '\n';
    }
    
    return 0;
}
