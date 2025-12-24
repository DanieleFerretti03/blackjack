#ifndef GENERATOR_STARTING_POSITION_HPP
#define GENERATOR_STARTING_POSITION_HPP

#include <array>
#include "../card/card.hpp"

class Generator_starting_positon{
public:
  Generator_starting_positon();
  
  void generateNewRandomPosition();
  void generateNewPairsPosition();
  void generateNewSoftPosition();
  void generateNewHardPosition();
private:
  Card croupierCard;
  std::array<Card, 2> playerHand;
};

#endif // !GENERATOR_STARTING_POSITION_HPP
