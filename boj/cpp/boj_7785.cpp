// https://www.acmicpc.net/problem/7785

#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    map<string, bool, greater<string>> enterLog;
    
    while (n--) {
        string name, action;
        cin >> name >> action;
        
        if (action == "enter") {
            enterLog[name] = true;
        } else if (enterLog.find(name) != enterLog.end()) {
            enterLog[name] = false;
        }
    }
    
    for (auto [name, action] : enterLog) {
        if (action) {
            cout << name << '\n';
        }
    }

    return 0;
}
