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

    ~StartScreen();

private:
    Ui::StartScreen *ui;

public slots:
    void StartButtonClicked();


};

#endif // STARTSCREEN_H
