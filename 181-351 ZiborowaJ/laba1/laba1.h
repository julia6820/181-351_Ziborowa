#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_laba1.h"

class laba1 : public QMainWindow
{
	Q_OBJECT

public:
	laba1(QWidget *parent = Q_NULLPTR);

private:
	Ui::laba1Class ui;

private slots:
	void On_pushButton_authorize_clicked();
};
