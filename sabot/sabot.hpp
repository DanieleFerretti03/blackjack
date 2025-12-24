#ifndef SABOT_HPP
#define SABOT_HPP

#include <vector>
#include "../card/card.hpp"

class Sabot {
public:
  Sabot();

  void shuffle();
  Card getCard();
private:
  std::vector<Card> sabot;
  int8_t numberOfDeck;
  int16_t sabotsIndex;
};


#endif // ifndef SABOT_HPP
