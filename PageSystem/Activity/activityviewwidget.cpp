#include "activityviewwidget.hpp"

ActivityViewWidget::ActivityViewWidget(QWidget *parent)
	: QWidget{parent},
	  parent_(parent) {
	this->setContentsMargins(0, 0, 0, 0);
	layout_.setContentsMargins(0, 0, 0, 0);
	view_.setContentsMargins(0, 0, 0, 0);

	view_.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	layout_.addWidget(&view_);
	this->setLayout(&layout_);
}

ActivityViewWidget::~ActivityViewWidget() {
	for(auto p : activity_view_set_) {
		delete p;
	}
}

bool ActivityViewWidget::setDefaultActivityView(const QString &view_id) {
	if((!map_.contains(view_id)) || (!stack_.empty())) {
		return false;
	}

	ActivityView *page = activity_view_set_.at(map_.value(view_id));

	stack_.push(page);
	page->start();
	view_.setCurrentWidget(page);

	return true;
}

void ActivityViewWidget::finishEvent(const QJsonObject &message) {
	if(stack_.size() == 1) {
		return;
	}

	ActivityView *from = stack_.top();
	stack_.pop();
	ActivityView *to = stack_.top();

	from->stop(message);
	to->resume(message);

	view_.setCurrentWidget(to);
}

void ActivityViewWidget::startActivityViewEvent(
	const QString &activity_view_id,
	const QJsonObject &message) {
	if(!map_.contains(activity_view_id)) {
		return;
	}

	ActivityView *from = stack_.top();
	ActivityView *to = activity_view_set_[map_.value(activity_view_id)];

	from->pause(message);
	to->start(message);

	stack_.push(to);

	view_.setCurrentWidget(to);
}

void ActivityViewWidget::closeWidgetEvent() {
	emit ActivityViewWidget::closeThis(this);
}

void ActivityViewWidget::finish(const QJsonObject &message) {
	this->finishEvent(message);
}

void ActivityViewWidget::startActivityView(const QString &activity_view_id,
		const QJsonObject &message) {
	this->startActivityViewEvent(activity_view_id, message);
}

void ActivityViewWidget::closeWidget() {
	this->closeWidgetEvent();
}
