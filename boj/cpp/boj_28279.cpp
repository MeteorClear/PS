// https://www.acmicpc.net/problem/28279

#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    deque<int> dq;
    
    while (N--) {
        int command, X;
        cin >> command;
        
        switch (command) {
            case 1:
                cin >> X;
                dq.push_front(X);
                break;
            case 2:
                cin >> X;
                dq.push_back(X);
                break;
            case 3:
                if (dq.empty()) {
                    cout << "-1\n";
                } else {
                    cout << dq.front() << '\n';
                    dq.pop_front();
                }
                break;
            case 4:
                if (dq.empty()) {
                    cout << "-1\n";
                } else {
                    cout << dq.back() << '\n';
                    dq.pop_back();
                }
                break;
            case 5:
                cout << dq.size() << '\n';
                break;
            case 6:
                cout << dq.empty() << '\n';
                break;
            case 7:
                if (dq.empty()) {
                    cout << "-1\n";
                } else {
                    cout << dq.front() << '\n';
                }
                break;
            case 8:
                if (dq.empty()) {
                    cout << "-1\n";
                } else {
                    cout << dq.back() << '\n';
                }
                break;
        }
    }

    return 0;
}
