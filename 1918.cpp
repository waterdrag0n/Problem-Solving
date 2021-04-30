#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    stack<int> s;
    string str;
    cin >> str;
    vector<char> answer;

    for (int i = 0; i < str.length(); i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            answer.push_back(str[i]);
        }
        else if (str[i] == '(') {
            s.push(str[i]);
        }
        else if (str[i] == ')') {
            while (s.top() != '(') {
                answer.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
        else if (str[i] == '*' || str[i] == '/') {
            while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
                answer.push_back(s.top());
                s.pop();
            }
            s.push(str[i]);
        }
        else if (str[i] == '+' || str[i] == '-') {
            while (!s.empty() && (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/')) {
                answer.push_back(s.top());
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while (!s.empty()) {
        answer.push_back(s.top());
        s.pop();
    }
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i];
}