#ifndef CARD_HPP
#define CARD_HPP

#include <bitset>
#include <cstdint>

class Card {
public:
  Card();

  std::string getCardInfo();
  std::string getCardSeed();
  int8_t getCardNumber();

  void setSeed();
  void setNumber();
private:
  // variable with 2 bits for seed
  // 13 cards need 4 bits
  std::bitset<6> info;
};


#endif // ifndef CARD_HPP

