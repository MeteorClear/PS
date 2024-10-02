// https://www.acmicpc.net/problem/11478

#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string S;
    cin >> S;
    
    unordered_set<string> C;
    
    for (int i=1; i<=S.size(); ++i) {
        for (int j=0; j+i<=S.size(); ++j) {
            C.insert(S.substr(j, i));
        }
    }
    
    cout << C.size();
    
    return 0;
}
