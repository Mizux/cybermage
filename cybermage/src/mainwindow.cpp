#include "mainwindow.hpp"

// #include <thread>
// #include <chrono>
#include "player.hpp"
#include <QApplication>
#include <QFrame>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>

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
	QVBoxLayout* frameLayout = new QVBoxLayout;

	{
		QHBoxLayout* boardLayout = new QHBoxLayout;

		player_ = new PlayerWidget(player, this);
		// player_->setVisible(true);
		boardLayout->addWidget(player_);

		enemy_ = new PlayerWidget(enemy, this);
		// enemy_->setVisible(false);
		boardLayout->addWidget(enemy_);

		frameLayout->addItem(boardLayout);
	}
	{ // Quit button at bottom
		QSpacerItem* spacer =
		  new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
		frameLayout->addItem(spacer);

		QPushButton* quitButton = new QPushButton("Quit", this);
		quitButton->setShortcut(QKeySequence::Quit);
		connect(quitButton, &QPushButton::clicked, qApp, &QApplication::quit);
		frameLayout->addWidget(quitButton);
	}
	frame->setLayout(frameLayout);
	setCentralWidget(frame);
}
