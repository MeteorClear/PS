// https://www.acmicpc.net/problem/4779

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void MakeCantorSet(vector<bool>& cantor_set, int length, int pos) {
    if (length <= 1) return;
    
    int sub_length = length / 3;
    for (int i=0; i<sub_length; ++i) cantor_set[pos+sub_length+i] = true;
    
    MakeCantorSet(cantor_set, sub_length, pos);
    MakeCantorSet(cantor_set, sub_length, pos+sub_length*2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    while (cin >> N) {
        int length = pow(3, N);
        vector<bool> cantor_set(length);
        
        MakeCantorSet(cantor_set, length, 0);
        
        for (auto state : cantor_set) cout << (state ? ' ' : '-');
        cout << '\n';
    }
    
    return 0;
}
