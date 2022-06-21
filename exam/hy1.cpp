#include <queue>
#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <memory>
#include <functional>
#include <cstring>   
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

struct Team {
    string name;
    int points;
    int goal_win, goal_lose;
    int pure_goal;
    Team() {}
    Team(const string &_name, int _point, int _win, int _lose): name(_name), points(_point), goal_win(_win), goal_lose(_lose), pure_goal(_win-_lose) {}
    bool operator < (const Team &rhs) {
        if (points == rhs.points) {
            if (pure_goal == rhs.pure_goal) {
                if (goal_win == rhs.goal_win) {
                    return name < rhs.name;
                }
                return goal_win > rhs.goal_win;
            }
            return pure_goal > rhs.pure_goal;
        }
        return points > rhs.points;
    }
    void update(int _win, int _lose, int _point) {
        goal_win += _win;
        goal_lose += _lose;
        pure_goal = goal_win - goal_lose;
        points += _point;
    }
};

vector<Team> tvec;

void print() {
    for (auto &t : tvec) {
        cout << t.name << " " << t.points << " " << t.goal_win << " " << t.goal_lose << endl;
    }
    cout << "END" << endl;
}

Team& findTeam(const string &name) {
    for (auto &t : tvec) {
        if (t.name == name) {
            return t;
        }
    }
    return tvec[0];
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        tvec.clear();
        string _name;
        int _point;
        int _win;
        int _lose;
        for (int i = 0; i < 6; ++i) {
            cin >> _name >> _point >> _win >> _lose;
            Team t(_name, _point, _win, _lose);
            tvec.push_back(t);
        }
        string name1, name2;
        int win1, win2;
        for (int i = 0; i < 3; ++i) {
            cin >> name1 >> name2 >> win1 >> win2;
            Team &t1 = findTeam(name1), &t2 = findTeam(name2);
            int p1 = 0, p2 = 0;
            if (win1 > win2) {
                p1 = 3;
            }
            else if (win1 < win2) {
                p2 = 3;
            }
            else {
                p1 = p2 = 1;
            }
            t1.update(win1, win2, p1);
            t2.update(win2, win1, p2);
        }
        sort(tvec.begin(), tvec.end());
        print();
    }
}

// 1 
// China 18 16 7
// Oman 12 9 10
// Japan 24 12 3
// Iran 20 11 6
// Thailand 7 9 17
// Vietam 0 6 20
// Iran Japan 0 3
// China Oman 2 0
// Thailand Vietam 1 1

// Japan 27 15 3
// China 21 18 7
// Iran 20 11 3
// Oman 12 9 8
// Thailand 8 10 16
// Vietam 1 7 19

// Japan 27 15 3
// China 21 18 7
// Iran 20 11 9
// Oman 12 9 12
// Thailand 8 10 18
// Vietam 1 7 21
// END