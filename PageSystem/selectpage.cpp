#include "selectpage.hpp"
#include "waitpage.hpp"

SelectPage::SelectPage(QWidget *parent, myPage *parent_page_)
	: myPage(parent, parent_page_) {
	main_layout_.addStretch(1);
	main_layout_.addLayout(&sub_layout_, 1);
	main_layout_.addStretch(1);

	button_list_.push_back(new QPushButton("结果", this));
	myPage *page = this->addChildNode<WaitPage>();
	connect(button_list_.back(), &QPushButton::clicked, this, [this, page]() {
		this->toChildPage(page);
	});

	button_list_.push_back(new QPushButton("退出", this));
	connect(button_list_.back(), &QPushButton::clicked, this, [this]() {
		emit myPage::closeWindowSig(this);
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

void SelectPage::entry() {
}

void SelectPage::exit() {
}

void SelectPage::start() {
}

void SelectPage::stop() {
}
