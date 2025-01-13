// https://www.acmicpc.net/problem/1543

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string docs, search;
    getline(cin, docs);
    getline(cin, search);
    
    int res = 0;
    
    auto pos = docs.find(search, 0);
    while (pos != string::npos) {
        ++res;
        pos = docs.find(search, pos + search.size());
    }
    
    cout << res;

    return 0;
}
