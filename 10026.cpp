#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

#define X first
#define Y second

char board[100][100];
char RGBoard[100][100];

int vis[100][100];
int vis2[100][100];//해당 칸을 방문했는지, 1이 방문, 0 미방문

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 }; //상하좌우 방향

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    queue<pair<int, int>> Q;
    int cnt1 = 0, cnt2 = 0;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'G')
                RGBoard[i][j] = 'R';
            else
                RGBoard[i][j] = board[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] != 1) {
                vis[i][j] = 1;
                Q.push({ i,j });
                while (!Q.empty()) {
                    pair<int, int> cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (vis[nx][ny] || board[nx][ny] != board[cur.X][cur.Y]) continue;
                        Q.push({ nx,ny });
                        vis[nx][ny] = 1;
                    }
                }
                cnt1++;
            }
        }
    }

    while (!Q.empty())
        Q.pop();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis2[i][j] != 1) {
                vis2[i][j] = 1;
                Q.push({ i,j });
                while (!Q.empty()) {
                    pair<int, int> cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (vis2[nx][ny] || RGBoard[nx][ny] != RGBoard[cur.X][cur.Y]) continue;
                        Q.push({ nx,ny });
                        vis2[nx][ny] = 1;
                    }
                }
                cnt2++;
            }
        }
    }
    cout << cnt1 << " " << cnt2;
}