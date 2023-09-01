#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "deck.hpp"
#include "ressources.hpp"
#include <QFrame>

struct Deck;

struct Player {
	Player(const std::string& name);
	std::string name;
	std::vector<Card> hand;
	Deck deck;
	Deck discard;

	std::list<Ressource> ressources;
};

class PlayerWidget : public QWidget {
	Q_OBJECT
	PlayerWidget(const PlayerWidget&)            = delete;
	PlayerWidget& operator=(const PlayerWidget&) = delete;

	public:
	PlayerWidget(const Player& player, QWidget* parent = 0);
	public slots:
	// void setVisible(bool visible);

	private:
	void setup();

	Player player_;

	RessourcesWidget* ressources_;
	QWidget* area_;

	HandWidget* hand_;
	DeckWidget* deck_;
	DeckWidget* discard_;
};

#endif
