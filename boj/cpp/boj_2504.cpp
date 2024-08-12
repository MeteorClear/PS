// https://www.acmicpc.net/problem/2504

#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string PS;
    cin >> PS;
    
    stack<char> s;
    bool is_error = false;
    
    for (char p : PS) {
        if (p == '(' || p == '[') {
            s.push(p);
        } else if(!s.empty()) {
            if (s.top() == '(' && p ==')') {
                s.pop();
            } else if (s.top() == '[' && p ==']') {
                s.pop();
            } else {
                is_error = true;
                break;
            }
        } else {
            is_error = true;
            break;
        }
    }
    
    if (!s.empty() || is_error) {
        cout << 0;
        return 0;
    }
    
    stack<string> f;
    int now = 1;
    for (char p : PS) {
        if (p == '(' || p == '[') {
            string str_temp = "";
            str_temp += p;
            f.push(str_temp);
        } else {
            int temp = 0;
            while (!f.empty() && f.top() != "(" && f.top() != "[") {
                temp += stoi(f.top());
                f.pop();
            }
            temp = temp == 0 ? 1 : temp;
            if (p == ')') {
                temp *= 2;
            } else {
                temp *= 3;
            }
            f.pop();
            f.push(to_string(temp));
        }
    }
    
    int res = 0;
    while (!f.empty()) {
        res += stoi(f.top());
        f.pop();
    }
    
    cout << res;
    
    return 0;
}
