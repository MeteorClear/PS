#include <iostream>
// https://www.acmicpc.net/problem/1822

#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int nA, nB;
    cin >> nA >> nB;
    
    vector<int> A(nA), B(nB);
    for (int i=0; i<nA; ++i) cin >> A[i];
    for (int i=0; i<nB; ++i) cin >> B[i];
    
    sort(B.begin(), B.end());
    
    int cnt = 0;
    vector<int> res;
    for (auto target : A) {
        if (!binary_search(B.begin(), B.end(), target)) {
            ++cnt;
            res.push_back(target);
        }
    }
    
    cout << cnt << '\n';
    if (cnt) {
        sort(res.begin(), res.end());
        for (auto e : res) {
            cout << e << ' ';
        }
    }

    return 0;
}
