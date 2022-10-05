#ifndef DECK_H
#define DECK_H

#include <vector>

class Deck
{
    public:
        Deck();

        inline static int getMaxCardCount() { return maxCardCount; };

        inline const std::vector<int>& getSpareCards() const { return spareCards; };
        inline const std::vector<int>& getTrashedCards() const {return trashedCards; };

        int drawSpareCard(int);

        void shuffleSpareCards();
        void trashSpareCards();
        void recycleTrashedCards();

        void addTrashedCards(int);
        void addTrashedCards(std::vector<int>&);

    private:
        const static int maxCardCount;
        const static std::string boundary;

        static void displayCards(const std::vector<int>&);

        std::vector<int> spareCards, trashedCards;

        friend std::ostream& operator<<(std::ostream&, const Deck&);
};

#endif
