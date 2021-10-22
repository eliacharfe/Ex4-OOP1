#include "BoardEditor.h"
#include <string>

BoardEditor::BoardEditor() : m_char(EMPTY_CELL)
{ }
//---------------------------------------------------------
void BoardEditor::setBoard()
{
	sf::Vector2f pos(BUTTOMS_SIZE_MENU, 0.0f);
	sf::Vector2f size(700.0f / m_size.x, DEF_SIZE_WINDOW / m_size.y);

	m_charBoard.resize(m_size.x);

	for (int y = 0; y < m_size.y; ++y)
	{
		std::vector<GameObject> temp;
		for (int x = 0; x < m_size.x; ++x)
		{
			m_charBoard[x].resize(m_size.y);
			GameObject object(pos, m_char);
			temp.push_back(object);
			pos.x += (700.0f / m_size.x);
		}
		m_gameObject.push_back(temp);
		pos.x = BUTTOMS_SIZE_MENU;
		pos.y += DEF_SIZE_WINDOW / m_size.y;
	}
}
//--------------------------------------------
void BoardEditor::buttomPressed(sf::Vector2f location, const char c)
{
	if (location.x >= BUTTOMS_SIZE_MENU && location.x < m_size.x * BUTTOMS_SIZE_MENU
		&& location.y >= 0 && location.y < m_size.y * BUTTOMS_SIZE_MENU)
		m_charBoard[location.x / BUTTOMS_SIZE_MENU][location.y / BUTTOMS_SIZE_MENU] = c;
}
//---------------------------------------------
sf::Vector2f BoardEditor::GetSizeBoard() const
{
	return sf::Vector2f(m_size.x, m_size.y);
}
//-----------------------------------------------
std::vector<std::vector<char>> BoardEditor::getCharBoard() const
{
	return std::vector<std::vector<char>>(m_charBoard);
}
//-------------------------------------
void BoardEditor::setSizeBoardUser()
{
	std::system("cls");
	std::cout << "Enter Height: " << std::endl;
	std::cin >> m_size.y;
	std::cout << "Enter Width: " << std::endl;
	std::cin >> m_size.x;
}
//----------------------------------------------------------------
void BoardEditor::setSizeBoardFronFile(sf::Vector2f size)
{
	m_size = size;
}
//----------------------------
void BoardEditor::Erase()
{
	for (int i = 0; i < m_charBoard.size(); i++)
		for (int j = 0; j < m_charBoard[0].size(); j++)
			m_charBoard[i][j] = EMPTY_CELL;
}
//-----------------------------------------
bool BoardEditor::Delete(sf::Vector2f location)
{
	if (m_charBoard[location.x / BUTTOMS_SIZE_MENU][location.y / BUTTOMS_SIZE_MENU] == PLAYER)
		return true;
	m_charBoard[location.x / BUTTOMS_SIZE_MENU][location.y / BUTTOMS_SIZE_MENU]
		= EMPTY_CELL;
	return false;
}
//----------------------------------------------
void BoardEditor::setObjectType(int i, int j, const char c)
{
	m_charBoard[i][j] = c;
}
//-----------------------------------------------------
char BoardEditor::GetObjectType() const
{
	return m_char;
}
//------------------------------------------
char BoardEditor::GetChar(sf::Vector2f location)const
{
	return m_charBoard[location.x / BUTTOMS_SIZE_MENU][location.y / BUTTOMS_SIZE_MENU];
}
//--------------------------------------------------
void BoardEditor::readFromFile()
{
	cout << "\nOpen to read\n";
	ifstream BoardFile("Board.txt");
	sf::Vector2f size;
	BoardFile >> size.x >> size.y;

	setSizeBoardFronFile(size);

	setBoard();

	while (!BoardFile.eof())
	{
		for (int y = 0; y < m_size.y; y++)
		{
			for ( int x = 0; x < m_size.x; x++)
			{
				setObjectType(y, x, BoardFile.get());
			}
			BoardFile.get();
		}
	}
	BoardFile.close();
}
//------------------------------------------
void BoardEditor::saveToFile()
{
	cout << "\nSave to file\n";
	ofstream BoardFileSave("Board.txt");
	BoardFileSave << m_size.y << " " << m_size.x;

	for (unsigned int y = 0; y < m_size.y; y++)
	{
		BoardFileSave << std::endl;
		for (unsigned int x = 0; x < m_size.x; x++)
		{
			BoardFileSave << GetObjectType();
		}
	}
	BoardFileSave.close();
}






