#pragma once
#include <vector>
#include <memory>
#include <string>

enum class PieceColor { WHITE, BLACK, NONE };
enum class PieceType { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING, EMPTY };

class Piece {
public:
    PieceColor color;
    PieceType type;
    Piece(PieceColor c, PieceType t) : color(c), type(t) {}
    virtual ~Piece() = default;
    virtual char getSymbol() const = 0;
    // Hàm cốt lõi sẽ được overwrite bởi từng loại quân (Tốt, Xe, Mã...)
    virtual bool isValidMove(int startX, int startY, int endX, int endY, const class ChessBoard& board) const = 0;
};

class EmptyPiece : public Piece {
public:
    EmptyPiece() : Piece(PieceColor::NONE, PieceType::EMPTY) {}
    char getSymbol() const override { return '.'; }
    bool isValidMove(int, int, int, int, const ChessBoard&) const override { return false; }
};

class Pawn : public Piece {
public:
    Pawn(PieceColor c) : Piece(c, PieceType::PAWN) {}
    char getSymbol() const override { return color == PieceColor::WHITE ? 'P' : 'p'; }
    bool isValidMove(int startX, int startY, int endX, int endY, const ChessBoard& board) const override;
};
// TODO: Tạo thêm class cho Rook, Knight, Bishop, Queen, King tương tự như Pawn

class ChessBoard {
public:
    std::unique_ptr<Piece> grid[8][8]; // Sử dụng smart pointer tránh memory leak
    ChessBoard();
    void setupBoard();
    void printBoard() const;
    bool movePiece(int startX, int startY, int endX, int endY);
};

class ChessGame {
private:
    ChessBoard board;
    PieceColor currentTurn;
public:
    ChessGame();
    void start();
};