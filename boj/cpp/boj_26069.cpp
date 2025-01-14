// https://www.acmicpc.net/problem/26069

#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	unordered_set<string> dance;

	while (N--) {
		string A, B;
		cin >> A >> B;
		
		if (dance.empty() && (A == "ChongChong" || B == "ChongChong")) {
            dance.insert(A);
            dance.insert(B);
            continue;
		}
		
		if (dance.find(A) != dance.end()) {
		    dance.insert(B);
		} else if (dance.find(B) != dance.end()) {
		    dance.insert(A);
		}
    }
    
    cout << dance.size();

	return 0;
}
