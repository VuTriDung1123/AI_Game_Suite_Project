#include "GameManager.h"
#include "BlackjackGame.h"
#include "ChessGame.h"
#include <iostream>

GameManager::GameManager() : currentState(GameState::MAIN_MENU) {}

void GameManager::run() {
    while (currentState != GameState::EXIT) {
        switch (currentState) {
        case GameState::MAIN_MENU:
            displayMainMenu();
            break;
        case GameState::PLAYING_BLACKJACK:
            startBlackjack();
            break;
        case GameState::PLAYING_CHESS:
            startChess();
            break;
        case GameState::EXIT:
            std::cout << "Cam on ban da trai nghiem he thong AI Game Suite!\n";
            break;
        }
    }
}

void GameManager::displayMainMenu() {
    std::cout << "========================================\n";
    std::cout << "   AI GAME SUITE - INTEGRATED SYSTEM    \n";
    std::cout << "========================================\n";
    std::cout << "1. Choi Blackjack voi AI (Q-Learning)\n";
    std::cout << "2. Choi Co Vua voi AI (Minimax)\n";
    std::cout << "3. Thoat chuong trinh\n";
    std::cout << "========================================\n";
    std::cout << "Nhap lua chon cua ban (1-3): ";

    int choice;
    std::cin >> choice;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Lua chon khong hop le. Vui long nhap lai!\n\n";
        return;
    }

    switch (choice) {
    case 1:
        currentState = GameState::PLAYING_BLACKJACK;
        break;
    case 2:
        currentState = GameState::PLAYING_CHESS;
        break;
    case 3:
        currentState = GameState::EXIT;
        break;
    default:
        std::cout << "Lua chon khong hop le. Vui long nhap lai!\n\n";
        break;
    }
}

void GameManager::startBlackjack() {
    // Khởi tạo và chạy game Blackjack
    BlackjackGame blackjack;
    blackjack.start();

    // Sau khi chơi xong, quay lại menu
    currentState = GameState::MAIN_MENU;
}

void GameManager::startChess() {
    // Khởi tạo và chạy game Cờ Vua
    ChessGame chess;
    chess.start();

    // Sau khi chơi xong, quay lại menu
    currentState = GameState::MAIN_MENU;
}