// https://www.acmicpc.net/problem/1431

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumStr(const string& s) {
    int res = 0;
    for (auto c : s) {
        if (c >= '0' && c <= '9') {
            res += (int)(c - '0');
        }
    }
    return res;
}

bool compare(const string& a, const string& b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }
    
    int sumA = sumStr(a);
    int sumB = sumStr(b);
    if (sumA != sumB) {
        return sumA < sumB;
    }
    
    return a < b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<string> v;
    
    while (N--) {
        string str;
        cin >> str;
        v.push_back(str);
    }
    
    sort(v.begin(), v.end(), compare);
    
    for (auto& e : v) {
        cout << e << '\n';
    }

    return 0;
}
