// 1983. 조교의 성적 매기기 D2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

//정렬 쓰고싶으면, vector를 써야되!
//두번째 사람은 인덱스 1임 , 정렬되기전에 자신의 순서를 기억할 필요가 있다!
//배수를 고려해야함.
// 점수 계산에서 논리적 오류 발생 0.35 -> 0.45 ㅠ_ㅠ..

int arr[100][3];
vector<pair<double, int>> total;
// midterm finalterm report

string GPA[10] = { "A+","A0","A-","B+","B0","B-","C+","C0","C-","D0" };

int n, k;

int main()
{
	int t;
	cin >> t;
	int num = 1;
	while (t--) {

		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
			total.push_back(make_pair((float)arr[i][0] * 0.35 + (float)arr[i][1] * 0.45 + (float)arr[i][2] * 0.2, i));
		}

		sort(total.begin(), total.end());
		reverse(total.begin(), total.end());

		/*for (int i = 0; i < n; i++) {
		cout << total[i].first << ' ' << total[i].second << endl;
		}
		cout << endl;*/

		for (int i = 0; i < n; i++) {

			if (k - 1 == total[i].second) {
				cout << '#' << num++ << ' ' << GPA[(int)floor((double)(i) / (double)(n / 10))] << '\n';
				// cout << "total[i] : " << total[i].first << endl;
			}

		}

		total.clear();
		for (int i = 0; i < n; i++) {
			memset(arr[i], 0, sizeof(arr[i]));
		}


	}

	return 0;
}

