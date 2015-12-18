#include "card.hpp"

#include <QVBoxLayout>
#include <QLabel>

CardWidget::CardWidget(const Card& card, QWidget* parent)
    : QFrame(parent), card_(card) {
  setup();
}

void CardWidget::setup() {
  setFrameStyle(QFrame::StyledPanel);
  QVBoxLayout* layout = new QVBoxLayout(this);

  QLabel* cost = new QLabel;
  cost->setText(QString::fromStdString(card_.cost));
  layout->addWidget(cost);

  QLabel* name = new QLabel;
  name->setText(QString::fromStdString(card_.name));
  layout->addWidget(name);

  QLabel* illustration = new QLabel;
  illustration->setPixmap(QPixmap(QString::fromStdString(card_.illustration)));
  layout->addWidget(illustration);

  QLabel* description = new QLabel;
  description->setText(QString::fromStdString(card_.description));
  layout->addWidget(description);

#if 1  // DEBUG
  QLabel* code = new QLabel;
  code->setText(QString::fromStdString(card_.code));
  layout->addWidget(code);
#endif

  setLayout(layout);
}
