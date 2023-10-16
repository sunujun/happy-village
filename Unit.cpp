#include "stdafx.h"
#include "Unit.h"


Unit::Unit()
{
}


Unit::~Unit()
{
}


Unit::Unit(int a, string b, string c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int x, int isA, int co)
	: code(a)
	, name(b)
	, description(c)
	, atk(d)
	, hp(e)
	, cost(f)
	, m_speed(g)
	, a_speed(h)
	, rarity(i)
	, pos(j)
	, range(k)
	, dis(l)
	, x(x)
	, isAttack(isA)
	, count(co)
{
}
