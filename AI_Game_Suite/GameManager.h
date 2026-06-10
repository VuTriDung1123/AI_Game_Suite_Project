#pragma once
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

// Khai báo trước các class để tránh lỗi Include vòng (Circular Dependency)
class BlackjackGame;
class ChessGame;

enum class GameState {
    MAIN_MENU,
    PLAYING_BLACKJACK,
    PLAYING_CHESS,
    EXIT
};

class GameManager {
private:
    GameState currentState;

    void displayMainMenu();
    void startBlackjack();
    void startChess();

public:
    GameManager();
    void run();
};

#endif