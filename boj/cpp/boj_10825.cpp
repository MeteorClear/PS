// https://www.acmicpc.net/problem/10825
// 10825번 국영수
// 정렬 문제
// 국어 점수가 "감소"하는 순서로
// 국어 점수가 같으면 영어 점수가 "증가"하는 순서로
// 국어 점수와 영어 점수가 같으면 수학 점수가 "감소"하는 순서로
// 모든 점수가 같으면 이름이 사전 순으로 "증가"하는 순서로 정렬하여 해결 가능

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student {
    string name;
    int kor;
    int eng;
    int mat;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<student> students;
    
    for (int i = 0; i < N; ++i) {
        string tname;
        int tkor, teng, tmat;
        cin >> tname >> tkor >> teng >> tmat;
        students.push_back({tname, tkor, teng, tmat});
    }
    
    sort(students.begin(), students.end(), [](auto& a, auto& b) {
        if (a.kor != b.kor) {
            return a.kor > b.kor;
        }
        if (a.eng != b.eng) {
            return a.eng < b.eng;
        }
        if (a.mat != b.mat) {
            return a.mat > b.mat;
        }
        return a.name < b.name;
    });
    
    for (auto& student : students) {
        cout << student.name << '\n';
    }

    return 0;
}
