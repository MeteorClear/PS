// https://www.acmicpc.net/problem/10799

#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int piece = 0;
    string steel_bar;
    cin >> steel_bar;
    
    stack<char> s;
    
    for (int i=0; i<steel_bar.size(); i++) {
        if (steel_bar[i] == '(') {
            s.push(steel_bar[i]);
        } else if (steel_bar[i] == ')') {
            s.pop();
            piece += steel_bar[i-1] == '(' ? s.size() : 1;
        }
    }
    
    cout << piece;
    
    return 0;
}
