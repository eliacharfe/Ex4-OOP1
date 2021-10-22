#include "WindowManager.h"

WindowManager::WindowManager()
	: m_window(sf::VideoMode(DEF_SIZE_WINDOW, DEF_SIZE_WINDOW), "BOARD GAME"
	                          , sf::Style::Default), m_char(EMPTY_CELL)
{
}
//-----------------------------------------------
void WindowManager::Run()
{
	if (openFile())
		m_board.readFromFile();
	else
	{
		m_board.setSizeBoardUser();
		m_board.setBoard();
		m_menu.setMenu();
	}

	m_board.GetSizeBoard(); // from user

	while (m_window.isOpen())
	{
		m_window.clear();
		readDrawBoard();
		m_menu.Draw(m_window);
		m_window.display();

		if (auto event = sf::Event{}; m_window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::MouseButtonReleased:
			{
				m_MousePos = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
				buttomPressed( m_MousePos);
				break;
			}
			}
		}
	}
}
//-----------------------------------------------------------
void WindowManager::buttomPressed(const sf::Vector2f& location)
{
	float maxX, maxY;
	sf::Vector2f size = m_board.GetSizeBoard();
	if (size.y * BUTTOMS_SIZE_MENU > NUM_BUTTOMS * BUTTOMS_SIZE_MENU)
		maxY = (size.y * BUTTOMS_SIZE_MENU);
	else
		maxY = NUM_BUTTOMS * BUTTOMS_SIZE_MENU;

	if (location.y > maxY)
		return; // outside of max board and menu

	if (location.x < m_menu.getWidth()) // if pressed on menu
	{
		m_menu.buttomPressed(location);
		m_char = m_menu.GetObjectType();
		if (m_char == ERASE)
		{
		    m_board.Erase();
			m_isPlayerChar = false;
			m_wasPlayerChar = false;
			return;
		}
		if (m_char == PLAYER && !m_isDeletePressed)
			m_isPlayerChar = true;
		else
			m_isPlayerChar = false;

		if (m_char == SAVE)
			m_board.saveToFile();
		m_isDeletePressed = false;
	}

	if (location.x > BUTTOMS_SIZE_MENU
		|| location.y > NUM_BUTTOMS * BUTTOMS_SIZE_MENU) // if on board
	{
		if (m_char == DELETE)
		{
			m_isDeletePressed = true;
			if (m_board.Delete(location))
			{
				m_isPlayerChar = false;
				m_wasPlayerChar = false;
			}
			m_char = EMPTY_CELL;
			return;
		}
		if (m_wasPlayerChar && m_char == PLAYER)
		{
			m_char = EMPTY_CELL;
			return;
		}
		if (m_char == PLAYER && m_isPlayerChar)
			m_wasPlayerChar = true;

		m_board.buttomPressed(location, m_char);
		cout << "board get: " << m_char << std::endl << std::endl;
	}
}
//--------------------------------------------------------------
void WindowManager::readDrawBoard()
{
	sf::Vector2f size = m_board.GetSizeBoard();
	auto shape = sf::RectangleShape(sf::Vector2f(size.x * BUTTOMS_SIZE_MENU,
		                            size.y * BUTTOMS_SIZE_MENU));
	shape.setFillColor(sf::Color::White);
	m_window.draw(shape);

	shape = sf::RectangleShape(sf::Vector2f(BUTTOMS_SIZE_MENU, NUM_BUTTOMS * BUTTOMS_SIZE_MENU));
	shape.setFillColor(sf::Color(195,195,195));
	m_window.draw(shape);

	std::vector < std::vector < char >> board = m_board.getCharBoard();

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			sf::Texture texture;
			switch (board[i][j])
			{
			case PLAYER :	  texture.loadFromFile("player.png");  break;
			case ENEMY :	  texture.loadFromFile("enemy.png");   break;
			case COIN :	      texture.loadFromFile("coin.png");    break;
			case WALL :	      texture.loadFromFile("wall.png");    break;
			case LADDER :	  texture.loadFromFile("ladder.png"); break;
			case POLE :       texture.loadFromFile("pole.png");   break;
			default:
				break;
			}

			sf::Sprite sprite;
			sprite.setTexture(texture);
			sprite.setPosition( (i) * BUTTOMS_SIZE_MENU , (j)* BUTTOMS_SIZE_MENU);
			m_window.draw(sprite);
		}	
	}
}
//------------------------------------------
bool WindowManager::openFile()
{
	ifstream BoardFile("Board.txt");
	if (!BoardFile.is_open())
	{
		std::cerr << "Cannot open file\n";
		BoardFile.close();
		return false;
	}
	BoardFile.close();
	return true;
}
