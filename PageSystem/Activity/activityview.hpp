#ifndef ACTIVITYVIEW_HPP
#define ACTIVITYVIEW_HPP

#include <QWidget>
#include <QJsonObject>

enum ACTIVITY_VIEW_STATUS {
	UNUSED = 0,
	USED,
	ACTIVE
};

/**
 * @brief The ActivityView class
 * 页面基类，用于管理。
 */
class ActivityView : public QWidget {
	Q_OBJECT

	// 该页面状态
	enum ACTIVITY_VIEW_STATUS status_;

	// 该页面id，全局唯一
	const QString view_id_;

	// 引用数，为0时表示该页面未被使用
	qsizetype reference_number_;
  public:
	explicit ActivityView(const QString &name, QWidget *parent = nullptr);

	inline enum ACTIVITY_VIEW_STATUS status();

	// 进入页面栈时调用
	void start(const QJsonObject &message = QJsonObject());
	// 在页面栈中变为栈顶时调用
	void resume(const QJsonObject &message = QJsonObject());
	// 在页面栈中离开栈顶时调用
	void pause(const QJsonObject &message = QJsonObject());
	// 离开页面栈时调用
	void stop(const QJsonObject &message = QJsonObject());

	// 对应上述阶段的事件
	virtual void onStart(const QJsonObject &message = QJsonObject()) = 0;
	virtual void onResume(const QJsonObject &message = QJsonObject()) = 0;
	virtual void onPause(const QJsonObject &message = QJsonObject()) = 0;
	virtual void onStop(const QJsonObject &message = QJsonObject()) = 0;

	void finish(const QJsonObject &message = QJsonObject());
	void startActivityView(const QString &activity_view_id,
						   const QJsonObject &message = QJsonObject());
	void closeWidget();

	inline QString view_id();
  signals:
	// 返回该页面出栈
	void finishSig(const QJsonObject &message);
	// 调用目标页面并入栈
	void startActivityViewSig(const QString &activity_view_id,
							  const QJsonObject &message);
	// 关闭该窗口
	void closeWidgetSig();
};

QString ActivityView::view_id() {
	return view_id_;
}

enum ACTIVITY_VIEW_STATUS ActivityView::status() {
	return status_;
}

#endif // ACTIVITYVIEW_HPP
