#include <iostream>
#include <iomanip>
#include <algorithm>
#include <format>
#include "Player.h"
#include "Card.h"

using namespace std;

Player::Player(const string& nm)
    : name(nm)
{
    ++playerCount;
}

Player::~Player()
{
    --playerCount;
}

void Player::displayCards(const string& name, const vector<int>& cards)
{
    if (cards.size() > 0)
        for (int i = 0; i < cards.size(); ++i)
        {
            cout << Card::getSuits()[cards[i] % 4]
                 << setw(3)
                 << left
                 << Card::getRanks()[cards[i] >> 2];
            
            if (i % 5 == 4 && i < cards.size() - 1)
                cout << endl;
        }
    else
        cout << "Player has no cards to be displayed.";
}

int Player::drawCard(int pos)
{
    int card = -1;

    if (cards.size() > 0)
    {
        if (pos < 0) // Logical order is critical.
            pos = 0;
        else if (pos > cards.size() - 1)
            pos = cards.size() - 1;

        card = cards[pos];
        cards.erase(cards.begin() + pos);
    }

    return card;
}

vector<int> Player::trashCards()
{
    vector<int> trashedCards;

    if (cards.size() > 0)
    {
        move(cards.begin(), cards.end(), back_inserter(trashedCards));
        cards.clear();
    }

    return trashedCards;
}

void Player::addCard(int card)
{
    if (card > -1)
        cards.insert(cards.end(), card);
}

std::ostream& operator<<(ostream& out, const Player& p)
{
    out << p.getName() << ": " << endl;
    Player::displayCards(p.getName(), p.getCards());
    out << endl;

    return out;
}

const int Player::maxCardCount = 13;
int Player::playerCount = 0;
