//! @file

#ifndef CARD_HPP
#define CARD_HPP

#include <QFrame>

struct Card {
  std::string cost;
  std::string name;
  std::string illustration;
  std::string description;
  std::string code;
};

class CardWidget : public QFrame {
  Q_OBJECT
 public:
  CardWidget(const Card& card, QWidget* parent = 0);

 private:
  void setup();

  Card card_;
};

#endif
