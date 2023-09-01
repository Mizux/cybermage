#ifndef RESSOURCES_HPP
#define RESSOURCES_HPP

#include <QFrame>

struct Ressource {
	std::string name;
	std::int32_t value;
};

class RessourceWidget : public QFrame {
	Q_OBJECT
	public:
	RessourceWidget(const Ressource& res, QWidget* parent = 0);

	private:
	void setup();

	Ressource ressource_;
};

class RessourcesWidget : public QFrame {
	Q_OBJECT
	RessourcesWidget(const RessourcesWidget&)            = delete;
	RessourcesWidget& operator=(const RessourcesWidget&) = delete;

	public:
	RessourcesWidget(const std::list<Ressource>& ressources, QWidget* parent = 0);

	private:
	void setup(const std::list<Ressource>& ressources);

	QList<RessourceWidget*> ressources_;
};

#endif
