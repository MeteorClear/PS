// https://www.acmicpc.net/problem/17219

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    unordered_map<string, string> note;
    
    while (N--) {
        string site, pw;
        cin >> site >> pw;
        note[site] = pw;
    }
    
    while (M--) {
        string site;
        cin >> site;
        cout << note[site] << '\n';
    }

    return 0;
}
