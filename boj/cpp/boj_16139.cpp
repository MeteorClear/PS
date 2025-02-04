// https://www.acmicpc.net/problem/16139

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string S;
    int q;
    cin >> S >> q;
    
    vector<vector<int>> alphabet_count(26, vector<int>(S.size()+1, 0));
    
    for (int i=0; i<S.size(); ++i) {
        for (int j=0; j<26; ++j) {
            alphabet_count[j][i+1] = alphabet_count[j][i] + (S[i]-'a' == j);
        }
    }
    
    while (q--) {
        char a;
        int l, r;
        cin >> a >> l >> r;
        
        cout << alphabet_count[a-'a'][r+1] - alphabet_count[a-'a'][l] << '\n';
    }

    return 0;
}
