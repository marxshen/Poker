#include <iostream>
#include "Deck.h"
#include "Player.h"

using namespace std;

int main()
{
    Deck cardDeck;
    cout << cardDeck << endl;

    cardDeck.shuffleSpareCards();
    cout << cardDeck << endl;

    Player alice("Alice"), emma("Emma"), amelia("Amelia"), 
           john("John"), james("James"), henry("Henry");

    vector<Player*> players {&alice, &emma, &amelia, &john, &james, &henry};

    while (cardDeck.getSpareCards().size() > Player::getPlayerCount() - 1)
        for (int i = 0; i < players.size(); ++i)
            players[i]->addCard(cardDeck.drawSpareCard(-100));

    cardDeck.trashSpareCards();
    cout << cardDeck << endl;

    for (int i = 0; i < players.size(); ++i)
        cout << *players[i] << endl;

    while (cardDeck.getTrashedCards().size() < Deck::getMaxCardCount() / 2)
        for (int i = 0; i < players.size(); ++i)
            cardDeck.addTrashedCards(players[i]->drawCard(-100));

    cout << cardDeck << endl;

    for (int i = 0; i < players.size(); ++i)
        cout << *players[i] << endl;

    for (int i = 0; i < players.size(); ++i)
    {
        vector<int> cards {players[i]->trashCards()};
        cardDeck.addTrashedCards(cards);
    }

    cout << cardDeck << endl;

    for (int i = 0; i < players.size(); ++i)
        cout << *players[i] << endl;

    cardDeck.recycleTrashedCards();
    cout << cardDeck << endl;
}
