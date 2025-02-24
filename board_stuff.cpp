#include"vars.h"

//add pieces to associated vectors for later looping through objects
void defaultVectors()
{
	//add references to black pieces in a vector
	bPiece.push_back(&pawn1);
	bPiece.push_back(&pawn2);
	bPiece.push_back(&pawn3);
	bPiece.push_back(&pawn4);
	bPiece.push_back(&pawn5);
	bPiece.push_back(&pawn6);
	bPiece.push_back(&pawn7);
	bPiece.push_back(&pawn8);
	bPiece.push_back(&rook1);
	bPiece.push_back(&rook2);
	bPiece.push_back(&bishop1);
	bPiece.push_back(&bishop2);
	bPiece.push_back(&horse1);
	bPiece.push_back(&horse2);
	bPiece.push_back(&queen);
	bPiece.push_back(&king);

	//add references to white pieces in a vector
	wPiece.push_back(&wpawn1);
	wPiece.push_back(&wpawn2);
	wPiece.push_back(&wpawn3);
	wPiece.push_back(&wpawn4);
	wPiece.push_back(&wpawn5);
	wPiece.push_back(&wpawn6);
	wPiece.push_back(&wpawn7);
	wPiece.push_back(&wpawn8);
	wPiece.push_back(&wrook1);
	wPiece.push_back(&wrook2);
	wPiece.push_back(&wbishop1);
	wPiece.push_back(&wbishop2);
	wPiece.push_back(&whorse1);
	wPiece.push_back(&whorse2);
	wPiece.push_back(&wqueen);
	wPiece.push_back(&wking);
}

