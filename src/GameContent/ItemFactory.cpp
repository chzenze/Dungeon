#include "../../include/GameContant/ItemFactory.h"
#include <vector>
#include <unordered_map>
#include "../../include/GameCommon.h"
#include "../../include/GameContant/Item.h"

ItemFactory::ItemFactory(std::vector<std::unordered_map<std::string, std::string> > attributeList){
    int index = 0;
    this->attributeList = attributeList;
    updateGameItemPool();
}

Item ItemFactory::generateNewGameContant(dungeon * dungeon){
     if (attributeList.size() < 10) {
        updateGameItemPool();
    }

    Item item(contentPool[index]);
    if (contentPool[index]["TYPE"] == "WEAPON")
        item.symbol = '|';
    else if (contentPool[index]["TYPE"] == "OFFHAND")
        item.symbol = '}';
    else if (contentPool[index]["TYPE"] == "RANGED")
        item.symbol = '[';
    else if (contentPool[index]["TYPE"] == "ARMOR")
        item.symbol = ']';
    else if (contentPool[index]["TYPE"] == "HELMET")
        item.symbol = '(';
    else if (contentPool[index]["TYPE"] == "CLOAK")
        item.symbol = '{';
    else if (contentPool[index]["TYPE"] == "GLOVES")
        item.symbol = '\\';
    else if (contentPool[index]["TYPE"] == "BOOTS")
        item.symbol = '=';
    else if (contentPool[index]["TYPE"] == "RING")
        item.symbol = '"';
    else if (contentPool[index]["TYPE"] == "AMULET")
        item.symbol = '_';
    else if (contentPool[index]["TYPE"] == "LIGHT")
        item.symbol = '+';
    else if (contentPool[index]["TYPE"] == "SCROLL")
        item.symbol = '?';
    else if (contentPool[index]["TYPE"] == "FLASK")
        item.symbol = '!';
    else if (contentPool[index]["TYPE"] == "GOLD")
        item.symbol = '$';
    else if (contentPool[index]["TYPE"] == "AMMUNITION")
        item.symbol = '/';
    else if (contentPool[index]["TYPE"] == "FOOD")
        item.symbol = ',';
    else if (contentPool[index]["TYPE"] == "WAND")
        item.symbol = '-';
    else if (contentPool[index]["TYPE"] == "CONTAINER")
        item.symbol = '%';
    else
       item.symbol = '&'; 
    
    int randRoam = rand()%(dungeon->rooms.size() - 1);
    item.currentLocation[dim_x] = dungeon->rooms[randRoam]->position[dim_x] + rand()%dungeon->rooms[randRoam]->size[dim_x];
    item.currentLocation[dim_y] = dungeon->rooms[randRoam]->position[dim_y] + rand()%dungeon->rooms[randRoam]->size[dim_y];

    return item;
}
void ItemFactory::updateGameItemPool(){
    std::unordered_map<std::string, std::string> tmpAttribute;

    for(size_t j = 0; j < 100; j++){
        for(size_t i = 0; i < attributeList.size (); i++){
            tmpAttribute = attributeList.at(i);
            if (rand()%100 < stoi(tmpAttribute["RRTY"])) {
                contentPool.push_back(tmpAttribute);
            }
        } 
    }
    
}