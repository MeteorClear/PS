// https://www.acmicpc.net/problem/10799
// 10799번 쇠막대기
// 스택 문제
// 스택을 통해 "()" 가 들어올 때마다 지금까지의 스택 크기를 더해 해결 가능
// 스택에 '('가 들어올 때마다 푸쉬하여 추적
// ')'이 들어오면 팝하고 "()"인 경우 현재 열린 막대기 수(스택의 크기)만큼 조각 증가
// 아닌 경우 조각 1개 추가 (막대기 하나의 끝 처리)

#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int piece = 0;
    string steel_bar;
    cin >> steel_bar;
    
    stack<char> s;
    
    for (int i=0; i<steel_bar.size(); i++) {
        if (steel_bar[i] == '(') {
            s.push(steel_bar[i]);
        } else if (steel_bar[i] == ')') {
            s.pop();
            piece += steel_bar[i-1] == '(' ? s.size() : 1;
        }
    }
    
    cout << piece;
    
    return 0;
}
