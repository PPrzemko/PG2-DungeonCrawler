#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <iostream>
#include <QDialog>

namespace Ui {
class StartScreen;
}

class StartScreen : public QDialog
{
    Q_OBJECT

public:
    explicit StartScreen(QWidget *parent = nullptr);
    QPushButton* getButtonStartGame();
    ~StartScreen();
    QPushButton* getLoadGameButton() const;


private:
    Ui::StartScreen *ui;



};

#endif // STARTSCREEN_H
