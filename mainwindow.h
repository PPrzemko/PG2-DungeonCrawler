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
    void addPlayer(std::map<std::string,QPixmap*> textures);
    void updateStausbarLabels(const std::string &strength, const std::string &stamina, const std::string &hitpoint);

    // GET SET
    const std::vector<std::vector<QLabel *> > &getLabelVector() const;
    void setDirection(char newDirection);
    char getDirection() const;
    bool getHasInputReady() const;
    void setHasInputReady(bool newHasInputReady);
    QPoint getQPosOfLabel(int col, int row);
    QLabel *getCurrentCharLabel() const;
    void setLabelTexture(QPixmap *texture);
    void setLabelTexture(QPixmap* texture, int col, int row);
    void setCharacterParent(int col, int row, bool isPit);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool hasInputReady;
    char direction;
    QLabel* currentCharLabel;
    std::vector<std::vector<QLabel*>> labelVector;

    void createGridTemplateForLabels();

    // need for CharStatus in GUI
    void initQStatusbar();
    QLabel* strengthStatusLabel;
    QLabel* staminaStatusLabel;
    QLabel* hitPointStatusLabel;

    
public slots:
    void charButtonClickedSlot(char direction);
};

#endif // MAINWINDOW_H
