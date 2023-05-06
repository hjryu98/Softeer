#include <iostream>
#include <queue>
using namespace std;
struct gem {
	int m, p;
};
struct comp {
	bool operator()(gem a, gem b) {
		return a.p < b.p;
	}
};
int w, n, ans;
priority_queue <gem, vector<gem>, comp> pq;
int main() {
	cin >> w >> n;
	while (n--) {
		int m, p;
		cin >> m >> p;
		pq.push({ m,p });
	}
	while (!pq.empty()) {
		int m = pq.top().m;
		int p = pq.top().p;
		pq.pop();
		if (m >= w) {
			ans += w * p;
			w = 0;
			break;
		}
		else {
			w -= m;
			ans += m * p;
		}
	}
	cout << ans;

	return 0;
}