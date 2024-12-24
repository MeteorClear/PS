// https://www.acmicpc.net/problem/7662

#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while (T--) {
        int k;
        cin >> k;
        
        multiset<int> ms;
        
        while (k--) {
            char command;
            int n;
            cin >> command >> n;
            
            if (command == 'D') {
                if (ms.empty()) continue;
                if (n == 1) ms.erase(prev(ms.end()));
                else ms.erase(ms.begin());
            } else {
                ms.insert(n);
            }
        }
        
        if (ms.empty()) cout << "EMPTY\n";
        else cout << *ms.rbegin() << ' ' << *ms.begin() << '\n';
    }

    return 0;
}
