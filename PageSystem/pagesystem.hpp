#ifndef PAGESYSTEM_HPP
#define PAGESYSTEM_HPP

#include <QWidget>
#include <QStackedWidget>
#include <QGridLayout>
#include <QHBoxLayout>

#include "mypage.hpp"

class PageSystem : public QWidget {
	Q_OBJECT

	myPage *default_page_;

	QGridLayout layout_;

	QStackedWidget view_;

	void newDefaultPage(myPage *page);
  public:
	explicit PageSystem(QWidget *parent = nullptr);
	~PageSystem();

	template <typename T>
	void setDefaultPage();

  signals:
	void closePageSystemSig(PageSystem *page);
};

template <typename T>
void PageSystem::setDefaultPage() {
	myPage *page = new T();
	newDefaultPage(page);
}

#endif // PAGESYSTEM_HPP
