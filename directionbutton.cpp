#include "directionbutton.h"

DirectionButton::DirectionButton(QPixmap* texture, char direction): direction(direction)
{
    this->setIcon(*texture);
    this->setIconSize(QSize(64,64));
    connect(this, &DirectionButton::clicked, this, &DirectionButton::clickedSlot);


}
void DirectionButton::clickedSlot()
{
    emit charButtonClicked(direction);
}
