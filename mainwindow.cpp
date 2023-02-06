#include "mainwindow.hpp"

#include <QScreen>

#include "PageSystem/selectpage.hpp"


MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent),
	  view_(this) {

	this->setContentsMargins(0, 0, 0, 0);

	this->setCentralWidget(&view_);

	view_.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	view_.setDefaultPage<SelectPage>();

	connect(&view_, &PageSystem::closePageSystemSig, this, &QMainWindow::close);
}

MainWindow::~MainWindow() {
}

