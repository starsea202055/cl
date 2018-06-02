#ifndef MW_H
#define MW_H

#include <QMainWindow>
#include <QPainter>
#include <QImage>

namespace Ui {
class MW;
}

class MW : public QMainWindow
{
    Q_OBJECT

public:
    explicit MW(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    ~MW();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void receiveEnter();

signals:
    void showmainwindow();
    void quit();

private:
    Ui::MW *ui;
};

#endif // MW_H