//displays the current board
void drawBoard()
{
	system("cls");

	//your board
	std::cout << "       0      1      2      3      4      5      6      7             killed black pieces        killed white pieces" << std::endl << std::endl;
	std::cout << "    " << whiteTile << "    " << "   " << whiteTile << "   " << "    " << whiteTile << "   " << "    " << whiteTile << "   " << "                  " << whiteTile << "       " << "             " << whiteTile << std::endl;
	std::cout << " 0 " << " " << "\033[100;47;10m   \033[0m" << board[0][0] << "\033[100;47;10m   \033[0m" << "   " << board[0][1] << "   " << "\033[100;47;10m   \033[0m" << board[0][2] << "\033[100;47;10m   \033[0m" << "   " << board[0][3] << "   " << "\033[100;47;10m   \033[0m" << board[0][4] << "\033[100;47;10m   \033[0m" << "   " << board[0][5] << "   " << "\033[100;47;10m   \033[0m" << board[0][6] << "\033[100;47;10m   \033[0m" << "   " << board[0][7] << "              1  " << "\033[100;47;10m   \033[0m" << board[0][8] << "\033[100;47;10m   \033[0m" << "   " << board[0][9] << "   " << "          1  " << "\033[100;47;10m   \033[0m" << board[0][10] << "\033[100;47;10m   \033[0m" << "   " << board[0][11] << std::endl;
	std::cout << "    " << whiteTile << "    " << "   " << whiteTile << "    " << "   " << whiteTile << "    " << "   " << whiteTile << "    " << "                 " << whiteTile << "       " "             " << whiteTile << std::endl;
	std::cout << "    " << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "                     " << whiteTile << "             " << "       " << whiteTile << std::endl;
	std::cout << " 1 " << "    " << board[1][0] << "   " << "\033[100;47;10m   \033[0m" << board[1][1] << "\033[100;47;10m   \033[0m" << "   " << board[1][2] << "   " << "\033[100;47;10m   \033[0m" << board[1][3] << "\033[100;47;10m   \033[0m" << "   " << board[1][4] << "   " << "\033[100;47;10m   \033[0m" << board[1][5] << "\033[100;47;10m   \033[0m" << "   " << board[1][6] << "   " << "\033[100;47;10m   \033[0m" << board[1][7] << "\033[100;47;10m   \033[0m" << "           2  " << "   " << board[1][8] << "   " << "\033[100;47;10m   \033[0m" << board[1][9] << "\033[100;47;10m   \033[0m" << "          2  " << "   " << board[1][10] << "   " << "\033[100;47;10m   \033[0m" << board[1][11] << "\033[100;47;10m   \033[0m" << std::endl;
	std::cout << "         " << "  " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "                     " << whiteTile << "             " << "       " << whiteTile << std::endl;
	std::cout << "    " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << "              " << whiteTile << "       " << "             " << whiteTile << std::endl;
	std::cout << " 2 " << " " << "\033[100;47;10m   \033[0m" << board[2][0] << "\033[100;47;10m   \033[0m" << "   " << board[2][1] << "   " << "\033[100;47;10m   \033[0m" << board[2][2] << "\033[100;47;10m   \033[0m" << "   " << board[2][3] << "   " << "\033[100;47;10m   \033[0m" << board[2][4] << "\033[100;47;10m   \033[0m" << "   " << board[2][5] << "   " << "\033[100;47;10m   \033[0m" << board[2][6] << "\033[100;47;10m   \033[0m" << "   " << board[2][7] << "              3  " << "\033[100;47;10m   \033[0m" << board[2][8] << "\033[100;47;10m   \033[0m" << "   " << board[2][9] << "   " << "          3  " << "\033[100;47;10m   \033[0m" << board[2][10] << "\033[100;47;10m   \033[0m" << "   " << board[2][11] << std::endl;
	std::cout << "    " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << "              " << whiteTile << "       " << "             " << whiteTile << std::endl;
	std::cout << "         " << "  " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "                     " << whiteTile << "             " << "       " << whiteTile << std::endl;
	std::cout << " 3 " << "    " << board[3][0] << "   " << "\033[100;47;10m   \033[0m" << board[3][1] << "\033[100;47;10m   \033[0m" << "   " << board[3][2] << "   " << "\033[100;47;10m   \033[0m" << board[3][3] << "\033[100;47;10m   \033[0m" << "   " << board[3][4] << "   " << "\033[100;47;10m   \033[0m" << board[3][5] << "\033[100;47;10m   \033[0m" << "   " << board[3][6] << "   " << "\033[100;47;10m   \033[0m" << board[3][7] << "\033[100;47;10m   \033[0m" << "           4  " << "   " << board[3][8] << "   " << "\033[100;47;10m   \033[0m" << board[3][9] << "\033[100;47;10m   \033[0m" << "          4  " << "   " << board[3][10] << "   " << "\033[100;47;10m   \033[0m" << board[3][11] << "\033[100;47;10m   \033[0m" << std::endl;
	std::cout << "           " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "                     " << whiteTile << "             " << "       " << whiteTile << std::endl;
	std::cout << "    " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << "              " << whiteTile << "       " << "             " << whiteTile << std::endl;
	std::cout << " 4 " << " " << "\033[100;47;10m   \033[0m" << board[4][0] << "\033[100;47;10m   \033[0m" << "   " << board[4][1] << "   " << "\033[100;47;10m   \033[0m" << board[4][2] << "\033[100;47;10m   \033[0m" << "   " << board[4][3] << "   " << "\033[100;47;10m   \033[0m" << board[4][4] << "\033[100;47;10m   \033[0m" << "   " << board[4][5] << "   " << "\033[100;47;10m   \033[0m" << board[4][6] << "\033[100;47;10m   \033[0m" << "   " << board[4][7] << "   " << "           5  " << "\033[100;47;10m   \033[0m" << board[4][8] << "\033[100;47;10m   \033[0m" << "   " << board[4][9] << "   " << "          5  " << "\033[100;47;10m   \033[0m" << board[4][10] << "\033[100;47;10m   \033[0m" << "   " << board[4][11] << "   " << std::endl;
	std::cout << "    " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << "              " << whiteTile << "       " << "             " << whiteTile << std::endl;
	std::cout << "         " << "  " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "                     " << whiteTile << "             " << "       " << whiteTile << std::endl;
	std::cout << " 5 " << "    " << board[5][0] << "   " << "\033[100;47;10m   \033[0m" << board[5][1] << "\033[100;47;10m   \033[0m" << "   " << board[5][2] << "   " << "\033[100;47;10m   \033[0m" << board[5][3] << "\033[100;47;10m   \033[0m" << "   " << board[5][4] << "   " << "\033[100;47;10m   \033[0m" << board[5][5] << "\033[100;47;10m   \033[0m" << "   " << board[5][6] << "   " << "\033[100;47;10m   \033[0m" << board[5][7] << "\033[100;47;10m   \033[0m" << "           6  " << "   " << board[5][8] << "   " << "\033[100;47;10m   \033[0m" << board[5][9] << "\033[100;47;10m   \033[0m" << "          6  " << "   " << board[5][10] << "   " << "\033[100;47;10m   \033[0m" << board[5][11] << "\033[100;47;10m   \033[0m" << std::endl;
	std::cout << "         " << "  " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "                     " << whiteTile << "             " << "       " << whiteTile << std::endl;
	std::cout << "    " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << "              " << whiteTile << "       " << "             " << whiteTile << std::endl;
	std::cout << " 6 " << " " << "\033[100;47;10m   \033[0m" << board[6][0] << "\033[100;47;10m   \033[0m" << "   " << board[6][1] << "   " << "\033[100;47;10m   \033[0m" << board[6][2] << "\033[100;47;10m   \033[0m" << "   " << board[6][3] << "   " << "\033[100;47;10m   \033[0m" << board[6][4] << "\033[100;47;10m   \033[0m" << "   " << board[6][5] << "   " << "\033[100;47;10m   \033[0m" << board[6][6] << "\033[100;47;10m   \033[0m" << "   " << board[6][7] << "   " << "           7  " << "\033[100;47;10m   \033[0m" << board[6][8] << "\033[100;47;10m   \033[0m" << "   " << board[6][9] << "   " << "          7  " << "\033[100;47;10m   \033[0m" << board[6][10] << "\033[100;47;10m   \033[0m" << "   " << board[6][11] << std::endl;
	std::cout << "    " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << "              " << whiteTile << "       " << "             " << whiteTile << std::endl;
	std::cout << "         " << "  " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "                     " << whiteTile << "             " << "       " << whiteTile << std::endl;
	std::cout << " 7 " << "    " << board[7][0] << "   " << "\033[100;47;10m   \033[0m" << board[7][1] << "\033[100;47;10m   \033[0m" << "   " << board[7][2] << "   " << "\033[100;47;10m   \033[0m" << board[7][3] << "\033[100;47;10m   \033[0m" << "   " << board[7][4] << "   " << "\033[100;47;10m   \033[0m" << board[7][5] << "\033[100;47;10m   \033[0m" << "   " << board[7][6] << "   " << "\033[100;47;10m   \033[0m" << board[7][7] << "\033[100;47;10m   \033[0m" << "           8  " << "   " << board[7][8] << "   " << "\033[100;47;10m   \033[0m" << board[7][9] << "\033[100;47;10m   \033[0m" << "          8  " << "   " << board[7][10] << "   " << "\033[100;47;10m   \033[0m" << board[7][11] << "\033[100;47;10m   \033[0m" << std::endl;
	std::cout << "         " << "  " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "                     " << whiteTile << "             " << "       " << whiteTile << std::endl;
}

