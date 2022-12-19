#include "tower.h"
#include <iostream>
#include <string>
using namespace std;
#define empty -7777
int main()
{
	tower first_tower{3};
	tower second_tower{};
	tower third_tower{};
	char tow;
	bool won = false;
	tower* selected_ring = nullptr;
	tower* to = nullptr; //easier handling
	while(!won)
	{
		//ugly print stuff
		if(third_tower.rings() == 3)
		{
			won=true; //game complete, every ring has been moved! yay!
			std::cout << "YOU WON!\n(unlike the person who programmed this, the only thing he won is the small amount of sanity still left in him\n";
			return 0;
		}
		std::cout << "There are three rings in total. You can move rings, but it must be placed on top of a larger ring. Here is the layout\n";
		//vector<int> sizes;
		//vector<int> sizes_second;
		//vector<int> sizes_third;
		for(int i = 2; i != -1; --i)
		{
			//std::cout << (first_tower.rings()-1)-i << '\n' << (second_tower.rings()-1)-i; 
	
		//	std::cout << i << '\n';
		//	std::cout << "(first_tower): " << (first_tower.rings()-1)-i;
		//	std::cout << "\n(second_tower): " << (second_tower.rings()-1)-i;
			//std::cout << "\n(third_tower): " << (third_tower.rings()-1)-i;
			if((first_tower.rings()-1)-i>=0)
				std::cout << '\t' << string(first_tower.get_ring((first_tower.rings()-1)-i).size()+1,'x') << '\t';
			else 
				std::cout << '\t' << " | " << '\t';

			//std::cout << "finished tower 1 ";
			if((second_tower.rings()-1)-i>=0)
                                std::cout <<  string(second_tower.get_ring((second_tower.rings()-1)-i).size()+1,'x') << '\t';
                        else
                                std::cout << " | " << '\t';

                        if((third_tower.rings()-1)-i>=0)
                                std::cout << string(third_tower.get_ring((third_tower.rings()-1)-i).size()+1,'x') << '\t';
                        else
                                std::cout  << " | " << '\t';
			if(i != 0)
			std::cout << '\n';
				//std::cout << "correct";
	//		if((first_tower.rings()-1)-i>=-1)
				//std::cout << '\t' << string(first_tower.get_ring((first_tower.rings()-1)-i).size()+1,'x');
	//			sizes.push_back(first_tower.get_ring((first_tower.rings()-1)-i).size()+1);
	//		else 
	//			sizes.push_back(empty);

	//		 if((second_tower.rings()-1)-i>=-1)
                              //std::cout << '\t' << string(first_tower.get_ring((first_tower.rings()-1)-i).size()+1,'x');
          //                      sizes_second.push_back(second_tower.get_ring((second_tower.rings()-1)-i).size()+1);
            //            else
              //                  sizes_second.push_back(empty);
                        
                //        if((third_tower.rings()-1)-i>=-1)
                               //std::cout << '\t' << string(first_tower.get_ring((first_tower.rings()-1)-i).size()+1,'x');
                  //              sizes_third.push_back(third_tower.get_ring((third_tower.rings()-1)-i).size()+1);
                    //    else 
                      //          sizes.push_back(empty);
                        //t << '\n';

			//t << '\n';

			//t << '\n';
		//	std::cout << '\n';
		//	std::cout << '\n' << "rings: " << (first_tower.rings()-1)-i;
		//	std::cout << i << ' ' << 4-i << ' ';
		//	if(first_tower.rings()<(4-i))
		//		std::cout << "\t|\t";
		//	else
		//		std::cout << '\t' << string(i,'x') << '\t';
		//	
		//	if(second_tower.rings()-1<(3-i))
		//		cout << " |\t";	
		//	else
		//		cout << string(second_tower.get_ring(i-1).size(),'x') << '\t';
		//	
		//	if(third_tower.rings()<(4-i))
		//		cout << " |\t\n";
		//	else 
		//		cout << string("x",i) << '\n';
			//cout << '\n';
		}
	/*	for(int i = 2; i != 0; --i)
		{
			if(sizes[i] == empty)
				cout << "|\t";
			else 
				cout << string(sizes[i],'x') << '\t';
                          if(sizes_second[i] == empty)                                                                                                                  
                                  cout << "|\t";                                                                                                                 
                          else                          
                                  cout << string(sizes_second[i],'x') << '\t';
                   
                          if(sizes_third[i] == empty)                                                                                                                  
                                  cout << "|\t";                                                                                                                 
                          else                          
                                  cout << string(sizes_third[i],'x');
                   

			  std::cout << '\n';
		}*/
	//	for(int i = sizes.size()-1; i != 0; --i)
	//	{
			
	//	}
		cout << '\n';
		cout << "        --- \t";
		cout << "--- \t";
		cout << "--- \t";
		cout <<"\n         1 \t 2\t 3\n";
		cout << "\nSelect a ring 1-3 (q discards any selected ring): ";
	//	std::cout << '\n' << "1 contains: ";
//		for(auto a : first_tower)
//		{
//			cout << a.size() << ' ';
//		}
	//	std::cout << '\n' << "2 contains: ";
		for(auto a : second_tower)
		{
			std::cout << a.size() << ' ';
		}
	//	std::cout << '\n' << "3 contains: ";
		for(auto a : third_tower)
			std::cout << a.size() << ' ';
		std::cout << '\n';
		cin >> tow; //The reason the input character is a char is to prevent a mistake. For example, if i used int and a user entered 1a by accident, I would have to fix cin due to that.
			    //chars on the other hand, can handle numbers (0-9) and characters, so I won't have to do anything to fix cin if some user by mistake enters a character.
		
		switch(tow)
		{
			case '1':
				//selected_ring = 1;
				selected_ring = &first_tower;
				break;
			case '2':
				//selected_ring = 2;
				selected_ring = &second_tower;
				break;
			case '3':
				selected_ring = &third_tower;
				break;
			case 'q':
				selected_ring = nullptr;
				break;
			default: 
				cout << "Error: Invalid Tower\n";
				selected_ring = nullptr;
				break;
		}
		//if(selected_ring
		if(selected_ring != nullptr)
		{
			std::cout << "\nWhere should I move this disc to? (1-3) (q skips): ";
			cin >> tow; //The reason the input character is a char is to prevent a mistake. For example, if i used int and a user entered 1a by accident, I would have to fix cin due to that.
                              //chars on the other hand, can handle numbers (0-9) and characters, so I won't have to do anything to fix cin if some user by mistake enters a character.
                  
                 	 switch(tow)
                  	 {
                        	case '1':                       
                        	          to = &first_tower;              
                                	  break;                          
                                case '2':                       
                                	  to = &second_tower;              
                                          break;                          
                                case '3':                       
                               	          to = &third_tower;              
                                          break;                          
                                case 'q':                       
                                          to = nullptr;              
                                          break;                          
                                default:                        
                                          cout << "Error: Invalid Tower\n";
                                          to = nullptr;              
                                          break;                          
                  	}
			if(to!=nullptr && to!=selected_ring && selected_ring->rings()!=0)
			{
			//		if(first_tower.size() == 0)
			//		{

			//		}
			//		
			
				if (to->rings()==0) // I don't know why but when I use the '->', it somehow is satisfying to me.
					selected_ring->move_ring(0,*to);
				else
				{
					if(selected_ring->get_ring(0).size()<to->get_ring(0).size())
						selected_ring->move_ring(0,*to);
					else 
						std::cout << "Selected ring is larger than the other ring!\n";
				}
			}
  			
		}
		}
//		selected_ring = 0; unnessessary 
//		to = 0; yet again not needed
		return 0;
	}
	//std::cout << my_tower[1].size();



