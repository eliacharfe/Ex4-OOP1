#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>

#include "consts.h"
#include "BoardEditor.h"
#include "GameObject.h"
#include "Menu.h"

using std::vector;

class WindowManager
{
public:
	WindowManager();

	void Run();
	void buttomPressed(const sf::Vector2f& location);
	void readDrawBoard();

	bool openFile();

private:
	sf::RenderWindow m_window;
	BoardEditor m_board;
	Menu m_menu;

	sf::Vector2f m_MousePos;

	char m_char;

	bool m_isPlayerChar = false;
	bool m_wasPlayerChar = false;
	bool m_isDeletePressed = false;
};


