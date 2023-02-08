#include "activityview.hpp"

ActivityView::ActivityView(const QString &id, QWidget *parent)
	: QWidget{parent},
	  status_(ACTIVITY_VIEW_STATUS::UNUSED),
	  view_id_(id),
	  reference_number_(0) {
}

void ActivityView::finish(const QJsonObject &message) {
	emit ActivityView::finishSig(message);
}

void ActivityView::startActivityView(const QString &activity_view_id,
									 const QJsonObject &message) {
	emit ActivityView::startActivityViewSig(activity_view_id, message);
}

void ActivityView::closeWidget() {
	emit ActivityView::closeWidgetSig();
}

void ActivityView::start(const QJsonObject &message) {
	++reference_number_;

	if(reference_number_ == 1) {
		this->onStart(message);
	} else {
		this->onResume(message);
	}

	status_ = ACTIVITY_VIEW_STATUS::ACTIVE;
}

void ActivityView::resume(const QJsonObject &message) {
	this->onResume(message);

	status_ = ACTIVITY_VIEW_STATUS::ACTIVE;
}

void ActivityView::pause(const QJsonObject &message) {
	this->onPause(message);

	status_ = ACTIVITY_VIEW_STATUS::USED;
}

void ActivityView::stop(const QJsonObject &message) {
	if(reference_number_ == 1) {
		this->onStop(message);
		status_ = ACTIVITY_VIEW_STATUS::UNUSED;
	} else {
		this->pause(message);
	}

	--reference_number_;
}
