#include <vector>
#include <exception>
#include "rings.h"
#include <stdexcept>
#include <algorithm>

#pragma once
class tower //Tower. You cannot add another ring once you set it.
{
private:
	std::vector<ring> rings_v; //rings of tower
public:
	ring* begin()
	{
		return &rings_v[0];
	}
	
	ring* end()
	{
		return &rings_v[rings_v.size()];
	}
	tower(int rings); 
	tower(); //empty tower. These should be used for the other 3 towers.
	void move_ring(const int& ring_index, tower& to);
	void move_ring(ring* from, tower& to); // I, for some reason, forgot to
					      // include a pointer version
					      // Nearly everyone (and their grandma) would need to use a pointer version.
	const bool can_move(const int& ring_index, const ring& to);
	ring& get_ring(const int& index);
//	ring& get_ring(const int& index) const:
	ring& operator[](int index);
	int rings() const;
//	{
//		return rings_v.size();
//	}
//	ring& operator[](int index) const;
};
