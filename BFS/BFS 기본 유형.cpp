int visited[max_y][max_x];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int n, m;

void bfs(int posy, posx)
{
	queue<pair<int, int>> q;
	q.push({posy, posx});
	visited[posy][posx] = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = dy[i] + cur.first;
			int nx = dx[i] + cur.second;
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || sth_condition() || visited[ny][nx] == 1)
				continue;
			visited[ny][nx] == 1;
			q.push({ny, nx});
			Action();
		}
	}
}