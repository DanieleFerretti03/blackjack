#ifndef CROUPIER_HPP
#define CROUPIER_HPP

class Croupier {
public:
  Croupier();

  int8_t hasToAskCard();
  void updateSum();
  void updateBestPlayerTotal();
private:
  int8_t bestPlayerNumber;
  int8_t totalSum;
};


#endif // ifndef CROUPIER_HPP

