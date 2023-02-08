#ifndef ACTIVITYVIEWMANAGER_HPP
#define ACTIVITYVIEWMANAGER_HPP

#include <QWidget>
#include <QStackedWidget>
#include <QGridLayout>
#include <QStack>
#include <QHash>

#include "activityview.hpp"

class ActivityViewWidget : public QWidget {
	Q_OBJECT

	QWidget *parent_;

	QStack<ActivityView *> stack_;
	QHash<QString, qsizetype> map_;

	QGridLayout layout_;
	QStackedWidget view_;
	QList<ActivityView *>activity_view_set_;
  public:
	explicit ActivityViewWidget(QWidget *parent = nullptr);
	~ActivityViewWidget();

	bool setDefaultActivityView(const QString &view_id);

	template <typename T>
	bool addActivityView(const QString &view_id = typeid(T).name());

	virtual void finishEvent(const QJsonObject &message = QJsonObject());
	virtual void startActivityViewEvent(const QString &activity_view_id,
										const QJsonObject &message = QJsonObject());
	virtual void closeWidgetEvent();
  signals:
	void closeThis(const QWidget *p);

  public slots:
	void finish(const QJsonObject &message = QJsonObject());
	void startActivityView(const QString &activity_view_id,
						   const QJsonObject &message = QJsonObject());
	void closeWidget();
};

template <typename T>
bool ActivityViewWidget::addActivityView(const QString &view_id) {
	if(map_.contains(view_id)) {
		return false;
	}

	ActivityView *page = new T(view_id, parent_);

	connect(page, &ActivityView::closeWidgetSig, this,
			&ActivityViewWidget::closeWidget);
	connect(page, &ActivityView::finishSig, this, &ActivityViewWidget::finish);
	connect(page, &ActivityView::startActivityViewSig, this,
			&ActivityViewWidget::startActivityView);

	activity_view_set_.append(page);
	view_.addWidget(page);
	map_.emplace(view_id, activity_view_set_.size() - 1);

	return true;
}

#endif // ACTIVITYVIEWMANAGER_HPP
