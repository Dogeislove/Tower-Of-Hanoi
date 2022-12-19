#include "rings.h"

int ring::size() const
{
	return sz;
}

const bool ring::operator<(const ring& operand1)
{
	return sz<operand1.sz;
}

const bool ring::operator>(const ring& operand1)
{
	return sz>operand1.sz;
}

