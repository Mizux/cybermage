#ifndef DECK_HPP
#define DECK_HPP

#include "card.hpp"
#include <QWidget>

struct Deck {
	Deck(const std::string& name);
	std::string name;
	std::vector<Card> cards;

	void shuffle();
};

class HandWidget : public QFrame {
	Q_OBJECT
	public:
	HandWidget(const std::vector<Card>& cards, QWidget* parent = 0);

	private:
	void setup();

	std::vector<Card> cards_;
};

class DeckWidget : public QFrame {
	Q_OBJECT
	public:
	DeckWidget(const Deck& deck, QWidget* parent = 0);

	public slots:
	void shuffle();

	private:
	void setup();

	Deck deck_;
};

#endif
