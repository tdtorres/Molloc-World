#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
/////////////////////////////////////////////////
//Structure of the Player's inventory//
/////////////////////////////////////////////////
struct inventory{
    int id;
    char nom [20];
    char type [20];
    int damage;
    int resistance;
    int restoring;
    int durability;
    int quantity;
};
typedef struct inventory  inventory;

/////////////////////////////////////////////////
//Structure of the Player//
/////////////////////////////////////////////////
struct Player{
    int level;
    float xp;
    int hpMax;
    float currHp;
    int currentWeapon;
    int currentArmor;
    inventory CurrentInventory;

};
typedef struct Player Player;
Player* initPlayer(){
    Player* Hero;
    Hero->level =32;
    Hero->xp= 615;
    Hero->hpMax=1000;
    Hero->currHp =921;
    Hero->currentWeapon=0;
    Hero->currentArmor=0;
    printf("le level de ce type est : %d ",Hero->level);
    return Hero;
}
int main() {

    initPlayer();
    printf("le level de ce type est : %d ",Hero->level);





}
