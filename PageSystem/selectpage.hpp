#ifndef SELECTPAGE_HPP
#define SELECTPAGE_HPP

#include "mypage.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QList>

class SelectPage : public myPage {
	QHBoxLayout main_layout_;
	QVBoxLayout sub_layout_;
	QList<QPushButton *> button_list_;
  public:
	explicit SelectPage(QWidget *parent = nullptr,
						myPage *parent_page_ = nullptr);
	~SelectPage();

	void entry();
	void exit();

	void start();
	void stop();
};

#endif // SELECTPAGE_HPP
