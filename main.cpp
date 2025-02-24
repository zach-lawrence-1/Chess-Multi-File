#include"vars.h"

int turn = 0;
int win = 0;
int bDead = 0;
int wDead = 0;

std::string blackPawnCol = "\033[100;47;30mP\033[0m";
std::string blackRookCol = "\033[100;47;30mR\033[0m";
std::string blackBishopCol = "\033[100;47;30mB\033[0m";
std::string blackHorseCol = "\033[100;47;30mH\033[0m";
std::string blackQueenCol = "\033[100;47;30mQ\033[0m";
std::string blackKingCol = "\033[100;47;30mK\033[0m";

std::string whitePawnCol = "\033[100;47;93mP\033[0m";
std::string whiteRookCol = "\033[100;47;93mR\033[0m";
std::string whiteBishopCol = "\033[100;47;93mB\033[0m";
std::string whiteHorseCol = "\033[100;47;93mH\033[0m";
std::string whiteQueenCol = "\033[100;47;93mQ\033[0m";
std::string whiteKingCol = "\033[100;47;93mK\033[0m";

std::string whiteTile = "\033[100;47;10m       \033[0m";

std::string board[8][12] = {
	{"\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m"," ", "\033[100;47;10m \033[0m", " "},   // row 1
	{" ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m"},   // row 2
	{"\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m"," ", "\033[100;47;10m \033[0m", " "},   // row 3
	{" ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m"},   // row 4
	{"\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m"," ", "\033[100;47;10m \033[0m", " "},   // row 5
	{" ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m"},   // row 6
	{"\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m"," ", "\033[100;47;10m \033[0m", " "},   // row 7
	{" ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m"}	  // row 8
};

bPieces pawn1(0, 6, PAWN), pawn2(1, 6, PAWN), pawn3(2, 6, PAWN), pawn4(3, 6, PAWN), pawn5(4, 6, PAWN),
pawn6(5, 6, PAWN), pawn7(6, 6, PAWN), pawn8(7, 6, PAWN), rook1(0, 7, ROOK), rook2(7, 7, ROOK),
bishop1(2, 7, BISHOP), bishop2(5, 7, BISHOP), horse1(1, 7, HORSE), horse2(6, 7, HORSE), queen(4, 7, QUEEN),
king(3, 7, KING);

bPieces::bPieces()
{}

void bPieces::piecePlacement(int X, int Y, int typePiece)
{
	x = X;
	y = Y;
	piece = typePiece;
	death = 0;
	movesMade = 0;
	check = 0;
	enPassantCnt = 0;
	switch (typePiece)
	{
	case PAWN:
		//displays white background with piece if both x and y are even coordinates because
		//of the alternating pattern of the board
		if ((X % 2 == 0 && Y % 2 == 0) || (X % 2 == 1 && Y % 2 == 1))
		{
			board[Y][X] = blackPawnCol;
			break;
		}
		board[Y][X] = "\033[10;1;30mP\033[0m";
		break;
	case ROOK:
		if ((X % 2 == 0 && Y % 2 == 0) || (X % 2 == 1 && Y % 2 == 1))
		{
			board[Y][X] = blackRookCol;
			break;
		}
		board[Y][X] = "\033[10;1;30mR\033[0m";
		break;
	case BISHOP:
		if ((X % 2 == 0 && Y % 2 == 0) || (X % 2 == 1 && Y % 2 == 1))
		{
			board[Y][X] = blackBishopCol;
			break;
		}
		board[Y][X] = "\033[10;1;30mB\033[0m";
		break;
	case HORSE:
		if ((X % 2 == 0 && Y % 2 == 0) || (X % 2 == 1 && Y % 2 == 1))
		{
			board[Y][X] = blackHorseCol;
			break;
		}
		board[Y][X] = "\033[10;1;30mH\033[0m";
		break;
	case QUEEN:
		if ((X % 2 == 0 && Y % 2 == 0) || (X % 2 == 1 && Y % 2 == 1))
		{
			board[Y][X] = blackQueenCol;
			break;
		}
		board[Y][X] = "\033[10;1;30mQ\033[0m";
		break;
	case KING:
		if ((X % 2 == 0 && Y % 2 == 0) || (X % 2 == 1 && Y % 2 == 1))
		{
			board[Y][X] = blackKingCol;
			break;
		}
		board[Y][X] = "\033[10;1;30mK\033[0m";
		break;
	default:
		break;
	}
}

