// https://www.acmicpc.net/problem/2941

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string S;
    cin >> S;
    
    vector<string> croatia_alphabet = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    
    for (string alphabet : croatia_alphabet) {
        auto pos = S.find(alphabet, 0);
        while (pos != string::npos) {
            S.replace(pos, alphabet.size(), "0");
            pos = S.find(alphabet, pos + 1);
        }
    }
    cout << S.size();

    return 0;
}
