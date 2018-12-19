#ifndef _RANKING_H__
#define _RANKING_H__ value
#include "deck.h"
#include "handValue.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>
//proioity que to get the best hand currently
class HandRanking{
public:
	HandRanking() {};
	HandRanking(const std::vector<Hand*>& q){
		for (int i = 0; i < q.size(); ++i)
		{
			
		}
	}

	const std::pair<Hand*, int> top() const {return queue[0];}
	void pop(){
		int sucess = lookUp.erase(queue[0]);
		assert(sucess == 1);
		queue[0] = queue.back();

		percolateDown(0);
	}
	void upDate(int value, Hand* card);
	void clear(){
		queue.clear();
		loopUp.clear();
	}
	int size(){return queue.size();}
private:
	void percolateUp();
	void percolateDown();
	std::vector<std::pair<Hand*, int>> queue;//stores a hand and its score
	std::unordered_map<std::pair<Hand*,int>, int> lookUp;
};

#endif