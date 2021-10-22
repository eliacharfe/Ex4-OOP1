#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "consts.h"
#include "GameObject.h"
#include "Menu.h"

using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::cout;

class BoardEditor
{
public:
	// c-tors
	BoardEditor();

	void setBoard();
	void setSizeBoardUser();
	void setSizeBoardFronFile(sf::Vector2f size);

	void readFromFile();
	void saveToFile();

	void Erase();
	bool Delete(sf::Vector2f location);

	void setObjectType(int i, int j, const char c);

	void buttomPressed(sf::Vector2f location, const char c);
	sf::Vector2f GetSizeBoard()const;

	std::vector < std::vector<char>>  getCharBoard()const;
	char GetObjectType()const;
	char GetChar(sf::Vector2f location)const;

private:
	std::vector < std::vector<GameObject>> m_gameObject;
	std::vector < std::vector< char> > m_charBoard;

	sf::Vector2f m_size;

	char m_char;
};


