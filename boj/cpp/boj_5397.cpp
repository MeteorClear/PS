// https://www.acmicpc.net/problem/5397

#include <iostream>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    
    while (tc--) {
        string s;
        cin >> s;
        
        list<char> l;
        auto p = l.begin();
        
        for (char c : s) {
            if (c == '-') {
                if (p != l.begin()) {
                    p--;
                    p = l.erase(p);
                }
            } else if (c == '<') {
                if (p != l.begin()) {
                    p--;
                }
            } else if (c == '>') {
                if (p != l.end()) {
                    p++;
                }
            } else l.insert(p, c);
        }
        
        for (char c : l) cout << c;
        cout << '\n';
    }

    return 0;
}
