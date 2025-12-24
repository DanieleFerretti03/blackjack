#include "menu.hpp"

Menu::Menu(){}

void Menu::startMenu(){
  const std::string EXIT_RESONSE = "4";
  
  std::string response = EXIT_RESONSE;
  do {
    // Stampa opzioni menu principale
    std::cout << this->getStartingMenu();

    // Prendi risposta
    std::cin >> response;

    // Esegui opzione richiesta
    this->fromStartMenuToOther(response);

  } while(response.compare(EXIT_RESONSE) != 0);
}

std::string Menu::getStartingMenu(){
  // Menu per scelta opzione
  // Simula gioco
  // Simula strategia
  // Settings
  // Esci dal menu
  std::string output = "";
  
  output += "Menu iniziale, fai la tua scelta:\n\n";
  output += "1) Simula partita di blackjack\n";
  output += "2) Allenati nella strategia di base\n";
  output += "3) Imposta le regole del gioco\n";
  output += "4) Esci\n";

  output += "\nScrivi il numero: ";

  return output;
}

void Menu::fromStartMenuToOther(std::string option){
  if(option.compare("4") == 0){
    return;
  }

  return;
}
