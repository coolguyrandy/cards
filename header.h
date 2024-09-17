
//implement functions here
#include <vector>
#include <random>

int randomGen(char choice){

	std::mt19937 generator(std::random_device{}());
	//S is for deck split
	if(choice == 'S'){
		std::uniform_int_distribution<int> distribution(19, 33);	
		return distribution(generator);
	}
	//R is for riffle shuffle
	else if(choice == 'R'){ 
		std::uniform_int_distribution<int> distribution(1, 4);	
		return distribution(generator);
	}

	return 0;//
}

struct Card{
	std::string CardV;
	std::string CardS;
	Card* next;	
	Card(std::string CardValue, std::string CardSuit, Card* nex): CardV(CardValue), CardS(CardSuit), next(nex){}	

	~Card(){}
};

class CardDeck{

	public:
	Card* headMain;
	int DeckSize;

	CardDeck(): headMain(nullptr), DeckSize(0) {}

	void GenerateDeck(){
		std::string Values[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
		std::string Suits[4] = {"Spades", "Diamonds", "Clubs", "Hearts"};

		for(size_t suit = 0; suit < 4; suit++){
			for(size_t val = 0; val < 13; val++){
			Card* CardToAdd = new Card(Values[val], Suits[suit], headMain);
				headMain = CardToAdd;
				DeckSize+=1;
			}
		}
	}
	
	~CardDeck(){
		Card* CurrentCard = headMain;
		while(CurrentCard != nullptr){
			Card* NextCard = CurrentCard->next;
			delete CurrentCard;
			DeckSize-=1;
			CurrentCard = NextCard;
			headMain= CurrentCard;
		}
	}
	void printCardsMain(){
		Card* CurrentCard = headMain;
		std::cout << "__________________________________" << std::endl;
		while(CurrentCard){
			std::cout << "(" << CurrentCard->CardS << " " << CurrentCard->CardV << ")" << "\n";
			CurrentCard = CurrentCard->next;
		}

		std::cout << "_________________________________" << std::endl;
	}

	void ShuffleA(){
		Card* ary1[26];
		Card* ary2[26];
		Card* CurrentCard;
	
		CurrentCard = headMain;

		
		for(size_t i = 0; i < 26; i++){
			ary1[i] = CurrentCard;
			CurrentCard = CurrentCard->next;
		}


		for(size_t j = 0; j < 26; j++){
			ary2[j] = CurrentCard;
			CurrentCard = CurrentCard->next;
		}


		for(size_t i = 0; i < 25; i++){
			ary1[i]->next = ary2[i];
			ary2[i]->next = ary1[i+1];
		}
		headMain = ary1[0];
		ary1[25]->next = ary2[25];
		ary2[25]->next = nullptr;
	}

	void ShuffleB(){
		Card* ary1[26];
		Card* ary2[26];
		Card* CurrentCard;
	
		CurrentCard = headMain;

		
		for(size_t i = 0; i < 26; i++){
			ary1[i] = CurrentCard;
			CurrentCard = CurrentCard->next;
		}


		for(size_t j = 0; j < 26; j++){
			ary2[j] = CurrentCard;
			CurrentCard = CurrentCard->next;
		}


		for(size_t i = 0; i < 25; i++){
			ary2[i]->next = ary1[i];
			ary1[i]->next = ary2[i+1];
		}
		headMain = ary2[0];
		ary2[25]->next = ary1[25];
		ary1[25]->next = nullptr;
	}

	void shuffleC(){
		std::vector<Card*> vec1;
		std::vector<Card*> vec2;

		Card* currentCard = headMain;

		int deckSplit = randomGen('S');
		int largerDeck, smallerDeck;

		for(int i = 0; i < deckSplit; i++){
			vec1.insert(vec1.begin()+i, currentCard);
			currentCard = currentCard->next;		
		}

		for(int i = 0; i < 52-deckSplit; i++){
			vec2.insert(vec2.begin()+i, currentCard);
			if(currentCard->next != nullptr)
				currentCard = currentCard->next;
			else
				break;
		}

		if(vec1.size() > vec2.size()){
			largerDeck = vec1.size();
			smallerDeck = vec2.size();
		}	
		else if(vec2.size() > vec1.size()){
			largerDeck = vec2.size();
			smallerDeck = vec1.size();
		}
		else{
			largerDeck = vec1.size();
			smallerDeck = vec1.size();
		}
		if(vec1.size() > vec2.size())
			headMain = vec1.at(0);
		else if(vec2.size() > vec1.size())
			headMain = vec2.at(0);

		for(size_t i = 0; i < smallerDeck; i++){
			if(vec1.size() > vec2.size()){
				vec1.at(i)->next = vec2.at(i);
				vec2.at(i)->next = vec1.at(i+1);
			}
			else if(vec1.size() < vec2.size()){
				vec2.at(i)->next = vec1.at(i);
				vec1.at(i)->next = vec2.at(i+1);
			}
		
		}

		vec1.erase(vec1.begin(), vec1.begin()+smallerDeck);
		vec2.erase(vec2.begin(), vec2.begin()+smallerDeck);

		if(vec1.size() > vec2.size()){
			for(int i = 0; i < largerDeck-smallerDeck-1; i++){
				vec1.at(i)->next = vec1.at(i+1);
			}
			vec1.back()->next = nullptr;
		}
		else if(vec1.size() < vec2.size()){
			for(int i = 0; i < largerDeck-smallerDeck-1; i++){
				vec2.at(i)->next = vec2.at(i+1);
			}
			vec2.back()->next = nullptr;
		}


	}
};

