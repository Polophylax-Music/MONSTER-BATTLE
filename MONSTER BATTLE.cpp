#include <iostream>
#include <map>
#include <time.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <stdio.h>
using namespace std;

// �l�̃N���X
class monster {
public:
	int hp1;
	int attack1;
	monster(int hp, int attack);
	monster();
	void substitutiondata(int* hp, int* attack);
};

monster::monster(int hp, int attack)
{
	hp1 = hp;
	attack1 = attack;
}

monster::monster()
{
	hp1 = 0;
	attack1 = 0;
}

// �����o�ϐ��̒l�̑��
void monster::substitutiondata(int* hp, int* attack)
{
	*hp = hp1;
	*attack = attack1;
	return;
}

int main()
{
	map<string, monster> m;
	int k = 0, i, r, r2, hp, attack, c;
	char bravename[80];
	int bravehp = 1000;
	int bravemp = 500;


	m.insert(pair<string, monster>("�h���S��", monster(1000, 600)));
	m.insert(pair<string, monster>("�O���t�H��", monster(600, 400)));
	m.insert(pair<string, monster>("�P���x���X", monster(300, 300)));
	m.insert(pair<string, monster>("�~�m�^�E���X", monster(300, 200)));
	m.insert(pair<string, monster>("�]���r", monster(50, 50)));

	cout << "���O����͂��Ă��������B�F";
	cin >> bravename;

	cout << "���̃Q�[���͏o�Ă��郂���X�^�[���ǂꂾ���̐���|���邩�Ƃ����Q�[���ł��B" << "\n";
	getchar();
	cout << "�G��|������ɁA�܂������邩�A������߂邩�I�����邱�Ƃ��ł��܂��B" << "\n";
	getchar();
	cout << "������HP���[���ɂȂ�΋L�^�͎c��܂���B" << "\n";
	getchar();
	cout << "�I���͔��p�����ōs���Ă��������B" << "\n";
	getchar();
	cout << "�퓬���̑I�����̐���\n���������F�G���U�����܂��B���̌�A�G����̍U�����󂯂܂��B" << "\n";
	getchar();
	cout << "�q�[���FMP��20����āA������HP��S�������܂��B" << "\n";
	getchar();
	cout << "�T���_�[�FMP��50����ēG�ɑ�_���[�W��^���܂��B���̌�A�G����U�����󂯂܂��B" << "\n";
	getchar();
	cout << "����ł́A�Q�[�����n�߂܂��傤�B" << "\n";
	getchar();


	while (1) {
		map<string, monster>::iterator p;
		srand((unsigned)time(NULL));
		r = rand() % 5;
		p = m.begin();
		for (i = 0; i < r; i++)
			p++;

		p->second.substitutiondata(&hp, &attack);

		cout << p->first << "�������ꂽ�B" << "\n";
		while (1) {
			srand((unsigned)time(NULL));
			r = rand() % 200;
			cout << "--------------------------------------------------------------" << "\n\n";
			cout << bravename << "�@HP�F" << bravehp << "�@MP�F" << bravemp << "\n\n";
			cout << "--------------------------------------------------------------" << "\n\n";
			cout << "�ǂ�����H" << "\n";
			while (1) {
				c = 0;
				cout << "���������F�P�@�q�[���F�Q�@�T���_�[�F�R" << "\n";
				cin >> c;
				if (c == 1) {
					break;
				}
				else if (c == 2) {
					if (bravemp >= 20) {
						cout << bravename << "��HP��" << 1000 << "�ɉ񕜂����B" << "\n";
						bravehp = 1000;
						bravemp = bravemp - 20;
						cout << "--------------------------------------------------------------" << "\n\n";
						cout << bravename << "�@HP�F" << bravehp << "�@MP�F" << bravemp << "\n\n";
						cout << "--------------------------------------------------------------" << "\n\n";
					}
					else
						cout << "MP������Ȃ��B" << "\n";
				}
				else if (c == 3) {
					if (bravemp >= 50) {
						cout << p->first << "�ɗ����~�蒍���I" << "\n";
						srand((unsigned)time(NULL));
						r = rand() % 1000;
						r2 = 0;
						bravemp = bravemp - 50;
						break;
					}
					else
						cout << "MP������Ȃ��B" << "\n";
				}
			}
			cout << p->first << "�ɁA" << r << "�_���[�W��^�����B" << "\n";
			hp = hp - r;
			if (hp <= 0)
				break;
			getchar();

			cout << p->first << "�̍U���I" << "\n";
			srand((unsigned)time(NULL));
			r2 = rand() % attack;
			getchar();


			cout << bravename << "�́A" << r2 << "�_���[�W���󂯂��B" << "\n";
			bravehp = bravehp - r2;
			if (bravehp <= 0) {
				bravehp = 0;
				cout << "--------------------------------------------------------------" << "\n\n";
				cout << bravename << "�@HP�F" << bravehp << "�@MP�F" << bravemp << "\n\n";
				cout << "--------------------------------------------------------------" << "\n\n";
				cout << "GAME OVER" << "\n";
				getchar();
				cout << bravename << "�́A�͐s���Ă��܂����B" << "\n";
				getchar();
				cout << "�I������F�P" << "\n";

				while (1) {
					c = 0;
					cin >> c;
					if (c == 1)
						break;
				}
				return 0;
			}
			getchar();
		}

		cout << p->first << "��|�����I" << "\n";
		k++;
		getchar();

		cout << "--------------------------------------------------------------" << "\n\n";
		cout << bravename << "�@HP�F" << bravehp << "�@MP�F" << bravemp << "\n\n";
		cout << "--------------------------------------------------------------" << "\n\n";
		cout << "������F�P�@������߂�F�Q" << "\n";
		cin >> c;
		if (c == 2)
			break;
	}

	cout << "����A�|���������X�^�[�̐��F" << k << "\n";
	getchar();
	cout << "�I������F�P" << "\n";

	while (1) {
		c = 0;
		cin >> c;
		if (c == 1)
			break;
	}
	return 0;
}