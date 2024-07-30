// https://www.acmicpc.net/problem/11098

#include <iostream>

using namespace std;

struct Player {
    int C;
    string N;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, p;
    
    cin >> n;
    while (n--) {
        cin >> p;
        Player bestPlayer={-1,""}, currentPlayer;
        
        while (p--) {
            cin >> currentPlayer.C >> currentPlayer.N;
            if (currentPlayer.C > bestPlayer.C) bestPlayer = currentPlayer;
        }
        cout << bestPlayer.N << '\n';
    }

    return 0;
}
