#ifndef BASIC_STRATEGY.HPP
#define BASIC_STRATEGY.HPP

// Tipo della mano X totale X totale dealer -> azione
//
//  Tipi di mano:
//  0 = Hard totale (senza asso)
//  1 = Soft totale (con asso)
//  2 = coppia (due carte uguali)
//
// Azioni: 
// 0 = Stare
// 1 = Chiamare
// 2 = Raddoppio
// 3 = Dividi
// 4 = Arrenditi

// Hard totals: righe = totale giocatore (5-20), colonne = carta dealer (2-11/A)
// Indice riga: total - 5, Indice colonna: dealer - 2
constexpr int HARD_STRATEGY[16][10] = {
  // Dealer:  2  3  4  5  6  7  8  9 10  A
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, /* 5 */
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, /* 6 */
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, /* 7 */
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, /* 8 */
  { 1, 2, 2, 2, 2, 1, 1, 1, 1, 1 }, /* 9 */
  { 2, 2, 2, 2, 2, 2, 2, 2, 1, 1 }, /* 10 */
  { 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 }, /* 11 */
  { 1, 1, 0, 0, 0, 1, 1, 1, 1, 1 }, /* 12 */
  { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 }, /* 13 */
  { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 }, /* 14 */
  { 0, 0, 0, 0, 0, 1, 1, 1, 4, 1 }, /* 15 */
  { 0, 0, 0, 0, 0, 1, 1, 4, 4, 4 }, /* 16 */
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, /* 17 */
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, /* 18 */
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, /* 19 */
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }  /* 20 */
};

// Soft totals: A-2 (13) fino a A-9 (20)
constexpr int SOFT_STRATEGY[8][10] = {
  // Dealer:  2  3  4  5  6  7  8  9 10  A
  { 1, 1, 1, 2, 2, 1, 1, 1, 1, 1 }, /* A-2 */
  { 1, 1, 1, 2, 2, 1, 1, 1, 1, 1 }, /* A-3 */
  { 1, 1, 2, 2, 2, 1, 1, 1, 1, 1 }, /* A-4 */
  { 1, 1, 2, 2, 2, 1, 1, 1, 1, 1 }, /* A-5 */
  { 1, 2, 2, 2, 2, 1, 1, 1, 1, 1 }, /* A-6 */
  { 0, 2, 2, 2, 2, 0, 0, 1, 1, 1 }, /* A-7 */
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, /* A-8 */
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }  /* A-9 */
};

// Pairs: 2-2 fino a A-A
constexpr int PAIR_STRATEGY[10][10] = {
  // Dealer:  2  3  4  5  6  7  8  9 10  A
  { 3, 3, 3, 3, 3, 3, 1, 1, 1, 1 }, /* 2-2 */
  { 3, 3, 3, 3, 3, 3, 1, 1, 1, 1 }, /* 3-3 */
  { 1, 1, 1, 3, 3, 1, 1, 1, 1, 1 }, /* 4-4 */
  { 2, 2, 2, 2, 2, 2, 2, 2, 1, 1 }, /* 5-5 */
  { 3, 3, 3, 3, 3, 1, 1, 1, 1, 1 }, /* 6-6 */
  { 3, 3, 3, 3, 3, 3, 1, 1, 1, 1 }, /* 7-7 */
  { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 }, /* 8-8 */
  { 3, 3, 3, 3, 3, 0, 3, 3, 0, 0 }, /* 9-9 */
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, /* 10-10*/
  { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 }  /* A-A */
};

// Helper function inline
inline int getAction(int handType, int playerTotal, int dealerCard) {
  // Normalizza dealer card (2-11, dove 11=A)
  int dealerIdx = dealerCard - 2;
  
  if (handType == 0) { // HARD
    if (playerTotal < 5 || playerTotal > 20) return STARE;
    return HARD_STRATEGY[playerTotal - 5][dealerIdx];
  }

  if (handType == 1) { // SOFT
    if (playerTotal < 13 || playerTotal > 20) return STARE;
    return SOFT_STRATEGY[playerTotal - 13][dealerIdx];
  }

  if (playerTotal < 4 || playerTotal > 22) return STARE;
  return PAIR_STRATEGY[(playerTotal / 2) - 2][dealerIdx];
}

#endif // !BASIC_STRATEGY.HPP
