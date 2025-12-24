#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>

class Menu {
public:
  Menu();

  void startMenu();
private:
  std::string getStartingMenu();
  void fromStartMenuToOther(std::string option);
};


#endif // ifndef
