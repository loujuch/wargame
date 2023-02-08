#include "selectpage.hpp"

SelectPage::SelectPage(const QString &name, QWidget *parent)
	: myPage(name, parent) {
	main_layout_.addStretch(1);
	main_layout_.addLayout(&sub_layout_, 1);
	main_layout_.addStretch(1);

	button_list_.push_back(new QPushButton("结果", this));
	connect(button_list_.back(), &QPushButton::clicked, this, [this]() {
		this->startActivityView("timer");
	});

	button_list_.push_back(new QPushButton("退出", this));
	connect(button_list_.back(), &QPushButton::clicked, this, [this]() {
		emit myPage::closeWidget();
	});

	sub_layout_.addStretch(1);

	for(auto &b : button_list_) {
		b->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
		sub_layout_.addWidget(b, 2);
		sub_layout_.addStretch(1);
	}

	this->setLayout(&main_layout_);
}

SelectPage::~SelectPage() {
	for(auto &b : button_list_) {
		delete b;
	}
}

void SelectPage::onStart(const QJsonObject &message) {
}

void SelectPage::onResume(const QJsonObject &message) {
}

void SelectPage::onPause(const QJsonObject &message) {
}

void SelectPage::onStop(const QJsonObject &message) {
}
