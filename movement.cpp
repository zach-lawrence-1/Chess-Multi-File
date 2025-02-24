#include"vars.h"

//moves black pieces
void bMove()
{
	if (win == 0)
	{
		int snum = 0;
		int valid = 0;
		int currx = 0;
		int curry = 0;
		std::string select = "";
		int selectx = 0;
		int selecty = 0;

		std::cout << "To operate a command, type N for newgame, D to delete a previous save, L for loading a previous save, Q for quitting," << std::endl << "or S to save the current game\n";
		std::cout << "Black's turn: select a piece ";

		//get selection piece or command
		std::cin >> select;
		//for loading commands
		try {
			//on number entry sets selectx to converted string select to int
			selectx = std::stoi(select);
		}
		catch (const std::invalid_argument& ia) {
			//fails conversion and checks if valid command entered
			if (select == "L")
			{
				saveSlot("L");
				return;
			}
			if (select == "S")
			{
				saveSlot("S");
				return;
			}
			if (select == "D")
			{
				saveSlot("D");
				return;
			}
			if (select == "N")
			{
				newGame();
				std::cout << "new game loaded" << std::endl;
				return;
			}
			if (select == "Q")
			{
				exit(0);
			}
			drawBoard();
			std::cout << "invalid command" << std::endl;
			bMove();
			return;
		}
		std::cin >> selecty;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			drawBoard();
			std::cout << "cannot enter letter values" << std::endl;
			bMove();
			return;
		}

		if (selectx > 7 || selecty > 7)
		{
			std::cin.clear();
			std::cin.ignore();
			drawBoard();
			std::cout << "out of chess bounds" << std::endl;
			bMove();
			return;
		}

		if (selectx < 0 || selecty < 0)
		{
			std::cin.clear();
			std::cin.ignore();
			drawBoard();
			std::cout << "out of chess bounds" << std::endl;
			bMove();
			return;
		}

		for (auto& b : bPiece)
		{
			if (selectx == b->x && selecty == b->y)
			{
				snum++;
				//get selection piece
				std::cin >> currx;
				std::cin >> curry;

				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore();
					drawBoard();
					std::cout << "cannot enter letter values" << std::endl;
					bMove();
					return;
				}

				if (currx > 7 || curry > 7)
				{
					std::cin.clear();
					std::cin.ignore();
					drawBoard();
					std::cout << "out of chess bounds" << std::endl;
					bMove();
					return;
				}

				if (currx < 0 || curry < 0)
				{
					std::cin.clear();
					std::cin.ignore();
					drawBoard();
					std::cout << "out of chess bounds" << std::endl;
					bMove();
					return;
				}

				//check moves for pawn
				if (b->piece == PAWN)
				{
					//moves forward 1
					if (currx == selectx && curry == selecty - 1)
					{
						valid = 1;
					}

					//moves forward 2
					if (b->movesMade == 0)
					{
						if (currx == selectx && curry == selecty - 2)
						{
							valid = 1;
							for (auto& b1 : bPiece)
							{
								if (currx == b1->x && b1->y == curry + 1)
								{
									valid = 0;
								}
								if (b1->x == currx && b1->y == curry)
								{
									valid = 0;
								}
							}
							for (auto& w : wPiece)
							{
								if (currx == w->x && w->y == curry + 1)
								{
									valid = 0;
								}
								if (w->x == currx && w->y == curry)
								{
									valid = 0;
								}
							}

							if (valid == 1)
							{
								check();
								if (king.check == 1)
								{
									drawBoard();
									std::cout << "Black is in check" << std::endl;
									bMove();
									return;
								}
								for (auto& w : wPiece)
								{
									if (w->piece == PAWN)
									{
										if (w->y == curry && (w->x == currx - 1 || w->x == currx + 1))
										{
											std::cout << "black en passant is active";
											int g;
											b->enPassantCnt = 1;
											std::cin >> g;
										}
									}
								}
							}
						}
					}

					for (auto& w : wPiece)
					{
						if (w->x == currx && w->y == curry)
						{
							valid = 0;
						}
					}

					if (currx == selectx + 1 && curry == selecty - 1)
					{
						for (auto& w : wPiece)
						{
							if (w->x == currx && w->y == curry)
							{
								valid = 1;
							}
							if (w->x == currx && w->y == curry + 1 && w->enPassantCnt == 1)
							{
								valid = 1;
							}
						}
					}

					if (currx == selectx - 1 && curry == selecty - 1)
					{
						for (auto& w : wPiece)
						{
							if (w->x == currx && w->y == curry)
							{
								valid = 1;
							}
							if (w->x == currx && w->y == curry + 1 && w->enPassantCnt == 1)
							{
								valid = 1;
							}
						}
					}
				}

				//check moves for rook
				if (b->piece == ROOK)
				{
					//vertical movement
					if (currx == selectx && (curry < selecty || curry > selecty))
					{
						valid = 1;
						for (auto& b1 : bPiece)
						{
							if (b1->x == selectx)
							{
								if (curry < selecty && (curry < b1->y && selecty > b1->y))
								{
									valid = 0;
								}
								if (curry > selecty && (curry > b1->y && selecty < b1->y))
								{
									valid = 0;
								}
							}
						}

						for (auto& w : wPiece)
						{
							if (w->x == selectx)
							{
								if (curry < selecty && (curry < w->y && selecty > w->y))
								{
									valid = 0;
								}
								if (curry > selecty && (curry > w->y && selecty < w->y))
								{
									valid = 0;
								}
							}
						}
					}

					//horizontal movement
					if (curry == selecty && (currx < selectx || currx > selectx))
					{
						valid = 1;
						for (auto& b1 : bPiece)
						{
							if (b1->y == selecty)
							{
								if (currx < selectx && (currx < b1->x && selectx > b1->x))
								{
									valid = 0;
								}
								if (currx > selectx && (currx > b1->x && selectx < b1->x))
								{
									valid = 0;
								}
							}
						}

						for (auto& w : wPiece)
						{
							if (w->y == selecty)
							{
								if (currx < selectx && (currx < w->x && selectx > w->x))
								{
									valid = 0;
								}
								if (currx > selectx && (currx > w->x && selectx < w->x))
								{
									valid = 0;
								}
							}
						}
					}
				}

				//check moves for horse
				if (b->piece == HORSE)
				{
					if (currx == selectx - 2 && curry == selecty - 1)
					{
						valid = 1;
					}

					if (currx == selectx - 2 && curry == selecty + 1)
					{
						valid = 1;
					}

					if (currx == selectx + 2 && curry == selecty - 1)
					{
						valid = 1;
					}

					if (currx == selectx + 2 && curry == selecty + 1)
					{
						valid = 1;
					}

					if (currx == selectx - 1 && curry == selecty - 2)
					{
						valid = 1;
					}

					if (currx == selectx - 1 && curry == selecty + 2)
					{
						valid = 1;
					}

					if (currx == selectx + 1 && curry == selecty - 2)
					{
						valid = 1;
					}

					if (currx == selectx + 1 && curry == selecty + 2)
					{
						valid = 1;
					}
				}

				//check moves for bishop
				if (b->piece == BISHOP)
				{
					//right up diagonal
					if (currx > selectx && curry < selecty && (currx - selectx == selecty - curry))
					{
						valid = 1;
						for (auto& b1 : bPiece)
						{
							if ((selectx < b1->x && selecty > b1->y) && (currx > b1->x && curry < b1->y))
							{
								if (currx - b1->x == b1->y - curry)
								{
									valid = 0;
								}
							}
						}

						for (auto& w : wPiece)
						{
							if ((selectx < w->x && selecty > w->y) && (currx > w->x && curry < w->y))
							{
								if (currx - w->x == w->y - curry)
								{
									valid = 0;
								}
							}
						}
					}

					//right down diagonal
					if (currx > selectx && curry > selecty && (currx - selectx == curry - selecty))
					{
						valid = 1;
						for (auto& b1 : bPiece)
						{
							if ((selectx < b1->x && selecty < b1->y) && (currx > b1->x && curry > b1->y))
							{
								if (currx - b1->x == curry - b1->y)
								{
									valid = 0;
								}
							}
						}

						for (auto& w : wPiece)
						{
							if ((selectx < w->x && selecty < w->y) && (currx > w->x && curry > w->y))
							{
								if (currx - w->x == curry - w->y)
								{
									valid = 0;
								}
							}
						}
					}

					//left up diagonal
					if (currx < selectx && curry < selecty && (selectx - currx == selecty - curry))
					{
						valid = 1;
						for (auto& b1 : bPiece)
						{
							if ((selectx > b1->x && selecty > b1->y) && (currx < b1->x && curry < b1->y))
							{
								if (b1->x - currx == b1->y - curry)
								{
									valid = 0;
								}
							}
						}

						for (auto& w : wPiece)
						{
							if ((selectx > w->x && selecty > w->y) && (currx < w->x && curry < w->y))
							{
								if (w->x - currx == w->y - curry)
								{
									valid = 0;
								}
							}
						}
					}

					//left down diagonal
					if (currx < selectx && curry > selecty && (selectx - currx == curry - selecty))
					{
						valid = 1;
						for (auto& b1 : bPiece)
						{
							if ((selectx > b1->x && selecty < b1->y) && (currx < b1->x && curry > b1->y))
							{
								if (b1->x - currx == curry - b1->y)
								{
									valid = 0;
								}
							}
						}

						for (auto& w : wPiece)
						{
							if ((selectx > w->x && selecty < w->y) && (currx < w->x && curry > w->y))
							{
								if (w->x - currx == curry - w->y)
								{
									valid = 0;
								}
							}
						}
					}
				}

				//check moves for queen
				if (b->piece == QUEEN)
				{
					//right up diagonal
					if (currx > selectx && curry < selecty && (currx - selectx == selecty - curry))
					{
						valid = 1;
						for (auto& b1 : bPiece)
						{
							if ((selectx < b1->x && selecty > b1->y) && (currx > b1->x && curry < b1->y))
							{
								if (currx - b1->x == b1->y - curry)
								{
									valid = 0;
								}
							}
						}

						for (auto& w : wPiece)
						{
							if ((selectx < w->x && selecty > w->y) && (currx > w->x && curry < w->y))
							{
								if (currx - w->x == w->y - curry)
								{
									valid = 0;
								}
							}
						}
					}

					//right down diagonal
					if (currx > selectx && curry > selecty && (currx - selectx == curry - selecty))
					{
						valid = 1;
						for (auto& b1 : bPiece)
						{
							if ((selectx < b1->x && selecty < b1->y) && (currx > b1->x && curry > b1->y))
							{
								if (currx - b1->x == curry - b1->y)
								{
									valid = 0;
								}
							}
						}

						for (auto& w : wPiece)
						{
							if ((selectx < w->x && selecty < w->y) && (currx > w->x && curry > w->y))
							{
								if (currx - w->x == curry - w->y)
								{
									valid = 0;
								}
							}
						}
					}

					//left up diagonal
					if (currx < selectx && curry < selecty && (selectx - currx == selecty - curry))
					{
						valid = 1;
						for (auto& b1 : bPiece)
						{
							if ((selectx > b1->x && selecty > b1->y) && (currx < b1->x && curry < b1->y))
							{
								if (b1->x - currx == b1->y - curry)
								{
									valid = 0;
								}
							}
						}

						for (auto& w : wPiece)
						{
							if ((selectx > w->x && selecty > w->y) && (currx < w->x && curry < w->y))
							{
								if (w->x - currx == w->y - curry)
								{
									valid = 0;
								}
							}
						}
					}

					//left down diagonal
					if (currx < selectx && curry > selecty && (selectx - currx == curry - selecty))
					{
						valid = 1;
						for (auto& b1 : bPiece)
						{
							if ((selectx > b1->x && selecty < b1->y) && (currx < b1->x && curry > b1->y))
							{
								if (b1->x - currx == curry - b1->y)
								{
									valid = 0;
								}
							}
						}

						for (auto& w : wPiece)
						{
							if ((selectx > w->x && selecty < w->y) && (currx < w->x && curry > w->y))
							{
								if (w->x - currx == curry - w->y)
								{
									valid = 0;
								}
							}
						}
					}

					//vertical movement
					if (currx == selectx && (curry < selecty || curry > selecty))
					{
						valid = 1;
						for (auto& b1 : bPiece)
						{
							if (b1->x == selectx)
							{
								if (curry < selecty && (curry < b1->y && selecty > b1->y))
								{
									valid = 0;
								}
								if (curry > selecty && (curry > b1->y && selecty < b1->y))
								{
									valid = 0;
								}
							}
						}

						for (auto& w : wPiece)
						{
							if (w->x == selectx)
							{
								if (curry < selecty && (curry < w->y && selecty > w->y))
								{
									valid = 0;
								}
								if (curry > selecty && (curry > w->y && selecty < w->y))
								{
									valid = 0;
								}
							}
						}
					}

					//horizontal movement
					if (curry == selecty && (currx < selectx || currx > selectx))
					{
						valid = 1;
						for (auto& b1 : bPiece)
						{
							if (b1->y == selecty)
							{
								if (currx < selectx && (currx < b1->x && selectx > b1->x))
								{
									valid = 0;
								}
								if (currx > selectx && (currx > b1->x && selectx < b1->x))
								{
									valid = 0;
								}
							}
						}

						for (auto& w : wPiece)
						{
							if (w->y == selecty)
							{
								if (currx < selectx && (currx < w->x && selectx > w->x))
								{
									valid = 0;
								}
								if (currx > selectx && (currx > w->x && selectx < w->x))
								{
									valid = 0;
								}
							}
						}
					}
				}

				//check moves for king
				if (b->piece == KING)
				{
					//right up
					if (currx == selectx + 1 && curry == selecty - 1)
					{
						valid = 1;
					}

					//right down
					if (currx == selectx + 1 && curry == selecty + 1)
					{
						valid = 1;
					}

					//left up
					if (currx == selectx - 1 && curry == selecty - 1)
					{
						valid = 1;
					}

					//left down
					if (currx == selectx - 1 && curry == selecty + 1)
					{
						valid = 1;
					}

					//up
					if (currx == selectx && curry == selecty - 1)
					{
						valid = 1;
					}

					//down
					if (currx == selectx && curry == selecty + 1)
					{
						valid = 1;
					}

					//left
					if (currx == selectx - 1 && curry == selecty)
					{
						valid = 1;
					}

					//right
					if (currx == selectx + 1 && curry == selecty)
					{
						valid = 1;
					}

					//up or down
					if (currx == wking.x && (curry - 1 == wking.y || curry + 1 == wking.y))
					{
						valid = 0;
					}

					//left up diagonal or left down diagonal
					if (currx - 1 == wking.x && (curry - 1 == wking.y || curry + 1 == wking.y))
					{
						valid = 0;
					}

					//right up diagonal or right down diagonal
					if (currx + 1 == wking.x && (curry - 1 == wking.y || curry + 1 == wking.y))
					{
						valid = 0;
					}

					//right or left
					if (curry == wking.y && (currx - 1 == wking.x || currx + 1 == wking.x))
					{
						valid = 0;
					}

					// if king is not in check
					if (king.check == 0)
					{
						//kings side castling
						if (currx == selectx - 2 && curry == selecty)
						{
							if (b->movesMade == 0 && rook1.movesMade == 0)
							{
								valid = 1;
							}

							for (auto& b1 : bPiece)
							{
								if (b1->y == 7)
								{
									if (b1->x < king.x && b1->x > rook1.x)
									{
										valid = 0;
									}
								}
							}
							for (auto& w : wPiece)
							{
								if (w->y == 7)
								{
									if (w->x < king.x && w->x > rook1.x)
									{
										valid = 0;
									}
								}
							}

							if (valid == 1)
							{
								rook1.movesMade++;
								rook1.x = 2;
								col(7, 0, 7, 2, 2);

								b->x = currx;
								check();
								if (king.check == 1)
								{
									b->x = selectx;
									rook1.movesMade--;
									rook1.x = 0;
									col(7, 2, 7, 0, 2);
									valid = 0;
								}
								b->x = selectx;
							}
						}

						//queens side castling
						if (currx == selectx + 2 && curry == selecty)
						{
							if (b->movesMade == 0 && rook2.movesMade == 0)
							{
								valid = 1;
							}

							for (auto& b1 : bPiece)
							{
								if (b1->y == 7)
								{
									if (b1->x > king.x && b1->x < rook2.x)
									{
										valid = 0;
									}
								}
							}
							for (auto& w : wPiece)
							{
								if (w->y == 7)
								{
									if (w->x > king.x && w->x < rook2.x)
									{
										valid = 0;
									}
								}
							}

							if (valid == 1)
							{
								rook2.movesMade++;
								rook2.x = 4;
								col(7, 7, 7, 4, 2);

								b->x = currx;
								check();
								if (king.check == 1)
								{
									b->x = selectx;
									rook2.movesMade--;
									rook2.x = 7;
									col(7, 4, 7, 7, 2);
									valid = 0;
								}
								b->x = selectx;
							}
						}
					}
				}

				for (auto& b1 : bPiece)
				{
					if (currx == b1->x && curry == b1->y)
					{
						valid = 0;
					}
					if (currx == wking.x && curry == wking.y)
					{
						valid = 0;
					}
				}

				if (valid == 1)
				{
					b->x = currx;
					b->y = curry;
					b->movesMade++;

					//runs promotion
					if (b->piece == PAWN && b->y == 0)
					{
						char promotion = ' ';
						std::cout << "Pawn has been promoted, please choose a piece to promote to" << std::endl;
						std::cout << "enter Q, H, B, or R: ";
						std::cin >> promotion;
						if (promotion != 'Q' && promotion != 'H' && promotion != 'B' && promotion != 'R')
						{
							b->x = selectx;
							b->y = selecty;
							col(curry, currx, selecty, selectx, b->piece);
							for (auto& w : wPiece)
							{
								if (currx == w->x && curry == w->y)
								{
									col(w->y, w->x, curry, currx, w->piece + 6);
								}
							}
							drawBoard();
							std::cout << "must enter a valid promotion value" << std::endl;
							bMove();
							return;
						}
						if (promotion == 'Q')
						{
							b->piece = QUEEN;
						}
						if (promotion == 'H')
						{
							b->piece = HORSE;
						}
						if (promotion == 'B')
						{
							b->piece = BISHOP;
						}
						if (promotion == 'R')
						{
							b->piece = ROOK;
						}
					}

					//killed white piece
					for (auto& w : wPiece)
					{
						if (currx == w->x && curry == w->y)
						{
							w->death = 1;
							wDead++;
							w->dead(wDead);

							check();

							if (king.check == 1)
							{
								col(w->y, w->x, curry, currx, w->piece + 6);
								w->x = currx;
								w->y = curry;
								w->death = 0;
								wDead--;
								b->x = selectx;
								b->y = selecty;
								b->movesMade--;
								drawBoard();
								std::cout << "black is in check" << std::endl;
								bMove();
								return;
							}
							col(curry, currx, w->y, w->x, w->piece + 6);
						}
						if (b->piece == PAWN)
						{
							if (currx == w->x && curry + 1 == w->y)
							{
								w->death = 1;
								wDead++;
								w->dead(wDead);

								check();

								if (king.check == 1)
								{
									col(w->y, w->x, curry + 1, currx, w->piece + 6);
									w->x = currx;
									w->y = curry - 1;
									w->death = 0;
									wDead--;
									b->x = selectx;
									b->y = selecty;
									b->movesMade--;
									drawBoard();
									std::cout << "black is in check" << std::endl;
									bMove();
									return;
								}
								col(curry - 1, currx, w->y, w->x, w->piece + 6);
							}
						}
					}

					check();

					if (king.check == 1)
					{
						b->x = selectx;
						b->y = selecty;
						b->movesMade--;
						drawBoard();
						std::cout << "black is in check" << std::endl;
						bMove();
						return;
					}

					checkmate();
					stalemate();

					col(selecty, selectx, curry, currx, b->piece);
					for (auto& w : wPiece)
					{
						if (w->piece == PAWN)
						{
							w->enPassantCnt = 0;
						}
					}
					turn = 1;
					if (wking.check == 1)
					{
						drawBoard();
						std::cout << "white is in check" << std::endl;
						return;
					}
					drawBoard();
				}
				else
				{
					if (king.check == 1)
					{
						drawBoard();
						std::cout << "black is in check" << std::endl;
						bMove();
						return;
					}
					drawBoard();
					std::cout << "invalid move" << std::endl;
					bMove();
					return;
				}
			}
		}
		if (snum == 0)
		{
			drawBoard();
			std::cout << "no valid piece selected" << std::endl;
			bMove();
			return;
		}
	}
}

