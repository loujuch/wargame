#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "PageSystem/pagesystem.hpp"

class MainWindow : public QMainWindow {
	Q_OBJECT

	PageSystem view_;
  public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();
};
#endif // MAINWINDOW_HPP
