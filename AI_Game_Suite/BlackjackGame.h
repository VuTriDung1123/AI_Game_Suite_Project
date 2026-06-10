#pragma once
#include <vector>
#include <string>
#include <memory>

enum class Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
enum class Rank { TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK = 10, QUEEN = 10, KING = 10, ACE = 11 };

class Card {
public:
    Suit suit;
    Rank rank;
    Card(Suit s, Rank r) : suit(s), rank(r) {}
    int getValue() const;
    std::string toString() const;
};

class Deck {
private:
    std::vector<Card> cards;
public:
    Deck();
    void shuffle();
    Card drawCard();
};

class Hand {
public:
    std::vector<Card> cards;
    void addCard(Card c);
    int getTotalValue() const;
    void display(bool hideFirstCard = false) const;
};

class BlackjackGame {
private:
    Deck deck;
    Hand playerHand;
    Hand dealerHand;
    void resetGame();
public:
    BlackjackGame();
    void start();
};