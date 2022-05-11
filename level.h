#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
class Tile;
class Character;

class Level
{

private:
    const int width;
    const int height;
protected:
    std::vector<std::vector<Tile*>> tileVector;
    std::vector<std::vector<Character*>> characterVector;

public:
    Level(const int& width, const int& height);
    const Tile *getTile(int row, int col) const;
    void placeCharacter(Character *c, int row, int col);




};

#endif // LEVEL_H
