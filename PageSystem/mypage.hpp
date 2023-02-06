#ifndef MYPAGE_H
#define MYPAGE_H

#include <QWidget>

class myPage : public QWidget {
	Q_OBJECT

	QWidget *parent_;

	myPage *parent_page_;
	QList<myPage *> child_page_list_;
  public:
	explicit myPage(QWidget *parent = nullptr, myPage *parent_page_ = nullptr);

	template <typename T>
	myPage *addChildNode();

	void registerPage();
	void unregisterPage();

	void toChildIdeex(int index);
	void toChildPage(myPage *page);

	void toParent();

	virtual void entry() = 0;
	virtual void exit() = 0;

	virtual void start() = 0;
	virtual void stop() = 0;

	virtual void registerPageEvent(myPage *page);
	virtual void unregisterPageEvent(myPage *page);
	virtual void closeWindowEvent(myPage *page);
	virtual void toChildEvent(myPage *page);
	virtual void toParentEvent(myPage *page);

  signals:
	void registerPageSig(myPage *page);
	void unregisterPageSig(myPage *page);
	void toChildSig(myPage *page);
	void toParentSig(myPage *page);
	void closeWindowSig(myPage *page);

  public slots:
	void registerPageSlot(myPage *page);
	void unregisterPageSlot(myPage *page);
	void toChildSlot(myPage *page);
	void toParentSlot(myPage *page);
	void closeWindowSlot(myPage *page);
};

template <typename T>
myPage *myPage::addChildNode() {
	myPage *page = new T(parent_, this);

	connect(page, &myPage::toChildSig, this, &myPage::toChildSlot);
	connect(page, &myPage::toParentSig, this, &myPage::toParentSlot);
	connect(page, &myPage::registerPageSig, this, &myPage::registerPageSlot);
	connect(page, &myPage::unregisterPageSig, this, &myPage::unregisterPageSlot);
	connect(page, &myPage::closeWindowSig, this, &myPage::closeWindowSlot);

	child_page_list_.push_back(page);

	return page;
}

#endif // MYPAGE_H
