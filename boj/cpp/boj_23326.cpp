// https://www.acmicpc.net/problem/23326

#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    set<int> s;
    
    int N, Q, pos = 1;
    cin >> N >> Q;
    
    for(int i=1; i<=N; ++i) {
        int A;
        cin >> A;
        
        if (A == 1) s.insert(i);
    }
    
    while (Q--) {
        int command;
        cin >> command;
        
        if (command == 1) {
            int i;
            cin >> i;
            
            if (s.find(i) == s.end()) s.insert(i);
            else s.erase(i);
            
        } else if (command == 2) {
            int x; 
            cin >> x;
            pos = (pos - 1 + x) % N + 1;
            
        } else {
            if (!s.empty()) {
                auto next = s.find(pos);
                if (next != s.end()) {
                    cout << "0\n";
                    continue;
                }
                
                next = s.upper_bound(pos);
                if (next == s.end()) {
                    next = s.begin();
                    cout << (N - pos + *next) << '\n';
                } else {
                    cout << (*next - pos) << '\n';
                }
                
            } else {
                cout << "-1\n";
            }
        }
    }

    return 0;
}
