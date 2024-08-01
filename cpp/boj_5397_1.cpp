// https://www.acmicpc.net/problem/5397

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    
    while (tc--) {
        string s;
        cin >> s;
        
        stack<char> ls, rs;
        for (char c : s) {
            if (c == '-') {
                if (!ls.empty()) {
                    ls.pop();
                }
                
            } else if (c == '<') {
                if (!ls.empty()) {
                    rs.push(ls.top());
                    ls.pop();
                }
                
            } else if (c == '>') {
                if (!rs.empty()) {
                    ls.push(rs.top());
                    rs.pop();
                }
                
            } else {
                ls.push(c);
            }
        }
        while(!rs.empty()) {
            ls.push(rs.top());
            rs.pop();
        }
        
        string res;
        while(!ls.empty()) {
            res += ls.top();
            ls.pop();
        }
        reverse(res.begin(), res.end());
        cout << res << '\n';
    }

    return 0;
}
