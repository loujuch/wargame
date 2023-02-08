#include "mainwindow.hpp"

#include <QScreen>

#include "PageSystem/selectpage.hpp"
#include "PageSystem/waitpage.hpp"


MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent),
	  view_(this) {

	this->setContentsMargins(0, 0, 0, 0);

	this->setCentralWidget(&view_);

	view_.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	view_.addActivityView<SelectPage>("default");
	view_.addActivityView<WaitPage>("timer");

	view_.setDefaultActivityView("default");

	connect(&view_, &PageSystem::closeThis, this, &QMainWindow::close);
}

MainWindow::~MainWindow() {
}

