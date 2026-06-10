#include "BlackjackGame.h"
#include <iostream>

BlackjackGame::BlackjackGame() {
    // Khởi tạo các thông số cơ bản nếu cần
}

void BlackjackGame::start() {
    std::cout << "\n========================================\n";
    std::cout << "      CHAO MUNG DEN VOI BLACKJACK       \n";
    std::cout << "========================================\n";
    std::cout << "[Core Logic] Dang khoi tao bo bai 52 la...\n";

    // TODO: Viết vòng lặp game Blackjack ở đây

    std::cout << "Nhan Enter de quay lai Menu chinh...";
    std::cin.ignore(32767, '\n');
    std::cin.get();
}