#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstdlib>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//ru ��Ҫ�������ݵı�����ָ�� max �������ֵ min ������Сֵ��Ҫ��������󲻻ᵼ�±��������ٴγ���������ʾ�����践��ֵ
void input(int* ru, int max, int min) {
	while (1) {
		string s;
		cin >> s;
		if (*ru > max || *ru < min) {
			printf("������%d��%d֮�����!\n", min, max);

		}
		else break;
	}
}