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

    stack<pair<int,int>> s;
    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        int tmp; cin >> tmp;
        if (s.empty()) {
            cout << "0 ";
            s.push({ tmp,i });
        }
        else {
            while (s.top().first < tmp ) {
                s.pop();
                if (s.empty()) break;
            }
            if (s.empty()) {
                cout << "0 ";
                s.push({ tmp,i });
            }
            else {
                cout << s.top().second << " ";
                s.push({ tmp,i });
            }
        }
    }
}