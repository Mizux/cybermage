#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

class Player;
class PlayerWidget;

class MainWindow : public QMainWindow {
  Q_OBJECT
  MainWindow(const MainWindow&) = delete;
  MainWindow& operator=(const MainWindow&) = delete;

 public:
  MainWindow(const Player& player, const Player& enemy, QWidget* parent = 0);

 private:
  void setup(const Player& player, const Player& enemy);
  PlayerWidget* player_;
  PlayerWidget* enemy_;
};

#endif
