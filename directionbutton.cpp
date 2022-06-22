#include "directionbutton.h"

DirectionButton::DirectionButton(QPixmap* texture, char direction): direction(direction)
{
    this->setIcon(*texture);
    this->setMinimumSize(64,64);
    this->setMaximumSize(64,64);

    connect(this, &DirectionButton::clicked, this, &DirectionButton::clickedSlot);


}
void DirectionButton::clickedSlot()
{
    emit charButtonClicked(direction);
}
