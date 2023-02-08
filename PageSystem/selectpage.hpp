#ifndef SELECTPAGE_HPP
#define SELECTPAGE_HPP

#include "mypage.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QList>

class SelectPage : public myPage {
	QHBoxLayout main_layout_;
	QVBoxLayout sub_layout_;
	QList<QPushButton *> button_list_;
  public:
	explicit SelectPage(const QString &name, QWidget *parent = nullptr);
	~SelectPage();

	void onStart(const QJsonObject &message = QJsonObject());
	void onResume(const QJsonObject &message = QJsonObject());
	void onPause(const QJsonObject &message = QJsonObject());
	void onStop(const QJsonObject &message = QJsonObject());
};

#endif // SELECTPAGE_HPP
