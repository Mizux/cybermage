#include "mainwindow.hpp"

//#include <thread>
//#include <chrono>
#include "player.hpp"
#include <QFrame>
#include <QHBoxLayout>
#include <QMainWindow>

MainWindow::MainWindow(const Player& player, const Player& enemy, QWidget* parent)
  : QMainWindow(parent)
  , player_()
  , enemy_() {
	setWindowTitle("CyberMage");
	setup(player, enemy);
	// std::this_thread::sleep_for (std::chrono::seconds(5));
	// setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
}

void
MainWindow::setup(const Player& player, const Player& enemy) {
	QFrame* frame            = new QFrame;
	QHBoxLayout* frameLayout = new QHBoxLayout;

	player_ = new PlayerWidget(player, this);
	// player_->setVisible(true);
	frameLayout->addWidget(player_);

	enemy_ = new PlayerWidget(enemy);
	// enemy_->setVisible(false);
	frameLayout->addWidget(enemy_);

	frame->setLayout(frameLayout);
	setCentralWidget(frame);
}
