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
		printf("the file which  named input.txt cannot be opened！\n");
		exit(1);
	}
	for (int i = 0; i < 9; i++) {
		fscanf(fpr, "%d", &num[i]);
	}
	cout << "你上次购买了番茄味薯片:" << num[0]<<endl;
	cout << "你上次购买了海盐味薯片:" << num[1] << endl;
	cout << "你上次购买了鼻屎味薯片:" << num[2] << endl;
	cout << "你上次购买了原味可口可乐:" << num[3] << endl;
	cout << "你上次购买了香草味可口可乐:" << num[4] << endl;
	cout << "你上次购买了无糖百事可乐:" << num[5] << endl;
	cout << "你上次购买了统一方便面:" << num[6] << endl;
	cout << "你上次购买了白象方便面:" << num[7] << endl;
	cout << "你上次购买了老坛酸菜方便面:" << num[8] << endl;
	fclose(fpr);
	if ((fpr = fopen("input.txt", "w+")) == NULL)
	{
		printf("the file which  named input.txt cannot be opened！\n");
		exit(1);
	}
	system("color F0");
	int price = 0;
	int sw;
	bool bo;
	while (1) {
		printf("\n1.薯片-10\n2.可乐-4\n3.方便面-8\n4.退出\n输入你要啥:");
		bo = false;
		do {
			if (bo)cout << "输入范围是" << 1 << '~' << 4 << "哦~~\n请重新输入:";
			bo = true;
			cin >> sw;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (sw > 4 || sw < 1);
		switch (sw)
		{
		case 1:cout << "你选择了薯片\n";
			price += 10;
			cout << "1.番茄\n2.海盐\n3.退出,不选\n你要啥口味:";
			bo = false;
			do {
				if (bo)cout << "输入范围是" << 1 << '~' << 3 << "哦~~\n请重新输入:";
				bo = true;
				cin >> sw;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			} while (sw > 3 || sw < 1);
			switch (sw)
			{
			case 1:cout << "你选择了番茄味薯片\n"; num[0]++; break;
			case 2:cout << "你选择了海盐味薯片\n"; num[1]++; break;
			case 3:cout << "不选是吧,罚你吃鼻屎味\n"; num[2]++; break;
			default:
				break;
			}
			break;
		case 2:cout << "你选择了可乐\n";
			price += 4;
			cout << "1.可口可乐\n2.香草味可口可乐\n3.退出,不选\n你要啥:";
			bo = false;
			do {
				if (bo)cout << "输入范围是" << 1 << '~' << 3 << "哦~~\n请重新输入:";
				bo = true;
				cin >> sw;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			} while (sw > 3 || sw < 1);
			switch (sw)
			{
			case 1:cout << "你选择了原味可口可乐\n"; num[3]++; break;
			case 2:cout << "你选择了香草味可口可乐\n"; num[4]++; break;
			case 3:cout << "不选是吧,罚你喝无糖百事可乐\n"; num[5]++; break;
			default:
				break;
			}break;
		case 3:cout << "你选择了方便面\n";
			price += 8;
			cout << "1.统一\n2.白象\n3.退出,不选\n你要啥牌子的:";
			bo = false;
			do {
				if (bo)cout << "输入范围是" << 1 << '~' << 3 << "哦~~\n请重新输入:";
				bo = true;
				cin >> sw;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			} while (sw > 3 || sw < 1);
			switch (sw)
			{
			case 1:cout << "你选择了统一方便面\n"; num[6]++; break;
			case 2:cout << "你选择了白象方便面\n"; num[7]++; break;
			case 3:cout << "不选是吧,罚你吃老坛酸菜\n"; num[8]++; break;
			default:
				break;
			}
			break;
		case 4:cout << "你选择了退出\n";
			cout << "你一共消费了:" << price << endl;
			for (int i = 0; i < 9; i++)fprintf(fpr, "%d ", num[i]);
			return 0;
		default:
			break;
		}
	}

	fclose(fpr);
}