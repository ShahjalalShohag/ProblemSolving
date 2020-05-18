#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

double dist(double x1, double y1, double z1, double x2, double y2, double z2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2); 
}
int x[N], y[N], z[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	double X = 0, Y = 0, Z = 0;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> z[i];
		X += x[i]; Y +=y[i]; Z += z[i];
	}
	X /= n; Y /= n; Z /= n;
	double ratio = 1.0;
	int it = 100000;
	while (it--) {
		int id = 0;
		for (int i = 1; i < n; i++) {
			if (dist(X, Y, Z, x[i], y[i], z[i]) > dist(X, Y, Z, x[id], y[id], z[id])) id = i;
		}
		X = X + (x[id] - X) * ratio; 
		Y = Y + (y[id] - Y) * ratio; 
		Z = Z + (z[id] - Z) * ratio; 
		ratio *= 0.998;
	}
	cout << fixed << setprecision(10) << X << ' ' << Y << ' ' << Z << '\n';
    return 0;
}