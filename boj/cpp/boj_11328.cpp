// https://www.acmicpc.net/problem/11328
// 11328번 Strfry
// 문자열 문제
// 두 문자열을 비교하여 사용된 알파벳이 같은지 확인하여 해결 가능
// 사용된 알파벳 종류와 수를 카운팅하여 비교 같은지 알 수 있다

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
