// https://www.acmicpc.net/problem/21966

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    string S;
    cin >> S;
    
    if (N <= 25) {
        cout << S;
        return 0;
    }
    
    string mid = S.substr(11, S.size()-23);
    
    if (mid.find('.') == string::npos) {
        cout << S.substr(0, 11) << "..." << S.substr(S.size()-11);
    } else {
        cout << S.substr(0, 9) << "......" << S.substr(S.size()-10);
    }
    
    return 0;
}
