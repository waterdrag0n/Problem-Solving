#include <iostream>
#include <vector>
#include <queue>
#define P pair<int,int>

using namespace std;

vector<P> vv[10001];
int total = 0;
bool visited[10001] = {false,};
void prim() {
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push(P(0,1));
	
	while (!pq.empty()) {
		P cur = pq.top();
		pq.pop();

		if (visited[cur.second]) continue;
		visited[cur.second] = true;
		total += cur.first;

		for (int i = 0; i < vv[cur.second].size(); i++) {
			if (!visited[vv[cur.second][i].second]) {
				pq.push(vv[cur.second][i]);
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int v, e;
	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int f, to, w;
		cin >> f >> to >> w;
		vv[f].push_back(P(w,to));
		vv[to].push_back(P(w,f));
	}

	prim();
	cout << total;
}

