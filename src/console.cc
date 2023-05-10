#include <sequence/sequence.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace SEQUENCE;
using namespace std;

const char* data1[4] = { "�������� ������� � ������ �� ���������� �������", "������� ������� �� ������ �� ���������� �������", "������� ������ �� �����", "��������� ����� � ������ ��������� ���������� � ������������ ������ ������ n ��������� ��� �������� n"};

int get_key()
{
	int key = _getch();
	if ((key == 0) || (key == 224))
		key = _getch();
	return key;
}

void print_current(int i)
{
	system("cls");
	printf("\n\"%s\"\n", data1[i]);
}

SequencePtr seq()
{
	float first_n=0, d_q=0;
	int type = 0;
	while (type != 1 && type != 2) {
		system("cls");
		cout << "������� ����� (1-��������������, 2-��������������): ";
		cin >> type;
	}
	cout << "������� ������ ���� ����������: ";
	cin >> first_n;
	cout << "������� ���/����������� ����������: ";
	cin >> d_q;
	switch (type) {
	case(1):
		return(Sequence::create_ARITHMETIC(first_n, d_q));
		break;
	case(2):
		return(Sequence::create_GEOMETRIC(first_n, d_q));
		break;
	}
}

int index(int size, bool flag)
{
	system("cls");
	int num;
	cout << "������� ������: ";
	cin >> num;
	while (!(0 <= num && num < size)) {
		if (flag && num == size)
			break;
		system("cls");
		cout << "������� ���������� ������: ";
		cin >> num;
	}
	return num;
}

void out(SequenceList mas)
{
	system("cls");
	for (int i = 0; i < mas.size(); ++i) {
		cout << *mas[i];
	}
	getchar();
}

void search_crit(SequenceList mas)
{
	system("cls");
	int n;
	cout << "������� n: ";
	cin >> n;
	while (n<1) {
		system("cls");
		cout << "������� ���������� n: ";
		cin >> n;
	}
	cout << *mas[search(mas, n)];
	getchar();
	getchar();
}

int menu()
{
	cout<<"\n������: ->\n�����: <-\n��������: Enter\n�����: Ecs";
	while (true)
	{
		int key = get_key();
		if ((key == 27) || (key == 75) || (key == 77) || (key == 13))
			return key;
	}
}

int main()
{
	SequenceList mas;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int current = 0;
	bool b = true;
	system("cls");
	while (b)
	{
		print_current(current);
		switch (menu())
		{
		case 27:
			b = 0;
			break;
		case 75:
			if (current > 0)
				current--;
			break;
		case 77:
			if (current < 3)
				current++;
			break;
		case 13:
		{
			switch (current)
			{
			case 0:
				mas.insert_index(seq(), index(mas.size(), 1));
				out(mas);
				getchar();
				break;
			case 1:
				mas.del_index(index(mas.size(), 0));
				out(mas);
				getchar();
				break;
			case 2:
				out(mas);
				break;
			case 3:
				search_crit(mas);
				break;
			}
		}
			break;
		}
	}
}