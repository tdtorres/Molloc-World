#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main() {
    struct Player{
        int level;
        float xp;
        int HpMax;
        float currHp;
        int currentWeapon;
        int CurrentArmor;
        int inventory [2][20];
    };
    typedef struct Player Player;

}
