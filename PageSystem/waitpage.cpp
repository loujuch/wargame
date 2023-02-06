#include "waitpage.hpp"

#include <QTimer>

WaitPage::WaitPage(QWidget *parent, myPage *parent_page_)
	: myPage(parent, parent_page_),
	  time_(0),
	  timer_(this),
	  button_("0", this) {
	main_layout_.addStretch(1);
	main_layout_.addLayout(&sub_layout_, 1);
	main_layout_.addStretch(1);

	sub_layout_.addStretch(1);
	sub_layout_.addWidget(&button_, 2);
	sub_layout_.addStretch(1);

	button_.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	this->setLayout(&main_layout_);

	connect(&button_, &QPushButton::clicked, this, [this]() {
		this->toParent();
	});
}

void WaitPage::entry() {
	time_ = 0;
	button_.setText(QString::number(time_));
	timer_.start(1000);

	connect(&timer_, &QTimer::timeout, this, [this]() {
		++time_;
		button_.setText(QString::number(time_));

		if(time_ == 60) {
			this->toParent();
		}
	});
}

void WaitPage::exit() {
	timer_.stop();
	disconnect(&timer_, &QTimer::timeout, nullptr, nullptr);
}

void WaitPage::start() {
	entry();
}

void WaitPage::stop() {
	exit();
}
