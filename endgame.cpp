#include"vars.h"

//checks if king is in check
void check()
{
	int pbtwn = 0;
	king.check = 0;

	//check if black is in check
	for (auto& w : wPiece)
	{
		if (w->death == 0)
		{
			//pawn
			if (w->piece == PAWN)
			{
				if (w->y + 1 == king.y)
				{
					if (w->x + 1 == king.x)
					{
						king.check = 1;
						return;
					}
					if (w->x - 1 == king.x)
					{
						king.check = 1;
						return;
					}
				}
			}

			//rook
			if (w->piece == ROOK)
			{
				//vertical movement
				if (king.x == w->x)
				{
					for (auto& b : bPiece)
					{
						if (b->x == w->x && b->piece != KING)
						{
							if (king.y < b->y && b->y < w->y)
							{
								pbtwn = 1;
								break;
							}

							if (king.y > b->y && b->y > w->y)
							{
								pbtwn = 1;
								break;
							}
						}
					}

					for (auto& w1 : wPiece)
					{
						if (w1->x == w->x)
						{
							if (king.y < w1->y && w1->y < w->y)
							{
								pbtwn = 1;
								break;
							}

							if (king.y > w1->y && w1->y > w->y)
							{
								pbtwn = 1;
								break;
							}
						}
					}

					if (pbtwn == 0)
					{
						king.check = 1;
						return;
					}
				}

				//horizontal movement
				if (king.y == w->y)
				{
					for (auto& b : bPiece)
					{
						if (b->y == w->y && b->piece != KING)
						{
							if (king.x < b->x && b->x < w->x)
							{
								pbtwn = 1;
								break;
							}

							if (king.x > b->x && b->x > w->x)
							{
								pbtwn = 1;
								break;
							}
						}
					}

					for (auto& w1 : wPiece)
					{
						if (w1->y == w->y)
						{
							if (king.x < w1->x && w1->x < w->x)
							{
								pbtwn = 1;
								break;
							}

							if (king.x > w1->x && w1->x > w->x)
							{
								pbtwn = 1;
								break;
							}
						}
					}

					if (pbtwn == 0)
					{
						king.check = 1;
						return;
					}
				}
			}

			//horse
			if (w->piece == HORSE)
			{
				if (king.x == w->x - 2 && king.y == w->y - 1)
				{
					king.check = 1;
				}

				if (king.x == w->x - 2 && king.y == w->y + 1)
				{
					king.check = 1;
				}

				if (king.x == w->x + 2 && king.y == w->y - 1)
				{
					king.check = 1;
				}

				if (king.x == w->x + 2 && king.y == w->y + 1)
				{
					king.check = 1;
				}

				if (king.x == w->x - 1 && king.y == w->y - 2)
				{
					king.check = 1;
				}

				if (king.x == w->x - 1 && king.y == w->y + 2)
				{
					king.check = 1;
				}

				if (king.x == w->x + 1 && king.y == w->y - 2)
				{
					king.check = 1;
				}

				if (king.x == w->x + 1 && king.y == w->y + 2)
				{
					king.check = 1;
				}
			}

			//bishop
			if (w->piece == BISHOP)
			{
				//right up diagonal
				if (king.x > w->x && king.y < w->y && (king.x - w->x == w->y - king.y))
				{
					king.check = 1;
					for (auto& b : bPiece)
					{
						if ((w->x < b->x && w->y > b->y) && (king.x > b->x && king.y < b->y))
						{
							if (king.x - b->x == b->y - king.y)
							{
								king.check = 0;
							}
						}
					}

					for (auto& w1 : wPiece)
					{
						if ((w->x < w1->x && w->y > w1->y) && (king.x > w1->x && king.y < w1->y))
						{
							if (king.x - w1->x == w1->y - king.y)
							{
								king.check = 0;
							}
						}
					}
					if (king.check == 1)
					{
						return;
					}
				}

				//right down diagonal
				if (king.x > w->x && king.y > w->y && (king.x - w->x == king.y - w->y))
				{
					king.check = 1;
					for (auto& b : bPiece)
					{
						if ((w->x < b->x && w->y < b->y) && (king.x > b->x && king.y > b->y))
						{
							if (king.x - b->x == king.y - b->y)
							{
								king.check = 0;
							}
						}
					}

					for (auto& w1 : wPiece)
					{
						if ((w->x < w1->x && w->y < w1->y) && (king.x > w1->x && king.y > w1->y))
						{
							if (king.x - w1->x == king.y - w1->y)
							{
								king.check = 0;
							}
						}
					}
					if (king.check == 1)
					{
						return;
					}
				}

				//left up diagonal
				if (king.x < w->x && king.y < w->y && (w->x - king.x == w->y - king.y))
				{
					king.check = 1;
					for (auto& b : bPiece)
					{
						if ((w->x > b->x && w->y > b->y) && (king.x < b->x && king.y < b->y))
						{
							if (b->x - king.x == b->y - king.y)
							{
								king.check = 0;
							}
						}
					}

					for (auto& w1 : wPiece)
					{
						if ((w->x > w1->x && w->y > w1->y) && (king.x < w1->x && king.y < w1->y))
						{
							if (w1->x - king.x == w1->y - king.y)
							{
								king.check = 0;
							}
						}
					}
					if (king.check == 1)
					{
						return;
					}
				}

				//left down diagonal
				if (king.x < w->x && king.y > w->y && (w->x - king.x == king.y - w->y))
				{
					king.check = 1;
					for (auto& b : bPiece)
					{
						if ((w->x > b->x && w->y < b->y) && (king.x < b->x && king.y > b->y))
						{
							if (b->x - king.x == king.y - b->y)
							{
								king.check = 0;
							}
						}
					}

					for (auto& w1 : wPiece)
					{
						if ((w->x > w1->x && w->y < w1->y) && (king.x < w1->x && king.y > w1->y))
						{
							if (w1->x - king.x == king.y - w1->y)
							{
								king.check = 0;
							}
						}
					}
					if (king.check == 1)
					{
						return;
					}
				}
			}

			//queen
			if (w->piece == QUEEN)
			{
				//vertical movement
				if (king.x == w->x)
				{
					for (auto& b : bPiece)
					{
						if (b->x == w->x && b->piece != KING)
						{
							if (king.y < b->y && b->y < w->y)
							{
								pbtwn = 1;
								break;
							}

							if (king.y > b->y && b->y > w->y)
							{
								pbtwn = 1;
								break;
							}
						}
					}

					for (auto& w1 : wPiece)
					{
						if (w1->x == w->x)
						{
							if (king.y < w1->y && w1->y < w->y)
							{
								pbtwn = 1;
								break;
							}

							if (king.y > w1->y && w1->y > w->y)
							{
								pbtwn = 1;
								break;
							}
						}
					}

					if (pbtwn == 0)
					{
						king.check = 1;
						return;
					}
				}

				//horizontal movement
				if (king.y == w->y)
				{
					for (auto& b : bPiece)
					{
						if (b->y == w->y && b->piece != KING)
						{
							if (king.x < b->x && b->x < w->x)
							{
								pbtwn = 1;
								break;
							}

							if (king.x > b->x && b->x > w->x)
							{
								pbtwn = 1;
								break;
							}
						}
					}

					for (auto& w1 : wPiece)
					{
						if (w1->y == w->y)
						{
							if (king.x < w1->x && w1->x < w->x)
							{
								pbtwn = 1;
								break;
							}

							if (king.x > w1->x && w1->x > w->x)
							{
								pbtwn = 1;
								break;
							}
						}
					}

					if (pbtwn == 0)
					{
						king.check = 1;
						return;
					}
				}

				//right up diagonal
				if (king.x > w->x && king.y < w->y && (king.x - w->x == w->y - king.y))
				{
					king.check = 1;
					for (auto& b : bPiece)
					{
						if ((w->x < b->x && w->y > b->y) && (king.x > b->x && king.y < b->y))
						{
							if (king.x - b->x == b->y - king.y)
							{
								king.check = 0;
							}
						}
					}

					for (auto& w1 : wPiece)
					{
						if ((w->x < w1->x && w->y > w1->y) && (king.x > w1->x && king.y < w1->y))
						{
							if (king.x - w1->x == w1->y - king.y)
							{
								king.check = 0;
							}
						}
					}
					if (king.check == 1)
					{
						return;
					}
				}

				//right down diagonal
				if (king.x > w->x && king.y > w->y && (king.x - w->x == king.y - w->y))
				{
					king.check = 1;
					for (auto& b : bPiece)
					{
						if ((w->x < b->x && w->y < b->y) && (king.x > b->x && king.y > b->y))
						{
							if (king.x - b->x == king.y - b->y)
							{
								king.check = 0;
							}
						}
					}

					for (auto& w1 : wPiece)
					{
						if ((w->x < w1->x && w->y < w1->y) && (king.x > w1->x && king.y > w1->y))
						{
							if (king.x - w1->x == king.y - w1->y)
							{
								king.check = 0;
							}
						}
					}
					if (king.check == 1)
					{
						return;
					}
				}

				//left up diagonal
				if (king.x < w->x && king.y < w->y && (w->x - king.x == w->y - king.y))
				{
					king.check = 1;
					for (auto& b : bPiece)
					{
						if ((w->x > b->x && w->y > b->y) && (king.x < b->x && king.y < b->y))
						{
							if (b->x - king.x == b->y - king.y)
							{
								king.check = 0;
							}
						}
					}

					for (auto& w1 : wPiece)
					{
						if ((w->x > w1->x && w->y > w1->y) && (king.x < w1->x && king.y < w1->y))
						{
							if (w1->x - king.x == w1->y - king.y)
							{
								king.check = 0;
							}
						}
					}
					if (king.check == 1)
					{
						return;
					}
				}

				//left down diagonal
				if (king.x < w->x && king.y > w->y && (w->x - king.x == king.y - w->y))
				{
					king.check = 1;
					for (auto& b : bPiece)
					{
						if ((w->x > b->x && w->y < b->y) && (king.x < b->x && king.y > b->y))
						{
							if (b->x - king.x == king.y - b->y)
							{
								king.check = 0;
							}
						}
					}

					for (auto& w1 : wPiece)
					{
						if ((w->x > w1->x && w->y < w1->y) && (king.x < w1->x && king.y > w1->y))
						{
							if (w1->x - king.x == king.y - w1->y)
							{
								king.check = 0;
							}
						}
					}
					if (king.check == 1)
					{
						return;
					}
				}
			}
		}
	}

	wking.check = 0;
	//check if white is in check
	for (auto& b : bPiece)
	{
		pbtwn = 0;
		if (b->death == 0)
		{
			//pawn
			if (b->piece == PAWN)
			{
				if (b->y - 1 == wking.y)
				{
					if (b->x + 1 == wking.x)
					{
						wking.check = 1;
						return;
					}
					if (b->x - 1 == wking.x)
					{
						wking.check = 1;
						return;
					}
				}
			}

			//rook
			if (b->piece == ROOK)
			{
				//vertical movement
				if (wking.x == b->x)
				{
					for (auto& w : wPiece)
					{
						if (w->x == b->x && w->piece != KING)
						{
							if (wking.y < w->y && w->y < b->y)
							{
								pbtwn = 1;
								break;
							}

							if (wking.y > w->y && w->y > b->y)
							{
								pbtwn = 1;
								break;
							}
						}
					}

					for (auto& b1 : bPiece)
					{
						if (b1->x == b->x && b1->piece != KING)
						{
							if (wking.y < b1->y && b1->y < b->y)
							{
								pbtwn = 1;
								break;
							}

							if (wking.y > b1->y && b1->y > b->y)
							{
								pbtwn = 1;
								break;
							}
						}
					}

					if (pbtwn == 0)
					{
						wking.check = 1;
						return;
					}
				}

				//horizontal movement
				if (wking.y == b->y)
				{
					for (auto& w : wPiece)
					{
						if (w->y == b->y && w->piece != KING)
						{
							if (wking.x < w->x && w->x < b->x)
							{
								pbtwn = 1;
								break;
							}

							if (wking.x > w->x && w->x > b->x)
							{
								pbtwn = 1;
								break;
							}
						}
					}

					for (auto& b1 : bPiece)
					{
						if (b1->y == b->y && b1->piece != KING)
						{
							if (wking.x < b1->x && b1->x < b->x)
							{
								pbtwn = 1;
								break;
							}

							if (wking.x > b1->x && b1->x > b->x)
							{
								pbtwn = 1;
								break;
							}
						}
					}

					if (pbtwn == 0)
					{
						wking.check = 1;
						return;
					}
				}
			}

			//horse
			if (b->piece == HORSE)
			{
				if (wking.x == b->x - 2 && wking.y == b->y - 1)
				{
					wking.check = 1;
				}

				if (wking.x == b->x - 2 && wking.y == b->y + 1)
				{
					wking.check = 1;
				}

				if (wking.x == b->x + 2 && wking.y == b->y - 1)
				{
					wking.check = 1;
				}

				if (wking.x == b->x + 2 && wking.y == b->y + 1)
				{
					wking.check = 1;
				}

				if (wking.x == b->x - 1 && wking.y == b->y - 2)
				{
					wking.check = 1;
				}

				if (wking.x == b->x - 1 && wking.y == b->y + 2)
				{
					wking.check = 1;
				}

				if (wking.x == b->x + 1 && wking.y == b->y - 2)
				{
					wking.check = 1;
				}

				if (wking.x == b->x + 1 && wking.y == b->y + 2)
				{
					wking.check = 1;
				}
				if (wking.check == 1)
				{
					return;
				}
			}

			//bishop
			if (b->piece == BISHOP)
			{
				//right up diagonal
				if (wking.x > b->x && wking.y < b->y && (wking.x - b->x == b->y - wking.y))
				{
					wking.check = 1;
					for (auto& b1 : bPiece)
					{
						if ((b->x < b1->x && b->y > b1->y) && (wking.x > b1->x && wking.y < b1->y))
						{
							if (wking.x - b1->x == b1->y - wking.y)
							{
								wking.check = 0;
							}
						}
					}

					for (auto& w : wPiece)
					{
						if ((b->x < w->x && b->y > w->y) && (wking.x > w->x && wking.y < w->y))
						{
							if (wking.x - w->x == w->y - wking.y)
							{
								wking.check = 0;
							}
						}
					}
					if (wking.check == 1)
					{
						return;
					}
				}

				//right down diagonal
				if (wking.x > b->x && wking.y > b->y && (wking.x - b->x == wking.y - b->y))
				{
					wking.check = 1;
					for (auto& b1 : bPiece)
					{
						if ((b->x < b1->x && b->y < b1->y) && (wking.x > b1->x && wking.y > b1->y))
						{
							if (wking.x - b1->x == wking.y - b1->y)
							{
								wking.check = 0;
							}
						}
					}

					for (auto& w : wPiece)
					{
						if ((b->x < w->x && b->y < w->y) && (wking.x > w->x && wking.y > w->y))
						{
							if (wking.x - w->x == wking.y - w->y)
							{
								wking.check = 0;
							}
						}
					}
					if (wking.check == 1)
					{
						return;
					}
				}

				//left up diagonal
				if (wking.x < b->x && wking.y < b->y && (b->x - wking.x == b->y - wking.y))
				{
					wking.check = 1;
					for (auto& b1 : bPiece)
					{
						if ((b->x > b1->x && b->y > b1->y) && (wking.x < b1->x && wking.y < b1->y))
						{
							if (b1->x - wking.x == b1->y - wking.y)
							{
								wking.check = 0;
							}
						}
					}

					for (auto& w : wPiece)
					{
						if ((b->x > w->x && b->y > w->y) && (wking.x < w->x && wking.y < w->y))
						{
							if (w->x - wking.x == w->y - wking.y)
							{
								wking.check = 0;
							}
						}
					}
					if (wking.check == 1)
					{
						return;
					}
				}

				//left down diagonal
				if (wking.x < b->x && wking.y > b->y && (b->x - wking.x == wking.y - b->y))
				{
					wking.check = 1;
					for (auto& b1 : bPiece)
					{
						if ((b->x > b1->x && b->y < b1->y) && (wking.x < b1->x && wking.y > b1->y))
						{
							if (b1->x - wking.x == wking.y - b1->y)
							{
								wking.check = 0;
							}
						}
					}

					for (auto& w : wPiece)
					{
						if ((b->x > w->x && b->y < w->y) && (wking.x < w->x && wking.y > w->y))
						{
							if (w->x - wking.x == wking.y - w->y)
							{
								wking.check = 0;
							}
						}
					}
					if (wking.check == 1)
					{
						return;
					}
				}
			}

			//queen
			if (b->piece == QUEEN)
			{
				//vertical movement
				if (wking.x == b->x)
				{
					for (auto& w : wPiece)
					{
						if (w->x == b->x && w->piece != KING)
						{
							if (wking.y < w->y && w->y < b->y)
							{
								pbtwn = 1;
								break;
							}

							if (wking.y > w->y && w->y > b->y)
							{
								pbtwn = 1;
								break;
							}
						}
					}

					for (auto& b1 : bPiece)
					{
						if (b1->x == b->x && b1->piece != KING)
						{
							if (wking.y < b1->y && b1->y < b->y)
							{
								pbtwn = 1;
								break;
							}

							if (wking.y > b1->y && b1->y > b->y)
							{
								pbtwn = 1;
								break;
							}
						}
					}

					if (pbtwn == 0)
					{
						wking.check = 1;
						return;
					}
				}

				//horizontal movement
				if (wking.y == b->y)
				{
					for (auto& w : wPiece)
					{
						if (w->y == b->y && w->piece != KING)
						{
							if (wking.x < w->x && w->x < b->x)
							{
								pbtwn = 1;
								break;
							}

							if (wking.x > w->x && w->x > b->x)
							{
								pbtwn = 1;
								break;
							}
						}
					}

					for (auto& b1 : bPiece)
					{
						if (b1->y == b->y && b1->piece != KING)
						{
							if (wking.x < b1->x && b1->x < b->x)
							{
								pbtwn = 1;
								break;
							}

							if (wking.x > b1->x && b1->x > b->x)
							{
								pbtwn = 1;
								break;
							}
						}
					}

					if (pbtwn == 0)
					{
						wking.check = 1;
						return;
					}
				}

				//right up diagonal
				if (wking.x > b->x && wking.y < b->y && (wking.x - b->x == b->y - wking.y))
				{
					wking.check = 1;
					for (auto& b1 : bPiece)
					{
						if ((b->x < b1->x && b->y > b1->y) && (wking.x > b1->x && wking.y < b1->y))
						{
							if (wking.x - b1->x == b1->y - wking.y)
							{
								wking.check = 0;
							}
						}
					}

					for (auto& w : wPiece)
					{
						if ((b->x < w->x && b->y > w->y) && (wking.x > w->x && wking.y < w->y))
						{
							if (wking.x - w->x == w->y - wking.y)
							{
								wking.check = 0;
							}
						}
					}
					if (wking.check == 1)
					{
						return;
					}
				}

				//right down diagonal
				if (wking.x > b->x && wking.y > b->y && (wking.x - b->x == wking.y - b->y))
				{
					wking.check = 1;
					for (auto& b1 : bPiece)
					{
						if ((b->x < b1->x && b->y < b1->y) && (wking.x > b1->x && wking.y > b1->y))
						{
							if (wking.x - b1->x == wking.y - b1->y)
							{
								wking.check = 0;
							}
						}
					}

					for (auto& w : wPiece)
					{
						if ((b->x < w->x && b->y < w->y) && (wking.x > w->x && wking.y > w->y))
						{
							if (wking.x - w->x == wking.y - w->y)
							{
								wking.check = 0;
							}
						}
					}
					if (wking.check == 1)
					{
						return;
					}
				}

				//left up diagonal
				if (wking.x < b->x && wking.y < b->y && (b->x - wking.x == b->y - wking.y))
				{
					wking.check = 1;
					for (auto& b1 : bPiece)
					{
						if ((b->x > b1->x && b->y > b1->y) && (wking.x < b1->x && wking.y < b1->y))
						{
							if (b1->x - wking.x == b1->y - wking.y)
							{
								wking.check = 0;
							}
						}
					}

					for (auto& w : wPiece)
					{
						if ((b->x > w->x && b->y > w->y) && (wking.x < w->x && wking.y < w->y))
						{
							if (w->x - wking.x == w->y - wking.y)
							{
								wking.check = 0;
							}
						}
					}
					if (wking.check == 1)
					{
						return;
					}
				}

				//left down diagonal
				if (wking.x < b->x && wking.y > b->y && (b->x - wking.x == wking.y - b->y))
				{
					wking.check = 1;
					for (auto& b1 : bPiece)
					{
						if ((b->x > b1->x && b->y < b1->y) && (wking.x < b1->x && wking.y > b1->y))
						{
							if (b1->x - wking.x == wking.y - b1->y)
							{
								wking.check = 0;
							}
						}
					}

					for (auto& w : wPiece)
					{
						if ((b->x > w->x && b->y < w->y) && (wking.x < w->x && wking.y > w->y))
						{
							if (w->x - wking.x == wking.y - w->y)
							{
								wking.check = 0;
							}
						}
					}
					if (wking.check == 1)
					{
						return;
					}
				}
			}
		}
	}
}

