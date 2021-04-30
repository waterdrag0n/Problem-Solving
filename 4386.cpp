#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#define P pair<float,int>

using namespace std;

vector<P> vv[10001];
vector<P> graph;
float total = 0;
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
	int v;
	cin >> v;

	for (int i = 0; i < v; i++) {
		float x, y;
		cin >> x >> y;
		graph.push_back(P(x, y));
	}

	for (int i = 0; i < v-1; i++) {
		for (int j = i+1; j < v; j++) {
			float xCorf = graph[i].first;
			float yCorf = graph[i].second;
			float xCorr = graph[j].first;
			float yCorr = graph[j].second;
			float l = sqrt(pow(xCorf - xCorr, 2) + pow(yCorf - yCorr, 2));
			vv[i].push_back(P(l, j));
			vv[j].push_back(P(l, i));
		}
	}

	prim();
	printf("%.2f\n", total);
}

