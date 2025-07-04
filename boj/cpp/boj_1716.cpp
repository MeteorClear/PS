// https://www.acmicpc.net/problem/1716

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    while (1) {
        cin >> n >> k;
        if (n==-1 && k==-1) break;
        
        vector<int> a(n+1);
        for (auto& e : a) {
            cin >> e;
        }
        
        if (k == 0) {
            cout << 0 << '\n';
            continue;
        }
        
        vector<int> remains(k, 0);
        for (int i=0; i<=n; ++i) {
            int block = i / k;
            int idx = i % k;
            remains[idx] += ((block & 1) ? -1 : 1) * a[i];
        }
        
        bool is_zero = true;
        for (auto& e : remains) {
            if (e != 0) {
                is_zero = false;
                break;
            }
        }
        
        if (is_zero) {
            cout << 0 << '\n';
            continue;
        }
        
        for (auto& e : remains) {
            if (!e) continue;
            cout << e << ' ';
        }
        cout << '\n';
    }

    return 0;
}
