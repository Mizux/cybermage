#include "player.hpp"

#include <QVBoxLayout>
#include <QSpacerItem>
#include <QLabel>
#include <QPushButton>

Player::Player(const std::string& name)
    : name(name), hand(), deck("deck"), discard("discard"), ressources() {}

PlayerWidget::PlayerWidget(const Player& player, QWidget* parent)
    : QWidget(parent),
      player_(player),
      ressources_(),
      area_(),
      hand_(),
      deck_(),
      discard_() {
  setup();
}

void PlayerWidget::setup() {
  QVBoxLayout* mainLayout = new QVBoxLayout;

  QLabel* name = new QLabel;
  name->setText(QString::fromStdString(player_.name));
  mainLayout->addWidget(name);

  {
    QHBoxLayout* topLayout = new QHBoxLayout;
    ressources_ = new RessourcesWidget(player_.ressources);
    topLayout->addWidget(ressources_);

    area_ = new QWidget;
    topLayout->addWidget(area_);

    mainLayout->addLayout(topLayout);
  }

  {
    QHBoxLayout* bottomLayout = new QHBoxLayout;
    hand_ = new HandWidget(player_.hand);
    bottomLayout->addWidget(hand_);

    deck_ = new DeckWidget(player_.deck);
    bottomLayout->addWidget(deck_);

    discard_ = new DeckWidget(player_.discard);
    bottomLayout->addWidget(discard_);

    mainLayout->addLayout(bottomLayout);
  }

  setLayout(mainLayout);
}
