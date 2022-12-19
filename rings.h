//#include <vector>
#pragma once

class ring //ring. Circular disk to be used
{
private:
	int sz = 0;
public:
	ring(int size) : sz{size} {}
	int size() const; //returns the size of the disk.
	const bool operator<(const ring& operand1);
	//return operand1.sz<sz;

	const bool operator>(const ring& operand1);
	//return operand1.sz>sz;
		
};
