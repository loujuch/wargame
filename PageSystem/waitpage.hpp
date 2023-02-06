#ifndef WAITPAGE_HPP
#define WAITPAGE_HPP

#include "mypage.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTimer>

class WaitPage : public myPage {
	int time_;

	QHBoxLayout main_layout_;
	QVBoxLayout sub_layout_;
	QTimer timer_;
	QPushButton button_;
  public:
	WaitPage(QWidget *parent = nullptr,
			 myPage *parent_page_ = nullptr);

	void entry();
	void exit();

	void start();
	void stop();
};

#endif // WAITPAGE_HPP
