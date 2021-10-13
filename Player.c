#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
/////////////////////////////////////////////////
//Structure of the Player's inventory//
/////////////////////////////////////////////////

struct inventory{
    int id;                         //The id of the item
    char name [20];                 //The name of the item
    char type [20];                 //The type of the item(weapon,tools,armor,crafting ressource,heal)
    int damage;                     //the damage of the item(only for type  weapon)
    int resistance;                 //the percentage of damage reduction (only for type armor)
    int restoring;                  //the number of HP that the item restore (only for type heal)
    int durabilityMax;              //the number of use of an item ( only for type weapon and tools)
    int currentDurability;          //the current durability of the item ( only for type weapon and tools)
    int quantity;                   //the quantity of a crafting ressource (only for crafting ressoruce)
};
typedef struct inventory  inventory;

/////////////////////////////////////////////////
//Structure of the Player//
/////////////////////////////////////////////////

struct Player{
    int level;                      //the level of the player
    float xp;                       //the quantity of xp
    int xpNextLevel;                //the quantity of xp needed for a level up
    int hpMax;                      //the maximum quantity of life that the player can reach
    float currHp;                   //the current quantity of life of the player
    int currentArmor;               //the id of the currentArmor
    char armorName[20];             //the name of the currentArmor
    inventory CurrentInventory;     //the inventory of the player

};
typedef struct Player Player;

/////////////////////////////////////////////////
//Structure of the itemList //
/////////////////////////////////////////////////

struct itemList{
    int id;
    char name [20];
    char type [20];
    int damage;
    int resistance;
    int restoring;
    int durability;
    struct itemList* next;
};
typedef struct itemList itemList;

/////////////////////////////////////////////////
//Function of the ItemList//
/////////////////////////////////////////////////

//add an element in the itemList
itemList* newItem(int id,char name[],char type[],int damage,int resistance,int restoring,int durability){
    itemList* temp = malloc(sizeof(itemList));
    temp->id=id;
    int i ;
    for ( i = 0; name[i]!='\0' ; ++i) {
        temp->name[i]=name[i];

    }
    temp->name[i]=name[i];
    for ( i = 0; type[i]!='\0' ; ++i) {
        temp->type[i]=type[i];
    }
    temp->type[i]=type[i];
    temp->damage=damage;
    temp->resistance=resistance;
    temp->restoring=restoring;
    temp->durability=durability;
    temp->next=NULL;
    return temp;

}

//init the itemList 
itemList* initItemList(){
    itemList* tmp;
    itemList* head = newItem(1,"Epee en bois","Arme",1,-1,-1,10);
    tmp= head;
    head->next = newItem(2,"Pioche en bois","Outil",-1,-1,-1,10);
    tmp=tmp->next;
    tmp->next = newItem(3,"Serpe en bois","Outil",-1,-1,-1,10);
    tmp=tmp->next;
    tmp->next= newItem(4,"Hache en bois","Outil",-1,-1,-1,10);
    tmp=tmp->next;
    tmp->next= newItem(5,"Sapin","Ressource de craft",-1,-1,-1,-1);
    tmp=tmp->next;
    tmp->next= newItem(6,"Pierre","Ressource de craft",-1,-1,-1,-1);
    tmp=tmp->next;
    tmp->next= newItem(7,"Herbe","Ressource de craft",-1,-1,-1,-1);
    tmp=tmp->next;
    tmp->next= newItem(8,"Epee en pierre","Arme",2,-1,-1,10);
    tmp=tmp->next;
    tmp->next= newItem(9,"Lance en pierre","Arme",3,-1,-1,8);
    tmp=tmp->next;
    tmp->next= newItem(10,"Marteau en pierre","Arme",4,-1,-1,5);
    tmp=tmp->next;
    tmp->next= newItem(11,"Plastron en pierre","Armure",-1,10,-1,-1);

    return head;
};

//print the item list
itemList* printItemList(itemList* item){
    while (item!=NULL){
        printf("-------------------------------------------------------------------\n");
        printf("cet item est le numero %d de la liste \n",item->id);
        printf("cet item s'appelle: ");
        for (int i = 0; item->name[i]!='\0' ; ++i) {
            printf("%c",item->name[i]);
        }
        printf("\ncet item est du type: ");
        for (int i = 0; item->type[i]!='\0' ; ++i) {
            printf("%c",item->type[i]);
        }
        if (strcmp(item->type,"Arme")==0){
            printf("\ncet item fait %d de degat\n",item->damage);
            printf("cet item a %d de durabilite maximum\n",item->durability);
        }
        else if(strcmp(item->type,"Outil")==0){
            printf("\ncet item a %d de durabilite maximum\n",item->durability);
        }
        else if(strcmp(item->type,"Ressource de craft")==0){
            printf("\n");
        }
        else if(strcmp(item->type,"Armure")==0){
            printf("\ncet item permet de resister a %d %% de degat maximum\n",item->resistance);
        }
        else if(strcmp(item->type,"Soin")==0){
            printf("\ncet item permet de soigner un maximum de %d de HP\n",item->restoring);
        }
        else{
            printf("\nPas de type trouver a cette item\n");
        }
        item=item->next;

    }
}

/////////////////////////////////////////////////
//Function of the Player//
/////////////////////////////////////////////////

//init the player with beggining values
Player* initPlayer(){
    Player* Hero = malloc(sizeof (Player));
    Hero->level =1;
    Hero->xp= 0;
    Hero->hpMax=100;
    Hero->currHp =100;
    Hero->currentArmor=0;

    return Hero;
}

//modify the armor of the Player
Player modifyArmor(Player* Hero,int idArmor){
    Hero->currentArmor=idArmor;
    switch (idArmor) {
        case 0: Hero->armorName[0]='\0';break;
        //case 1: for(int j;i)
    }
}

//print the actual armor of the Player
void printArmor(Player* hero){
    if (hero->currentArmor==0){
        printf("Le glandu la il a pas d'armure  bahahaha");
    }
    else{
        printf("LE PREUX CHEVALIER A CETTE ARMURE:");
        for (int i = 0; hero->armorName[i]!='\0'; ++i) {
            printf("%c",hero->armorName[i]);
        }
    }
};
int main() {
    itemList* item=initItemList();
    printItemList(item);
    Player* hero = initPlayer();
    printArmor(hero);


    printf("le level de ce type est : %d \n ",hero->level);





}
