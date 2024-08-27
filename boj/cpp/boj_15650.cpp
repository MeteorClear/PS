// https://www.acmicpc.net/problem/15650

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<bool> p(N);
    fill(p.begin()+M, p.end(), true);
    
    do {
        for (int i=0; i<N; ++i) {
            if (!p[i]) cout << i+1 << ' ';
        } cout << '\n';
    } while (next_permutation(p.begin(), p.end()));
    
    return 0;
}
