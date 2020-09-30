#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	if (n % 2 == 0) {
		if (n != 2) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}