bPieces::bPieces(int X, int Y, int typePiece)
{
	piecePlacement(X, Y, typePiece);
}

void bPieces::dead(int numDead)
	{
	if (death == 1)
	{
		if (numDead < 9)
		{
			if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
			{
				board[y][x] = "\033[100;47;10m \033[0m";
			}
			else
			{
				board[y][x] = " ";
			}
			x = 8;
			y = 8 - numDead;

			switch (piece)
			{
			case PAWN:
				if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
				{
					board[y][x] = blackPawnCol;
					return;
				}
				board[y][x] = "\033[10;1;30mP\033[0m";
				break;
			case ROOK:
				if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
				{
					board[y][x] = blackRookCol;
					return;
				}
				board[y][x] = "\033[10;1;30mR\033[0m";
				break;
			case HORSE:
				if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
				{
					board[y][x] = blackHorseCol;
					return;
				}
				board[y][x] = "\033[10;1;30mH\033[0m";
				break;
			case BISHOP:
				if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
				{
					board[y][x] = blackBishopCol;
					return;
				}
				board[y][x] = "\033[10;1;30mB\033[0m";
				break;
			case QUEEN:
				if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
				{
					board[y][x] = blackQueenCol;
					return;
				}
				board[y][x] = "\033[10;1;30mQ\033[0m";
				break;
			default:
				break;
			}
		}
		if (numDead > 8)
		{
			if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
			{
				board[y][x] = "\033[100;47;10m \033[0m";
			}
			else
			{
				board[y][x] = " ";
			}
			x = 9;
			y = 16 - numDead;

			switch (piece)
			{
			case PAWN:
				if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
				{
					board[y][x] = blackPawnCol;
					return;
				}
				board[y][x] = "\033[10;1;30mP\033[0m";
				break;
			case ROOK:
				if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
				{
					board[y][x] = blackRookCol;
					return;
				}
				board[y][x] = "\033[10;1;30mR\033[0m";
				break;
			case HORSE:
				if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
				{
					board[y][x] = blackHorseCol;
					return;
				}
				board[y][x] = "\033[10;1;30mH\033[0m";
				break;
			case BISHOP:
				if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
				{
					board[y][x] = blackBishopCol;
					return;
				}
				board[y][x] = "\033[10;1;30mB\033[0m";
				break;
			case QUEEN:
				if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
				{
					board[y][x] = blackQueenCol;
					return;
				}
				board[y][x] = "\033[10;1;30mQ\033[0m";
				break;
			default:
				break;
			}
		}
	}
	}

std::vector<bPieces*> bPiece;

wPieces::wPieces()
{}

void wPieces::piecePlacement(int X, int Y, int typePiece)
{
	x = X;
	y = Y;
	piece = typePiece;
	death = 0;
	movesMade = 0;
	check = 0;
	enPassantCnt = 0;
	switch (typePiece)
	{
	case PAWN:
		if ((X % 2 == 0 && Y % 2 == 0) || (X % 2 == 1 && Y % 2 == 1))
		{
			board[Y][X] = whitePawnCol;
			break;
		}
		board[Y][X] = "\x1B[93mP\033[0m";
		break;
	case ROOK:
		if ((X % 2 == 0 && Y % 2 == 0) || (X % 2 == 1 && Y % 2 == 1))
		{
			board[Y][X] = whiteRookCol;
			break;
		}
		board[Y][X] = "\x1B[93mR\033[0m";
		break;
	case BISHOP:
		if ((X % 2 == 0 && Y % 2 == 0) || (X % 2 == 1 && Y % 2 == 1))
		{
			board[Y][X] = whiteBishopCol;
			break;
		}
		board[Y][X] = "\x1B[93mB\033[0m";
		break;
	case HORSE:
		if ((X % 2 == 0 && Y % 2 == 0) || (X % 2 == 1 && Y % 2 == 1))
		{
			board[Y][X] = whiteHorseCol;
			break;
		}
		board[Y][X] = "\x1B[93mH\033[0m";
		break;
	case QUEEN:
		if ((X % 2 == 0 && Y % 2 == 0) || (X % 2 == 1 && Y % 2 == 1))
		{
			board[Y][X] = whiteQueenCol;
			break;
		}
		board[Y][X] = "\x1B[93mQ\033[0m";
		break;
	case KING:
		if ((X % 2 == 0 && Y % 2 == 0) || (X % 2 == 1 && Y % 2 == 1))
		{
			board[Y][X] = whiteKingCol;
			break;
		}
		board[Y][X] = "\x1B[93mK\033[0m";
		break;
	default:
		break;
	}
}

