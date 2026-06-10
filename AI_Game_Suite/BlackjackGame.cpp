#include "BlackjackGame.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

// --- CARD ---
int Card::getValue() const { return static_cast<int>(rank); }
std::string Card::toString() const {
    std::string rStr, sStr;
    if (rank == Rank::ACE) rStr = "A";
    else if (rank == Rank::JACK) rStr = "J";
    else if (rank == Rank::QUEEN) rStr = "Q";
    else if (rank == Rank::KING) rStr = "K";
    else rStr = std::to_string(static_cast<int>(rank));

    if (suit == Suit::HEARTS) sStr = "Co";
    else if (suit == Suit::DIAMONDS) sStr = "Ro";
    else if (suit == Suit::CLUBS) sStr = "Chuon";
    else sStr = "Bich";
    return rStr + " " + sStr;
}

// --- DECK ---
Deck::Deck() {
    for (int s = 0; s < 4; ++s) {
        for (int r = 2; r <= 14; ++r) { // 11=J, 12=Q, 13=K, 14=A
            Rank rankVal = (r <= 10) ? static_cast<Rank>(r) :
                (r == 14) ? Rank::ACE : Rank::JACK; // JACK/QUEEN/KING đều tính là 10
            cards.emplace_back(static_cast<Suit>(s), rankVal);
        }
    }
}
void Deck::shuffle() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}
Card Deck::drawCard() {
    Card c = cards.back();
    cards.pop_back();
    return c;
}

// --- HAND ---
void Hand::addCard(Card c) { cards.push_back(c); }
int Hand::getTotalValue() const {
    int sum = 0, aces = 0;
    for (const auto& c : cards) {
        sum += c.getValue();
        if (c.rank == Rank::ACE) aces++;
    }
    while (sum > 21 && aces > 0) {
        sum -= 10; // Đổi giá trị Át từ 11 thành 1
        aces--;
    }
    return sum;
}
void Hand::display(bool hideFirstCard) const {
    for (size_t i = 0; i < cards.size(); ++i) {
        if (i == 0 && hideFirstCard) std::cout << "[La bai an] ";
        else std::cout << "[" << cards[i].toString() << "] ";
    }
    if (!hideFirstCard) std::cout << " => Tong: " << getTotalValue();
    std::cout << "\n";
}

// --- BLACKJACK GAME LOGIC ---
BlackjackGame::BlackjackGame() {}
void BlackjackGame::resetGame() {
    deck = Deck();
    deck.shuffle();
    playerHand.cards.clear();
    dealerHand.cards.clear();
}
void BlackjackGame::start() {
    bool keepPlaying = true;
    while (keepPlaying) {
        resetGame();
        std::cout << "\n--- VAN MOI ---\n";
        playerHand.addCard(deck.drawCard()); dealerHand.addCard(deck.drawCard());
        playerHand.addCard(deck.drawCard()); dealerHand.addCard(deck.drawCard());

        std::cout << "Bai cua Dealer: "; dealerHand.display(true);
        std::cout << "Bai cua Ban: "; playerHand.display();

        // Player turn
        char choice;
        while (playerHand.getTotalValue() < 21) {
            std::cout << "Rut them (h) hay Dung (s)? (h/s): ";
            std::cin >> choice;
            if (choice == 'h') {
                playerHand.addCard(deck.drawCard());
                std::cout << "Bai cua Ban: "; playerHand.display();
            }
            else break;
        }

        if (playerHand.getTotalValue() > 21) {
            std::cout << "Ban da Quac (Bust)! Dealer thang.\n";
        }
        else {
            // Dealer turn
            std::cout << "\nLuot cua Dealer:\n";
            std::cout << "Bai cua Dealer: "; dealerHand.display();
            while (dealerHand.getTotalValue() < 17) {
                std::cout << "Dealer rut them...\n";
                dealerHand.addCard(deck.drawCard());
                dealerHand.display();
            }

            int pScore = playerHand.getTotalValue();
            int dScore = dealerHand.getTotalValue();
            if (dScore > 21 || pScore > dScore) std::cout << ">> BAN THANG! <<\n";
            else if (pScore == dScore) std::cout << ">> HOA (PUSH)! <<\n";
            else std::cout << ">> DEALER THANG! <<\n";
        }

        std::cout << "Choi tiep khong? (y/n): ";
        std::cin >> choice;
        if (choice == 'n') keepPlaying = false;
    }
}