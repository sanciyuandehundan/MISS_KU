#include "including.h"


void Top(const char* c)
{
	cout << "������������" << c << "������������" << endl;
}

void Introduce_main(Score* s) {
	system("cls");
	Top("����ɼ�ͳ�������ϵͳ");
	cout << "1.�ֶ�����ɼ�" << endl;
	cout << "2.����ɼ��ļ�" << endl;
	cout << "3.�����ɼ��ļ�" << endl;
	cout << "4.�鿴�����ɼ�" << endl;
	cout << "5.�޸ĳɼ�����" << endl;
	cout << "Ҫ���к��ֲ���:";
}

void Introduce_input(Score* s)
{
	system("cls");
	Top("�ֶ���������");
	cout << "1.�趨��������" << endl;
	cout << "2.�趨����" << endl;
	cout << "3.�趨����" << endl;
	cout << "4.�趨ÿ�ּ���" << endl;
	cout << "5.��ʼ����" << endl;
	cout << "6.����" << endl;
	cout << "Ҫ���к��ֲ���:";
}

void Introduce_import(Score* s)
{
	system("cls");
	Top("����ɼ��ļ�");
	cout << "������չ��Ϊ.json���ļ����ļ�·��(����·��)\n�������ɼ������������гɼ���������ͬ��ֱ�ӽ��ļ��ڳɼ���������гɼ�\n�������ɼ��Ĺ����������гɼ������߲�ͬ,���гɼ��ļ����Զ����浼��,�����ó���������" << endl;
	s->Show();
	cout << "1.��ʼ����" << endl;
	cout << "2.����" << endl;
	cout << "Ҫ���к��ֲ���:";
}

void Introduce_export(Score* s)
{
	system("cls");
	Top("�����ɼ��ļ�");
	s->Show();
	cout << "1.��ʼ����" << endl;
	cout << "2.����" << endl;
	cout << "Ҫ���к��ֲ���:";
}

void Introduce_view(Score* s)
{
	system("cls");
	Top("�鿴�����ɼ�");
	s->Show();
	system("pause");
}

void Introduce_scoremaster(Score* s)
{
	system("cls");
	Top("�޸ĳɼ�����");
	cout << "1.�޸ĸ÷ݳɼ��Ĺ�����" << endl;
	cout << "2.��ʼ��¼��һ���˵ĳɼ�,��ǰ�ɼ������Զ�����" << endl;
	cout << "3.����" << endl;
	cout << "Ҫ���к��ֲ���:";
}
