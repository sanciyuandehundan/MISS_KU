#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstdlib>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
	int num[9] = { 0 };
	FILE* fpr;
	if ((fpr = fopen("input.txt", "r+")) == NULL)
	{
		printf("the file which  named input.txt cannot be opened��\n");
		exit(1);
	}
	for (int i = 0; i < 9; i++) {
		fscanf(fpr, "%d", &num[i]);
	}
	cout << "���ϴι����˷���ζ��Ƭ:" << num[0]<<endl;
	cout << "���ϴι����˺���ζ��Ƭ:" << num[1] << endl;
	cout << "���ϴι����˱�ʺζ��Ƭ:" << num[2] << endl;
	cout << "���ϴι�����ԭζ�ɿڿ���:" << num[3] << endl;
	cout << "���ϴι��������ζ�ɿڿ���:" << num[4] << endl;
	cout << "���ϴι��������ǰ��¿���:" << num[5] << endl;
	cout << "���ϴι�����ͳһ������:" << num[6] << endl;
	cout << "���ϴι����˰��󷽱���:" << num[7] << endl;
	cout << "���ϴι�������̳��˷�����:" << num[8] << endl;
	fclose(fpr);
	if ((fpr = fopen("input.txt", "w+")) == NULL)
	{
		printf("the file which  named input.txt cannot be opened��\n");
		exit(1);
	}
	system("color F0");
	int price = 0;
	int sw;
	bool bo;
	while (1) {
		printf("\n1.��Ƭ-10\n2.����-4\n3.������-8\n4.�˳�\n������Ҫɶ:");
		bo = false;
		do {
			if (bo)cout << "���뷶Χ��" << 1 << '~' << 4 << "Ŷ~~\n����������:";
			bo = true;
			cin >> sw;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (sw > 4 || sw < 1);
		switch (sw)
		{
		case 1:cout << "��ѡ������Ƭ\n";
			price += 10;
			cout << "1.����\n2.����\n3.�˳�,��ѡ\n��Ҫɶ��ζ:";
			bo = false;
			do {
				if (bo)cout << "���뷶Χ��" << 1 << '~' << 3 << "Ŷ~~\n����������:";
				bo = true;
				cin >> sw;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			} while (sw > 3 || sw < 1);
			switch (sw)
			{
			case 1:cout << "��ѡ���˷���ζ��Ƭ\n"; num[0]++; break;
			case 2:cout << "��ѡ���˺���ζ��Ƭ\n"; num[1]++; break;
			case 3:cout << "��ѡ�ǰ�,����Ա�ʺζ\n"; num[2]++; break;
			default:
				break;
			}
			break;
		case 2:cout << "��ѡ���˿���\n";
			price += 4;
			cout << "1.�ɿڿ���\n2.���ζ�ɿڿ���\n3.�˳�,��ѡ\n��Ҫɶ:";
			bo = false;
			do {
				if (bo)cout << "���뷶Χ��" << 1 << '~' << 3 << "Ŷ~~\n����������:";
				bo = true;
				cin >> sw;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			} while (sw > 3 || sw < 1);
			switch (sw)
			{
			case 1:cout << "��ѡ����ԭζ�ɿڿ���\n"; num[3]++; break;
			case 2:cout << "��ѡ�������ζ�ɿڿ���\n"; num[4]++; break;
			case 3:cout << "��ѡ�ǰ�,��������ǰ��¿���\n"; num[5]++; break;
			default:
				break;
			}break;
		case 3:cout << "��ѡ���˷�����\n";
			price += 8;
			cout << "1.ͳһ\n2.����\n3.�˳�,��ѡ\n��Ҫɶ���ӵ�:";
			bo = false;
			do {
				if (bo)cout << "���뷶Χ��" << 1 << '~' << 3 << "Ŷ~~\n����������:";
				bo = true;
				cin >> sw;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			} while (sw > 3 || sw < 1);
			switch (sw)
			{
			case 1:cout << "��ѡ����ͳһ������\n"; num[6]++; break;
			case 2:cout << "��ѡ���˰��󷽱���\n"; num[7]++; break;
			case 3:cout << "��ѡ�ǰ�,�������̳���\n"; num[8]++; break;
			default:
				break;
			}
			break;
		case 4:cout << "��ѡ�����˳�\n";
			cout << "��һ��������:" << price << endl;
			for (int i = 0; i < 9; i++)fprintf(fpr, "%d ", num[i]);
			return 0;
		default:
			break;
		}
	}

	fclose(fpr);
}