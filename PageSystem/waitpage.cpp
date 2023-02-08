#include "waitpage.hpp"

#include <QTimer>

WaitPage::WaitPage(const QString &name, QWidget *parent)
	: myPage(name, parent),
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
		this->finish();
	});
}

void WaitPage::onStart(const QJsonObject &message) {
	time_ = 0;
	button_.setText(QString::number(time_));
	timer_.start(1000);

	connect(&timer_, &QTimer::timeout, this, [this]() {
		++time_;
		button_.setText(QString::number(time_));

		if(time_ == 60) {
			this->finish();
		}
	});
}

void WaitPage::onResume(const QJsonObject &message) {
	onStart(message);
}

void WaitPage::onPause(const QJsonObject &message) {
	onStop(message);
}

void WaitPage::onStop(const QJsonObject &message) {
	timer_.stop();
	disconnect(&timer_, &QTimer::timeout, nullptr, nullptr);
}
