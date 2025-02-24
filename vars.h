#pragma once
#include<iostream>
#include<string>
#include<vector>

//special variable, and replaces doing macros bc it is a precompiled constant
//because it is processed before runtime, it is more efficient to your program
//enum of consts for more readable code
enum pieceType : const int
{
	PAWN = 1, ROOK, HORSE, BISHOP, QUEEN, KING
};

extern int turn;
extern int win;
extern int bDead;
extern int wDead;

extern std::string blackPawnCol;
extern std::string blackRookCol;
extern std::string blackBishopCol;
extern std::string blackHorseCol;
extern std::string blackQueenCol;
extern std::string blackKingCol;

extern std::string whitePawnCol;
extern std::string whiteRookCol;
extern std::string whiteBishopCol;
extern std::string whiteHorseCol;
extern std::string whiteQueenCol;
extern std::string whiteKingCol;

extern std::string whiteTile;

extern std::string board[8][12];

class bPieces
{
public:
	int death;
	int movesMade;
	int x;
	int y;
	int check;
	int piece;
	int enPassantCnt;
	bPieces();
	bPieces(int X, int Y, int typePiece);
	void piecePlacement(int X, int Y, int typePiece);
	void dead(int numDead);
};
extern bPieces pawn1, pawn2, pawn3, pawn4, pawn5, pawn6, pawn7, pawn8, rook1, rook2, bishop1, bishop2, horse1, horse2, queen, king;

extern std::vector<bPieces*> bPiece;

class wPieces
{
public:
	int death;
	int movesMade;
	int x;
	int y;
	int check;
	int piece;
	int enPassantCnt;
	wPieces();
	wPieces(int X, int Y, int typePiece);
	void piecePlacement(int X, int Y, int typePiece);
	void dead(int numDead);
};
extern wPieces wpawn1, wpawn2, wpawn3, wpawn4, wpawn5, wpawn6, wpawn7, wpawn8, wrook1, wrook2, wbishop1, wbishop2, whorse1, whorse2, wqueen, wking;

extern std::vector<wPieces*> wPiece;

void defaultVectors();
void drawBoard();
void col(int selecty, int selectx, int curry, int currx, int piece);
void check();
int locAlg(int wx, int wy, int chngx, int chngy);
void checkmate();
void stalemate();
void newGame();
void save(std::string file);
void load(std::string file);
void saveSlot(std::string command);
void bMove();
void wMove();