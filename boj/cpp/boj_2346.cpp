// https://www.acmicpc.net/problem/2346

#include <iostream>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    list<pair<int, int>> l;
    
    for (int i=1; i<=N; i++) {
        int x;
        cin >> x;
        l.push_back({i, x});
    }
    
    auto p = l.begin();
    
    while (!l.empty()) {
        cout << p->first << ' ';
        int next = p->second;
        
        p = l.erase(p);
        if (l.empty()) break;
        
        if (next > 0) {
            for (int i=0; i<next-1; ++i) {
                if (p == l.end()) p = l.begin();
                ++p;
            }
            if (p == l.end()) p = l.begin();
        } else {
            for (int i=0; i<abs(next); ++i) {
                if (p == l.begin()) p = l.end();
                --p;
            }
        }
    }
    return 0;
}
