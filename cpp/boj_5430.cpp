// https://www.acmicpc.net/problem/5430

#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    
    while (tc--) {
        string command;
        cin >> command;
        
        int n;
        cin >> n;
        
        deque<int> x(n);
        char temp;
        
        cin >> temp;
        if (n==0) cin >> temp;
        for (int i=0; i<n; i++) {
            cin >> x[i] >> temp;
        }
        
        bool is_reverse = false, is_error = false;
        for (char p : command) {
            if (p == 'R') {
                is_reverse = !is_reverse;
            } else if (p == 'D') {
                if (x.empty()) {
                    is_error = true;
                    break;
                }
                
                if (is_reverse) {
                    x.pop_back();
                } else {
                    x.pop_front();
                }
            }
        }
        
        if (is_error) {
            cout << "error\n";
        } else {
            cout << "[";
            if (is_reverse) {
                for (int i=x.size()-1; i>-1; i--) {
                    cout << x[i];
                    if (i!=0) cout << ",";
                }
            } else {
                for (int i=0; i<x.size(); i++) {
                    cout << x[i];
                    if (i!=x.size()-1) cout << ",";
                }
            }
            cout << "]\n";
        }
    }

    return 0;
}
