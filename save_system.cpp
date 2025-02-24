#include"vars.h"
#include<fstream>

//restarts the game
void newGame()
{
	int px = 0;
	int py = 0;
	turn = 0;
	bDead = 0;
	wDead = 0;
	//empty out current taken locations
	for (int i = 0; i < 16; i++)
	{
		px = bPiece[i]->x;
		py = bPiece[i]->y;
		if ((px % 2 == 0 && py % 2 == 0) || (px % 2 == 1 && py % 2 == 1))
		{
			board[py][px] = "\033[100;47;10m \033[0m";
			continue;
		}
		board[py][px] = " ";
	}
	for (int i = 0; i < 16; i++)
	{
		px = wPiece[i]->x;
		py = wPiece[i]->y;
		if ((px % 2 == 0 && py % 2 == 0) || (px % 2 == 1 && py % 2 == 1))
		{
			board[py][px] = "\033[100;47;10m \033[0m";
			continue;
		}
		board[py][px] = " ";
	}

	//reset black and white pieces
	for (int i = 0; i < 16; i++)
	{
		if (i < 8)
		{
			bPiece[i]->piece = PAWN;
			wPiece[i]->piece = PAWN;
			bPiece[i]->piecePlacement(i, 6, PAWN);
			wPiece[i]->piecePlacement(i, 1, PAWN);
		}
		else if (i < 10)
		{
			if (i == 8)
			{
				bPiece[i]->piecePlacement(0, 7, ROOK);
				wPiece[i]->piecePlacement(0, 0, ROOK);
			}
			else
			{
				bPiece[i]->piecePlacement(7, 7, ROOK);
				wPiece[i]->piecePlacement(7, 0, ROOK);
			}
		}
		else if (i < 12)
		{
			if (i == 10)
			{
				bPiece[i]->piecePlacement(2, 7, BISHOP);
				wPiece[i]->piecePlacement(2, 0, BISHOP);
			}
			else
			{
				bPiece[i]->piecePlacement(5, 7, BISHOP);
				wPiece[i]->piecePlacement(5, 0, BISHOP);
			}
		}
		else if (i < 14)
		{
			if (i == 12)
			{
				bPiece[i]->piecePlacement(1, 7, HORSE);
				wPiece[i]->piecePlacement(1, 0, HORSE);
			}
			else
			{
				bPiece[i]->piecePlacement(6, 7, HORSE);
				wPiece[i]->piecePlacement(6, 0, HORSE);
			}
		}
		else
		{
			if (i == 14)
			{
				bPiece[i]->piecePlacement(4, 7, QUEEN);
				wPiece[i]->piecePlacement(4, 0, QUEEN);
			}
			else
			{
				bPiece[i]->piecePlacement(3, 7, KING);
				wPiece[i]->piecePlacement(3, 0, KING);
			}
		}
	}
	drawBoard();
}

//saves game to file
void save(std::string file)
{
	std::fstream File;
	File.open(file, std::ios::out);
	if (File.fail())
	{
		std::ofstream newFile(file);
		newFile.close();
		newFile.clear();
	}
	File.close();
	File.clear();

	File.open(file, std::ios::out);
	if (File.is_open())
	{
		for (auto& b : bPiece)
		{
			File << b->death << std::to_string(b->movesMade).length() << b->movesMade << std::to_string(b->x).length() << b->x << std::to_string(b->y).length() << b->y << std::to_string(b->check).length() << b->check << std::to_string(b->piece).length() << b->piece << std::to_string(b->enPassantCnt).length() << b->enPassantCnt << std::to_string(win).length() << win << std::to_string(turn).length() << turn << "\n";
		}
		for (auto& w : wPiece)
		{
			File << w->death << std::to_string(w->movesMade).length() << w->movesMade << std::to_string(w->x).length() << w->x << std::to_string(w->y).length() << w->y << std::to_string(w->check).length() << w->check << std::to_string(w->piece).length() << w->piece << std::to_string(w->enPassantCnt).length() << w->enPassantCnt << std::to_string(win).length() << win << std::to_string(turn).length() << turn << "\n";
		}
		File.close();
		File.clear();
		drawBoard();
		std::cout << "saved" << std::endl;
	}
}

