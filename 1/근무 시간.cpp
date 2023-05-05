#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	int cnt = 10;
	int ans = 0;
	int fh, rh, fm, rm;
	for (int i = 1; i <= cnt; i++) {
		int cur = 0;
		string st;
		cin >> st;
		if (i % 2 != 0) {
			fh = stoi(st.substr(0, 2));
			fm = stoi(st.substr(3, 2));
		}
		else {
			rh = stoi(st.substr(0, 2));
			rm = stoi(st.substr(3, 2));
			cur += (rh - fh) * 60;
			rm -= fm;
			cur += rm;
			ans += cur;
		}
	}

	cout << ans;
	return 0;
}