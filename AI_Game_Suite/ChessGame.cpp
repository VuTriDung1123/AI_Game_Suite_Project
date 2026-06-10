#include "ChessGame.h"
#include <iostream>

ChessGame::ChessGame() {
    // Khởi tạo bàn cờ 8x8 nếu cần
}

void ChessGame::start() {
    std::cout << "\n========================================\n";
    std::cout << "        CHAO MUNG DEN VOI CHESS         \n";
    std::cout << "========================================\n";
    std::cout << "[Core Logic] Dang khoi tao ban co 8x8...\n";

    // TODO: Viết vòng lặp game Cờ vua ở đây

    std::cout << "Nhan Enter de quay lai Menu chinh...";
    std::cin.ignore(32767, '\n');
    std::cin.get();
}