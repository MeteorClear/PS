// https://www.acmicpc.net/problem/15657

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void makePermutaion(vector<int>& v, vector<int>& p, int k, int m) {
    if (p.size() == m) {
        for (auto e : p) {
            cout << e << ' ';
        } cout << '\n';
        return;
    }
    
    for (int i=k; i<v.size(); ++i) {
        p.push_back(v[i]);
        makePermutaion(v, p, i, m);
        p.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> v(N), p;
    
    for (int i=0; i<N; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    makePermutaion(v, p, 0, M);

    return 0;
}
