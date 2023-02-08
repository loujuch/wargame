#ifndef WAITPAGE_HPP
#define WAITPAGE_HPP

#include "mypage.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTimer>

class WaitPage : public myPage {
	int time_;

	QHBoxLayout main_layout_;
	QVBoxLayout sub_layout_;
	QTimer timer_;
	QPushButton button_;
  public:
	WaitPage(const QString &name, QWidget *parent = nullptr);

	void onStart(const QJsonObject &message = QJsonObject());
	void onResume(const QJsonObject &message = QJsonObject());
	void onPause(const QJsonObject &message = QJsonObject());
	void onStop(const QJsonObject &message = QJsonObject());
};

#endif // WAITPAGE_HPP
