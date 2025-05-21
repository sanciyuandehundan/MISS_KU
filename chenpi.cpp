#include "including.h"
#include "xiahui.h"
#include "chenpi.h"
#include "sanciyuandehundan.h"
#include <io.h>
#include <fcntl.h>

void Top(const char* c) {
    cout << COLOR_TITLE;
    cout << "�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T" << endl;
    cout << "  " << c << "  " << endl;
    cout << "�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T" << endl;
    cout << COLOR_RESET;
}

void Introduce_main(Log* s) {
    system("cls");
    Top("����ɼ�ͳ�������ϵͳ");
    cout << COLOR_MENU;
    cout << "������������������������������������������������������������" << endl;
    cout << "��     " << COLOR_OPTION << "1. �ֶ�����ɼ�" << COLOR_MENU << "        ��" << endl;
    cout << "��     " << COLOR_OPTION << "2. ����ɼ��ļ�" << COLOR_MENU << "        ��" << endl;
    cout << "��     " << COLOR_OPTION << "3. �����ɼ��ļ�" << COLOR_MENU << "        ��" << endl;
    cout << "��     " << COLOR_OPTION << "4. �鿴�����ɼ�" << COLOR_MENU << "        ��" << endl;
    cout << "��     " << COLOR_OPTION << "5. �޸ĳɼ�����" << COLOR_MENU << "        ��" << endl;
    cout << "��     " << COLOR_OPTION << "6. ɾ�������ɼ�" << COLOR_MENU << "        ��" << endl;
    cout << "��     " << COLOR_OPTION << "7. �˳�����    " << COLOR_MENU << "        ��" << endl;
    cout << "������������������������������������������������������������" << endl;
}

void Introduce_input(Log* s) {
    system("cls");
    Top("�ֶ���������");
    cout << COLOR_MENU;
    cout << "������������������������������������������������������������" << endl;
    cout << "��    " << COLOR_OPTION << "1. �޸���������" << COLOR_MENU << "         ��" << endl;
    cout << "��    " << COLOR_OPTION << "2. ���������" << COLOR_MENU << "           ��" << endl;
    cout << "��    " << COLOR_OPTION << "3. �������˵�" << COLOR_MENU << "           ��" << endl;
    cout << "������������������������������������������������������������" << endl;
}

void Introduce_import(Log* s) {
    system("cls");
    Top("����ɼ��ļ�");
    cout << COLOR_MENU;
    cout << "����������������������������������������������������������������" << endl;
    cout << " ������չ��Ϊ .json ���ļ�·�� (����·��)\n\n";
    cout << " * �������ɼ������������гɼ���������ͬ\n";
    cout << "   ��ֱ�ӽ��ļ��ڳɼ���������гɼ�\n";
    cout << " * �������ɼ��Ĺ����������гɼ������߲�ͬ\n";
    cout << "   ���гɼ��ļ����Զ����浼��,�����ó���������\n";
    cout << "����������������������������������������������������������������" << endl;
    s->Show();
    cout << "������������������������������������������������������������" << endl;
    cout << "��   " << COLOR_OPTION << "1. ��ʼ����" << COLOR_MENU << "              ��" << endl;
    cout << "��   " << COLOR_OPTION << "2. �������˵�" << COLOR_MENU << "            ��" << endl;
    cout << "������������������������������������������������������������" << endl;
}

void Introduce_export(Log* s) {
    system("cls");
    Top("�����ɼ��ļ�");
    s->Show();
    cout << COLOR_MENU;
    cout << "������������������������������������������������������������" << endl;
    cout << "��      " << COLOR_OPTION << "1. ��ʼ����" << COLOR_MENU << "           ��" << endl;
    cout << "��      " << COLOR_OPTION << "2. �������˵�" << COLOR_MENU << "         ��" << endl;
    cout << "������������������������������������������������������������" << endl;
}

void Introduce_delete(Log* s)
{
    system("cls");
    Top("ɾ�������ɼ�");
    cout << COLOR_MENU;
    cout << "������������������������������������������������������������������������������" << endl;
    cout << "��   " << COLOR_OPTION << "0.�鿴ȫ����ѡ��ָ����ųɼ�ɾ��" << COLOR_MENU << "  ��" << endl;
    cout << "��   " << COLOR_OPTION << "1.ȫ��ɾ��" << COLOR_MENU << "                        ��" << endl;
    cout << "��   " << COLOR_OPTION << "2.�������˵�" << COLOR_MENU << "                      ��" << endl;
    cout << "������������������������������������������������������������������������������" << endl;
}

void Introduce_view(Log* s) {
    system("cls");
    Top("�鿴�����ɼ�");
    s->Show();
    cout << COLOR_MENU;
    cout << "����������������������������������������������������������������" << endl;
    cout << COLOR_OPTION << "��������������˵�..." << COLOR_RESET;
    system("pause > nul");
}

void Introduce_scoremaster(Log* s) {
    system("cls");
    Top("�޸ĳɼ�����");
    cout << COLOR_MENU;
    cout << "������������������������������������������������������������" << endl;
    cout << "�� " << COLOR_OPTION << "1. �޸ĸ÷ݳɼ��Ĺ�����" << COLOR_MENU << "    ��" << endl;
    cout << "�� " << COLOR_OPTION << "2. ��ʼ��¼��һ���˵ĳɼ�" << COLOR_MENU << "  ��" << endl;
    cout << "�� " << COLOR_OPTION << "   (��ǰ�ɼ������Զ�����)" << COLOR_MENU << "  ��" << endl;
    cout << "�� " << COLOR_OPTION << "3. �������˵�" << COLOR_MENU << "              ��" << endl;
    cout << "������������������������������������������������������������" << endl;
}

void rectangle_one_row(string s)
{
    cout << COLOR_TITLE;
    size_t length = s.length();  // �����ֽ�����ȡ���ڱ��룩
    cout << "�X";
    for (int i = 0; i < length; i++) {
        cout << "�T" ;
    }
    cout << "�[" << endl;
    cout<<"�U" << s << "�U" << endl; 
    cout << "�^" ;
    for (int i = 0; i < length; i++) {
        cout << "�T" ;
    }
    cout << "�a" << endl;
}

void output(string s)
{
    int length = 0;
    int max = 0;
    cout << COLOR_TITLE;
    for (char c : s) {
        if (c != '\n') length++;
        else {
            if (length > max) max = length;
            length = 0;
        }
    }
    cout << "�X";
    for (int i = 0; i < max; i++) {
        cout << "�T";
    }
    cout << "�[" << endl;
    cout << "�U";
    for (long long i = 0; i < s.length();i++) {
        if (s[i] != '\n') {
            cout << s[i];
        }
        else {
            cout << "�U" << endl;
            if (s[i + 1] != '\0') cout << "�U";
        }
    }
    cout << "�^";
    for (int i = 0; i < max; i++) {
        cout << "�T";
    }
    cout << "�a" << endl;
}
