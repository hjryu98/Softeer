#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string arr[30];
bool check[30][30];
int n;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector <int> ans;
bool range(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < n;
}

int dfs(int x, int y) {
	int cnt = 1;
	check[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!range(nx, ny)) continue;
		if (check[nx][ny]) continue;
		if (arr[nx][ny] == '1') cnt += dfs(nx, ny);
	}
	return cnt;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j] && arr[i][j] == '1') ans.push_back(dfs(i, j));
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";

	return 0;
}