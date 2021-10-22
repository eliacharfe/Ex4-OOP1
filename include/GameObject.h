#pragma once
#include <SFML/Graphics.hpp>
#include "consts.h"

class GameObject
{
public:
	GameObject(const sf::Vector2f& position,const char c);

	void SetGameObjectChar(const char c);
	void SetGameObjectOutline(sf::Color lineColor, float lineSize);
	void SetGameObjectposition(sf::Vector2f location);

	void DrawMenu(sf::RenderWindow& window, int i);

	char getObjectType() const;
	bool isButtomPressed(sf::Vector2f location, int i);

	void makeFalse();
	sf::Texture& getObjPicture(const char c);
	bool isObjectTrue()const;

private:
	char setCharType(int i);
	sf::RectangleShape createObject(int i);

	sf::Texture m_menuTexture;
	sf::Texture m_playerTexture;
	sf::Texture m_enemyTexture;
	sf::Texture m_coinTexture;
	sf::Texture	m_wallTexture;
	sf::Texture m_ladderTexture;
	sf::Texture m_poleTexture;
	sf::Texture m_emptyTexture;
	sf::Texture m_eraseTexture;
	sf::Texture m_deleteTexture;
	sf::Texture m_saveTexture;

	sf::Color m_outLineColor; 
    sf::Vector2f m_position;
	sf::Vector2f m_size;
	float m_outlineThikness;

	char m_char;
	bool m_isObject = false;
};