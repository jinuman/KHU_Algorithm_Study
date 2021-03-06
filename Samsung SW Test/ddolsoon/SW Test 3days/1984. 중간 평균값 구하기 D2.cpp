// 1984. 중간 평균값 구하기 D2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a > b ? b : a;
}

int arr[10];

int main()
{
	int t;
	int num = 1;
	cin >> t;
	while (t--) {


		memset(arr, 0, sizeof(arr));
		double ans = 0;
		for (int i = 0; i < 10; i++) {
			cin >> arr[i];
			ans += arr[i];
		}

		//최대 / 최소 계산
		int max_val = arr[0];
		int min_val = arr[0];
		for (int i = 1; i < 10; i++) {
			
			max_val = max(max_val, arr[i]);
			min_val = min(min_val, arr[i]);
		}

		ans -= max_val;
		ans -= min_val;

		cout << '#' << num++ << ' ' << fixed << setprecision(0) << ans/(double)8 << '\n';;
	}


    return 0;
}