int locAlg(int wx, int wy, int chngx, int chngy)
{
	wx += chngx;
	wy += chngy;
	if (wx > 7 || wx < 0 || wy > 7 || wy < 0)
	{
		return 0;
	}
	for (auto& w : wPiece)
	{
		if (w->x == wx && w->y == wy)
		{
			return 1;
		}
	}
	for (auto& b : bPiece)
	{
		if (wx == b->x && wy == b->y)
		{
			return 2;
		}
	}
	return 3;
}

//checks if color is in check
void checkmate()
{
	int valid = 1;
	int bxtemp = 0;
	int wxtemp = 0;
	int bytemp = 0;
	int wytemp = 0;
	int px = 0;
	int py = 0;
	int t = 0;

	//if white is in check
	if (wking.check == 1)
	{
		for (auto& w : wPiece)
		{
			if (w->death == 0)
			{
				valid = 1;
				bxtemp = -1;
				wxtemp = -1;
				bytemp = -1;
				wytemp = -1;
				px = 0;
				py = 0;

				//pawn
				if (w->piece == PAWN)
				{
					//piece in front
					for (auto& w1 : wPiece)
					{
						if (w->x == w1->x && w1->y == w->y + 1)
						{
							valid = 0;
							break;
						}
					}
					for (auto& b : bPiece)
					{
						if (w->x == b->x && b->y == w->y + 1)
						{
							valid = 0;
							break;
						}
					}

					if (valid == 1)
					{
						w->y += 1;
						check();
						w->y -= 1;
						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
					}

					if (w->movesMade == 0)
					{
						for (auto& w1 : wPiece)
						{
							if (w->y + 2 == w1->y && w->x == w1->x)
							{
								valid = 0;
								break;
							}
						}
						for (auto& b : bPiece)
						{
							if (w->y + 2 == b->y && w->x == b->x)
							{
								valid = 0;
								break;
							}
						}
					}
					else
					{
						valid = 0;
					}

					if (valid == 1)
					{
						w->y += 2;
						check();
						w->y -= 2;
						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
					}

					//killing piece
					for (auto& b : bPiece)
					{
						if (b->piece != KING)
						{
							if (b->x == w->x + 1 && b->y == w->y + 1)
							{
								bDead++;
								px = b->x;
								py = b->y;
								b->death = 1;
								b->dead(bDead);

								w->x += 1;
								w->y += 1;
								check();
								w->x -= 1;
								w->y -= 1;

								col(b->y, b->x, py, px, b->piece);
								bDead--;
								b->x = px;
								b->y = py;
								b->death = 0;

								if (wking.check == 0)
								{
									wking.check = 1;
									return;
								}
							}
							if (b->x == w->x - 1 && b->y == w->y + 1)
							{
								bDead++;
								px = b->x;
								py = b->y;
								b->death = 1;
								b->dead(bDead);

								w->x -= 1;
								w->y += 1;
								check();
								w->x += 1;
								w->y -= 1;

								col(b->y, b->x, py, px, b->piece);
								bDead--;
								b->x = px;
								b->y = py;
								b->death = 0;

								if (wking.check == 0)
								{
									wking.check = 1;
									return;
								}
							}
						}

						if (b->enPassantCnt == 1)
						{
							if (b->x == w->x + 1 && b->y == w->y)
							{
								bDead++;
								px = b->x;
								py = b->y;
								b->death = 1;
								b->dead(bDead);

								w->x += 1;
								w->y += 1;
								check();
								w->x -= 1;
								w->y -= 1;

								col(b->y, b->x, py, px, b->piece);
								bDead--;
								b->x = px;
								b->y = py;
								b->death = 0;

								if (wking.check == 0)
								{
									wking.check = 1;
									return;
								}
							}
							if (b->x == w->x - 1 && b->y == w->y)
							{
								bDead++;
								px = b->x;
								py = b->y;
								b->death = 1;
								b->dead(bDead);

								w->x -= 1;
								w->y += 1;
								check();
								w->x += 1;
								w->y -= 1;

								col(b->y, b->x, py, px, b->piece);
								bDead--;
								b->x = px;
								b->y = py;
								b->death = 0;

								if (wking.check == 0)
								{
									wking.check = 1;
									return;
								}
							}
						}
					}
				}
				//rook
				if (w->piece == ROOK)
				{
					//horizontal left movement
					for (auto& b : bPiece)
					{
						if (b->x < w->x && b->y == w->y && b->x > bxtemp)
						{
							//for multiple pieces in the same row select one and store its x value then compare 
							//its x location to other black pieces and see which one is closest to the rook being 
							//checked and say that bxtemp is that x value
							bxtemp = b->x;
						}
					}
					for (auto& w1 : wPiece)
					{
						if (w1->x < w->x && w1->y == w->y && w1->x > bxtemp && w1->x > wxtemp && w1->piece != KING)
						{
							wxtemp = w1->x;
						}
					}

					int t = 0;
					while (t <= 7)
					{
						t++;
						w->x -= t;
						if (w->x == wxtemp)
						{
							w->x += t;
							break;
						}
						if (w->x == bxtemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);
									check();
									w->x += t;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x += t;
						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
					}

					wxtemp = 8;
					bxtemp = 8;

					//horizontal right movement
					for (auto& b : bPiece)
					{
						if (b->x > w->x && b->y == w->y && b->x < bxtemp)
						{
							bxtemp = b->x;
						}
					}
					for (auto& w1 : wPiece)
					{
						if (w1->x > w->x && w1->y == w->y && w1->x < bxtemp && w1->x < wxtemp && w1->piece != KING)
						{
							wxtemp = w1->x;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						w->x += t;
						if (w->x == wxtemp)
						{
							w->x -= t;
							break;
						}
						if (w->x == bxtemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x -= t;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x -= t;

						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
					}

					//vertical up movement
					for (auto& b : bPiece)
					{
						if (b->y < w->y && b->x == w->x && b->y > bytemp)
						{
							bytemp = b->y;
						}
					}
					for (auto& w1 : wPiece)
					{
						if (w1->y < w->y && w1->x == w->x && w1->y > bytemp && w1->y > wytemp && w1->piece != KING)
						{
							wytemp = w1->y;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						w->y -= t;
						if (w->y == wytemp)
						{
							w->y += t;
							break;
						}
						if (w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->y == bytemp && b->x == w->x)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->y += t;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->y += t;
						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
					}

					bytemp = 8;
					wytemp = 8;

					//vertical down movement
					for (auto& b : bPiece)
					{
						if (b->y > w->y && b->x == w->x && b->y < bytemp)
						{
							bytemp = b->y;
						}
					}
					for (auto& w1 : wPiece)
					{
						if (w1->y > w->y && w1->x == w->x && w1->y < bytemp && w1->y < wytemp && w1->piece != KING)
						{
							wytemp = w1->y;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						w->y += t;
						if (w->y == wytemp)
						{
							w->y -= t;
							break;
						}
						if (w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->y == bytemp && b->x == w->x)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->y -= t;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->y -= t;
						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
					}
				}
				//horse
				if (w->piece == HORSE)
				{
					switch (locAlg(w->x, w->y, -2, -1))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x -= 2;
						w->y -= 1;
						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x += 2;
									w->y += 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x -= 2;
						w->y -= 1;
						check();
						w->x += 2;
						w->y += 1;

						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
						break;
					}

					switch (locAlg(w->x, w->y, -2, 1))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x -= 2;
						w->y += 1;
						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x += 2;
									w->y -= 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x -= 2;
						w->y += 1;
						check();
						w->x += 2;
						w->y -= 1;

						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
						break;
					}

					switch (locAlg(w->x, w->y, 2, -1))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x += 2;
						w->y -= 1;
						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x -= 2;
									w->y += 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x += 2;
						w->y -= 1;
						check();
						w->x -= 2;
						w->y += 1;

						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
						break;
					}

					switch (locAlg(w->x, w->y, 2, 1))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x += 2;
						w->y += 1;
						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x -= 2;
									w->y -= 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x += 2;
						w->y += 1;
						check();
						w->x -= 2;
						w->y -= 1;

						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
						break;
					}

					switch (locAlg(w->x, w->y, -1, -2))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x -= 1;
						w->y -= 2;
						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x += 1;
									w->y += 2;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x -= 1;
						w->y -= 2;
						check();
						w->x += 1;
						w->y += 2;

						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
						break;
					}

					switch (locAlg(w->x, w->y, -1, 2))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x -= 1;
						w->y += 2;
						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x += 1;
									w->y -= 2;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x -= 1;
						w->y += 2;
						check();
						w->x += 1;
						w->y -= 2;

						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
						break;
					}

					switch (locAlg(w->x, w->y, 1, -2))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x += 1;
						w->y -= 2;
						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x -= 1;
									w->y += 2;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x += 1;
						w->y -= 2;
						check();
						w->x += 1;
						w->y -= 2;

						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
						break;
					}

					switch (locAlg(w->x, w->y, 1, 2))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x += 1;
						w->y += 2;
						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x -= 1;
									w->y -= 2;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x += 1;
						w->y += 2;
						check();
						w->x -= 1;
						w->y -= 2;

						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
						break;
					}
				}
				//bishop
				if (w->piece == BISHOP)
				{
					//left down diagonal
					wytemp = 8;
					bytemp = 8;
					t = 0;

					for (auto& b : bPiece)
					{
						if (b->x < w->x && b->y > w->y && w->x - b->x == b->y - w->y && b->x > bxtemp && b->y < bytemp)
						{
							bxtemp = b->x;
							bytemp = b->y;
						}
					}

					for (auto& w1 : wPiece)
					{
						if (w1->x < w->x && w1->y > w->y && w->x - w1->x == w1->y - w->y && w1->x > bxtemp && w1->y < bytemp && w1->x > wxtemp && w1->y < wytemp)
						{
							wxtemp = w1->x;
							wytemp = w1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						w->x -= t;
						w->y += t;

						if (w->x == wxtemp || w->y == wytemp)
						{
							w->x += t;
							w->y -= t;
							break;
						}

						if (w->x == bxtemp || w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == bytemp)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);
									check();
									w->x += t;
									w->y -= t;

									col(b->y, b->x, py, px, b->piece);

									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x += t;
						w->y -= t;

						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
					}

					//right down diagonal
					bxtemp = 8;
					bytemp = 8;
					wxtemp = 8;
					wytemp = 8;
					t = 0;

					for (auto& b : bPiece)
					{
						if (b->x > w->x && b->y > w->y && b->x - w->x == b->y - w->y && b->x < bxtemp && b->y < bytemp)
						{
							bxtemp = b->x;
							bytemp = b->y;
						}
					}

					for (auto& w1 : wPiece)
					{
						if (w1->x > w->x && w1->y > w->y && w1->x - w->x == w1->y - w->y && w1->x < bxtemp && w1->y < bytemp && w1->x < wxtemp && w1->y < wytemp)
						{
							wxtemp = w1->x;
							wytemp = w1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						w->x += t;
						w->y += t;

						if (w->x == wxtemp || w->y == wytemp)
						{
							w->x -= t;
							w->y -= t;
							break;
						}

						if (w->x == bxtemp || w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == bytemp)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);
									check();
									w->x -= t;
									w->y -= t;

									col(b->y, b->x, py, px, b->piece);

									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x -= t;
						w->y -= t;
						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
					}

					//left up diagonal
					bxtemp = -1;
					bytemp = -1;
					wxtemp = -1;
					wytemp = -1;
					t = 0;

					for (auto& b : bPiece)
					{
						if (b->x < w->x && b->y < w->y && w->x - b->x == w->y - b->y && b->x > bxtemp && b->y > bytemp)
						{
							bxtemp = b->x;
							bytemp = b->y;
						}
					}

					for (auto& w1 : wPiece)
					{
						if (w1->x < w->x && w1->y < w->y && w->x - w1->x == w->y - w1->y && w1->x > bxtemp && w1->y > bytemp && w1->x > wxtemp && w1->y > wytemp)
						{
							wxtemp = w1->x;
							wytemp = w1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						w->x -= t;
						w->y -= t;

						if (w->x == wxtemp || w->y == wytemp)
						{
							w->x += t;
							w->y += t;
							break;
						}

						if (w->x == bxtemp || w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == bytemp)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);
									check();
									w->x += t;
									w->y += t;

									col(b->y, b->x, py, px, b->piece);

									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x += t;
						w->y += t;
						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
					}

					//right up diagonal
					bxtemp = 8;
					bytemp = -1;
					wxtemp = 8;
					wytemp = -1;
					t = 0;

					for (auto& b : bPiece)
					{
						if (b->x > w->x && b->y < w->y && b->x - w->x == w->y - b->y && b->x < bxtemp && b->y > bytemp)
						{
							bxtemp = b->x;
							bytemp = b->y;
						}
					}

					for (auto& w1 : wPiece)
					{
						if (w1->x > w->x && w1->y < w->y && w1->x - w->x == w->y - w1->y && w1->x < bxtemp && w1->y > bytemp && w1->x < wxtemp && w1->y > wytemp)
						{
							wxtemp = w1->x;
							wytemp = w1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						w->x += t;
						w->y -= t;

						if (w->x == wxtemp || w->y == wytemp)
						{
							w->x -= t;
							w->y += t;
							break;
						}

						if (w->x == bxtemp || w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == bytemp)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);
									check();
									w->x -= t;
									w->y += t;

									col(b->y, b->x, py, px, b->piece);

									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x -= t;
						w->y += t;
						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
					}
				}
				//queen
				if (w->piece == QUEEN)
				{
					//horizontal left movement
					for (auto& b : bPiece)
					{
						if (b->x < w->x && b->y == w->y && b->x > bxtemp)
						{
							bxtemp = b->x;
						}
					}
					for (auto& w1 : wPiece)
					{
						if (w1->x < w->x && w1->y == w->y && w1->x > bxtemp && w1->x > wxtemp && w1->piece != KING)
						{
							wxtemp = w1->x;
						}
					}

					int t = 0;
					while (t <= 7)
					{
						t++;
						w->x -= t;
						if (w->x == wxtemp)
						{
							w->x += t;
							break;
						}
						if (w->x == bxtemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);
									check();
									w->x += t;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x += t;
						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
					}

					wxtemp = 8;
					bxtemp = 8;

					//horizontal right movement
					for (auto& b : bPiece)
					{
						if (b->x > w->x && b->y == w->y && b->x < bxtemp)
						{
							bxtemp = b->x;
						}
					}
					for (auto& w1 : wPiece)
					{
						if (w1->x > w->x && w1->y == w->y && w1->x < bxtemp && w1->x < wxtemp && w1->piece != KING)
						{
							wxtemp = w1->x;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						w->x += t;
						if (w->x == wxtemp)
						{
							w->x -= t;
							break;
						}
						if (w->x == bxtemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x -= t;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x -= t;

						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
					}

					//vertical up movement
					for (auto& b : bPiece)
					{
						if (b->y < w->y && b->x == w->x && b->y > bytemp)
						{
							bytemp = b->y;
						}
					}
					for (auto& w1 : wPiece)
					{
						if (w1->y < w->y && w1->x == w->x && w1->y > bytemp && w1->y > wytemp && w1->piece != KING)
						{
							wytemp = w1->y;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						w->y -= t;
						if (w->y == wytemp)
						{
							w->y += t;
							break;
						}
						if (w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->y == bytemp && b->x == w->x)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->y += t;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->y += t;
						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
					}

					bytemp = 8;
					wytemp = 8;

					//vertical down movement
					for (auto& b : bPiece)
					{
						if (b->y > w->y && b->x == w->x && b->y < bytemp)
						{
							bytemp = b->y;
						}
					}
					for (auto& w1 : wPiece)
					{
						if (w1->y > w->y && w1->x == w->x && w1->y < bytemp && w1->y < wytemp && w1->piece != KING)
						{
							wytemp = w1->y;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						w->y += t;
						if (w->y == wytemp)
						{
							w->y -= t;
							break;
						}
						if (w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->y == bytemp && b->x == w->x)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->y -= t;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->y -= t;
						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
					}


					//left down diagonal
					bxtemp = -1;
					bytemp = 8;
					wxtemp = -1;
					wytemp = 8;

					t = 0;

					for (auto& b : bPiece)
					{
						if (b->x < w->x && b->y > w->y && w->x - b->x == b->y - w->y && b->x > bxtemp && b->y < bytemp)
						{
							bxtemp = b->x;
							bytemp = b->y;
						}
					}

					for (auto& w1 : wPiece)
					{
						if (w1->x < w->x && w1->y > w->y && w->x - w1->x == w1->y - w->y && w1->x > bxtemp && w1->y < bytemp && w1->x > wxtemp && w1->y < wytemp)
						{
							wxtemp = w1->x;
							wytemp = w1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						w->x -= t;
						w->y += t;

						if (w->x == wxtemp || w->y == wytemp)
						{
							w->x += t;
							w->y -= t;
							break;
						}

						if (w->x == bxtemp || w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == bytemp)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);
									check();
									w->x += t;
									w->y -= t;

									col(b->y, b->x, py, px, b->piece);

									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x += t;
						w->y -= t;

						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
					}

					//right down diagonal
					bxtemp = 8;
					bytemp = 8;
					wxtemp = 8;
					wytemp = 8;
					t = 0;

					for (auto& b : bPiece)
					{
						if (b->x > w->x && b->y > w->y && b->x - w->x == b->y - w->y && b->x < bxtemp && b->y < bytemp)
						{
							bxtemp = b->x;
							bytemp = b->y;
						}
					}

					for (auto& w1 : wPiece)
					{
						if (w1->x > w->x && w1->y > w->y && w1->x - w->x == w1->y - w->y && w1->x < bxtemp && w1->y < bytemp && w1->x < wxtemp && w1->y < wytemp)
						{
							wxtemp = w1->x;
							wytemp = w1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						w->x += t;
						w->y += t;

						if (w->x == wxtemp || w->y == wytemp)
						{
							w->x -= t;
							w->y -= t;
							break;
						}

						if (w->x == bxtemp || w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == bytemp)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);
									check();
									w->x -= t;
									w->y -= t;

									col(b->y, b->x, py, px, b->piece);

									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x -= t;
						w->y -= t;
						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
					}

					//left up diagonal
					bxtemp = -1;
					bytemp = -1;
					wxtemp = -1;
					wytemp = -1;
					t = 0;

					for (auto& b : bPiece)
					{
						if (b->x < w->x && b->y < w->y && w->x - b->x == w->y - b->y && b->x > bxtemp && b->y > bytemp)
						{
							bxtemp = b->x;
							bytemp = b->y;
						}
					}

					for (auto& w1 : wPiece)
					{
						if (w1->x < w->x && w1->y < w->y && w->x - w1->x == w->y - w1->y && w1->x > bxtemp && w1->y > bytemp && w1->x > wxtemp && w1->y > wytemp)
						{
							wxtemp = w1->x;
							wytemp = w1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						w->x -= t;
						w->y -= t;

						if (w->x == wxtemp || w->y == wytemp)
						{
							w->x += t;
							w->y += t;
							break;
						}

						if (w->x == bxtemp || w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == bytemp)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);
									check();
									w->x += t;
									w->y += t;

									col(b->y, b->x, py, px, b->piece);

									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x += t;
						w->y += t;
						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
					}

					//right up diagonal
					bxtemp = 8;
					bytemp = -1;
					wxtemp = 8;
					wytemp = -1;
					t = 0;

					for (auto& b : bPiece)
					{
						if (b->x > w->x && b->y < w->y && b->x - w->x == w->y - b->y && b->x < bxtemp && b->y > bytemp)
						{
							bxtemp = b->x;
							bytemp = b->y;
						}
					}

					for (auto& w1 : wPiece)
					{
						if (w1->x > w->x && w1->y < w->y && w1->x - w->x == w->y - w1->y && w1->x < bxtemp && w1->y > bytemp && w1->x < wxtemp && w1->y > wytemp)
						{
							wxtemp = w1->x;
							wytemp = w1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						w->x += t;
						w->y -= t;

						if (w->x == wxtemp || w->y == wytemp)
						{
							w->x -= t;
							w->y += t;
							break;
						}

						if (w->x == bxtemp || w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == bytemp)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);
									check();
									w->x -= t;
									w->y += t;

									col(b->y, b->x, py, px, b->piece);

									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x -= t;
						w->y += t;
						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
					}
				}
				//king
				if (w->piece == KING)
				{
					//right
					switch (locAlg(w->x, w->y, 1, 0))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x += 1;
						if (king.x == w->x + 1 && (king.y == w->y || king.y == w->y + 1 || king.y == w->y - 1))
						{
							w->x -= 1;
							break;
						}
						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x -= 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x += 1;
						if (king.x == w->x + 1 && (king.y == w->y || king.y == w->y + 1 || king.y == w->y - 1))
						{
							w->x -= 1;
							break;
						}
						check();
						w->x -= 1;

						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
						break;
					}

					//left
					switch (locAlg(w->x, w->y, -1, 0))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x -= 1;
						if (king.x == w->x - 1 && (king.y == w->y || king.y == w->y + 1 || king.y == w->y - 1))
						{
							w->x += 1;
							break;
						}
						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x += 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x -= 1;
						if (king.x == w->x - 1 && (king.y == w->y || king.y == w->y + 1 || king.y == w->y - 1))
						{
							w->x += 1;
							break;
						}
						check();
						w->x += 1;

						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
						break;
					}

					//up
					switch (locAlg(w->x, w->y, 0, -1))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->y -= 1;
						if (king.y == w->y - 1 && (king.x == w->x || king.x == w->x + 1 || king.x == w->x - 1))
						{
							w->y += 1;
							break;
						}
						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->y += 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->y -= 1;
						if (king.y == w->y - 1 && (king.x == w->x || king.x == w->x + 1 || king.x == w->x - 1))
						{
							w->y += 1;
							break;
						}
						check();
						w->y += 1;

						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
						break;
					}

					//down
					switch (locAlg(w->x, w->y, 0, 1))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->y += 1;
						if (king.y == w->y + 1 && (king.x == w->x || king.x == w->x + 1 || king.x == w->x - 1))
						{
							w->y -= 1;
							break;
						}
						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->y -= 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->y += 1;
						if (king.y == w->y + 1 && (king.x == w->x || king.x == w->x + 1 || king.x == w->x - 1))
						{
							w->y -= 1;
							break;
						}
						check();
						w->y -= 1;

						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
						break;
					}

					//right up
					switch (locAlg(w->x, w->y, 1, -1))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x += 1;
						w->y -= 1;
						if (king.y == w->y - 1 && king.x == w->x + 1)
						{
							w->x -= 1;
							w->y += 1;
							break;
						}

						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x -= 1;
									w->y += 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x += 1;
						w->y -= 1;
						if (king.y == w->y - 1 && king.x == w->x + 1)
						{
							w->x -= 1;
							w->y += 1;
							break;
						}
						check();
						w->x -= 1;
						w->y += 1;

						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
						break;
					}

					//left up
					switch (locAlg(w->x, w->y, -1, -1))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x -= 1;
						w->y -= 1;
						if (king.y == w->y - 1 && king.x == w->x - 1)
						{
							w->x += 1;
							w->y += 1;
							break;
						}
						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x += 1;
									w->y += 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x -= 1;
						w->y -= 1;
						if (king.y == w->y - 1 && king.x == w->x - 1)
						{
							w->x += 1;
							w->y += 1;
							break;
						}
						check();
						w->x += 1;
						w->y += 1;

						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
						break;
					}

					//right down
					switch (locAlg(w->x, w->y, 1, 1))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x += 1;
						w->y += 1;
						if (king.y == w->y + 1 && king.x == w->x + 1)
						{
							w->x -= 1;
							w->y -= 1;
							break;
						}

						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x -= 1;
									w->y -= 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x += 1;
						w->y += 1;
						if (king.y == w->y + 1 && king.x == w->x + 1)
						{
							w->x -= 1;
							w->y -= 1;
							break;
						}
						check();
						w->x -= 1;
						w->y -= 1;

						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
						break;
					}

					//left down
					switch (locAlg(w->x, w->y, -1, 1))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x -= 1;
						w->y += 1;
						if (king.y == w->y + 1 && king.x == w->x - 1)
						{
							w->x += 1;
							w->y -= 1;
							break;
						}
						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x += 1;
									w->y -= 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										wking.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x -= 1;
						w->y += 1;
						if (king.y == w->y + 1 && king.x == w->x - 1)
						{
							w->x += 1;
							w->y -= 1;
							break;
						}
						check();
						w->x += 1;
						w->y -= 1;

						if (wking.check == 0)
						{
							wking.check = 1;
							return;
						}
						break;
					}
				}
			}
		}
		//if this runs it means checkmate so black wins
		win = 1;
	}

	//if black is in check
	if (king.check == 1)
	{
		for (auto& b : bPiece)
		{
			if (b->death == 0)
			{
				valid = 1;
				bxtemp = -1;
				wxtemp = -1;
				bytemp = -1;
				wytemp = -1;
				px = 0;
				py = 0;

				//pawn
				if (b->piece == PAWN)
				{
					//piece in front
					for (auto& b1 : bPiece)
					{
						if (b->x == b1->x && b1->y == b->y - 1)
						{
							valid = 0;
							break;
						}
					}
					for (auto& w : wPiece)
					{
						if (b->x == w->x && w->y == b->y - 1)
						{
							valid = 0;
							break;
						}
					}

					if (valid == 1)
					{
						b->y -= 1;
						check();
						b->y += 1;
						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
					}

					if (b->movesMade == 0)
					{
						for (auto& b1 : bPiece)
						{
							if (b->y - 2 == b1->y && b->x == b1->x)
							{
								valid = 0;
								break;
							}
						}
						for (auto& w : wPiece)
						{
							if (b->y - 2 == w->y && b->x == w->x)
							{
								valid = 0;
								break;
							}
						}
					}
					else
					{
						valid = 0;
					}

					if (valid == 1)
					{
						b->y -= 2;
						check();
						b->y += 2;
						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
					}

					//killing piece
					for (auto& w : wPiece)
					{
						if (w->piece != KING)
						{
							if (w->x == b->x + 1 && w->y == b->y - 1)
							{
								wDead++;
								px = w->x;
								py = w->y;
								w->death = 1;
								w->dead(wDead);

								b->x += 1;
								b->y -= 1;
								check();
								b->x -= 1;
								b->y += 1;

								col(w->y, w->x, py, px, w->piece + 6);
								wDead--;
								w->x = px;
								w->y = py;
								w->death = 0;

								if (king.check == 0)
								{
									king.check = 1;
									return;
								}
							}
							if (w->x == b->x - 1 && w->y == b->y - 1)
							{
								wDead++;
								px = w->x;
								py = w->y;
								w->death = 1;
								w->dead(wDead);

								b->x -= 1;
								b->y -= 1;
								check();
								b->x += 1;
								b->y += 1;

								col(w->y, w->x, py, px, w->piece + 6);
								wDead--;
								w->x = px;
								w->y = py;
								w->death = 0;

								if (king.check == 0)
								{
									king.check = 1;
									return;
								}
							}
						}
						if (w->enPassantCnt == 1)
						{
							if (w->x == b->x + 1 && w->y == b->y)
							{
								wDead++;
								px = w->x;
								py = w->y;
								w->death = 1;
								w->dead(wDead);

								b->x += 1;
								b->y -= 1;
								check();
								b->x -= 1;
								b->y += 1;

								col(w->y, w->x, py, px, w->piece + 6);
								wDead--;
								w->x = px;
								w->y = py;
								w->death = 0;

								if (king.check == 0)
								{
									king.check = 1;
									return;
								}
							}
							if (w->x == b->x - 1 && w->y == b->y)
							{
								wDead++;
								px = w->x;
								py = w->y;
								w->death = 1;
								w->dead(wDead);

								b->x -= 1;
								b->y -= 1;
								check();
								b->x += 1;
								b->y += 1;

								col(w->y, w->x, py, px, w->piece + 6);
								wDead--;
								w->x = px;
								w->y = py;
								w->death = 0;

								if (king.check == 0)
								{
									king.check = 1;
									return;
								}
							}
						}
					}
				}
				//rook
				if (b->piece == ROOK)
				{
					//horizontal left movement
					for (auto& w : wPiece)
					{
						if (w->x < b->x && w->y == b->y && w->x > wxtemp)
						{
							//for multiple pieces in the same row select one and store its x value then compare 
							//its x location to other black pieces and see which one is closest to the rook being 
							//checked and say that bxtemp is that x value
							wxtemp = w->x;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->x < b->x && b1->y == b->y && b1->x > wxtemp && b1->x > bxtemp && b1->piece != KING)
						{
							bxtemp = b1->x;
						}
					}

					int t = 0;
					while (t <= 7)
					{
						t++;
						b->x -= t;
						if (b->x == bxtemp)
						{
							b->x += t;
							break;
						}
						if (b->x == wxtemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);
									check();
									b->x += t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x += t;
						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
					}

					wxtemp = 8;
					bxtemp = 8;

					//horizontal right movement
					for (auto& w : wPiece)
					{
						if (w->x > b->x && w->y == b->y && w->x < wxtemp)
						{
							wxtemp = w->x;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->x > b->x && b1->y == b->y && b1->x < wxtemp && b1->x < bxtemp && b1->piece != KING)
						{
							bxtemp = b1->x;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						b->x += t;
						if (b->x == bxtemp)
						{
							b->x -= t;
							break;
						}
						if (b->x == wxtemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x -= t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x -= t;

						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
					}

					//vertical up movement
					for (auto& w : wPiece)
					{
						if (w->y < b->y && w->x == b->x && w->y > wytemp)
						{
							wytemp = w->y;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->y < b->y && b1->x == b->x && b1->y > wytemp && b1->y > bytemp && b1->piece != KING)
						{
							bytemp = b1->y;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						b->y -= t;
						if (b->y == bytemp)
						{
							b->y += t;
							break;
						}
						if (b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->y == wytemp && w->x == b->x)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->y += t;

									col(w->y, w->x, py, px, w->piece + 6);
									bDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->y += t;
						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
					}

					bytemp = 8;
					wytemp = 8;

					//vertical down movement
					for (auto& w : wPiece)
					{
						if (w->y > b->y && w->x == b->x && w->y < wytemp)
						{
							wytemp = w->y;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->y > b->y && b1->x == b->x && b1->y < wytemp && b1->y < bytemp && b1->piece != KING)
						{
							bytemp = b1->y;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						b->y += t;
						if (b->y == bytemp)
						{
							b->y -= t;
							break;
						}
						if (b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->y == wytemp && w->x == b->x)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->y -= t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->y -= t;
						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
					}
				}
				//horse
				if (b->piece == HORSE)
				{
					switch (locAlg(b->x, b->y, -2, -1))
					{
					case 0:
						break;
					case 1:
						b->x -= 2;
						b->y -= 1;
						//run death sequence
						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (b->x == w->x && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x += 2;
									b->y += 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x -= 2;
						b->y -= 1;
						check();
						b->x += 2;
						b->y += 1;

						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
						break;
					}

					switch (locAlg(b->x, b->y, -2, 1))
					{
					case 0:
						break;
					case 1:
						b->x -= 2;
						b->y += 1;
						//run death sequence
						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (b->x == w->x && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x += 2;
									b->y -= 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x -= 2;
						b->y += 1;
						check();
						b->x += 2;
						b->y -= 1;

						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
						break;
					}

					switch (locAlg(b->x, b->y, 2, -1))
					{
					case 0:
						break;
					case 1:
						b->x += 2;
						b->y -= 1;
						//run death sequence
						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (b->x == w->x && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x -= 2;
									b->y += 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x += 2;
						b->y -= 1;
						check();
						b->x -= 2;
						b->y += 1;

						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
						break;
					}

					switch (locAlg(b->x, b->y, 2, 1))
					{
					case 0:
						break;
					case 1:
						b->x += 2;
						b->y += 1;
						//run death sequence
						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (b->x == w->x && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x -= 2;
									b->y -= 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x += 2;
						b->y += 1;
						check();
						b->x -= 2;
						b->y -= 1;

						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
						break;
					}

					switch (locAlg(b->x, b->y, -1, -2))
					{
					case 0:
						break;
					case 1:
						b->x -= 1;
						b->y -= 2;
						//run death sequence
						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (b->x == w->x && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x += 1;
									b->y += 2;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x -= 1;
						b->y -= 2;
						check();
						b->x += 1;
						b->y += 2;

						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
						break;
					}

					switch (locAlg(b->x, b->y, -1, 2))
					{
					case 0:
						break;
					case 1:
						b->x -= 1;
						b->y += 2;
						//run death sequence
						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (b->x == w->x && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x += 1;
									b->y -= 2;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x -= 1;
						b->y += 2;
						check();
						b->x += 1;
						b->y -= 2;

						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
						break;
					}

					switch (locAlg(b->x, b->y, 1, -2))
					{
					case 0:
						break;
					case 1:
						b->x += 1;
						b->y -= 2;
						//run death sequence
						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (b->x == w->x && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x -= 1;
									b->y += 2;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x += 1;
						b->y -= 2;
						check();
						b->x += 1;
						b->y -= 2;

						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
						break;
					}

					switch (locAlg(b->x, b->y, 1, 2))
					{
					case 0:
						break;
					case 1:
						b->x += 1;
						b->y += 2;
						//run death sequence
						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (b->x == w->x && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x -= 1;
									b->y -= 2;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x += 1;
						b->y += 2;
						check();
						b->x -= 1;
						b->y -= 2;

						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
						break;
					}
				}
				//bishop
				if (b->piece == BISHOP)
				{
					//left down diagonal
					wytemp = 8;
					bytemp = 8;
					t = 0;

					for (auto& w : wPiece)
					{
						if (w->x < b->x && w->y > b->y && b->x - w->x == w->y - b->y && w->x > wxtemp && w->y < wytemp)
						{
							wxtemp = w->x;
							wytemp = w->y;
						}
					}
					for (auto& b1 : wPiece)
					{
						if (b1->x < b->x && b1->y > b->y && b->x - b1->x == b1->y - b->y && b1->x > wxtemp && b1->y < wytemp && b1->x > bxtemp && b1->y < bytemp)
						{
							bxtemp = b1->x;
							bytemp = b1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						b->x -= t;
						b->y += t;

						if (b->x == bxtemp || b->y == bytemp)
						{
							b->x += t;
							b->y -= t;
							break;
						}

						if (b->x == wxtemp || b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == wytemp)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);
									check();
									b->x += t;
									b->y -= t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x += t;
						b->y -= t;

						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
					}

					//right down diagonal
					bxtemp = 8;
					bytemp = 8;
					wxtemp = 8;
					wytemp = 8;
					t = 0;

					for (auto& w : wPiece)
					{
						if (w->x > b->x && w->y > b->y && w->x - b->x == w->y - b->y && w->x < wxtemp && w->y < wytemp)
						{
							wxtemp = w->x;
							wytemp = w->y;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->x > b->x && b1->y > b->y && b1->x - b->x == b1->y - b->y && b1->x < wxtemp && b1->y < wytemp && b1->x < bxtemp && b1->y < bytemp)
						{
							bxtemp = b1->x;
							bytemp = b1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						b->x += t;
						b->y += t;

						if (b->x == bxtemp || b->y == bytemp)
						{
							b->x -= t;
							b->y -= t;
							break;
						}

						if (b->x == wxtemp || b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == wytemp)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);
									check();
									b->x -= t;
									b->y -= t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x -= t;
						b->y -= t;
						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
					}

					//left up diagonal
					bxtemp = -1;
					bytemp = -1;
					wxtemp = -1;
					wytemp = -1;
					t = 0;

					for (auto& w : wPiece)
					{
						if (w->x < b->x && w->y < b->y && b->x - w->x == b->y - w->y && w->x > wxtemp && w->y > wytemp)
						{
							wxtemp = w->x;
							wytemp = w->y;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->x < b->x && b1->y < b->y && b->x - b1->x == b->y - b1->y && b1->x > wxtemp && b1->y > wytemp && b1->x > bxtemp && b1->y > bytemp)
						{
							bxtemp = b1->x;
							bytemp = b1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						b->x -= t;
						b->y -= t;

						if (b->x == bxtemp || b->y == bytemp)
						{
							b->x += t;
							b->y += t;
							break;
						}

						if (b->x == wxtemp || b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == wytemp)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);
									check();
									b->x += t;
									b->y += t;

									col(w->y, w->x, py, px, w->piece + 6);

									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x += t;
						b->y += t;
						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
					}

					//right up diagonal
					bxtemp = 8;
					bytemp = -1;
					wxtemp = 8;
					wytemp = -1;
					t = 0;

					for (auto& w : wPiece)
					{
						if (w->x > b->x && w->y < b->y && w->x - b->x == b->y - w->y && w->x < wxtemp && w->y > wytemp)
						{
							wxtemp = w->x;
							wytemp = w->y;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->x > b->x && b1->y < b->y && b1->x - b->x == b->y - b1->y && b1->x < wxtemp && b1->y > wytemp && b1->x < bxtemp && b1->y > bytemp)
						{
							bxtemp = b1->x;
							bytemp = b1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						b->x += t;
						b->y -= t;

						if (b->x == bxtemp || b->y == bytemp)
						{
							b->x -= t;
							b->y += t;
							break;
						}

						if (b->x == wxtemp || b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == wytemp)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);
									check();
									b->x -= t;
									b->y += t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x -= t;
						b->y += t;
						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
					}
				}
				//queen
				if (b->piece == QUEEN)
				{
					//horizontal left movement
					for (auto& w : wPiece)
					{
						if (w->x < b->x && w->y == b->y && w->x > wxtemp)
						{
							wxtemp = w->x;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->x < b->x && b1->y == b->y && b1->x > wxtemp && b1->x > bxtemp && b1->piece != KING)
						{
							bxtemp = b1->x;
						}
					}

					int t = 0;
					while (t <= 7)
					{
						t++;
						b->x -= t;
						if (b->x == bxtemp)
						{
							b->x += t;
							break;
						}
						if (b->x == wxtemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);
									check();
									b->x += t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x += t;
						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
					}

					wxtemp = 8;
					bxtemp = 8;

					//horizontal right movement
					for (auto& w : wPiece)
					{
						if (w->x > b->x && w->y == b->y && w->x < wxtemp)
						{
							wxtemp = w->x;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->x > b->x && b1->y == b->y && b1->x < wxtemp && b1->x < bxtemp && b1->piece != KING)
						{
							bxtemp = b1->x;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						b->x += t;
						if (b->x == bxtemp)
						{
							b->x -= t;
							break;
						}
						if (b->x == wxtemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x -= t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x -= t;

						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
					}

					//vertical up movement
					for (auto& w : wPiece)
					{
						if (w->y < b->y && w->x == b->x && w->y > wytemp)
						{
							wytemp = w->y;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->y < b->y && b1->x == b->x && b1->y > wytemp && b1->y > bytemp && b1->piece != KING)
						{
							bytemp = b1->y;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						b->y -= t;
						if (b->y == bytemp)
						{
							b->y += t;
							break;
						}
						if (b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->y == wytemp && w->x == b->x)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->y += t;

									col(w->y, w->x, py, px, w->piece + 6);
									bDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->y += t;
						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
					}

					bytemp = 8;
					wytemp = 8;

					//vertical down movement
					for (auto& w : wPiece)
					{
						if (w->y > b->y && w->x == b->x && w->y < wytemp)
						{
							wytemp = w->y;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->y > b->y && b1->x == b->x && b1->y < wytemp && b1->y < bytemp && b1->piece != KING)
						{
							bytemp = b1->y;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						b->y += t;
						if (b->y == bytemp)
						{
							b->y -= t;
							break;
						}
						if (b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->y == wytemp && w->x == b->x)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->y -= t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->y -= t;
						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
					}

					//left down diagonal
					wytemp = 8;
					bytemp = 8;
					t = 0;

					for (auto& w : wPiece)
					{
						if (w->x < b->x && w->y > b->y && b->x - w->x == w->y - b->y && w->x > wxtemp && w->y < wytemp)
						{
							wxtemp = w->x;
							wytemp = w->y;
						}
					}
					for (auto& b1 : wPiece)
					{
						if (b1->x < b->x && b1->y > b->y && b->x - b1->x == b1->y - b->y && b1->x > wxtemp && b1->y < wytemp && b1->x > bxtemp && b1->y < bytemp)
						{
							bxtemp = b1->x;
							bytemp = b1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						b->x -= t;
						b->y += t;

						if (b->x == bxtemp || b->y == bytemp)
						{
							b->x += t;
							b->y -= t;
							break;
						}

						if (b->x == wxtemp || b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == wytemp)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);
									check();
									b->x += t;
									b->y -= t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x += t;
						b->y -= t;

						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
					}

					//right down diagonal
					bxtemp = 8;
					bytemp = 8;
					wxtemp = 8;
					wytemp = 8;
					t = 0;

					for (auto& w : wPiece)
					{
						if (w->x > b->x && w->y > b->y && w->x - b->x == w->y - b->y && w->x < wxtemp && w->y < wytemp)
						{
							wxtemp = w->x;
							wytemp = w->y;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->x > b->x && b1->y > b->y && b1->x - b->x == b1->y - b->y && b1->x < wxtemp && b1->y < wytemp && b1->x < bxtemp && b1->y < bytemp)
						{
							bxtemp = b1->x;
							bytemp = b1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						b->x += t;
						b->y += t;

						if (b->x == bxtemp || b->y == bytemp)
						{
							b->x -= t;
							b->y -= t;
							break;
						}

						if (b->x == wxtemp || b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == wytemp)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);
									check();
									b->x -= t;
									b->y -= t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x -= t;
						b->y -= t;
						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
					}

					//left up diagonal
					bxtemp = -1;
					bytemp = -1;
					wxtemp = -1;
					wytemp = -1;
					t = 0;

					for (auto& w : wPiece)
					{
						if (w->x < b->x && w->y < b->y && b->x - w->x == b->y - w->y && w->x > wxtemp && w->y > wytemp)
						{
							wxtemp = w->x;
							wytemp = w->y;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->x < b->x && b1->y < b->y && b->x - b1->x == b->y - b1->y && b1->x > wxtemp && b1->y > wytemp && b1->x > bxtemp && b1->y > bytemp)
						{
							bxtemp = b1->x;
							bytemp = b1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						b->x -= t;
						b->y -= t;

						if (b->x == bxtemp || b->y == bytemp)
						{
							b->x += t;
							b->y += t;
							break;
						}

						if (b->x == wxtemp || b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == wytemp)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);
									check();
									b->x += t;
									b->y += t;

									col(w->y, w->x, py, px, w->piece + 6);

									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x += t;
						b->y += t;
						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
					}

					//right up diagonal
					bxtemp = 8;
					bytemp = -1;
					wxtemp = 8;
					wytemp = -1;
					t = 0;

					for (auto& w : wPiece)
					{
						if (w->x > b->x && w->y < b->y && w->x - b->x == b->y - w->y && w->x < wxtemp && w->y > wytemp)
						{
							wxtemp = w->x;
							wytemp = w->y;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->x > b->x && b1->y < b->y && b1->x - b->x == b->y - b1->y && b1->x < wxtemp && b1->y > wytemp && b1->x < bxtemp && b1->y > bytemp)
						{
							bxtemp = b1->x;
							bytemp = b1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						b->x += t;
						b->y -= t;

						if (b->x == bxtemp || b->y == bytemp)
						{
							b->x -= t;
							b->y += t;
							break;
						}

						if (b->x == wxtemp || b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == wytemp)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);
									check();
									b->x -= t;
									b->y += t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x -= t;
						b->y += t;
						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
					}
				}
				//king
				if (b->piece == KING)
				{
					//right
					switch (locAlg(b->x, b->y, 1, 0))
					{
					case 0:
						break;
					case 1:
						b->x += 1;
						if (wking.x == b->x + 1 && (wking.y == b->y || wking.y == b->y + 1 || wking.y == b->y - 1))
						{
							b->x -= 1;
							break;
						}

						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x -= 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x += 1;
						if (wking.x == b->x + 1 && (wking.y == b->y || wking.y == b->y + 1 || wking.y == b->y - 1))
						{
							b->x -= 1;
							break;
						}
						check();
						b->x -= 1;

						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
						break;
					}

					//left
					switch (locAlg(b->x, b->y, -1, 0))
					{
					case 0:
						break;
					case 1:
						b->x -= 1;
						if (wking.x == b->x - 1 && (wking.y == b->y || wking.y == b->y + 1 || wking.y == b->y - 1))
						{
							b->x += 1;
							break;
						}

						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x += 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x -= 1;
						if (wking.x == b->x - 1 && (wking.y == b->y || wking.y == b->y + 1 || wking.y == b->y - 1))
						{
							b->x += 1;
							break;
						}
						check();
						b->x += 1;

						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
						break;
					}

					//up
					switch (locAlg(b->x, b->y, 0, -1))
					{
					case 0:
						break;
					case 1:
						b->y -= 1;
						if (wking.y == b->y - 1 && (wking.x == b->x || wking.x == b->x + 1 || wking.x == b->x - 1))
						{
							b->y += 1;
							break;
						}

						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->y += 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->y -= 1;
						if (wking.y == b->y - 1 && (wking.x == b->x || wking.x == b->x + 1 || wking.x == b->x - 1))
						{
							b->y += 1;
							break;
						}
						check();
						b->y += 1;

						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
						break;
					}

					//down
					switch (locAlg(b->x, b->y, 0, 1))
					{
					case 0:
						break;
					case 1:
						b->y += 1;
						if (wking.y == b->y + 1 && (wking.x == b->x || wking.x == b->x + 1 || wking.x == b->x - 1))
						{
							b->y -= 1;
							break;
						}

						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->y -= 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->y += 1;
						if (wking.y == b->y + 1 && (wking.x == b->x || wking.x == b->x + 1 || wking.x == b->x - 1))
						{
							b->y -= 1;
							break;
						}
						check();
						b->y -= 1;

						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
						break;
					}

					//right up
					switch (locAlg(b->x, b->y, 1, -1))
					{
					case 0:
						break;
					case 1:
						b->x += 1;
						b->y -= 1;
						if (wking.y == b->y - 1 && wking.x == b->x + 1)
						{
							b->x -= 1;
							b->y += 1;
							break;
						}

						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x -= 1;
									b->y += 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x += 1;
						b->y -= 1;
						if (wking.y == b->y - 1 && wking.x == b->x + 1)
						{
							b->x -= 1;
							b->y += 1;
							break;
						}
						check();
						b->x -= 1;
						b->y += 1;

						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
						break;
					}

					//left up
					switch (locAlg(b->x, b->y, -1, -1))
					{
					case 0:
						break;
					case 1:
						b->x -= 1;
						b->y -= 1;
						if (wking.y == b->y - 1 && wking.x == b->x - 1)
						{
							b->x += 1;
							b->y += 1;
							break;
						}

						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x += 1;
									b->y += 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x -= 1;
						b->y -= 1;
						if (wking.y == b->y - 1 && wking.x == b->x - 1)
						{
							b->x += 1;
							b->y += 1;
							break;
						}
						check();
						b->x += 1;
						b->y += 1;

						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
						break;
					}

					//right down
					switch (locAlg(b->x, b->y, 1, 1))
					{
					case 0:
						break;
					case 1:
						b->x += 1;
						b->y += 1;
						if (wking.y == b->y + 1 && wking.x == b->x + 1)
						{
							b->x -= 1;
							b->y -= 1;
							break;
						}

						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x -= 1;
									b->y -= 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x += 1;
						b->y += 1;
						if (wking.y == b->y + 1 && wking.x == b->x + 1)
						{
							b->x -= 1;
							b->y -= 1;
							break;
						}
						check();
						b->x -= 1;
						b->y -= 1;

						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
						break;
					}

					//left down
					switch (locAlg(b->x, b->y, -1, 1))
					{
					case 0:
						break;
					case 1:
						b->x -= 1;
						b->y += 1;
						if (wking.y == b->y + 1 && wking.x == b->x - 1)
						{
							b->x += 1;
							b->y -= 1;
							break;
						}

						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x += 1;
									b->y -= 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										king.check = 1;
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x -= 1;
						b->y += 1;
						if (wking.y == b->y + 1 && wking.x == b->x - 1)
						{
							b->x += 1;
							b->y -= 1;
							break;
						}
						check();
						b->x += 1;
						b->y -= 1;

						if (king.check == 0)
						{
							king.check = 1;
							return;
						}
						break;
					}
				}
			}
		}
		//if this runs it means checkmate so white wins
		win = 2;
	}
}

//checks if color is in stalemate
void stalemate()
{
	//uses checkmate function, but will only stop if the function results in a move thats not in check
	//otherwise it means that the color is in stalemate
	int valid = 1;
	int bxtemp = 0;
	int wxtemp = 0;
	int bytemp = 0;
	int wytemp = 0;
	int px = 0;
	int py = 0;
	int t = 0;

	//only kings on each side left
	for (auto& w : wPiece)
	{
		if (w->death == 0)
		{
			t++;
		}
	}
	for (auto& b : bPiece)
	{
		if (b->death == 0)
		{
			t++;
		}
	}
	if (t == 2)
	{
		win = 5;
		return;
	}
	t = 0;

	//if white is in check
	if (wking.check == 0)
	{
		for (auto& w : wPiece)
		{
			if (w->death == 0)
			{
				valid = 1;
				bxtemp = -1;
				wxtemp = -1;
				bytemp = -1;
				wytemp = -1;
				px = 0;
				py = 0;

				//pawn
				if (w->piece == PAWN)
				{
					//piece in front
					for (auto& w1 : wPiece)
					{
						if (w->x == w1->x && w1->y == w->y + 1)
						{
							valid = 0;
							break;
						}
					}
					for (auto& b : bPiece)
					{
						if (w->x == b->x && b->y == w->y + 1)
						{
							valid = 0;
							break;
						}
					}

					if (valid == 1)
					{
						w->y += 1;
						check();
						w->y -= 1;
						if (wking.check == 0)
						{
							return;
						}
					}

					if (w->movesMade == 0)
					{
						for (auto& w1 : wPiece)
						{
							if (w->y + 2 == w1->y && w->x == w1->x)
							{
								valid = 0;
								break;
							}
						}
						for (auto& b : bPiece)
						{
							if (w->y + 2 == b->y && w->x == b->x)
							{
								valid = 0;
								break;
							}
						}
					}
					else
					{
						valid = 0;
					}

					if (valid == 1)
					{
						w->y += 2;
						check();
						w->y -= 2;
						if (wking.check == 0)
						{
							return;
						}
					}

					//killing piece
					for (auto& b : bPiece)
					{
						if (b->piece != KING)
						{
							if (b->x == w->x + 1 && b->y == w->y + 1)
							{
								bDead++;
								px = b->x;
								py = b->y;
								b->death = 1;
								b->dead(bDead);

								w->x += 1;
								w->y += 1;
								check();
								w->x -= 1;
								w->y -= 1;

								col(b->y, b->x, py, px, b->piece);
								bDead--;
								b->x = px;
								b->y = py;
								b->death = 0;

								if (wking.check == 0)
								{
									return;
								}
							}
							if (b->x == w->x - 1 && b->y == w->y + 1)
							{
								bDead++;
								px = b->x;
								py = b->y;
								b->death = 1;
								b->dead(bDead);

								w->x -= 1;
								w->y += 1;
								check();
								w->x += 1;
								w->y -= 1;

								col(b->y, b->x, py, px, b->piece);
								bDead--;
								b->x = px;
								b->y = py;
								b->death = 0;

								if (wking.check == 0)
								{
									return;
								}
							}
						}

						if (b->enPassantCnt == 1)
						{
							if (b->x == w->x + 1 && b->y == w->y)
							{
								bDead++;
								px = b->x;
								py = b->y;
								b->death = 1;
								b->dead(bDead);

								w->x += 1;
								w->y += 1;
								check();
								w->x -= 1;
								w->y -= 1;

								col(b->y, b->x, py, px, b->piece);
								bDead--;
								b->x = px;
								b->y = py;
								b->death = 0;

								if (wking.check == 0)
								{
									return;
								}
							}
							if (b->x == w->x - 1 && b->y == w->y)
							{
								bDead++;
								px = b->x;
								py = b->y;
								b->death = 1;
								b->dead(bDead);

								w->x -= 1;
								w->y += 1;
								check();
								w->x += 1;
								w->y -= 1;

								col(b->y, b->x, py, px, b->piece);
								bDead--;
								b->x = px;
								b->y = py;
								b->death = 0;

								if (wking.check == 0)
								{
									return;
								}
							}
						}
					}
				}
				//rook
				if (w->piece == ROOK)
				{
					//horizontal left movement
					for (auto& b : bPiece)
					{
						if (b->x < w->x && b->y == w->y && b->x > bxtemp)
						{
							//for multiple pieces in the same row select one and store its x value then compare 
							//its x location to other black pieces and see which one is closest to the rook being 
							//checked and say that bxtemp is that x value
							bxtemp = b->x;
						}
					}
					for (auto& w1 : wPiece)
					{
						if (w1->x < w->x && w1->y == w->y && w1->x > bxtemp && w1->x > wxtemp && w1->piece != KING)
						{
							wxtemp = w1->x;
						}
					}

					int t = 0;
					while (t <= 7)
					{
						t++;
						w->x -= t;
						if (w->x == wxtemp)
						{
							w->x += t;
							break;
						}
						if (w->x == bxtemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);
									check();
									w->x += t;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x += t;
						if (wking.check == 0)
						{
							return;
						}
					}

					wxtemp = 8;
					bxtemp = 8;

					//horizontal right movement
					for (auto& b : bPiece)
					{
						if (b->x > w->x && b->y == w->y && b->x < bxtemp)
						{
							bxtemp = b->x;
						}
					}
					for (auto& w1 : wPiece)
					{
						if (w1->x > w->x && w1->y == w->y && w1->x < bxtemp && w1->x < wxtemp && w1->piece != KING)
						{
							wxtemp = w1->x;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						w->x += t;
						if (w->x == wxtemp)
						{
							w->x -= t;
							break;
						}
						if (w->x == bxtemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x -= t;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x -= t;

						if (wking.check == 0)
						{
							return;
						}
					}

					//vertical up movement
					for (auto& b : bPiece)
					{
						if (b->y < w->y && b->x == w->x && b->y > bytemp)
						{
							bytemp = b->y;
						}
					}
					for (auto& w1 : wPiece)
					{
						if (w1->y < w->y && w1->x == w->x && w1->y > bytemp && w1->y > wytemp && w1->piece != KING)
						{
							wytemp = w1->y;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						w->y -= t;
						if (w->y == wytemp)
						{
							w->y += t;
							break;
						}
						if (w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->y == bytemp && b->x == w->x)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->y += t;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->y += t;
						if (wking.check == 0)
						{
							return;
						}
					}

					bytemp = 8;
					wytemp = 8;

					//vertical down movement
					for (auto& b : bPiece)
					{
						if (b->y > w->y && b->x == w->x && b->y < bytemp)
						{
							bytemp = b->y;
						}
					}
					for (auto& w1 : wPiece)
					{
						if (w1->y > w->y && w1->x == w->x && w1->y < bytemp && w1->y < wytemp && w1->piece != KING)
						{
							wytemp = w1->y;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						w->y += t;
						if (w->y == wytemp)
						{
							w->y -= t;
							break;
						}
						if (w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->y == bytemp && b->x == w->x)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->y -= t;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->y -= t;
						if (wking.check == 0)
						{
							return;
						}
					}
				}
				//horse
				if (w->piece == HORSE)
				{
					switch (locAlg(w->x, w->y, -2, -1))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x -= 2;
						w->y -= 1;
						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x += 2;
									w->y += 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x -= 2;
						w->y -= 1;
						check();
						w->x += 2;
						w->y += 1;

						if (wking.check == 0)
						{
							return;
						}
						break;
					}

					switch (locAlg(w->x, w->y, -2, 1))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x -= 2;
						w->y += 1;
						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x += 2;
									w->y -= 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x -= 2;
						w->y += 1;
						check();
						w->x += 2;
						w->y -= 1;

						if (wking.check == 0)
						{
							return;
						}
						break;
					}

					switch (locAlg(w->x, w->y, 2, -1))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x += 2;
						w->y -= 1;
						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x -= 2;
									w->y += 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x += 2;
						w->y -= 1;
						check();
						w->x -= 2;
						w->y += 1;

						if (wking.check == 0)
						{
							return;
						}
						break;
					}

					switch (locAlg(w->x, w->y, 2, 1))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x += 2;
						w->y += 1;
						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x -= 2;
									w->y -= 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x += 2;
						w->y += 1;
						check();
						w->x -= 2;
						w->y -= 1;

						if (wking.check == 0)
						{
							return;
						}
						break;
					}

					switch (locAlg(w->x, w->y, -1, -2))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x -= 1;
						w->y -= 2;
						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x += 1;
									w->y += 2;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x -= 1;
						w->y -= 2;
						check();
						w->x += 1;
						w->y += 2;

						if (wking.check == 0)
						{
							return;
						}
						break;
					}

					switch (locAlg(w->x, w->y, -1, 2))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x -= 1;
						w->y += 2;
						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x += 1;
									w->y -= 2;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x -= 1;
						w->y += 2;
						check();
						w->x += 1;
						w->y -= 2;

						if (wking.check == 0)
						{
							return;
						}
						break;
					}

					switch (locAlg(w->x, w->y, 1, -2))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x += 1;
						w->y -= 2;
						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x -= 1;
									w->y += 2;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x += 1;
						w->y -= 2;
						check();
						w->x += 1;
						w->y -= 2;

						if (wking.check == 0)
						{
							return;
						}
						break;
					}

					switch (locAlg(w->x, w->y, 1, 2))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x += 1;
						w->y += 2;
						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x -= 1;
									w->y -= 2;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x += 1;
						w->y += 2;
						check();
						w->x -= 1;
						w->y -= 2;

						if (wking.check == 0)
						{
							return;
						}
						break;
					}
				}
				//bishop
				if (w->piece == BISHOP)
				{
					//left down diagonal
					wytemp = 8;
					bytemp = 8;
					t = 0;

					for (auto& b : bPiece)
					{
						if (b->x < w->x && b->y > w->y && w->x - b->x == b->y - w->y && b->x > bxtemp && b->y < bytemp)
						{
							bxtemp = b->x;
							bytemp = b->y;
						}
					}

					for (auto& w1 : wPiece)
					{
						if (w1->x < w->x && w1->y > w->y && w->x - w1->x == w1->y - w->y && w1->x > bxtemp && w1->y < bytemp && w1->x > wxtemp && w1->y < wytemp)
						{
							wxtemp = w1->x;
							wytemp = w1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						w->x -= t;
						w->y += t;

						if (w->x == wxtemp || w->y == wytemp)
						{
							w->x += t;
							w->y -= t;
							break;
						}

						if (w->x == bxtemp || w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == bytemp)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);
									check();
									w->x += t;
									w->y -= t;

									col(b->y, b->x, py, px, b->piece);

									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{

										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x += t;
						w->y -= t;

						if (wking.check == 0)
						{
							return;
						}
					}

					//right down diagonal
					bxtemp = 8;
					bytemp = 8;
					wxtemp = 8;
					wytemp = 8;
					t = 0;

					for (auto& b : bPiece)
					{
						if (b->x > w->x && b->y > w->y && b->x - w->x == b->y - w->y && b->x < bxtemp && b->y < bytemp)
						{
							bxtemp = b->x;
							bytemp = b->y;
						}
					}

					for (auto& w1 : wPiece)
					{
						if (w1->x > w->x && w1->y > w->y && w1->x - w->x == w1->y - w->y && w1->x < bxtemp && w1->y < bytemp && w1->x < wxtemp && w1->y < wytemp)
						{
							wxtemp = w1->x;
							wytemp = w1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						w->x += t;
						w->y += t;

						if (w->x == wxtemp || w->y == wytemp)
						{
							w->x -= t;
							w->y -= t;
							break;
						}

						if (w->x == bxtemp || w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == bytemp)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);
									check();
									w->x -= t;
									w->y -= t;

									col(b->y, b->x, py, px, b->piece);

									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x -= t;
						w->y -= t;
						if (wking.check == 0)
						{
							return;
						}
					}

					//left up diagonal
					bxtemp = -1;
					bytemp = -1;
					wxtemp = -1;
					wytemp = -1;
					t = 0;

					for (auto& b : bPiece)
					{
						if (b->x < w->x && b->y < w->y && w->x - b->x == w->y - b->y && b->x > bxtemp && b->y > bytemp)
						{
							bxtemp = b->x;
							bytemp = b->y;
						}
					}

					for (auto& w1 : wPiece)
					{
						if (w1->x < w->x && w1->y < w->y && w->x - w1->x == w->y - w1->y && w1->x > bxtemp && w1->y > bytemp && w1->x > wxtemp && w1->y > wytemp)
						{
							wxtemp = w1->x;
							wytemp = w1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						w->x -= t;
						w->y -= t;

						if (w->x == wxtemp || w->y == wytemp)
						{
							w->x += t;
							w->y += t;
							break;
						}

						if (w->x == bxtemp || w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == bytemp)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);
									check();
									w->x += t;
									w->y += t;

									col(b->y, b->x, py, px, b->piece);

									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x += t;
						w->y += t;
						if (wking.check == 0)
						{
							return;
						}
					}

					//right up diagonal
					bxtemp = 8;
					bytemp = -1;
					wxtemp = 8;
					wytemp = -1;
					t = 0;

					for (auto& b : bPiece)
					{
						if (b->x > w->x && b->y < w->y && b->x - w->x == w->y - b->y && b->x < bxtemp && b->y > bytemp)
						{
							bxtemp = b->x;
							bytemp = b->y;
						}
					}

					for (auto& w1 : wPiece)
					{
						if (w1->x > w->x && w1->y < w->y && w1->x - w->x == w->y - w1->y && w1->x < bxtemp && w1->y > bytemp && w1->x < wxtemp && w1->y > wytemp)
						{
							wxtemp = w1->x;
							wytemp = w1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						w->x += t;
						w->y -= t;

						if (w->x == wxtemp || w->y == wytemp)
						{
							w->x -= t;
							w->y += t;
							break;
						}

						if (w->x == bxtemp || w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == bytemp)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);
									check();
									w->x -= t;
									w->y += t;

									col(b->y, b->x, py, px, b->piece);

									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x -= t;
						w->y += t;
						if (wking.check == 0)
						{
							return;
						}
					}
				}
				//queen
				if (w->piece == QUEEN)
				{
					//horizontal left movement
					for (auto& b : bPiece)
					{
						if (b->x < w->x && b->y == w->y && b->x > bxtemp)
						{
							//for multiple pieces in the same row select one and store its x value then compare 
							//its x location to other black pieces and see which one is closest to the rook being 
							//checked and say that bxtemp is that x value
							bxtemp = b->x;
						}
					}
					for (auto& w1 : wPiece)
					{
						if (w1->x < w->x && w1->y == w->y && w1->x > bxtemp && w1->x > wxtemp && w1->piece != KING)
						{
							wxtemp = w1->x;
						}
					}

					int t = 0;
					while (t <= 7)
					{
						t++;
						w->x -= t;
						if (w->x == wxtemp)
						{
							w->x += t;
							break;
						}
						if (w->x == bxtemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);
									check();
									w->x += t;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x += t;
						if (wking.check == 0)
						{
							return;
						}
					}

					wxtemp = 8;
					bxtemp = 8;

					//horizontal right movement
					for (auto& b : bPiece)
					{
						if (b->x > w->x && b->y == w->y && b->x < bxtemp)
						{
							bxtemp = b->x;
						}
					}
					for (auto& w1 : wPiece)
					{
						if (w1->x > w->x && w1->y == w->y && w1->x < bxtemp && w1->x < wxtemp && w1->piece != KING)
						{
							wxtemp = w1->x;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						w->x += t;
						if (w->x == wxtemp)
						{
							w->x -= t;
							break;
						}
						if (w->x == bxtemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x -= t;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x -= t;

						if (wking.check == 0)
						{
							return;
						}
					}

					//vertical up movement
					for (auto& b : bPiece)
					{
						if (b->y < w->y && b->x == w->x && b->y > bytemp)
						{
							bytemp = b->y;
						}
					}
					for (auto& w1 : wPiece)
					{
						if (w1->y < w->y && w1->x == w->x && w1->y > bytemp && w1->y > wytemp && w1->piece != KING)
						{
							wytemp = w1->y;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						w->y -= t;
						if (w->y == wytemp)
						{
							w->y += t;
							break;
						}
						if (w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->y == bytemp && b->x == w->x)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->y += t;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->y += t;
						if (wking.check == 0)
						{
							return;
						}
					}

					bytemp = 8;
					wytemp = 8;

					//vertical down movement
					for (auto& b : bPiece)
					{
						if (b->y > w->y && b->x == w->x && b->y < bytemp)
						{
							bytemp = b->y;
						}
					}
					for (auto& w1 : wPiece)
					{
						if (w1->y > w->y && w1->x == w->x && w1->y < bytemp && w1->y < wytemp && w1->piece != KING)
						{
							wytemp = w1->y;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						w->y += t;
						if (w->y == wytemp)
						{
							w->y -= t;
							break;
						}
						if (w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->y == bytemp && b->x == w->x)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->y -= t;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->y -= t;
						if (wking.check == 0)
						{
							return;
						}
					}


					//left down diagonal
					bxtemp = -1;
					bytemp = 8;
					wxtemp = -1;
					wytemp = 8;

					t = 0;

					for (auto& b : bPiece)
					{
						if (b->x < w->x && b->y > w->y && w->x - b->x == b->y - w->y && b->x > bxtemp && b->y < bytemp)
						{
							bxtemp = b->x;
							bytemp = b->y;
						}
					}

					for (auto& w1 : wPiece)
					{
						if (w1->x < w->x && w1->y > w->y && w->x - w1->x == w1->y - w->y && w1->x > bxtemp && w1->y < bytemp && w1->x > wxtemp && w1->y < wytemp)
						{
							wxtemp = w1->x;
							wytemp = w1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						w->x -= t;
						w->y += t;

						if (w->x == wxtemp || w->y == wytemp)
						{
							w->x += t;
							w->y -= t;
							break;
						}

						if (w->x == bxtemp || w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == bytemp)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);
									check();
									w->x += t;
									w->y -= t;

									col(b->y, b->x, py, px, b->piece);

									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x += t;
						w->y -= t;

						if (wking.check == 0)
						{
							return;
						}
					}

					//right down diagonal
					bxtemp = 8;
					bytemp = 8;
					wxtemp = 8;
					wytemp = 8;
					t = 0;

					for (auto& b : bPiece)
					{
						if (b->x > w->x && b->y > w->y && b->x - w->x == b->y - w->y && b->x < bxtemp && b->y < bytemp)
						{
							bxtemp = b->x;
							bytemp = b->y;
						}
					}

					for (auto& w1 : wPiece)
					{
						if (w1->x > w->x && w1->y > w->y && w1->x - w->x == w1->y - w->y && w1->x < bxtemp && w1->y < bytemp && w1->x < wxtemp && w1->y < wytemp)
						{
							wxtemp = w1->x;
							wytemp = w1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						w->x += t;
						w->y += t;

						if (w->x == wxtemp || w->y == wytemp)
						{
							w->x -= t;
							w->y -= t;
							break;
						}

						if (w->x == bxtemp || w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == bytemp)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);
									check();
									w->x -= t;
									w->y -= t;

									col(b->y, b->x, py, px, b->piece);

									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x -= t;
						w->y -= t;
						if (wking.check == 0)
						{
							return;
						}
					}

					//left up diagonal
					bxtemp = -1;
					bytemp = -1;
					wxtemp = -1;
					wytemp = -1;
					t = 0;

					for (auto& b : bPiece)
					{
						if (b->x < w->x && b->y < w->y && w->x - b->x == w->y - b->y && b->x > bxtemp && b->y > bytemp)
						{
							bxtemp = b->x;
							bytemp = b->y;
						}
					}

					for (auto& w1 : wPiece)
					{
						if (w1->x < w->x && w1->y < w->y && w->x - w1->x == w->y - w1->y && w1->x > bxtemp && w1->y > bytemp && w1->x > wxtemp && w1->y > wytemp)
						{
							wxtemp = w1->x;
							wytemp = w1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						w->x -= t;
						w->y -= t;

						if (w->x == wxtemp || w->y == wytemp)
						{
							w->x += t;
							w->y += t;
							break;
						}

						if (w->x == bxtemp || w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == bytemp)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);
									check();
									w->x += t;
									w->y += t;

									col(b->y, b->x, py, px, b->piece);

									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x += t;
						w->y += t;
						if (wking.check == 0)
						{
							return;
						}
					}

					//right up diagonal
					bxtemp = 8;
					bytemp = -1;
					wxtemp = 8;
					wytemp = -1;
					t = 0;

					for (auto& b : bPiece)
					{
						if (b->x > w->x && b->y < w->y && b->x - w->x == w->y - b->y && b->x < bxtemp && b->y > bytemp)
						{
							bxtemp = b->x;
							bytemp = b->y;
						}
					}

					for (auto& w1 : wPiece)
					{
						if (w1->x > w->x && w1->y < w->y && w1->x - w->x == w->y - w1->y && w1->x < bxtemp && w1->y > bytemp && w1->x < wxtemp && w1->y > wytemp)
						{
							wxtemp = w1->x;
							wytemp = w1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						w->x += t;
						w->y -= t;

						if (w->x == wxtemp || w->y == wytemp)
						{
							w->x -= t;
							w->y += t;
							break;
						}

						if (w->x == bxtemp || w->y == bytemp)
						{
							for (auto& b : bPiece)
							{
								if (b->x == bxtemp && b->y == bytemp)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);
									check();
									w->x -= t;
									w->y += t;

									col(b->y, b->x, py, px, b->piece);

									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						w->x -= t;
						w->y += t;
						if (wking.check == 0)
						{
							return;
						}
					}
				}
				//king
				if (w->piece == KING)
				{
					//right
					switch (locAlg(w->x, w->y, 1, 0))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x += 1;
						if (king.x == w->x + 1 && (king.y == w->y || king.y == w->y + 1 || king.y == w->y - 1))
						{
							w->x -= 1;
							break;
						}

						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x -= 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x += 1;
						if (king.x == w->x + 1 && (king.y == w->y || king.y == w->y + 1 || king.y == w->y - 1))
						{
							w->x -= 1;
							break;
						}
						check();
						w->x -= 1;

						if (wking.check == 0)
						{
							return;
						}
						break;
					}

					//left
					switch (locAlg(w->x, w->y, -1, 0))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x -= 1;
						if (king.x == w->x - 1 && (king.y == w->y || king.y == w->y + 1 || king.y == w->y - 1))
						{
							w->x += 1;
							break;
						}

						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x += 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x -= 1;
						if (king.x == w->x - 1 && (king.y == w->y || king.y == w->y + 1 || king.y == w->y - 1))
						{
							w->x += 1;
							break;
						}
						check();
						w->x += 1;

						if (wking.check == 0)
						{
							return;
						}
						break;
					}

					//up
					switch (locAlg(w->x, w->y, 0, -1))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->y -= 1;
						if (king.y == w->y - 1 && (king.x == w->x || king.x == w->x + 1 || king.x == w->x - 1))
						{
							w->y += 1;
							break;
						}

						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->y += 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->y -= 1;
						if (king.y == w->y - 1 && (king.x == w->x || king.x == w->x + 1 || king.x == w->x - 1))
						{
							w->y += 1;
							break;
						}
						check();
						w->y += 1;

						if (wking.check == 0)
						{
							return;
						}
						break;
					}

					//down
					switch (locAlg(w->x, w->y, 0, 1))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->y += 1;
						if (king.y == w->y + 1 && (king.x == w->x || king.x == w->x + 1 || king.x == w->x - 1))
						{
							w->y -= 1;
							break;
						}

						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->y -= 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->y += 1;
						if (king.y == w->y + 1 && (king.x == w->x || king.x == w->x + 1 || king.x == w->x - 1))
						{
							w->y -= 1;
							break;
						}
						check();
						w->y -= 1;

						if (wking.check == 0)
						{
							return;
						}
						break;
					}

					//right up
					switch (locAlg(w->x, w->y, 1, -1))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x += 1;
						w->y -= 1;
						if (king.y == w->y - 1 && king.x == w->x + 1)
						{
							w->x -= 1;
							w->y += 1;
							break;
						}

						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x -= 1;
									w->y += 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x += 1;
						w->y -= 1;
						if (king.y == w->y - 1 && king.x == w->x + 1)
						{
							w->x -= 1;
							w->y += 1;
							break;
						}
						check();
						w->x -= 1;
						w->y += 1;

						if (wking.check == 0)
						{
							return;
						}
						break;
					}

					//left up
					switch (locAlg(w->x, w->y, -1, -1))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x -= 1;
						w->y -= 1;
						if (king.y == w->y - 1 && king.x == w->x - 1)
						{
							w->x += 1;
							w->y += 1;
							break;
						}

						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x += 1;
									w->y += 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x -= 1;
						w->y -= 1;
						if (king.y == w->y - 1 && king.x == w->x - 1)
						{
							w->x += 1;
							w->y += 1;
							break;
						}
						check();
						w->x += 1;
						w->y += 1;

						if (wking.check == 0)
						{
							return;
						}
						break;
					}

					//right down
					switch (locAlg(w->x, w->y, 1, 1))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x += 1;
						w->y += 1;
						if (king.y == w->y + 1 && king.x == w->x + 1)
						{
							w->x -= 1;
							w->y -= 1;
							break;
						}

						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x -= 1;
									w->y -= 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x += 1;
						w->y += 1;
						if (king.y == w->y + 1 && king.x == w->x + 1)
						{
							w->x -= 1;
							w->y -= 1;
							break;
						}
						check();
						w->x -= 1;
						w->y -= 1;

						if (wking.check == 0)
						{
							return;
						}
						break;
					}

					//left down
					switch (locAlg(w->x, w->y, -1, 1))
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						w->x -= 1;
						w->y += 1;
						if (king.y == w->y + 1 && king.x == w->x - 1)
						{
							w->x += 1;
							w->y -= 1;
							break;
						}

						//run death sequence
						for (auto& b : bPiece)
						{
							if (b->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									bDead++;
									px = b->x;
									py = b->y;
									b->death = 1;
									b->dead(bDead);

									check();
									w->x += 1;
									w->y -= 1;

									col(b->y, b->x, py, px, b->piece);
									bDead--;
									b->x = px;
									b->y = py;
									b->death = 0;

									if (wking.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 3:
						w->x -= 1;
						w->y += 1;
						if (king.y == w->y + 1 && king.x == w->x - 1)
						{
							w->x += 1;
							w->y -= 1;
							break;
						}
						check();
						w->x += 1;
						w->y -= 1;

						if (wking.check == 0)
						{
							return;
						}
						break;
					}
				}
			}
		}
		//if this runs it means stalemate, white cant move
		win = 3;
	}

	//if black is in check
	if (king.check == 0)
	{
		for (auto& b : bPiece)
		{
			if (b->death == 0)
			{
				valid = 1;
				bxtemp = -1;
				wxtemp = -1;
				bytemp = -1;
				wytemp = -1;
				px = 0;
				py = 0;

				//pawn
				if (b->piece == PAWN)
				{
					//piece in front
					for (auto& b1 : bPiece)
					{
						if (b->x == b1->x && b1->y == b->y - 1)
						{
							valid = 0;
							break;
						}
					}
					for (auto& w : wPiece)
					{
						if (b->x == w->x && w->y == b->y - 1)
						{
							valid = 0;
							break;
						}
					}

					if (valid == 1)
					{
						b->y -= 1;
						check();
						b->y += 1;
						if (king.check == 0)
						{
							return;
						}
					}

					if (b->movesMade == 0)
					{
						for (auto& b1 : bPiece)
						{
							if (b->y - 2 == b1->y && b->x == b1->x)
							{
								valid = 0;
								break;
							}
						}
						for (auto& w : wPiece)
						{
							if (b->y - 2 == w->y && b->x == w->x)
							{
								valid = 0;
								break;
							}
						}
					}
					else
					{
						valid = 0;
					}

					if (valid == 1)
					{
						b->y -= 2;
						check();
						b->y += 2;
						if (king.check == 0)
						{
							return;
						}
					}

					//killing piece
					for (auto& w : wPiece)
					{
						if (w->piece != KING)
						{
							if (w->x == b->x + 1 && w->y == b->y - 1)
							{
								wDead++;
								px = w->x;
								py = w->y;
								w->death = 1;
								w->dead(wDead);

								b->x += 1;
								b->y -= 1;
								check();
								b->x -= 1;
								b->y += 1;

								col(w->y, w->x, py, px, w->piece + 6);
								wDead--;
								w->x = px;
								w->y = py;
								w->death = 0;

								if (king.check == 0)
								{
									return;
								}
							}
							if (w->x == b->x - 1 && w->y == b->y - 1)
							{
								wDead++;
								px = w->x;
								py = w->y;
								w->death = 1;
								w->dead(wDead);

								b->x -= 1;
								b->y -= 1;
								check();
								b->x += 1;
								b->y += 1;

								col(w->y, w->x, py, px, w->piece + 6);
								wDead--;
								w->x = px;
								w->y = py;
								w->death = 0;

								if (king.check == 0)
								{
									return;
								}
							}
						}
						if (w->enPassantCnt == 1)
						{
							if (w->x == b->x + 1 && w->y == b->y)
							{
								wDead++;
								px = w->x;
								py = w->y;
								w->death = 1;
								w->dead(wDead);

								b->x += 1;
								b->y -= 1;
								check();
								b->x -= 1;
								b->y += 1;

								col(w->y, w->x, py, px, w->piece + 6);
								wDead--;
								w->x = px;
								w->y = py;
								w->death = 0;

								if (king.check == 0)
								{
									return;
								}
							}
							if (w->x == b->x - 1 && w->y == b->y)
							{
								wDead++;
								px = w->x;
								py = w->y;
								w->death = 1;
								w->dead(wDead);

								b->x -= 1;
								b->y -= 1;
								check();
								b->x += 1;
								b->y += 1;

								col(w->y, w->x, py, px, w->piece + 6);
								wDead--;
								w->x = px;
								w->y = py;
								w->death = 0;

								if (king.check == 0)
								{
									return;
								}
							}
						}
					}
				}
				//rook
				if (b->piece == ROOK)
				{
					//horizontal left movement
					for (auto& w : wPiece)
					{
						if (w->x < b->x && w->y == b->y && w->x > wxtemp)
						{
							//for multiple pieces in the same row select one and store its x value then compare 
							//its x location to other black pieces and see which one is closest to the rook being 
							//checked and say that bxtemp is that x value
							wxtemp = w->x;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->x < b->x && b1->y == b->y && b1->x > wxtemp && b1->x > bxtemp && b1->piece != KING)
						{
							bxtemp = b1->x;
						}
					}

					int t = 0;
					while (t <= 7)
					{
						t++;
						b->x -= t;
						if (b->x == bxtemp)
						{
							b->x += t;
							break;
						}
						if (b->x == wxtemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);
									check();
									b->x += t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x += t;
						if (king.check == 0)
						{
							return;
						}
					}

					wxtemp = 8;
					bxtemp = 8;

					//horizontal right movement
					for (auto& w : wPiece)
					{
						if (w->x > b->x && w->y == b->y && w->x < wxtemp)
						{
							wxtemp = w->x;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->x > b->x && b1->y == b->y && b1->x < wxtemp && b1->x < bxtemp && b1->piece != KING)
						{
							bxtemp = b1->x;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						b->x += t;
						if (b->x == bxtemp)
						{
							b->x -= t;
							break;
						}
						if (b->x == wxtemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x -= t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x -= t;

						if (king.check == 0)
						{
							return;
						}
					}

					//vertical up movement
					for (auto& w : wPiece)
					{
						if (w->y < b->y && w->x == b->x && w->y > wytemp)
						{
							wytemp = w->y;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->y < b->y && b1->x == b->x && b1->y > wytemp && b1->y > bytemp && b1->piece != KING)
						{
							bytemp = b1->y;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						b->y -= t;
						if (b->y == bytemp)
						{
							b->y += t;
							break;
						}
						if (b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->y == wytemp && w->x == b->x)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->y += t;

									col(w->y, w->x, py, px, w->piece + 6);
									bDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->y += t;
						if (king.check == 0)
						{
							return;
						}
					}

					bytemp = 8;
					wytemp = 8;

					//vertical down movement
					for (auto& w : wPiece)
					{
						if (w->y > b->y && w->x == b->x && w->y < wytemp)
						{
							wytemp = w->y;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->y > b->y && b1->x == b->x && b1->y < wytemp && b1->y < bytemp && b1->piece != KING)
						{
							bytemp = b1->y;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						b->y += t;
						if (b->y == bytemp)
						{
							b->y -= t;
							break;
						}
						if (b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->y == wytemp && w->x == b->x)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->y -= t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->y -= t;
						if (king.check == 0)
						{
							return;
						}
					}
				}
				//horse
				if (b->piece == HORSE)
				{
					switch (locAlg(b->x, b->y, -2, -1))
					{
					case 0:
						break;
					case 1:
						b->x -= 2;
						b->y -= 1;
						//run death sequence
						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (b->x == w->x && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x += 2;
									b->y += 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x -= 2;
						b->y -= 1;
						check();
						b->x += 2;
						b->y += 1;

						if (king.check == 0)
						{
							return;
						}
						break;
					}

					switch (locAlg(b->x, b->y, -2, 1))
					{
					case 0:
						break;
					case 1:
						b->x -= 2;
						b->y += 1;
						//run death sequence
						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (b->x == w->x && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x += 2;
									b->y -= 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x -= 2;
						b->y += 1;
						check();
						b->x += 2;
						b->y -= 1;

						if (king.check == 0)
						{
							return;
						}
						break;
					}

					switch (locAlg(b->x, b->y, 2, -1))
					{
					case 0:
						break;
					case 1:
						b->x += 2;
						b->y -= 1;
						//run death sequence
						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (b->x == w->x && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x -= 2;
									b->y += 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x += 2;
						b->y -= 1;
						check();
						b->x -= 2;
						b->y += 1;

						if (king.check == 0)
						{
							return;
						}
						break;
					}

					switch (locAlg(b->x, b->y, 2, 1))
					{
					case 0:
						break;
					case 1:
						b->x += 2;
						b->y += 1;
						//run death sequence
						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (b->x == w->x && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x -= 2;
									b->y -= 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x += 2;
						b->y += 1;
						check();
						b->x -= 2;
						b->y -= 1;

						if (king.check == 0)
						{
							return;
						}
						break;
					}

					switch (locAlg(b->x, b->y, -1, -2))
					{
					case 0:
						break;
					case 1:
						b->x -= 1;
						b->y -= 2;
						//run death sequence
						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (b->x == w->x && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x += 1;
									b->y += 2;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x -= 1;
						b->y -= 2;
						check();
						b->x += 1;
						b->y += 2;

						if (king.check == 0)
						{
							return;
						}
						break;
					}

					switch (locAlg(b->x, b->y, -1, 2))
					{
					case 0:
						break;
					case 1:
						b->x -= 1;
						b->y += 2;
						//run death sequence
						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (b->x == w->x && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x += 1;
									b->y -= 2;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x -= 1;
						b->y += 2;
						check();
						b->x += 1;
						b->y -= 2;

						if (king.check == 0)
						{
							return;
						}
						break;
					}

					switch (locAlg(b->x, b->y, 1, -2))
					{
					case 0:
						break;
					case 1:
						b->x += 1;
						b->y -= 2;
						//run death sequence
						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (b->x == w->x && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x -= 1;
									b->y += 2;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x += 1;
						b->y -= 2;
						check();
						b->x += 1;
						b->y -= 2;

						if (king.check == 0)
						{
							return;
						}
						break;
					}

					switch (locAlg(b->x, b->y, 1, 2))
					{
					case 0:
						break;
					case 1:
						b->x += 1;
						b->y += 2;
						//run death sequence
						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (b->x == w->x && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x -= 1;
									b->y -= 2;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x += 1;
						b->y += 2;
						check();
						b->x -= 1;
						b->y -= 2;

						if (king.check == 0)
						{
							return;
						}
						break;
					}
				}
				//bishop
				if (b->piece == BISHOP)
				{
					//left down diagonal
					wytemp = 8;
					bytemp = 8;
					t = 0;

					for (auto& w : wPiece)
					{
						if (w->x < b->x && w->y > b->y && b->x - w->x == w->y - b->y && w->x > wxtemp && w->y < wytemp)
						{
							wxtemp = w->x;
							wytemp = w->y;
						}
					}
					for (auto& b1 : wPiece)
					{
						if (b1->x < b->x && b1->y > b->y && b->x - b1->x == b1->y - b->y && b1->x > wxtemp && b1->y < wytemp && b1->x > bxtemp && b1->y < bytemp)
						{
							bxtemp = b1->x;
							bytemp = b1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						b->x -= t;
						b->y += t;

						if (b->x == bxtemp || b->y == bytemp)
						{
							b->x += t;
							b->y -= t;
							break;
						}

						if (b->x == wxtemp || b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == wytemp)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);
									check();
									b->x += t;
									b->y -= t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x += t;
						b->y -= t;

						if (king.check == 0)
						{
							return;
						}
					}

					//right down diagonal
					bxtemp = 8;
					bytemp = 8;
					wxtemp = 8;
					wytemp = 8;
					t = 0;

					for (auto& w : wPiece)
					{
						if (w->x > b->x && w->y > b->y && w->x - b->x == w->y - b->y && w->x < wxtemp && w->y < wytemp)
						{
							wxtemp = w->x;
							wytemp = w->y;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->x > b->x && b1->y > b->y && b1->x - b->x == b1->y - b->y && b1->x < wxtemp && b1->y < wytemp && b1->x < bxtemp && b1->y < bytemp)
						{
							bxtemp = b1->x;
							bytemp = b1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						b->x += t;
						b->y += t;

						if (b->x == bxtemp || b->y == bytemp)
						{
							b->x -= t;
							b->y -= t;
							break;
						}

						if (b->x == wxtemp || b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == wytemp)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);
									check();
									b->x -= t;
									b->y -= t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x -= t;
						b->y -= t;
						if (king.check == 0)
						{
							return;
						}
					}

					//left up diagonal
					bxtemp = -1;
					bytemp = -1;
					wxtemp = -1;
					wytemp = -1;
					t = 0;

					for (auto& w : wPiece)
					{
						if (w->x < b->x && w->y < b->y && b->x - w->x == b->y - w->y && w->x > wxtemp && w->y > wytemp)
						{
							wxtemp = w->x;
							wytemp = w->y;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->x < b->x && b1->y < b->y && b->x - b1->x == b->y - b1->y && b1->x > wxtemp && b1->y > wytemp && b1->x > bxtemp && b1->y > bytemp)
						{
							bxtemp = b1->x;
							bytemp = b1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						b->x -= t;
						b->y -= t;

						if (b->x == bxtemp || b->y == bytemp)
						{
							b->x += t;
							b->y += t;
							break;
						}

						if (b->x == wxtemp || b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == wytemp)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);
									check();
									b->x += t;
									b->y += t;

									col(w->y, w->x, py, px, w->piece + 6);

									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x += t;
						b->y += t;
						if (king.check == 0)
						{
							return;
						}
					}

					//right up diagonal
					bxtemp = 8;
					bytemp = -1;
					wxtemp = 8;
					wytemp = -1;
					t = 0;

					for (auto& w : wPiece)
					{
						if (w->x > b->x && w->y < b->y && w->x - b->x == b->y - w->y && w->x < wxtemp && w->y > wytemp)
						{
							wxtemp = w->x;
							wytemp = w->y;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->x > b->x && b1->y < b->y && b1->x - b->x == b->y - b1->y && b1->x < wxtemp && b1->y > wytemp && b1->x < bxtemp && b1->y > bytemp)
						{
							bxtemp = b1->x;
							bytemp = b1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						b->x += t;
						b->y -= t;

						if (b->x == bxtemp || b->y == bytemp)
						{
							b->x -= t;
							b->y += t;
							break;
						}

						if (b->x == wxtemp || b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == wytemp)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);
									check();
									b->x -= t;
									b->y += t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x -= t;
						b->y += t;
						if (king.check == 0)
						{
							return;
						}
					}
				}
				//queen
				if (b->piece == QUEEN)
				{
					//horizontal left movement
					for (auto& w : wPiece)
					{
						if (w->x < b->x && w->y == b->y && w->x > wxtemp)
						{
							//for multiple pieces in the same row select one and store its x value then compare 
							//its x location to other black pieces and see which one is closest to the rook being 
							//checked and say that bxtemp is that x value
							wxtemp = w->x;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->x < b->x && b1->y == b->y && b1->x > wxtemp && b1->x > bxtemp && b1->piece != KING)
						{
							bxtemp = b1->x;
						}
					}

					int t = 0;
					while (t <= 7)
					{
						t++;
						b->x -= t;
						if (b->x == bxtemp)
						{
							b->x += t;
							break;
						}
						if (b->x == wxtemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);
									check();
									b->x += t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x += t;
						if (king.check == 0)
						{
							return;
						}
					}

					wxtemp = 8;
					bxtemp = 8;

					//horizontal right movement
					for (auto& w : wPiece)
					{
						if (w->x > b->x && w->y == b->y && w->x < wxtemp)
						{
							wxtemp = w->x;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->x > b->x && b1->y == b->y && b1->x < wxtemp && b1->x < bxtemp && b1->piece != KING)
						{
							bxtemp = b1->x;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						b->x += t;
						if (b->x == bxtemp)
						{
							b->x -= t;
							break;
						}
						if (b->x == wxtemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == b->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x -= t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x -= t;

						if (king.check == 0)
						{
							return;
						}
					}

					//vertical up movement
					for (auto& w : wPiece)
					{
						if (w->y < b->y && w->x == b->x && w->y > wytemp)
						{
							wytemp = w->y;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->y < b->y && b1->x == b->x && b1->y > wytemp && b1->y > bytemp && b1->piece != KING)
						{
							bytemp = b1->y;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						b->y -= t;
						if (b->y == bytemp)
						{
							b->y += t;
							break;
						}
						if (b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->y == wytemp && w->x == b->x)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->y += t;

									col(w->y, w->x, py, px, w->piece + 6);
									bDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->y += t;
						if (king.check == 0)
						{
							return;
						}
					}

					bytemp = 8;
					wytemp = 8;

					//vertical down movement
					for (auto& w : wPiece)
					{
						if (w->y > b->y && w->x == b->x && w->y < wytemp)
						{
							wytemp = w->y;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->y > b->y && b1->x == b->x && b1->y < wytemp && b1->y < bytemp && b1->piece != KING)
						{
							bytemp = b1->y;
						}
					}

					t = 0;
					while (t <= 7)
					{
						t++;
						b->y += t;
						if (b->y == bytemp)
						{
							b->y -= t;
							break;
						}
						if (b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->y == wytemp && w->x == b->x)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->y -= t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->y -= t;
						if (king.check == 0)
						{
							return;
						}
					}

					//left down diagonal
					wytemp = 8;
					bytemp = 8;
					t = 0;

					for (auto& w : wPiece)
					{
						if (w->x < b->x && w->y > b->y && b->x - w->x == w->y - b->y && w->x > wxtemp && w->y < wytemp)
						{
							wxtemp = w->x;
							wytemp = w->y;
						}
					}
					for (auto& b1 : wPiece)
					{
						if (b1->x < b->x && b1->y > b->y && b->x - b1->x == b1->y - b->y && b1->x > wxtemp && b1->y < wytemp && b1->x > bxtemp && b1->y < bytemp)
						{
							bxtemp = b1->x;
							bytemp = b1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						b->x -= t;
						b->y += t;

						if (b->x == bxtemp || b->y == bytemp)
						{
							b->x += t;
							b->y -= t;
							break;
						}

						if (b->x == wxtemp || b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == wytemp)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);
									check();
									b->x += t;
									b->y -= t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x += t;
						b->y -= t;

						if (king.check == 0)
						{
							return;
						}
					}

					//right down diagonal
					bxtemp = 8;
					bytemp = 8;
					wxtemp = 8;
					wytemp = 8;
					t = 0;

					for (auto& w : wPiece)
					{
						if (w->x > b->x && w->y > b->y && w->x - b->x == w->y - b->y && w->x < wxtemp && w->y < wytemp)
						{
							wxtemp = w->x;
							wytemp = w->y;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->x > b->x && b1->y > b->y && b1->x - b->x == b1->y - b->y && b1->x < wxtemp && b1->y < wytemp && b1->x < bxtemp && b1->y < bytemp)
						{
							bxtemp = b1->x;
							bytemp = b1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						b->x += t;
						b->y += t;

						if (b->x == bxtemp || b->y == bytemp)
						{
							b->x -= t;
							b->y -= t;
							break;
						}

						if (b->x == wxtemp || b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == wytemp)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);
									check();
									b->x -= t;
									b->y -= t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x -= t;
						b->y -= t;
						if (king.check == 0)
						{
							return;
						}
					}

					//left up diagonal
					bxtemp = -1;
					bytemp = -1;
					wxtemp = -1;
					wytemp = -1;
					t = 0;

					for (auto& w : wPiece)
					{
						if (w->x < b->x && w->y < b->y && b->x - w->x == b->y - w->y && w->x > wxtemp && w->y > wytemp)
						{
							wxtemp = w->x;
							wytemp = w->y;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->x < b->x && b1->y < b->y && b->x - b1->x == b->y - b1->y && b1->x > wxtemp && b1->y > wytemp && b1->x > bxtemp && b1->y > bytemp)
						{
							bxtemp = b1->x;
							bytemp = b1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						b->x -= t;
						b->y -= t;

						if (b->x == bxtemp || b->y == bytemp)
						{
							b->x += t;
							b->y += t;
							break;
						}

						if (b->x == wxtemp || b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == wytemp)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);
									check();
									b->x += t;
									b->y += t;

									col(w->y, w->x, py, px, w->piece + 6);

									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x += t;
						b->y += t;
						if (king.check == 0)
						{
							return;
						}
					}

					//right up diagonal
					bxtemp = 8;
					bytemp = -1;
					wxtemp = 8;
					wytemp = -1;
					t = 0;

					for (auto& w : wPiece)
					{
						if (w->x > b->x && w->y < b->y && w->x - b->x == b->y - w->y && w->x < wxtemp && w->y > wytemp)
						{
							wxtemp = w->x;
							wytemp = w->y;
						}
					}
					for (auto& b1 : bPiece)
					{
						if (b1->x > b->x && b1->y < b->y && b1->x - b->x == b->y - b1->y && b1->x < wxtemp && b1->y > wytemp && b1->x < bxtemp && b1->y > bytemp)
						{
							bxtemp = b1->x;
							bytemp = b1->y;
						}
					}

					while (t <= 7)
					{
						t++;
						b->x += t;
						b->y -= t;

						if (b->x == bxtemp || b->y == bytemp)
						{
							b->x -= t;
							b->y += t;
							break;
						}

						if (b->x == wxtemp || b->y == wytemp)
						{
							for (auto& w : wPiece)
							{
								if (w->x == wxtemp && w->y == wytemp)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);
									check();
									b->x -= t;
									b->y += t;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
									t = 9;
									break;
								}
							}
						}
						if (t > 7)
						{
							break;
						}
						check();
						b->x -= t;
						b->y += t;
						if (king.check == 0)
						{
							return;
						}
					}
				}
				//king
				if (b->piece == KING)
				{
					//right
					switch (locAlg(b->x, b->y, 1, 0))
					{
					case 0:
						break;
					case 1:
						b->x += 1;
						if (wking.x == b->x + 1 && (wking.y == b->y || wking.y == b->y + 1 || wking.y == b->y - 1))
						{
							b->x -= 1;
							break;
						}

						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x -= 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x += 1;
						if (wking.x == b->x + 1 && (wking.y == b->y || wking.y == b->y + 1 || wking.y == b->y - 1))
						{
							b->x -= 1;
							break;
						}
						check();
						b->x -= 1;

						if (king.check == 0)
						{
							return;
						}
						break;
					}

					//left
					switch (locAlg(b->x, b->y, -1, 0))
					{
					case 0:
						break;
					case 1:
						b->x -= 1;
						if (wking.x == b->x - 1 && (wking.y == b->y || wking.y == b->y + 1 || wking.y == b->y - 1))
						{
							b->x += 1;
							break;
						}

						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x += 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x -= 1;
						if (wking.x == b->x - 1 && (wking.y == b->y || wking.y == b->y + 1 || wking.y == b->y - 1))
						{
							b->x += 1;
							break;
						}
						check();
						b->x += 1;

						if (king.check == 0)
						{
							return;
						}
						break;
					}

					//up
					switch (locAlg(b->x, b->y, 0, -1))
					{
					case 0:
						break;
					case 1:
						b->y -= 1;
						if (wking.y == b->y - 1 && (wking.x == b->x || wking.x == b->x + 1 || wking.x == b->x - 1))
						{
							b->y += 1;
							break;
						}

						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->y += 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->y -= 1;
						if (wking.y == b->y - 1 && (wking.x == b->x || wking.x == b->x + 1 || wking.x == b->x - 1))
						{
							b->y += 1;
							break;
						}
						check();
						b->y += 1;

						if (king.check == 0)
						{
							return;
						}
						break;
					}

					//down
					switch (locAlg(b->x, b->y, 0, 1))
					{
					case 0:
						break;
					case 1:
						b->y += 1;
						if (wking.y == b->y + 1 && (wking.x == b->x || wking.x == b->x + 1 || wking.x == b->x - 1))
						{
							b->y -= 1;
							break;
						}

						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->y -= 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->y += 1;
						if (wking.y == b->y + 1 && (wking.x == b->x || wking.x == b->x + 1 || wking.x == b->x - 1))
						{
							b->y -= 1;
							break;
						}
						check();
						b->y -= 1;

						if (king.check == 0)
						{
							return;
						}
						break;
					}

					//right up
					switch (locAlg(b->x, b->y, 1, -1))
					{
					case 0:
						break;
					case 1:
						b->x += 1;
						b->y -= 1;
						if (wking.y == b->y - 1 && wking.x == b->x + 1)
						{
							b->x -= 1;
							b->y += 1;
							break;
						}

						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x -= 1;
									b->y += 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x += 1;
						b->y -= 1;
						if (wking.y == b->y - 1 && wking.x == b->x + 1)
						{
							b->x -= 1;
							b->y += 1;
							break;
						}
						check();
						b->x -= 1;
						b->y += 1;

						if (king.check == 0)
						{
							return;
						}
						break;
					}

					//left up
					switch (locAlg(b->x, b->y, -1, -1))
					{
					case 0:
						break;
					case 1:
						b->x -= 1;
						b->y -= 1;
						if (wking.y == b->y - 1 && wking.x == b->x - 1)
						{
							b->x += 1;
							b->y += 1;
							break;
						}

						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x += 1;
									b->y += 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x -= 1;
						b->y -= 1;
						if (wking.y == b->y - 1 && wking.x == b->x - 1)
						{
							b->x += 1;
							b->y += 1;
							break;
						}
						check();
						b->x += 1;
						b->y += 1;

						if (king.check == 0)
						{
							return;
						}
						break;
					}

					//right down
					switch (locAlg(b->x, b->y, 1, 1))
					{
					case 0:
						break;
					case 1:
						b->x += 1;
						b->y += 1;
						if (wking.y == b->y + 1 && wking.x == b->x + 1)
						{
							b->x -= 1;
							b->y -= 1;
							break;
						}

						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x -= 1;
									b->y -= 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x += 1;
						b->y += 1;
						if (wking.y == b->y + 1 && wking.x == b->x + 1)
						{
							b->x -= 1;
							b->y -= 1;
							break;
						}
						check();
						b->x -= 1;
						b->y -= 1;

						if (king.check == 0)
						{
							return;
						}
						break;
					}

					//left down
					switch (locAlg(b->x, b->y, -1, 1))
					{
					case 0:
						break;
					case 1:
						b->x -= 1;
						b->y += 1;
						if (wking.y == b->y + 1 && wking.x == b->x - 1)
						{
							b->x += 1;
							b->y -= 1;
							break;
						}

						for (auto& w : wPiece)
						{
							if (w->piece != KING)
							{
								if (w->x == b->x && b->y == w->y)
								{
									wDead++;
									px = w->x;
									py = w->y;
									w->death = 1;
									w->dead(wDead);

									check();
									b->x += 1;
									b->y -= 1;

									col(w->y, w->x, py, px, w->piece + 6);
									wDead--;
									w->x = px;
									w->y = py;
									w->death = 0;

									if (king.check == 0)
									{
										return;
									}
								}
							}
						}
						break;
					case 2:
						break;
					case 3:
						b->x -= 1;
						b->y += 1;
						if (wking.y == b->y + 1 && wking.x == b->x - 1)
						{
							b->x += 1;
							b->y -= 1;
							break;
						}
						check();
						b->x += 1;
						b->y -= 1;

						if (king.check == 0)
						{
							return;
						}
						break;
					}
				}
			}
		}
		//if this runs it means stalemate, white cant move
		win = 4;
	}
	return;
}