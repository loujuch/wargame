#include "mypage.hpp"

myPage::myPage(QWidget *parent, myPage *parent_page_)
	: QWidget{parent},
	  parent_(parent),
	  parent_page_(parent_page_) {
	this->setContentsMargins(0, 0, 0, 0);
	this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void myPage::toChildIdeex(int index) {
	if(index >= child_page_list_.size()) {
		return;
	}

	emit myPage::toChildSig(child_page_list_[index]);
}

void myPage::toChildPage(myPage *page) {
	emit myPage::toChildSig(page);
}

void myPage::toParent() {
	emit myPage::toParentSig(parent_page_);
}

void myPage::registerPageEvent(myPage *page) {
	emit myPage::registerPageSig(page);
}

void myPage::unregisterPageEvent(myPage *page) {
	emit myPage::unregisterPageSig(page);
}

void myPage::closeWindowEvent(myPage *page) {
	emit myPage::closeWindowSig(page);
}

void myPage::toChildEvent(myPage *page) {
	emit myPage::toChildSig(page);
}

void myPage::toParentEvent(myPage *page) {
	emit myPage::toParentSig(page);
}

void myPage::registerPageSlot(myPage *page) {
	this->registerPageEvent(page);
}

void myPage::unregisterPageSlot(myPage *page) {
	this->unregisterPageEvent(page);
}

void myPage::toChildSlot(myPage *page) {
	this->toChildEvent(page);
}

void myPage::toParentSlot(myPage *page) {
	this->toParentEvent(page);
}

void myPage::closeWindowSlot(myPage *page) {
	this->closeWindowEvent(page);
}

void myPage::registerPage() {
	emit registerPageSig(this);

	for(auto &p : child_page_list_) {
		p->registerPage();
	}
}

void myPage::unregisterPage() {
	emit unregisterPageSig(this);

	for(auto &p : child_page_list_) {
		p->unregisterPage();
	}
}
