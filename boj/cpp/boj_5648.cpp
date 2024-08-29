// https://www.acmicpc.net/problem/5648

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<long long> v;
    
    while (n--) {
        string str;
        cin >> str;
        reverse(str.begin(), str.end());
        v.push_back(stoll(str));
    }
    
    sort(v.begin(), v.end());
    
    for (auto& e : v) {
        cout << e << '\n';
    }

    return 0;
}
