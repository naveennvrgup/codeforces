#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> ans[3];
int a[100][100];

void flip(int i, int j, int id) {
	if (id >= 0) ans[id].emplace_back(i+1, j+1);
	a[i][j] ^= 1;
}

void solve() {
	int n, m; cin >> n >> m;
	ans[0].clear();
	ans[1].clear();
	ans[2].clear();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			a[i][j] = c - '0';
		}
	}

	for (int i = n-1; i >= 2; i--) {
		for (int j = m-1; j >= 0; j--) {
			if (a[i][j] == 1) {
				// i j, i-1 j, i-1 j-1
				if (j > 0) {
					flip(i, j, 0);
					flip(i-1, j, 1);
					flip(i-1, j-1, 2);
				} else {
					flip(i, j, 0);
					flip(i-1, j, 1);
					flip(i-1, j+1, 2);
				}
			}
		}
	}

	for (int j = m-1; j >= 2; j--) {
		for (int i = 0; i < 2; i++) {
			if (a[i][j] == 1) {
				flip(i, j, 0);
				flip(i, j-1, 1);
				flip(i^1, j-1, 2);
			}
		}
	}

	for (int msk = 0; msk < (1 << 4); msk++) {
		// flip all
		int gg = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (msk & (1 << gg)) {
					flip(i, j, -1);
					flip(i^1, j, -1);
					flip(i, j^1, -1);
				}
				gg++;
			}
		}

		// is feasible
		bool is_feasible = 1;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (a[i][j]) is_feasible = 0;
			}
		}

		// flip back
		gg = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (msk & (1 << gg)) {
					flip(i, j, -1);
					flip(i^1, j, -1);
					flip(i, j^1, -1);
				}
				gg++;
			}
		}

		if (is_feasible) {
			// output
			gg = 0;
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					if (msk & (1 << gg)) {
						flip(i, j, 0);
						flip(i^1, j, 1);
						flip(i, j^1, 2);
					}
					gg++;
				}
			}
			break;
		}
	}

	cout << ans[0].size() << '\n';
	for (int i = 0; i < ans[0].size(); i++) {
		for (int j = 0; j < 3; j++) {
			cout << ans[j][i].first << ' ' << ans[j][i].second << ' ';
		}
		cout << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
