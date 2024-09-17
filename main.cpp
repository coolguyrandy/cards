#include <iostream>
#include "header.h"

int main(){

	CardDeck cards1;

	CardDeck cards2;

	cards1.GenerateDeck();

	cards1.ShuffleA();

	cards1.printCardsMain();

	cards2.GenerateDeck();

	cards2.ShuffleB();

	cards2.printCardsMain();

	return 0;
}
