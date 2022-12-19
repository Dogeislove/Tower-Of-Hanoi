#include "tower.h"
#include <stdexcept>

tower::tower(int rings)
{
	for(int i = 0; i != rings; ++i)
		rings_v.push_back(i);
}

tower::tower()
{
};
#include <iostream>
bool enable_debug = false;
void tower::move_ring(const int& ring_index, tower& to)
{
	std::vector<ring>::iterator iterator_elem = to.rings_v.begin();
	if(enable_debug)
		std::cout << "called with ring_index as " << ring_index << '\n'; 
	if(ring_index <= -1 || ring_index >= rings_v.size())
		throw std::out_of_range("out of range: void tower::move_ring was set to an out of bounds value.");
	if(rings_v.size() == 0)
		throw std::length_error("Error: rings_v.size() = 0 when calling tower::move_ring()");
	if(enable_debug)
	{
		std::cout << "\ncalled tower::move_ring(" << ring_index << "," << &to << ");\n";
	}
	if (to.rings()!=0)
	{
		to.rings_v.insert(iterator_elem, rings_v[ring_index]);
	//	for(auto a : to)
	//		std::cout << a.size() << ' ';
		//std::cout << '\n';
		//to.rings_v.push_back(rings_v[ring_index]);
		
		//iterator_elem.insert(rings_v[ring_index]);
		//ring old_ring = to.rings_v[0];
		//to.rings_v.insert(to.rings_v.begin(),rings_v[ring_index]);
	}
	else
	     to.rings_v.push_back(rings_v[ring_index]);
	//std::cout << "\nAdded new element " << rings_v[ring_index].size() << " to to.rings_v\n";
	ring* from = &*rings_v.begin()+ring_index;
	//ring* to_val = &*to.rings_v.end()-1;
	//std::move(from,from+1,to_val);
	//*to_val = *from;
	rings_v.erase(rings_v.begin()+ring_index);
	//std::cout << "To recap, to has these elements: ";
	for(auto a : to)
		std::cout << a.size() << ' ';
	std::cout << '\n';
	//to.rings_v.push_back(rings_v[ring_index]);
	//rings_v.erase(rings_v.begin()+ring_index);
		
}

void tower::move_ring(ring* from, tower& to) //Forgot to include this the first time of writting. I'm pretty sure even grandma would probably be using pointers instead of indexes. That is why kids you should use pointers
{
	//first, we want the size. However, we have no idea if it is pointing to our vector, so, we will check the memory address of it, if it is not in range from the start of the address of ring_v and the end of the address of ring_v, it can't be an element of our set.
	if(!(from>=&*rings_v.begin() && from<=&*rings_v.end()))
	{
		throw std::invalid_argument("error, from does not point to any element inside of tower!");
	}
	//now we kinda uhh want to push the ring to [sic] to
	to.rings_v.push_back(*from); 
	//and erase the element!
	//however, for some reason, vector::iterator is not the same as my iterator, which is quite ITERATEting (funny haha, right? no?), so we'll just create a variable of that type and have it converted to the iterator! yay!
	std::vector<ring>::iterator from_iter  (from);
	//huzzah! we have finally did it! yay!
	rings_v.erase(from_iter);
	return;
}
const bool tower::can_move(const int& ring_index, const ring& to) //is the size of the ring less than the other ring?
{	
	return (rings_v[ring_index].size()<to.size());

}

ring& tower::get_ring(const int& index) //get ring, so long as index is not out of bounds. if so, throw std::out_of_bounds.
{
	if(enable_debug)
	std::cout << "called with ring_index as " << index << '\n'; 

	if (index<=-1 || index>=rings_v.size())
		throw std::out_of_range("out of range: ring& tower::get_ring was requested to get an out of bounds element");
	return rings_v[index];
}

ring& tower::operator[](int index) //gets ring. Does not include out-of-bounds checking.
{
	return rings_v[index];
}

int tower::rings() const
{
	return rings_v.size();
}
