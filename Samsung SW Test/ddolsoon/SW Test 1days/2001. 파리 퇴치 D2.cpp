// 2001. 파리 퇴치 D2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

int arr[15][15];

int n, m;

int sum_fly(int i, int j) {

	int sum = 0;
	for (int r = i; r < i + m; r++) {
		for (int k = j; k < j + m; k++) {
			sum += arr[r][k];
		}
	}

	return sum;
}

int main()
{

	int t;
	cin >> t;
	int num = 1;

	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		//초기값
		int sum = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				sum += arr[i][j];
			}
		}

		for (int i = 0; i <= n - m; i++) {
			for (int j = 0; j <= n - m; j++) {

				if (sum < sum_fly(i, j)) {
					sum = sum_fly(i, j);
				}
			}
		}

		cout << '#' << num++ << ' ' << sum << '\n';
	}

	return 0;
}

