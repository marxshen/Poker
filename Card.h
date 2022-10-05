#ifndef CARD_H
#define CARD_H

#include <vector>

class Card
{
    public:
        inline const static std::vector<std::string>& getSuits()
        {
            return suits;
        };

        inline const static std::vector<std::string>& getRanks()
        {
            return ranks;
        };

    private:
        const static std::vector<std::string> suits, ranks;
};

#endif
