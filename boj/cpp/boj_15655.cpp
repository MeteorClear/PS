// https://www.acmicpc.net/problem/15655

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> v(N), p(N);
    
    for (int i=0; i<N; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    fill(p.begin()+M, p.end(), 1);
    
    do {
        for (int i=0; i<N; ++i) {
            if (!p[i]) {
                cout << v[i] << ' ';
            }
        } cout << '\n';
    } while (next_permutation(p.begin(), p.end()));

    return 0;
}
