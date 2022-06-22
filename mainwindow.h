#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "directionbutton.h"
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void addTile(QPixmap* texturePath);
    void addControl(std::map<std::string,QPixmap*> textures);
    ~MainWindow();

    char getDirection() const;

private:
    Ui::MainWindow *ui;
    char direction;

public slots:
    void charButtonClickedSlot(char direction);
};

#endif // MAINWINDOW_H
