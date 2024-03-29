#include <iostream>
#include <queue>
using namespace std;
#define MAX 51

int T, M, N, K;
int num = 0;
int visited[MAX][MAX];
int arr[MAX][MAX];
queue<pair<int, int>> q;
int x_dir[4] = { -1,1,0,0 };
int y_dir[4] = { 0,0,-1,1 };

void reset() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
			arr[i][j] = 0;
		}
	}
	num = 0;
}

void BFS(int x, int y) {
	visited[x][y] = 1;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x_new = x + x_dir[i];
			int y_new = y + y_dir[i];
			if ((x_new >= 0 && x_new < M) && (y_new >= 0 && y_new < N) && visited[x_new][y_new] == 0 && arr[x_new][y_new] == 1) {
				visited[x_new][y_new] = 1;
				q.push(make_pair(x_new, y_new));
			}
		}
	}
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		reset();
		int x, y;
		for (int j = 0; j < K; j++) {
			cin >> x >> y;
			arr[x][y] = 1;
		}
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (visited[j][k] == 0 && arr[j][k] == 1) {
					BFS(j, k);
					num++;
				}
			}
		}
		cout << num << endl;
	}
	return 0;
}
