#include "deck.hpp"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <algorithm>
#include <random>

Deck::Deck(const std::string& name)
  : name(name)
  , cards() {}

void
Deck::shuffle() {
	std::shuffle(cards.begin(), cards.end(), std::mt19937{std::random_device{}()});
}

HandWidget::HandWidget(const std::vector<Card>& cards, QWidget* parent)
  : QFrame(parent)
  , cards_(cards) {
	setup();
}

void
HandWidget::setup() {
	setFrameStyle(QFrame::Panel);
	QHBoxLayout* layout = new QHBoxLayout;

	for (auto&& i : cards_) {
		QPushButton* c = new QPushButton;
		c->setText(QString::fromStdString(i.cost) + "\n" + QString::fromStdString(i.name) +
		           "\n" + QString::fromStdString(i.illustration) + "\n" +
		           QString::fromStdString(i.description));
		layout->addWidget(c);
	}

	setLayout(layout);
}

DeckWidget::DeckWidget(const Deck& deck, QWidget* parent)
  : QFrame(parent)
  , deck_(deck) {
	setup();
}

void
DeckWidget::shuffle() {
	deck_.shuffle();
}

void
DeckWidget::setup() {
	setFrameStyle(QFrame::Panel);
	QVBoxLayout* layout = new QVBoxLayout;

	QLabel* name = new QLabel;
	name->setText(QString::fromStdString(deck_.name));
	layout->addWidget(name);

	QLabel* card = new QLabel;
	card->setText("Empty");
	layout->addWidget(card);

	setLayout(layout);
}
