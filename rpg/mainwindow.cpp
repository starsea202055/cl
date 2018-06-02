#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QMessageBox>

#include <QPushButton>
#include <QHBoxLayout>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _game.initWorld("");
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), QPixmap("://images/map2.png"));
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
    this->_game.show(pa);
    pa->end();
    delete pa;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    //direction = 1,2,3,4 for 上下左右
    if(e->key() == Qt::Key_A)
    {
        this->_game.handlePlayerMove(3,1);
    }
    else if(e->key() == Qt::Key_D)
    {
        this->_game.handlePlayerMove(4,1);
    }
    else if(e->key() == Qt::Key_W)
    {
        this->_game.handlePlayerMove(1,1);
    }
    else if(e->key() == Qt::Key_S)
    {
         this->_game.handlePlayerMove(2,1);
    }
    this->repaint();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveBegin()
{
    this->show();
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    emit showEnterDialog();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    emit showEnterDialog();

}
