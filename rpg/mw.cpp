#include "mw.h"
#include "ui_mw.h"
#include "mainwindow.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QMessageBox>

MW::MW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW)
{
    ui->setupUi(this);
}

void MW::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), QPixmap("://images/back.jpg"));
}

MW::~MW()
{
    delete ui;
}

void MW::receiveEnter()
{
    this->show();
}

void MW::on_pushButton_clicked()
{
    this->hide();
    emit showmainwindow();
}

void MW::on_pushButton_2_clicked()
{
    emit quit();
}
