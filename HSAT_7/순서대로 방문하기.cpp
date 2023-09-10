#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, ans;
int arr[6][6];
bool check[6][6];
bool togo[6][6]; //가야하는 좌표
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector <pair<int, int>> point;

bool range(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

void recur(pair<int, int> cur, int cnt) { //지금 까지 지나간 점 개수 : cnt
	int x = cur.first;
	int y = cur.second;
	check[x][y] = true;
	int ret = cnt;

	if (togo[x][y]) {
		if (x == point[ret].first && y == point[ret].second) {
			ret++;
			if (ret == point.size()) {
				ans++;
				return;
			}
		}
		else return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!range(nx, ny)) continue;

		if (arr[nx][ny] == 1) continue;

		if (check[nx][ny]) continue;

		recur({ nx,ny }, ret);
		check[nx][ny] = false;
	}
}


int main(int argc, char** argv)
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> arr[i][j];
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		point.push_back({ a,b });
		togo[a][b] = true;
	}

	recur(point[0], 0);

	cout << ans;

	return 0;
}