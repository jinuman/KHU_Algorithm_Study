// RGB거리(1149번 문제).cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int d[1001][3];
int a[1001][3];

int min(int x, int y) {
	return (x < y) ? x : y;
}

int main()
{
	ios_base::sync_with_stdio(false);

	//입력
	long long ans = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}

	//DP 계산
	d[1][0] = a[1][0];
	d[1][1] = a[1][1];
	d[1][2] = a[1][2];
	ans = min(d[1][0], min(d[1][1], d[1][2]));

	for (int i = 2; i <= n; i++)
	{
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + a[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + a[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + a[i][2];

		ans = min(d[i][0], min(d[i][1], d[i][2]));
	}


	//정답 출력
	cout << ans << endl;
	return 0;
}

