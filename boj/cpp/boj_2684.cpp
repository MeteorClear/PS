// https://www.acmicpc.net/problem/2684

#include <iostream>
#include <array>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int P;
	cin >> P;

	while (P--) {
		array<int, 8> coin_sequence{};
		string s;
		cin >> s;

        for (int i=0; i+2<40; ++i) {
            int idx = (s[i] == 'H') * 4 + (s[i+1] == 'H') * 2 + (s[i+2] == 'H');
            ++coin_sequence[idx];
        }
        
        for (auto e : coin_sequence) {
            cout << e << ' ';
        }
        cout << '\n';
	}

	return 0;
}
