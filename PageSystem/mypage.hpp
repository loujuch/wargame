#ifndef MYPAGE_H
#define MYPAGE_H

#include <QJsonObject>

#include "Activity/activityview.hpp"

class myPage : public ActivityView {
	QJsonObject music
  public:
	explicit myPage(const QString &name, QWidget *parent = nullptr);
  signals:
};

#endif // MYPAGE_H
