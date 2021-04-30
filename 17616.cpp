#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> maxGph[100001];
vector<int> minGph[100001];
bool maxVis[100001] = { false, };
bool minVis[100001] = { false, };

int mx = 0, mn = 0;
void maxDfs(int cur) {
    maxVis[cur] = true;
    mx++;
    for (int next : maxGph[cur])
        if (!maxVis[next]) {
            
            maxDfs(next);
            
        }
}

void minDfs(int cur) {
    minVis[cur] = true;
    mn++;
    for (int next : minGph[cur])
        if (!minVis[next]) {
            
            minDfs(next);
            
        }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, x;
    cin >> n >> m >> x;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        maxGph[a].push_back(b);
        minGph[b].push_back(a);
    }

    maxDfs(x);
    minDfs(x);
    cout << mn << "\n" << n - mx + 1;
}