wPieces::wPieces(int X, int Y, int typePiece)
{
	piecePlacement(X, Y, typePiece);
}

void wPieces::dead(int numDead)
	{
		if (death == 1)
	{
		if (numDead < 9)
		{
			if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
			{
				board[y][x] = "\033[100;47;10m \033[0m";
			}
			else
			{
				board[y][x] = " ";
			}
			x = 10;
			y = 8 - numDead;

			switch (piece)
			{
			case PAWN:
				if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
				{
					board[y][x] = whitePawnCol;
					return;
				}
				board[y][x] = "\x1B[93mP\033[0m";
				break;
			case ROOK:
				if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
				{
					board[y][x] = whiteRookCol;
					return;
				}
				board[y][x] = "\x1B[93mR\033[0m";
				break;
			case HORSE:
				if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
				{
					board[y][x] = whiteHorseCol;
					return;
				}
				board[y][x] = "\x1B[93mH\033[0m";
				break;
			case BISHOP:
				if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
				{
					board[y][x] = whiteBishopCol;
					return;
				}
				board[y][x] = "\x1B[93mB\033[0m";
				break;
			case QUEEN:
				if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
				{
					board[y][x] = whiteQueenCol;
					return;
				}
				board[y][x] = "\x1B[93mP\033[0m";
				break;
			default:
				break;
			}
		}
		if (numDead > 8)
		{
			if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
			{
				board[y][x] = "\033[100;47;10m \033[0m";
			}
			else
			{
				board[y][x] = " ";
			}
			x = 11;
			y = 16 - numDead;

			switch (piece)
			{
			case PAWN:
				if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
				{
					board[y][x] = whitePawnCol;
					return;
				}
				board[y][x] = "\x1B[93mP\033[0m";
				break;
			case ROOK:
				if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
				{
					board[y][x] = whiteRookCol;
					return;
				}
				board[y][x] = "\x1B[93mR\033[0m";
				break;
			case HORSE:
				if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
				{
					board[y][x] = whiteHorseCol;
					return;
				}
				board[y][x] = "\x1B[93mH\033[0m";
				break;
			case BISHOP:
				if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
				{
					board[y][x] = whiteBishopCol;
					return;
				}
				board[y][x] = "\x1B[93mB\033[0m";
				break;
			case QUEEN:
				if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
				{
					board[y][x] = whiteQueenCol;
					return;
				}
				board[y][x] = "\x1B[93mP\033[0m";
				break;
			default:
				break;
			}
		}
	}
	}

wPieces wpawn1(0, 1, PAWN), wpawn2(1, 1, PAWN), wpawn3(2, 1, PAWN), wpawn4(3, 1, PAWN), wpawn5(4, 1, PAWN),
wpawn6(5, 1, PAWN), wpawn7(6, 1, PAWN), wpawn8(7, 1, PAWN), wrook1(0, 0, ROOK), wrook2(7, 0, ROOK),
wbishop1(2, 0, BISHOP), wbishop2(5, 0, BISHOP), whorse1(1, 0, HORSE), whorse2(6, 0, HORSE), wqueen(4, 0, QUEEN),
wking(3, 0, KING);

std::vector<wPieces*> wPiece;

int main()
{
	defaultVectors();
	drawBoard();

	while (true)
		switch (win)
		{
		case 0:
			if (turn == 0)
			{
				bMove();
			}
			else
			{
				wMove();
			}
			break;
		case 1:
			drawBoard();
			std::cout << "black wins" << std::endl;
			return 0;
		case 2:
			drawBoard();
			std::cout << "white wins" << std::endl;
			return 0;
		case 3:
			drawBoard();
			std::cout << "draw white can't move" << std::endl;
			return 0;
		case 4:
			drawBoard();
			std::cout << "draw black can't move" << std::endl;
			return 0;
		default:
			drawBoard();
			std::cout << "stalemate" << std::endl;
			return 0;
		}
}