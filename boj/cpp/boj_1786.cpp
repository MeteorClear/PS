// https://www.acmicpc.net/problem/1786

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string T, P;
    
    getline(cin, T);
    getline(cin, P);
    
    vector<int> lps_array(P.size(), 0);
    
    for (int i=1, j=0; i<P.size(); ++i) {
        while (j > 0 && P[i] != P[j]) j = lps_array[j-1];
        if (P[i] == P[j]) lps_array[i] = ++j;
    }
    
    int find_count = 0;
    vector<int> match_position;
    
    for (int i=0, j=0; i<T.size(); ++i) {
        while (j > 0 && T[i] != P[j]) j = lps_array[j-1];
        if (T[i] == P[j]) ++j;
        
        if (j == P.size()) {
            ++find_count;
            match_position.push_back((i - j + 1) + 1);
            j = lps_array[j-1];
        }
    }
    
    cout << find_count << '\n';
    for (auto idx : match_position) cout << idx << ' ';

    return 0;
}
