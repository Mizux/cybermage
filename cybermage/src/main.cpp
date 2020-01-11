/* @file
 */

#include "mainwindow.hpp"
#include <QApplication>
#include <QSplashScreen>
#include <QStyleFactory>

#include "player.hpp"

Player
createPlayer(const std::string& name) {
	Player player(name);

	Ressource mili = {"Mercenary", 42};
	player.ressources.push_back(mili);
	Ressource nano = {"NanoTech", 42};
	player.ressources.push_back(nano);
	Ressource bio = {"BioTech", 42};
	player.ressources.push_back(bio);
	Ressource it = {"Telecom", 42};
	player.ressources.push_back(it);
	Ressource gov = {"Governement", 42};
	player.ressources.push_back(gov);
	Ressource mafia = {"Mafia", 42};
	player.ressources.push_back(mafia);

	return player;
}

int
main(int argc, char** argv) {
	QApplication app(argc, argv);
	app.setStyleSheet(
	  "QWidget {"
	  "color: #C0C0C0;"
	  "background-color: #202020;"
	  "}"

	  "QFrame, QToolTip {"
	  "border: 2px solid #3030C0;"
	  "border-radius: 2px;"
	  "padding: 2px;"
	  "}"
	  "QLabel {"
	  "border: 1px dashed #30C0C0;"
	  "border-radius: 2px;"
	  "padding: 1px;"
	  "}");

	QPixmap pixmap(":/ui/splash.png");
	QSplashScreen splash(pixmap);
	splash.show();

	splash.showMessage("Loading...");
	app.processEvents();

	splash.showMessage("Creating Player...");
	app.processEvents();

	Player player = createPlayer("mizux");
	Player enemy  = createPlayer("enemy");

	splash.showMessage("Creating Enemy...");
	app.processEvents();

	MainWindow window(player, enemy);
	window.show();
	splash.finish(&window);

	return app.exec();
}
