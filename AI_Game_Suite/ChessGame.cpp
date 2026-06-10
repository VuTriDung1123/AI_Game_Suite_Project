#include "ChessGame.h"
#include <iostream>

// --- PIECES LOGIC ---
bool Pawn::isValidMove(int startX, int startY, int endX, int endY, const ChessBoard& board) const {
    // TODO: Viết logic đi thẳng, ăn chéo của quân Tốt tại đây
    return true; // Tạm thời cho phép mọi nước đi để test vòng lặp
}

// --- CHESSBOARD ---
ChessBoard::ChessBoard() { setupBoard(); }

void ChessBoard::setupBoard() {
    // Khởi tạo bàn cờ trống
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            grid[i][j] = std::make_unique<EmptyPiece>();

    // Đặt Tốt (Pawns)
    for (int j = 0; j < 8; ++j) {
        grid[1][j] = std::make_unique<Pawn>(PieceColor::BLACK);
        grid[6][j] = std::make_unique<Pawn>(PieceColor::WHITE);
    }
    // TODO: Đặt các quân cờ khác (Xe, Mã, Tượng...) vào đúng vị trí grid[0] và grid[7]
}

void ChessBoard::printBoard() const {
    std::cout << "\n  a b c d e f g h\n";
    for (int i = 0; i < 8; ++i) {
        std::cout << 8 - i << " ";
        for (int j = 0; j < 8; ++j) {
            std::cout << grid[i][j]->getSymbol() << " ";
        }
        std::cout << 8 - i << "\n";
    }
    std::cout << "  a b c d e f g h\n\n";
}

bool ChessBoard::movePiece(int startX, int startY, int endX, int endY) {
    if (grid[startX][startY]->type == PieceType::EMPTY) return false;

    // Gọi tính đa hình: Tự động dùng luật di chuyển của quân cờ tương ứng
    if (grid[startX][startY]->isValidMove(startX, startY, endX, endY, *this)) {
        grid[endX][endY] = std::move(grid[startX][startY]); // Di chuyển vùng nhớ
        grid[startX][startY] = std::make_unique<EmptyPiece>(); // Để lại ô trống
        return true;
    }
    return false;
}

// --- CHESS GAME LOGIC ---
ChessGame::ChessGame() : currentTurn(PieceColor::WHITE) {}

void ChessGame::start() {
    bool playing = true;
    while (playing) {
        board.printBoard();
        std::string turnStr = (currentTurn == PieceColor::WHITE) ? "Trang (In Hoa)" : "Den (Chữ Thường)";
        std::cout << "Luot cua " << turnStr << ". Nhap toa do (VD: 6 0 5 0 de di chuyen Tot tu a2 len a3), hoac -1 de thoat: ";

        int r1, c1, r2, c2;
        std::cin >> r1;
        if (r1 == -1) break;
        std::cin >> c1 >> r2 >> c2;

        if (board.movePiece(r1, c1, r2, c2)) {
            // Chuyển lượt
            currentTurn = (currentTurn == PieceColor::WHITE) ? PieceColor::BLACK : PieceColor::WHITE;
        }
        else {
            std::cout << "Nuoc di khong hop le!\n";
        }
    }
}