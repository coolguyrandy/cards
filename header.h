
//implement functions here

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
};

