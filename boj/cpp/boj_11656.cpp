// https://www.acmicpc.net/problem/11656

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    vector<string> v;
    
    for (int i=0; i<s.size(); ++i) {
        v.push_back(s.substr(i));
    }
    
    sort(v.begin(), v.end());
    
    for (auto e : v) {
        cout << e << '\n';
    }

    return 0;
}
