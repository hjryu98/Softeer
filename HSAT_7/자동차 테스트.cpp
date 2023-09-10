#include<iostream>
#include <algorithm>
using namespace std;
int n, q, arr[50005];
int main(int argc, char** argv)
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + 1 + n);
	while (q--) {
		int a;
		cin >> a;

		int s = 1;
		int e = n + 1;
		int idx = -1;

		while (s + 1 < e) {
			int mid = (s + e) / 2;
			if (arr[mid] > a) e = mid;
			else if (arr[mid] < a) s = mid;
			else {
				idx = mid;
				break;
			}
		}
		if (idx == -1) cout << 0 << "\n";
		else cout << (idx - 1) * (n - idx) << "\n";

	}
	return 0;
}