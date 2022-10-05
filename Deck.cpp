#include <random>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Deck.h"
#include "Card.h"

using namespace std;

Deck::Deck()
    : spareCards(maxCardCount)
{
    for (int i = 0; i < spareCards.size(); ++i)
        spareCards[i] = i;
}

void Deck::displayCards(const vector<int>& cards)
{
    if (cards.size() > 0)
        for (int i = 0; i < cards.size(); ++i)
        {
            cout << Card::getSuits()[cards[i] % 4]
                 << setw(3)
                 << left
                 << Card::getRanks()[cards[i] >> 2];
            
            if (i % 13 == 12 && i < cards.size() - 1)
                cout << endl;
        }
    else
        cout << "Deck has no cards to be displayed.";
}

int Deck::drawSpareCard(int pos)
{
    int card = -1;

    if (spareCards.size() > 0)
    {
        if (pos < 0) // Logical order is critical.
            pos = 0;
        else if (pos > spareCards.size() - 1)
            pos = spareCards.size() - 1;

        card = spareCards[pos];
        spareCards.erase(spareCards.begin() + pos);
    }

    return card;
}

void Deck::shuffleSpareCards()
{
    if (spareCards.size() > 0)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, spareCards.size() - 1);

        for (int i = 0; i < spareCards.size(); ++i)
            swap(spareCards[i], spareCards[distrib(gen)]);
    }
    else
    {
        cout << "Deck has no spare cards to be shuffled.";
    }
}

void Deck::trashSpareCards()
{
    if (spareCards.size() > 0)
    {
        move(
            spareCards.begin(),
            spareCards.end(),
            back_inserter(trashedCards)
        );

        spareCards.clear();
    }
    else
    {
        cout << "Deck has no spare cards to be trashed.";
    }
}

void Deck::recycleTrashedCards()
{
    if (trashedCards.size() > 0)
    {
        move(
            trashedCards.begin(),
            trashedCards.end(),
            back_inserter(spareCards)
        );

        trashedCards.clear();
    } 
    else
    {
        cout << "Deck has no trashed cards to be recycled.";
    }
}

void Deck::addTrashedCards(int card)
{
    trashedCards.insert(trashedCards.end(), card);
}

void Deck::addTrashedCards(vector<int>& cards)
{
    if (cards.size() > 0)
    {
        move(cards.begin(), cards.end(), back_inserter(trashedCards));
        cards.clear();
    }
}

std::ostream& operator<<(ostream& out, const Deck& cardDeck)
{
    out << Deck::boundary << endl;
    out << "Spare cards" << ": " << endl;
    Deck::displayCards(cardDeck.getSpareCards());
    out << endl << endl;

    out << "Trashed cards" << ": " << endl;
    Deck::displayCards(cardDeck.getTrashedCards());
    out << endl << Deck::boundary << endl;

    return out;
}

const int Deck::maxCardCount = 52;
const string Deck::boundary = string (52, '-');
