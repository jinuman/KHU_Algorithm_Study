// 암복호화_문제.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

string encrpytion(string key,int roateCount,string plainText);
string decrpytion(string key, int roateCount, string plainText);


void Lrotate(string& plaintText);
void Rrotate(string& plaintText);

string encrpytion(string key, int rotateCount, string plainText)
{
	string result;

	
	for (int i = 0; i < key.size(); i++) {

		//알파벳도 회전 적용 필요
		if(plainText[i] + (key[i] -'a') > 'z')
			result += plainText[i] + (key[i] - 'a') - 26;
		else
			result += plainText[i] + (key[i] - 'a');
		
		//cout << (plainText[i] + key[i] - 'a') << endl;
	}
	
	//cout << result << endl;

	if (rotateCount > 0) {
		for (int i = 0; i < rotateCount; i++)
			Lrotate(result);
	}
	else {
		for (int i = 0; i < abs(rotateCount); i++)
			Rrotate(result);
	}

	return result;
}

string decrpytion(string key, int rotateCount, string plainText)
{
	string result = "";
	rotateCount = -rotateCount;	//복호화는 역순으로..

	if (rotateCount > 0) {
		for (int i = 0; i < rotateCount; i++)
			Lrotate(plainText);
	}
	else {
		for (int i = 0; i < abs(rotateCount); i++)
			Rrotate(plainText);
		
	}

	//cout << plainText << endl;

	for (int i = 0; i < key.size(); i++) {

		//알파벳도 회전 적용 필요
		if (plainText[i] - (key[i] - 'a') < 'a')
			result += plainText[i] - (key[i] - 'a') + 26;
		else
			result += plainText[i] - (key[i] - 'a');

		//cout << (plainText[i] + key[i] - 'a') << endl;
		//cout << result << endl;
	}

	return result;
}

void Lrotate(string& plaintText)
{
	char temp = plaintText[0];

	for (int i = 1; i < plaintText.size(); i++) {
		plaintText[i - 1] = plaintText[i];
	}

	plaintText[plaintText.size() - 1] = temp;

}

void Rrotate(string& plaintText)
{
	char temp = plaintText[plaintText.size() - 1];

	//주의!
	for (int i = plaintText.size() - 1; i >= 0; i--) {
		plaintText[i + 1] = plaintText[i];
	}

	plaintText[0] = temp;

}

int main()
{
	string command;
	string key;
	int rotateCount;
	string plainText;

	string result;

	// input case
	// encrypt secretword 3 helloworld
	// decrypt secretword 3 cspkfcgzin

	cin >> command >> key >> rotateCount >> plainText;
	if (command == "encrypt")
	{
		result = encrpytion(key, rotateCount, plainText);
	}
	else if (command == "decrypt")
	{
		result = decrpytion(key, rotateCount, plainText);
	}
	else 
	{
		result = "잘못된 결과입니다..";
	}

	cout << result << endl;

    return 0;
}