//displays new piece position
void col(int selecty, int selectx, int curry, int currx, int piece)
{
	if ((selectx % 2 == 0 && selecty % 2 == 0) || (selectx % 2 == 1 && selecty % 2 == 1))
	{
		board[selecty][selectx] = "\033[100;47;10m \033[0m";
	}
	else
	{
		board[selecty][selectx] = " ";
	}

	switch (piece)
	{
		//black pieces
	case PAWN:
		if ((currx % 2 == 0 && curry % 2 == 0) || (currx % 2 == 1 && curry % 2 == 1))
		{
			board[curry][currx] = blackPawnCol;
			break;
		}
		board[curry][currx] = "\033[10;1;30mP\033[0m";
		break;
	case ROOK:
		if ((currx % 2 == 0 && curry % 2 == 0) || (currx % 2 == 1 && curry % 2 == 1))
		{
			board[curry][currx] = blackRookCol;
			break;
		}
		board[curry][currx] = "\033[10;1;30mR\033[0m";
		break;
	case BISHOP:
		if ((currx % 2 == 0 && curry % 2 == 0) || (currx % 2 == 1 && curry % 2 == 1))
		{
			board[curry][currx] = blackBishopCol;
			break;
		}
		board[curry][currx] = "\033[10;1;30mB\033[0m";
		break;
	case HORSE:
		if ((currx % 2 == 0 && curry % 2 == 0) || (currx % 2 == 1 && curry % 2 == 1))
		{
			board[curry][currx] = blackHorseCol;
			break;
		}
		board[curry][currx] = "\033[10;1;30mH\033[0m";
		break;
	case QUEEN:
		if ((currx % 2 == 0 && curry % 2 == 0) || (currx % 2 == 1 && curry % 2 == 1))
		{
			board[curry][currx] = blackQueenCol;
			break;
		}
		board[curry][currx] = "\033[10;1;30mQ\033[0m";
		break;
	case KING:
		if ((currx % 2 == 0 && curry % 2 == 0) || (currx % 2 == 1 && curry % 2 == 1))
		{
			board[curry][currx] = blackKingCol;
			break;
		}
		board[curry][currx] = "\033[10;1;30mK\033[0m";
		break;

		//white pieces
	case PAWN + 6:
		if ((currx % 2 == 0 && curry % 2 == 0) || (currx % 2 == 1 && curry % 2 == 1))
		{
			board[curry][currx] = whitePawnCol;
			break;
		}
		board[curry][currx] = "\x1B[93mP\033[0m";
		break;
	case ROOK + 6:
		if ((currx % 2 == 0 && curry % 2 == 0) || (currx % 2 == 1 && curry % 2 == 1))
		{
			board[curry][currx] = whiteRookCol;
			break;
		}
		board[curry][currx] = "\x1B[93mR\033[0m";
		break;
	case BISHOP + 6:
		if ((currx % 2 == 0 && curry % 2 == 0) || (currx % 2 == 1 && curry % 2 == 1))
		{
			board[curry][currx] = whiteBishopCol;
			break;
		}
		board[curry][currx] = "\x1B[93mB\033[0m";
		break;
	case HORSE + 6:
		if ((currx % 2 == 0 && curry % 2 == 0) || (currx % 2 == 1 && curry % 2 == 1))
		{
			board[curry][currx] = whiteHorseCol;
			break;
		}
		board[curry][currx] = "\x1B[93mH\033[0m";
		break;
	case QUEEN + 6:
		if ((currx % 2 == 0 && curry % 2 == 0) || (currx % 2 == 1 && curry % 2 == 1))
		{
			board[curry][currx] = whiteQueenCol;
			break;
		}
		board[curry][currx] = "\x1B[93mQ\033[0m";
		break;
	case KING + 6:
		if ((currx % 2 == 0 && curry % 2 == 0) || (currx % 2 == 1 && curry % 2 == 1))
		{
			board[curry][currx] = whiteKingCol;
			break;
		}
		board[curry][currx] = "\x1B[93mK\033[0m";
		break;
	default:
		break;
	}
}