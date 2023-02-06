#include "pagesystem.hpp"

PageSystem::PageSystem(QWidget *parent)
	: QWidget{parent},
	  default_page_(nullptr),
	  view_(this) {
	this->setContentsMargins(0, 0, 0, 0);

	layout_.setContentsMargins(0, 0, 0, 0);
	layout_.addWidget(&view_);

	this->setLayout(&layout_);

	view_.setContentsMargins(0, 0, 0, 0);

	view_.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

PageSystem::~PageSystem() {
	if(default_page_ != nullptr) {
		delete default_page_;
		default_page_ = nullptr;
	}
}

void PageSystem::newDefaultPage(myPage *page) {
	if(page == nullptr) {
		return;
	}

	if(default_page_ != nullptr) {
		default_page_->unregisterPage();
		delete default_page_;
		default_page_ = nullptr;
	}

	default_page_ = page;
	default_page_->entry();

	connect(default_page_, &myPage::registerPageSig, this, [this](myPage * page) {
		view_.addWidget(page);
	});

	connect(default_page_, &myPage::unregisterPageSig, this, [this](myPage * page) {
		view_.removeWidget(page);
	});

	connect(default_page_, &myPage::toChildSig, this, [this](myPage * page) {
		myPage *p = nullptr;
		p = (myPage *)view_.currentWidget();
		p->stop();

		page->entry();
		view_.setCurrentWidget(page);
	});

	connect(default_page_, &myPage::toParentSig, this, [this](myPage * page) {
		myPage *p = nullptr;
		p = (myPage *)view_.currentWidget();
		p->exit();

		page->start();
		view_.setCurrentWidget(page);
	});

	connect(default_page_, &myPage::closeWindowSig, this, [this]() {
		emit PageSystem::closePageSystemSig(this);
	});

	default_page_->registerPage();
}
