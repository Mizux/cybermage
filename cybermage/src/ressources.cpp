#include "ressources.hpp"

#include <QDebug>
#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>

RessourceWidget::RessourceWidget(const Ressource& res, QWidget* parent)
    : QFrame(parent), ressource_(res) {
  setup();
}

void RessourceWidget::setup() {
  setFrameStyle(QFrame::Panel);
  QVBoxLayout* layout = new QVBoxLayout;

  QLabel* name = new QLabel;
  name->setText(QString::fromStdString(ressource_.name));
  layout->addWidget(name);

  QLabel* value = new QLabel;
  value->setText(QString::number(ressource_.value));
  layout->addWidget(value);

  setLayout(layout);
}

RessourcesWidget::RessourcesWidget(const std::list<Ressource>& ressources,
                                   QWidget* parent)
    : QFrame(parent), ressources_() {
  setup(ressources);
}

void RessourcesWidget::setup(const std::list<Ressource>& ressources) {
  setFrameStyle(QFrame::Panel);
  QVBoxLayout* layout = new QVBoxLayout;

  QLabel* title = new QLabel;
  title->setText("Ressources");
  layout->addWidget(title);

  // ressources_ = new RessourceWidget(*ressources.begin());
  // layout->addWidget(ressources_);

  for (auto&& it : ressources) {
    RessourceWidget* r = new RessourceWidget(it, this);
    ressources_.append(r);
    layout->addWidget(r);
  }

  setLayout(layout);
}
