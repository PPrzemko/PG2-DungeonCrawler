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
    void addTile(QPixmap* texturePath, bool hasPlayer);
    void addControl(std::map<std::string,QPixmap*> textures);
    void setLabelTexture(QPixmap* texture, int col, int row);
    void setCharacterParent(int col, int row, bool isPit);
    void addPlayer(std::map<std::string,QPixmap*> textures);
    void setLabelTexture(QPixmap *texture);


    ~MainWindow();



    const std::vector<std::vector<QLabel *> > &getLabelVector() const;
    void setDirection(char newDirection);
    char getDirection() const;
    bool getHasInputReady() const;
    void setHasInputReady(bool newHasInputReady);
    QPoint getQPosOfLabel(int col, int row);

    QLabel *getCurrentCharLabel() const;

private:
    bool hasInputReady;
    Ui::MainWindow *ui;
    char direction;
    QLabel* currentCharLabel;
    std::vector<std::vector<QLabel*>> labelVector;

public slots:
    void charButtonClickedSlot(char direction);
};

#endif // MAINWINDOW_H