//loads previously saved game
void load(std::string file)
{
	bDead = 0;
	wDead = 0;
	int px = 0;
	int py = 0;
	std::string p = "";
	std::string app = "";
	int size = 0;
	int cnt = 0;
	std::fstream File;
	std::string line = "";
	int ff = 0;

	File.open(file, std::ios::in);
	if (File.fail())
	{
		File.close();
		File.clear();
		drawBoard();
		std::cout << "file cannot be opened " << std::endl;
	}
	if (File.is_open())
	{
		//empty out current taken locations to prevent graphical errors from pieces
		for (int i = 0; i < 16; i++)
		{
			px = bPiece[i]->x;
			py = bPiece[i]->y;
			if ((px % 2 == 0 && py % 2 == 0) || (px % 2 == 1 && py % 2 == 1))
			{
				board[py][px] = "\033[100;47;10m \033[0m";
				continue;
			}
			board[py][px] = " ";
		}

		for (int i = 0; i < 16; i++)
		{
			px = wPiece[i]->x;
			py = wPiece[i]->y;
			if ((px % 2 == 0 && py % 2 == 0) || (px % 2 == 1 && py % 2 == 1))
			{
				board[py][px] = "\033[100;47;10m \033[0m";
				continue;
			}
			board[py][px] = " ";
		}

		//kill all dead pieces before placing new pieces
		for (auto& b : bPiece)
		{
			cnt = 1;
			if (ff < 16)
				getline(File, line);
			else
				break;
			//after 5 of these, it hits piece type
			for (int i = 0; i < 5; i++)
			{
				p = line[cnt];
				size = std::stoi(p);
				cnt++;
				for (int j = 0; j < size; j++)
				{
					p = line[cnt];
					app.append(p);
					cnt++;
				}
				if (i == 4)
				{
					b->piece = std::stoi(app);
				}
				app = "";
			}

			if (line[0] == '1')
			{
				b->death = 1;
				bDead++;
				b->dead(bDead);
			}
			ff++;
		}

		for (auto& w : wPiece)
		{
			cnt = 1;
			if (ff < 32)
				getline(File, line);
			else
				break;
			//after 5 of these, it hits piece type
			for (int i = 0; i < 5; i++)
			{
				p = line[cnt];
				size = std::stoi(p);
				cnt++;
				for (int j = 0; j < size; j++)
				{
					p = line[cnt];
					app.append(p);
					cnt++;
				}
				if (i == 4)
				{
					w->piece = std::stoi(app);
				}
				app = "";
			}

			if (line[0] == '1')
			{
				w->death = 1;
				wDead++;
				w->dead(wDead);
			}
			ff++;
		}
	}

	File.close();
	File.clear();
	File.open(file, std::ios::in);
	if (File.fail())
	{
		File.close();
		File.clear();
		drawBoard();
		std::cout << "file cannot be opened " << std::endl;
	}
	if (File.is_open())
	{
		px = 0;
		py = 0;
		ff = 0;

		for (auto& b : bPiece)
		{
			cnt = 1;
			px = b->x;
			py = b->y;
			app = "";

			if (ff < 16)
				getline(File, line);
			else
				break;

			p = line[0];
			app = p;
			b->death = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			b->movesMade = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			b->x = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			b->y = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			b->check = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			b->piece = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			b->enPassantCnt = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			win = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			turn = std::stoi(app);
			app = "";
			if (b->death == 0)
			{
				col(py, px, b->y, b->x, b->piece);
			}
			ff++;
		}

		for (auto& w : wPiece)
		{
			px = w->x;
			py = w->y;
			cnt = 1;
			app = "";

			if (ff < 32)
				getline(File, line);
			else
				break;

			p = line[0];
			app = p;
			w->death = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			w->movesMade = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			w->x = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			w->y = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			w->check = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			w->piece = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			w->enPassantCnt = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			win = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			turn = std::stoi(app);
			app = "";
			cnt = 0;

			if (w->death == 0)
			{
				col(py, px, w->y, w->x, w->piece + 6);
			}
			ff++;
		}
		File.close();
		File.clear();
		check();
		checkmate();
		stalemate();
		drawBoard();

		if (wking.check == 1)
		{
			std::cout << "white's in check" << std::endl;
			return;
		}
		if (king.check == 1)
		{
			std::cout << "black's in check" << std::endl;
			return;
		}
		std::cout << "loaded" << std::endl;
	}
}

