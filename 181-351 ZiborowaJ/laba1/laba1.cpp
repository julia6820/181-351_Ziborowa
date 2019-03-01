#include "laba1.h"
#include <QMessageBox>

laba1::laba1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

bool autorize(QString login, QString password)
{
	return login == "admin" && password == "123";

}
void laba1::On_pushButton_authorize_clicked()
{
	//Read lineEdits
	QString login = ui.lineEdit_login->text();
	QString password = ui.lineEdit_password->text();
	QMessageBox msgBox;

	if (autorize(login, password))
	{
		QMessageBox msgBox;
		msgBox.setText("Login is correct.");
		msgBox.exec();
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("Login is incorrect.");
		msgBox.setInformativeText("Do you want to try again?");
		msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
		msgBox.setDefaultButton(QMessageBox::Save);
	}
	int res = msgBox.exec();
	if (res == QMessageBox::Close)
	{
		close();
	}
};
