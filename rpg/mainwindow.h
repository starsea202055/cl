#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QKeyEvent>
#include "rpgobj.h"
#include "gameworld.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    gameworld _game;

private slots:
    void receiveBegin();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void showEnterDialog();
    void quit();
};

#endif // MAINWINDOW_H
