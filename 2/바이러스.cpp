#define mod 1000000007
#include<iostream>
using ll = long long;
using namespace std;
ll k, p, n;
int main(int argc, char** argv)
{
	cin >> k >> p >> n;

	while (n--) {
		k = k * p % mod;
	}
	cout << k;

	return 0;
}