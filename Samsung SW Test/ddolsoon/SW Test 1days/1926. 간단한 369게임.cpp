// 1926. 간단한 369게임.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

bool check_clip(int num) {
	
	string clip_number = to_string(num);
	for (int i = 0; i < clip_number.length(); i++) {
		if ((clip_number[i] -'0') % 3 == 0 && (clip_number[i] -'0') != 0) {
			return true;
		}
	}

	return false;
}

string clip(int num) {

	string clip_number = to_string(num);
	string result = "";
	for (int i = 0; i < clip_number.length(); i++) {
		if ((clip_number[i] -'0') % 3 == 0 && (clip_number[i] -'0') != 0) {
			result += '-';
		}
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if ((int)check_clip(i)) {
			cout << clip(i) << ' ';
			continue;
		}

		cout << i << ' ';
	}

	cout << '\n';

    return 0;
}

