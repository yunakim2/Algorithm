#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN	21

int a[MAXN][MAXN];
int b[MAXN][MAXN];
int n;
int total;

int solve(int x, int y, int d1, int d2) {
	memset(b, 0, sizeof(b));
	b[x][y] = 5;
	//5번 선거구의 경계선 구하기
	//1
	for (int i = 1; i <= d1; ++i) {
		b[x + i][y - i] = 5;
	}
	//2
	for (int i = 1; i <= d2; ++i) {
		b[x + i][y + i] = 5;
	}
	//3
	for (int i = 1; i <= d2; ++i) {
		b[x + d1 + i][y - d1 + i] = 5;
	}
	//4
	for (int i = 1; i <= d1; ++i) {
		b[x + d2 + i][y + d2 - i] = 5;
	}

	//각 선거구의 인구수 구하기
	int mmin = total, mmax = 0;
	int sum = 0;
	int t = total;

	//1
	for (int i = 1; i < x + d1; ++i) {
		for (int j = 1; j <= y; ++j) {
			if (b[i][j] == 5) break;
			sum += a[i][j];
			t -= a[i][j];
		}
	}
	mmin = std::min(mmin, sum);
	mmax = std::max(mmax, sum);
	sum = 0;
	//2
	for (int i = 1; i <= x + d2; ++i) {
		for (int j = n; j > y; --j) {
			if (b[i][j] == 5) break;
			sum += a[i][j];
			t -= a[i][j];
		}
	}
	mmin = std::min(mmin, sum);
	mmax = std::max(mmax, sum);
	sum = 0;
	//3
	for (int i = x + d1; i <= n; ++i) {
		for (int j = 1; j < y - d1 + d2; ++j) {
			if (b[i][j] == 5) break;
			sum += a[i][j];
			t -= a[i][j];
		}
	}
	mmin = std::min(mmin, sum);
	mmax = std::max(mmax, sum);
	sum = 0;
	//4
	for (int i = x + d2+1; i <= n; ++i) {
		for (int j = n; j >= y - d1 + d2; --j) {
			if (b[i][j] == 5) break;
			sum += a[i][j];
			t -= a[i][j];
		}
	}

	mmin = std::min({ mmin, sum,t });
	mmax = std::max({ mmax, sum,t });

	return mmax - mmin;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &a[i][j]);
			total += a[i][j];
		}
	}

	//solution
	int ans = total;
	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= n; ++y) {
			for (int d1 = 1; d1 < n; ++d1) {
				for (int d2 = 1; d2 < n; ++d2) {
					if (x + d1 + d2 <= n && 1 <= y - d1 && y + d2 <= n) {
						ans = std::min(ans, solve(x, y, d1, d2));
					}
				}
			}
		}
	}
	printf("%d", ans);

	return 0;
}