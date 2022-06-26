#include <iostream>
#include <map>
#include <time.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <stdio.h>
using namespace std;

// 値のクラス
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

// メンバ変数の値の代入
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


	m.insert(pair<string, monster>("ドラゴン", monster(1000, 600)));
	m.insert(pair<string, monster>("グリフォン", monster(600, 400)));
	m.insert(pair<string, monster>("ケルベロス", monster(300, 300)));
	m.insert(pair<string, monster>("ミノタウロス", monster(300, 200)));
	m.insert(pair<string, monster>("ゾンビ", monster(50, 50)));

	cout << "名前を入力してください。：";
	cin >> bravename;

	cout << "このゲームは出てくるモンスターをどれだけの数を倒せるかというゲームです。" << "\n";
	getchar();
	cout << "敵を倒した後に、まだ続けるか、あきらめるか選択することができます。" << "\n";
	getchar();
	cout << "自分のHPがゼロになれば記録は残りません。" << "\n";
	getchar();
	cout << "選択は半角数字で行ってください。" << "\n";
	getchar();
	cout << "戦闘時の選択肢の説明\nたたかう：敵を攻撃します。その後、敵からの攻撃を受けます。" << "\n";
	getchar();
	cout << "ヒール：MPを20消費して、自分のHPを全快させます。" << "\n";
	getchar();
	cout << "サンダー：MPを50消費して敵に大ダメージを与えます。その後、敵から攻撃を受けます。" << "\n";
	getchar();
	cout << "それでは、ゲームを始めましょう。" << "\n";
	getchar();


	while (1) {
		map<string, monster>::iterator p;
		srand((unsigned)time(NULL));
		r = rand() % 5;
		p = m.begin();
		for (i = 0; i < r; i++)
			p++;

		p->second.substitutiondata(&hp, &attack);

		cout << p->first << "があらわれた。" << "\n";
		while (1) {
			srand((unsigned)time(NULL));
			r = rand() % 200;
			cout << "--------------------------------------------------------------" << "\n\n";
			cout << bravename << "　HP：" << bravehp << "　MP：" << bravemp << "\n\n";
			cout << "--------------------------------------------------------------" << "\n\n";
			cout << "どうする？" << "\n";
			while (1) {
				c = 0;
				cout << "たたかう：１　ヒール：２　サンダー：３" << "\n";
				cin >> c;
				if (c == 1) {
					break;
				}
				else if (c == 2) {
					if (bravemp >= 20) {
						cout << bravename << "のHPが" << 1000 << "に回復した。" << "\n";
						bravehp = 1000;
						bravemp = bravemp - 20;
						cout << "--------------------------------------------------------------" << "\n\n";
						cout << bravename << "　HP：" << bravehp << "　MP：" << bravemp << "\n\n";
						cout << "--------------------------------------------------------------" << "\n\n";
					}
					else
						cout << "MPが足りない。" << "\n";
				}
				else if (c == 3) {
					if (bravemp >= 50) {
						cout << p->first << "に雷が降り注ぐ！" << "\n";
						srand((unsigned)time(NULL));
						r = rand() % 1000;
						r2 = 0;
						bravemp = bravemp - 50;
						break;
					}
					else
						cout << "MPが足りない。" << "\n";
				}
			}
			cout << p->first << "に、" << r << "ダメージを与えた。" << "\n";
			hp = hp - r;
			if (hp <= 0)
				break;
			getchar();

			cout << p->first << "の攻撃！" << "\n";
			srand((unsigned)time(NULL));
			r2 = rand() % attack;
			getchar();


			cout << bravename << "は、" << r2 << "ダメージを受けた。" << "\n";
			bravehp = bravehp - r2;
			if (bravehp <= 0) {
				bravehp = 0;
				cout << "--------------------------------------------------------------" << "\n\n";
				cout << bravename << "　HP：" << bravehp << "　MP：" << bravemp << "\n\n";
				cout << "--------------------------------------------------------------" << "\n\n";
				cout << "GAME OVER" << "\n";
				getchar();
				cout << bravename << "は、力尽きてしまった。" << "\n";
				getchar();
				cout << "終了する：１" << "\n";

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

		cout << p->first << "を倒した！" << "\n";
		k++;
		getchar();

		cout << "--------------------------------------------------------------" << "\n\n";
		cout << bravename << "　HP：" << bravehp << "　MP：" << bravemp << "\n\n";
		cout << "--------------------------------------------------------------" << "\n\n";
		cout << "続ける：１　あきらめる：２" << "\n";
		cin >> c;
		if (c == 2)
			break;
	}

	cout << "今回、倒したモンスターの数：" << k << "\n";
	getchar();
	cout << "終了する：１" << "\n";

	while (1) {
		c = 0;
		cin >> c;
		if (c == 1)
			break;
	}
	return 0;
}