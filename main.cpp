#include <iostream>
#include "header.h"

int main(){

	CardDeck cards1;

	cards1.GenerateDeck();

	for(int i = 0; i < 7; i++){
		cards1.shuffleC();
	}
	cards1.printCardsMain();

	return 0;
}
