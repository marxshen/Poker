#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

class Player
{
    public:
        Player(const std::string&);
        ~Player();

        inline static int getMaxCardCount() { return maxCardCount; };
        inline static int getPlayerCount() { return playerCount; };

        inline const std::string& getName() const { return name; };
        inline const std::vector<int>& getCards() const { return cards; };

        int drawCard(int);

        std::vector<int> trashCards();

        void addCard(int);

    private:
        const static int maxCardCount;
        static int playerCount;

        static void displayCards(const std::string&, const std::vector<int>&);

        std::string name;
        std::vector<int> cards;

        friend std::ostream& operator<<(std::ostream&, const Player&);
};

#endif
