#ifndef _DECK__
#define _DECK__
#include <random>
#include <list>
//general purpose card, deck, and hand class
class Card{
	public:
		Card(const int n, const int s) : face(n), suit(s) {}
		Card(const Card& c);//copy constructor
		int face;
		int suit;
};
class Hand{
	public:
		Hand(const std::vector<Card*> h) : hand_(h) {}
		Card getCard(int i){ return *hand_[i]; }
		vector<Card*> revealHand(){return hand_;}
		void addCard(Card* c){hand_.push_back(c);}
	private:
		std::vector<Card*> hand_;
};
class Deck{
	public:
		//num is the nubmer of decks
		Deck(int num) : deck_(52 * num), starting() {}
		void shuffle();
		void deal(std::list<Hand>& h, int num);
		void reset(){
			deck.clear();
			starting();
		}
	private:
		int numDecks;
		void starting();
		std::vector<Card*> deck_;
};
void Deck::starting(){
	deck_.resize(numDecks * 52);
	for (int i = 0; i < numDecks; ++i)//num of decks
	{
		for (int j = 0; j < 4; ++j)//suit
		{
			for (int k = 0; k < 13; ++k)//face
			{
				deck[(i + 1) * k].face = k;
				deck[(i + 1) * k].suit = j;	
			}
		}
	}
}
void Deck::deal(std::vector<Hand>& h, int num){
	shuffle();
	for (int i = 0; i < h.size(); ++i)
	{
		int size = num;
		for (int j = deck.size() - 1; j >= 0 && size >= 0; size--)
		{
			h[i].addCard(j);
			deck.pop_back();
		}
	}
}
/*
shuffles by swapping a 
random number of cards 
with a minimum number set
*/
void Deck::shuffle(){
	int numSwitches;
	while(numSwitches < 20 * numDecks) numSwitches = std::rand();
	int a[numSwitches * 2];
	for (int i = 0; i < numSwitches * 2; ++i) a[i] = std::rand();
	for (int i = 0; i < numSwithces; ++i) std::swap(deck_[a[i]], deck_[a[i + 1]]);	
}
#endif