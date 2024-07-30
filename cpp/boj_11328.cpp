// https://www.acmicpc.net/problem/11328

#include <iostream>

using namespace std;

void fill_arr(int* arr, string& s) {
    for (char c : s) arr[c-'a']++;
}

int main() {
    ios::sync_with_stdio(0);
	  cin.tie(0);
    
    int N;
    cin >> N;
    
    while (N--) {
        int arr1[26] = {0}, arr2[26] = {0};
        string s;
        
        cin >> s;
        fill_arr(arr1, s);
        
        cin >> s;
        fill_arr(arr2, s);
        
        string result = "Possible\n";
        for (int i=0; i<26; i++) {
            if (arr1[i] != arr2[i]) {
                result = "Impossible\n";
                break;
            }
        }
        
        cout << result;
    }

    return 0;
}
