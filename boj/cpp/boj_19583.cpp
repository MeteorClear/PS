// https://www.acmicpc.net/problem/19583

#include <iostream>
#include <unordered_map>

using namespace std;

bool isBefore(int th, int tm, int bh, int bm) {
    if (th == bh) return tm <= bm;
    return th <= bh;
}

bool isAfter(int th, int tm, int bh, int bm) {
    if (th == bh) return tm >= bm;
    return th >= bh;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    char temp;
    int sh, sm, eh, em, qh, qm;
    cin >> sh >> temp >> sm;
    cin >> eh >> temp >> em;
    cin >> qh >> temp >> qm;
    
    unordered_map<string, bool> chk;
    
    int nh, nm;
    string name;
    while (cin >> nh >> temp >> nm >> name) {
        if (isBefore(nh, nm, sh, sm)) chk[name] = false;
        if (isAfter(nh, nm, eh, em) && isBefore(nh, nm, qh, qm) && chk.find(name) != chk.end()) chk[name] = true;
    }
    
    int count = 0;
    for (auto [key, value] : chk) {
        if (value) ++count;
    }
    
    cout << count;
    
    return 0;
}
