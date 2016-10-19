#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<iostream>
using namespace std;
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent * event);
};

#endif // MAINWINDOW_H
