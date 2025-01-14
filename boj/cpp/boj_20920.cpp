// https://www.acmicpc.net/problem/20920

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	
	unordered_map<string, int> vocabulary;
	
	while (N--) {
	    string word;
	    cin >> word;
	    
	    if (word.size() < M) continue;
	    
	    if (vocabulary.find(word) == vocabulary.end()) {
	        vocabulary[word] = 1;
	    } else {
	        ++vocabulary[word];
	    }
	}
	
	vector<pair<string, int>> note;
	for (auto [word, count] : vocabulary) note.push_back({word, count});
	
	sort(note.begin(), note.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
	    if (a.second == b.second) {
	        if (a.first.size() == b.first.size()) {
	            return a.first < b.first;
	        }
	        return a.first.size() > b.first.size();
	    }
	    return a.second > b.second;
	});
	
	for (auto [word, count] : note) cout << word << '\n';

    return 0;
}
