// https://www.acmicpc.net/problem/2493

#include <iostream>
#include <stack>

using namespace std;

struct Tower {
    int idx;
    int height;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    int res[N] = {0};
    stack<Tower> ls, rs;
    
    for (int i=0; i<N; i++) {
        int t;
        cin >> t;
        ls.push({i,t});
    }
    
    while (!ls.empty()) {
        rs.push(ls.top());
        ls.pop();
        
        while (!ls.empty() && !rs.empty() && ls.top().height > rs.top().height) {
            res[rs.top().idx] = ls.top().idx+1;
            rs.pop();
        }
    }
    
    for (int i : res) cout << i << ' ';
    
    return 0;
}
