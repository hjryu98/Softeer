#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, ans;
vector <pair<int, int>> v;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) return a.second < b.second;
	return a.first > b.first;
}

int main(int argc, char** argv)
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, f;
		cin >> s >> f;
		v.push_back({ s,f });
	}
	sort(v.begin(), v.end(), comp);

	int cur = 0;
	for (int i = 0; i < v.size(); i++) {
		if (cur <= v[i].first) {
			ans++;
			cur = v[i].second;
		}
	}
	cout << ans;


	return 0;
}