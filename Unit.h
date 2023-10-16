#pragma once
#include <string>

using namespace std;
class Unit
{
public:
	Unit();
	~Unit();
	int code;
	string name;
	string description;
	int atk;
	int hp;
	int cost;
	int m_speed;
	int a_speed;
	int rarity;
	int pos;
	int range;
	int dis;
	int x;
	int isAttack;
	int count;
	Unit(int a, string b, string c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int x, int isA, int co);
};

