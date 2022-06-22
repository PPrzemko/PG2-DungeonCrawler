#ifndef DIRECTIONBUTTON_H
#define DIRECTIONBUTTON_H
#include <QPushButton>

class DirectionButton : public QPushButton
{
    Q_OBJECT

private:
char direction;

public:
    DirectionButton(QPixmap* texture, char direction);

private slots:
    void clickedSlot();

signals:
    void charButtonClicked(char number);



};

#endif // DIRECTIONBUTTON_H
