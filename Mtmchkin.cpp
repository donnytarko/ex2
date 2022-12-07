#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) {
    m_cards = new Card[numOfCards];
    for (int card = 0; card < numOfCards; card++) {
        m_cards[card] = cardsArray[card];
    }
    m_gameStatus = GameStatus::MidGame;
    m_player = Player(playerName);
    m_numOfCards = numOfCards;
    m_currentCard = 0;
}

Mtmchkin::~Mtmchkin() {
    delete[] m_cards;
}

void Mtmchkin::playNextCard() {
    m_cards[m_currentCard].printInfo();
    m_cards[m_currentCard].applyEncounter(m_player);
    m_player.printInfo();
    if (m_currentCard == m_numOfCards - 1) {
        m_currentCard = 0;
    }
    else {
        m_currentCard++;
    }
}

GameStatus Mtmchkin::getGameStatus() const{
    if (m_player.getLevel() == 10) {
        return GameStatus::Win;
    }
    if (m_player.isKnockedOut()) {
        return GameStatus::Loss;
    }
    return GameStatus::MidGame;
}

bool Mtmchkin::isOver() const{
    return !(getGameStatus() == GameStatus::MidGame);
}