//handles changes to saveslots
void saveSlot(std::string command)
{
	std::string fileName = "";
	std::vector<std::string> saveFiles;
	int size = 0;
	std::fstream File;
	int saveNum = 0;
	int newSave = 0;

	File.open("savefiles.txt", std::ios::in);
	if (File.fail())
	{
		std::ofstream newFile("saveFiles.txt");
		newFile.close();
	}
	if (File.is_open())
	{
		saveFiles.clear();
		while (getline(File, fileName))
		{
			saveFiles.push_back(fileName);
		}
		size = saveFiles.size();
		File.close();
		File.clear();
	}
	if (!saveFiles.empty())
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << " ____________________________________" << std::endl;
			std::cout << "|                                    |" << std::endl;
			int spaceOffset = 33 - saveFiles[i].length();

			std::cout << "| " << i + 1 << " " << saveFiles[i];
			for (int j = 0; j < spaceOffset; j++)
			{
				std::cout << " ";
			}
			std::cout << "|" << std::endl;
			std::cout << "|____________________________________|" << std::endl;
		}

		if (command == "L")
		{
			std::cout << "Enter saveslot number: ";
			std::cin >> saveNum;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				drawBoard();
				std::cout << "cannot enter letter values" << std::endl;
				return;
			}
			if (saveNum <= size && saveNum > 0)
			{
				fileName = saveFiles[saveNum - 1];
			}
			else
			{
				drawBoard();
				std::cout << "saveslot number doesnt exist" << std::endl;
				return;
			}

			load(fileName);
		}
		if (command == "S")
		{
			std::cout << "To save to a previous save, enter 1. To create a new save press 2 ";
			std::cin >> newSave;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				drawBoard();
				std::cout << "cannot enter letter values" << std::endl;
				return;
			}

			switch (newSave)
			{
			case 1:
				std::cout << "Enter saveslot number: ";
				std::cin >> saveNum;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore();
					drawBoard();
					std::cout << "cannot enter letter values" << std::endl;
					return;
				}
				if (saveNum <= size && saveNum > 0)
				{
					fileName = saveFiles[saveNum - 1];
				}
				else
				{
					drawBoard();
					std::cout << "saveslot number doesnt exist" << std::endl;
					return;
				}
				save(fileName);
				break;
			case 2:
				std::cout << "Enter the savefile name ";
				std::cin >> fileName;
				fileName.append(".txt");
				for (int i = 0; i < size; i++)
				{
					if (saveFiles[i] == fileName)
					{
						drawBoard();
						std::cout << "cannot enter the same name as another save" << std::endl;
						return;
					}
				}
				File.open("savefiles.txt", std::ios::app);
				File << fileName << "\n";
				File.close();
				File.clear();
				save(fileName);
				break;
			default:
				break;
			}
		}
		if (command == "D")
		{
			std::string temp = "";
			std::cout << "Enter saveslot number: ";
			std::cin >> saveNum;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				drawBoard();
				std::cout << "cannot enter letter values" << std::endl;
				return;
			}
			if (saveNum <= size && saveNum > 0)
			{
				fileName = saveFiles[saveNum - 1];
			}
			else
			{
				drawBoard();
				std::cout << "saveslot number doesnt exist" << std::endl;
				return;
			}
			std::cout << "Are you sure you want to delete " << fileName << "? y/n" << std::endl;
			std::cin >> temp;
			if (temp == "y")
			{
				saveFiles.erase(saveFiles.begin() + saveNum - 1);

				size = saveFiles.size();

				File.open("savefiles.txt", std::ios::out);
				if (File.is_open())
				{
					for (int i = 0; i < size; i++)
					{
						File << saveFiles[i] << "\n";
					}
				}
				File.close();
				File.clear();

				if (remove(fileName.c_str()) != 0)
				{
					drawBoard();
					std::cout << "Could not delete file" << std::endl;
					return;
				}
				drawBoard();
				std::cout << "File deleted successfully" << std::endl;
				return;
			}
		}
		return;
	}
	if (saveFiles.empty())
	{
		if (command == "S")
		{
			std::cout << "Enter the savefile name ";
			std::cin >> fileName;
			fileName.append(".txt");
			File.open("savefiles.txt", std::ios::app);
			File << fileName;
			File.close();
			File.clear();
			save(fileName);
			return;
		}
		drawBoard();
		std::cout << "no save files exist" << std::endl;
		return;
	}
}