//moves white pieces
void wMove()
{
	if (win == 0)
	{
		int snum = 0;
		int valid = 0;
		int currx = 0;
		int curry = 0;
		std::string select = "";
		int selectx = 0;
		int selecty = 0;

		std::cout << "To operate a command, type N for newgame, D to delete a previous save, L for loading a previous save, Q for quitting," << std::endl << "or S to save the current game\n";
		std::cout << "white's turn: select a piece ";

		//get selection piece
		std::cin >> select;
		//for loading commands
		try {
			//on number entry sets selectx to converted string select to int
			selectx = std::stoi(select);
		}
		catch (const std::invalid_argument& ia) {
			//fails conversion and checks if valid command entered
			if (select == "L")
			{
				saveSlot("L");
				return;
			}
			if (select == "S")
			{
				saveSlot("S");
				return;
			}
			if (select == "D")
			{
				saveSlot("D");
				return;
			}
			if (select == "Q")
			{
				exit(0);
			}
			if (select == "N")
			{
				newGame();
				std::cout << "new game loaded" << std::endl;
				return;
			}
			drawBoard();
			std::cout << "invalid command" << std::endl;
			wMove();
			return;
		}
		std::cin >> selecty;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			drawBoard();
			std::cout << "cannot enter letter values" << std::endl;
			wMove();
			return;
		}

		if (selectx > 7 || selecty > 7)
		{
			std::cin.clear();
			std::cin.ignore();
			drawBoard();
			std::cout << "out of chess bounds" << std::endl;
			wMove();
			return;
		}

		if (selectx < 0 || selecty < 0)
		{
			std::cin.clear();
			std::cin.ignore();
			drawBoard();
			std::cout << "out of chess bounds" << std::endl;
			wMove();
			return;
		}

		for (auto& w : wPiece)
		{
			if (selectx == w->x && selecty == w->y)
			{
				snum++;
				//new location
				std::cin >> currx;
				std::cin >> curry;

				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore();
					drawBoard();
					std::cout << "cannot enter letter values" << std::endl;
					wMove();
					return;
				}

				if (currx > 7 || curry > 7)
				{
					std::cin.clear();
					std::cin.ignore();
					drawBoard();
					std::cout << "out of chess bounds" << std::endl;
					wMove();
					return;
				}

				if (currx < 0 || curry < 0)
				{
					std::cin.clear();
					std::cin.ignore();
					drawBoard();
					std::cout << "out of chess bounds" << std::endl;
					wMove();
					return;
				}

				//check moves for pawn
				if (w->piece == PAWN)
				{
					//moves forward 1
					if (currx == selectx && curry == selecty + 1)
					{
						valid = 1;
					}

					//moves forward 2
					if (w->movesMade == 0)
					{
						if (currx == selectx && curry == selecty + 2)
						{
							valid = 1;
							for (auto& w1 : wPiece)
							{
								if (currx == w1->x && w1->y == curry - 1)
								{
									valid = 0;
								}
								if (w1->x == currx && w1->y == curry)
								{
									valid = 0;
								}
							}
							for (auto& b : bPiece)
							{
								if (currx == b->x && b->y == curry - 1)
								{
									valid = 0;
								}
								if (b->x == currx && b->y == curry)
								{
									valid = 0;
								}
							}
							if (valid == 1)
							{
								check();
								if (wking.check == 1)
								{
									drawBoard();
									std::cout << "White is in check" << std::endl;
									wMove();
									return;
								}
								for (auto& b : bPiece)
								{
									if (b->piece == PAWN)
									{
										if (b->y == curry && (b->x == currx - 1 || b->x == currx + 1))
										{
											std::cout << "white en passant is active";
											int g;
											w->enPassantCnt = 1;
											std::cin >> g;
										}
									}
								}
							}
						}
					}

					for (auto& b : bPiece)
					{
						if (b->x == currx && b->y == curry)
						{
							valid = 0;
						}
					}

					//enpassant
					if (currx == selectx + 1 && curry == selecty + 1)
					{
						for (auto& b : bPiece)
						{
							if (b->x == currx && b->y == curry)
							{
								valid = 1;
							}
							if (b->x == currx && b->y == curry - 1 && b->enPassantCnt == 1)
							{
								valid = 1;
							}
						}
					}

					if (currx == selectx - 1 && curry == selecty + 1)
					{
						for (auto& b : bPiece)
						{
							if (b->x == currx && b->y == curry)
							{
								valid = 1;
							}
							if (b->x == currx && b->y == curry - 1 && b->enPassantCnt == 1)
							{
								valid = 1;
							}
						}
					}
				}

				//check moves for rook
				if (w->piece == ROOK)
				{
					//vertical movement
					if (currx == selectx && (curry < selecty || curry > selecty))
					{
						valid = 1;
						for (auto& w1 : wPiece)
						{
							if (w1->x == selectx)
							{
								if (curry < selecty && (curry < w1->y && selecty > w1->y))
								{
									valid = 0;
								}
								if (curry > selecty && (curry > w1->y && selecty < w1->y))
								{
									valid = 0;
								}
							}
						}

						for (auto& b : bPiece)
						{
							if (b->x == selectx)
							{
								if (curry < selecty && (curry < b->y && selecty > b->y))
								{
									valid = 0;
								}
								if (curry > selecty && (curry > b->y && selecty < b->y))
								{
									valid = 0;
								}
							}
						}
					}

					//horizontal movement
					if (curry == selecty && (currx < selectx || currx > selectx))
					{
						valid = 1;
						for (auto& w1 : wPiece)
						{
							if (w1->y == selecty)
							{
								if (currx < selectx && (currx < w1->x && selectx > w1->x))
								{
									valid = 0;
								}
								if (currx > selectx && (currx > w1->x && selectx < w1->x))
								{
									valid = 0;
								}
							}
						}

						for (auto& b : bPiece)
						{
							if (b->y == selecty)
							{
								if (currx < selectx && (currx < b->x && selectx > b->x))
								{
									valid = 0;
								}
								if (currx > selectx && (currx > b->x && selectx < b->x))
								{
									valid = 0;
								}
							}
						}
					}
				}

				//check moves for horse
				if (w->piece == HORSE)
				{
					if (currx == selectx - 2 && curry == selecty - 1)
					{
						valid = 1;
					}

					if (currx == selectx - 2 && curry == selecty + 1)
					{
						valid = 1;
					}

					if (currx == selectx + 2 && curry == selecty - 1)
					{
						valid = 1;
					}

					if (currx == selectx + 2 && curry == selecty + 1)
					{
						valid = 1;
					}

					if (currx == selectx - 1 && curry == selecty - 2)
					{
						valid = 1;
					}

					if (currx == selectx - 1 && curry == selecty + 2)
					{
						valid = 1;
					}

					if (currx == selectx + 1 && curry == selecty - 2)
					{
						valid = 1;
					}

					if (currx == selectx + 1 && curry == selecty + 2)
					{
						valid = 1;
					}
				}

				//check moves for bishop
				if (w->piece == BISHOP)
				{
					//right up diagonal
					if (currx > selectx && curry < selecty && (currx - selectx == selecty - curry))
					{
						valid = 1;
						for (auto& w1 : wPiece)
						{
							if ((selectx < w1->x && selecty > w1->y) && (currx > w1->x && curry < w1->y))
							{
								if (currx - w1->x == w1->y - curry)
								{
									valid = 0;
								}
							}
						}

					}

					//right down diagonal
					if (currx > selectx && curry > selecty && (currx - selectx == curry - selecty))
					{
						valid = 1;
						for (auto& w1 : wPiece)
						{
							if ((selectx < w1->x && selecty < w1->y) && (currx > w1->x && curry > w1->y))
							{
								if (currx - w1->x == curry - w1->y)
								{
									valid = 0;
								}
							}
						}
					}

					//left up diagonal
					if (currx < selectx && curry < selecty && (selectx - currx == selecty - curry))
					{
						valid = 1;
						for (auto& w1 : wPiece)
						{
							if ((selectx > w1->x && selecty > w1->y) && (currx < w1->x && curry < w1->y))
							{
								if (w1->x - currx == w1->y - curry)
								{
									valid = 0;
								}
							}
						}
					}

					//left down diagonal
					if (currx < selectx && curry > selecty && (selectx - currx == curry - selecty))
					{
						valid = 1;
						for (auto& w1 : wPiece)
						{
							if ((selectx > w1->x && selecty < w1->y) && (currx < w1->x && curry > w1->y))
							{
								if (w1->x - currx == curry - w1->y)
								{
									valid = 0;
								}
							}
						}
					}
				}

				//check moves for queen
				if (w->piece == QUEEN)
				{
					//right up diagonal
					if (currx > selectx && curry < selecty && (currx - selectx == selecty - curry))
					{
						valid = 1;
						for (auto& w1 : wPiece)
						{
							if ((selectx < w1->x && selecty > w1->y) && (currx > w1->x && curry < w1->y))
							{
								if (currx - w1->x == w1->y - curry)
								{
									valid = 0;
								}
							}
						}
					}

					//right down diagonal
					if (currx > selectx && curry > selecty && (currx - selectx == curry - selecty))
					{
						valid = 1;
						for (auto& w1 : wPiece)
						{
							if ((selectx < w1->x && selecty < w1->y) && (currx > w1->x && curry > w1->y))
							{
								if (currx - w1->x == curry - w1->y)
								{
									valid = 0;
								}
							}
						}
					}

					//left up diagonal
					if (currx < selectx && curry < selecty && (selectx - currx == selecty - curry))
					{
						valid = 1;
						for (auto& w1 : wPiece)
						{
							if ((selectx > w1->x && selecty > w1->y) && (currx < w1->x && curry < w1->y))
							{
								if (w1->x - currx == w1->y - curry)
								{
									valid = 0;
								}
							}
						}
					}

					//left down diagonal
					if (currx < selectx && curry > selecty && (selectx - currx == curry - selecty))
					{
						valid = 1;
						for (auto& w1 : wPiece)
						{
							if ((selectx > w1->x && selecty < w1->y) && (currx < w1->x && curry > w1->y))
							{
								if (w1->x - currx == curry - w1->y)
								{
									valid = 0;
								}
							}
						}
					}

					//vertical movement
					if (currx == selectx && (curry < selecty || curry > selecty))
					{
						valid = 1;
						for (auto& w1 : wPiece)
						{
							if (w1->x == selectx)
							{
								if (curry < selecty && (curry < w1->y && selecty > w1->y))
								{
									valid = 0;
								}
								if (curry > selecty && (curry > w1->y && selecty < w1->y))
								{
									valid = 0;
								}
							}
						}
					}

					//horizontal movement
					if (curry == selecty && (currx < selectx || currx > selectx))
					{
						valid = 1;
						for (auto& w1 : wPiece)
						{
							if (w1->y == selecty)
							{
								if (currx < selectx && (currx < w1->x && selectx > w1->x))
								{
									valid = 0;
								}
								if (currx > selectx && (currx > w1->x && selectx < w1->x))
								{
									valid = 0;
								}
							}
						}
					}
				}

				//check moves for king
				if (w->piece == KING)
				{
					//right up
					if (currx == selectx + 1 && curry == selecty - 1)
					{
						valid = 1;
					}

					//right down
					if (currx == selectx + 1 && curry == selecty + 1)
					{
						valid = 1;
					}

					//left up
					if (currx == selectx - 1 && curry == selecty - 1)
					{
						valid = 1;
					}

					//left down
					if (currx == selectx - 1 && curry == selecty + 1)
					{
						valid = 1;
					}

					//up
					if (currx == selectx && curry == selecty - 1)
					{
						valid = 1;
					}

					//down
					if (currx == selectx && curry == selecty + 1)
					{
						valid = 1;
					}

					//left
					if (currx == selectx - 1 && curry == selecty)
					{
						valid = 1;
					}

					//right
					if (currx == selectx + 1 && curry == selecty)
					{
						valid = 1;
					}

					//other king up or down
					if (currx == king.x && (curry - 1 == king.y || curry + 1 == king.y))
					{
						valid = 0;
					}

					//other king left up diagonal or left down diagonal
					if (currx - 1 == king.x && (curry - 1 == king.y || curry + 1 == king.y))
					{
						valid = 0;
					}

					//other king right up diagonal or right down diagonal
					if (currx + 1 == king.x && (curry - 1 == king.y || curry + 1 == king.y))
					{
						valid = 0;
					}

					//other king right or left
					if (curry == king.y && (currx - 1 == king.x || currx + 1 == king.x))
					{
						valid = 0;
					}

					//if king is not in check it can castle	
					if (wking.check == 0)
					{
						//kings side castling
						if (currx == selectx - 2 && curry == selecty)
						{
							if (w->movesMade == 0 && wrook1.movesMade == 0)
							{
								valid = 1;
							}

							for (auto& b : bPiece)
							{
								if (b->y == 0)
								{
									if (b->x < wking.x && b->x > wrook1.x)
									{
										valid = 0;
									}
								}
							}

							for (auto& w1 : wPiece)
							{
								if (w1->y == 0)
								{
									if (w1->x < wking.x && w1->x > wrook1.x)
									{
										valid = 0;
									}
								}
							}

							if (valid == 1)
							{
								wrook1.movesMade++;
								wrook1.x = 2;
								col(0, 0, 0, 2, 8);

								w->x = currx;
								check();
								if (wking.check == 1)
								{
									w->x = selectx;
									wrook1.movesMade--;
									wrook1.x = 0;
									col(0, 2, 0, 0, 8);
									valid = 0;
								}
								w->x = selectx;
							}
						}

						//queens side castling
						if (currx == selectx + 2 && curry == selecty)
						{
							if (w->movesMade == 0 && wrook2.movesMade == 0)
							{
								valid = 1;
							}

							for (auto& b : bPiece)
							{
								if (b->y == 0)
								{
									if (b->x > wking.x && b->x < wrook2.x)
									{
										valid = 0;
									}
								}
							}

							for (auto& w1 : wPiece)
							{
								if (w1->y == 0)
								{
									if (w1->x > wking.x && w1->x < wrook2.x)
									{
										valid = 0;
									}
								}
							}

							if (valid == 1)
							{
								wrook2.movesMade++;
								wrook2.x = 4;
								col(0, 7, 0, 4, 8);

								w->x = currx;
								check();
								if (wking.check == 1)
								{
									w->x = selectx;
									wrook2.movesMade--;
									wrook2.x = 7;
									col(0, 4, 0, 7, 8);
									valid = 0;
								}
								w->x = selectx;
							}
						}
					}
				}

				for (auto& w1 : wPiece)
				{
					if (currx == w1->x && curry == w1->y)
					{
						valid = 0;
					}
					if (currx == king.x && curry == king.y)
					{
						valid = 0;
					}
				}

				if (valid == 1)
				{
					w->x = currx;
					w->y = curry;
					w->movesMade++;

					//runs promotion
					if (w->piece == PAWN && w->y == 7)
					{
						char promotion = ' ';
						std::cout << "Pawn has been promoted, please choose a piece to promote to" << std::endl;
						std::cout << "enter Q, H, B, or R: ";
						std::cin >> promotion;
						if (promotion != 'Q' && promotion != 'H' && promotion != 'B' && promotion != 'R')
						{
							w->x = selectx;
							w->y = selecty;
							col(curry, currx, selecty, selectx, w->piece + 6);
							for (auto& b : bPiece)
							{
								if (currx == b->x && curry == b->y)
								{
									col(b->y, b->x, curry, currx, b->piece);
								}
							}
							drawBoard();
							std::cout << "must enter a valid promotion value" << std::endl;
							wMove();
							return;
						}
						if (promotion == 'Q')
						{
							w->piece = QUEEN;
						}
						if (promotion == 'H')
						{
							w->piece = HORSE;
						}
						if (promotion == 'B')
						{
							w->piece = BISHOP;
						}
						if (promotion == 'R')
						{
							w->piece = ROOK;
						}
					}

					for (auto& b : bPiece)
					{
						if (currx == b->x && curry == b->y)
						{
							b->death = 1;
							bDead++;
							b->dead(bDead);

							check();

							if (wking.check == 1)
							{
								col(b->y, b->x, curry, currx, b->piece);
								b->x = currx;
								b->y = curry;
								b->death = 0;
								bDead--;
								w->x = selectx;
								w->y = selecty;
								w->movesMade--;
								drawBoard();
								std::cout << "white is in check" << std::endl;
								wMove();
								return;
							}
							col(curry, currx, b->y, b->x, b->piece);
						}
						if (w->piece == PAWN)
						{
							if (currx == b->x && b->y == curry - 1 && b->enPassantCnt == 1)
							{
								b->death = 1;
								bDead++;
								b->dead(bDead);

								check();

								if (wking.check == 1)
								{
									col(b->y, b->x, curry - 1, currx, b->piece);
									b->x = currx;
									b->y = curry + 1;
									b->death = 0;
									bDead--;
									w->x = selectx;
									w->y = selecty;
									w->movesMade--;
									drawBoard();
									std::cout << "white is in check" << std::endl;
									wMove();
									return;
								}
								col(curry + 1, currx, b->y, b->x, b->piece);
							}
						}
					}

					check();

					if (wking.check == 1)
					{
						w->x = selectx;
						w->y = selecty;
						w->movesMade--;
						drawBoard();
						std::cout << "white is in check" << std::endl;
						wMove();
						return;
					}

					checkmate();
					stalemate();

					col(selecty, selectx, curry, currx, w->piece + 6);
					for (auto& b : bPiece)
					{
						if (b->piece == PAWN)
						{
							b->enPassantCnt = 0;
						}
					}
					turn = 0;
					if (king.check == 1)
					{
						drawBoard();
						std::cout << "black is in check" << std::endl;
						return;
					}
					drawBoard();
				}
				else
				{
					if (wking.check == 1)
					{
						drawBoard();
						std::cout << "white is in check" << std::endl;
						wMove();
						return;
					}
					drawBoard();
					std::cout << "invalid move" << std::endl;
					wMove();
					return;
				}
			}
		}
		if (snum == 0)
		{
			drawBoard();
			std::cout << "no valid piece selected" << std::endl;
			wMove();
		}
	}
}