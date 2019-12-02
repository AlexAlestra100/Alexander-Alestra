// -----------------------------------------------------------------------
// monsterdb.c
// -----------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// -----------------------------------------------------------------------
// Some defines
#define NAME_MAX 64
#define BUFFER_MAX 256

// User instructions
const char *info[] = {
  "Enter a command:",
  "",
  "  ?  - print this list of commands",
  "  r  - read monster database (binary file)",
  "  w  - write monster database (binary file)",
  "  d  - display monsters",
  "  n  - sort monsters by name (ascending)",
  "  h  - sort monsters by hitpoints (descending)",
  "  q  - quit",
};
const int N_INFO = 9;


// -----------------------------------------------------------------------
// Structs

typedef struct Weapon_struct {
    char name[NAME_MAX];
    int damageModifier;
} Weapon;

typedef struct Stats_struct {
    int agility;
    int toughness;
    int hitpoints;
} Stats;

typedef struct Monster_struct {
    char name[NAME_MAX];
    Stats stats;
    Weapon weapon;
} Monster;

typedef struct MonsterList_struct {
    int size;
    Monster *list;
} MonsterList;


// -----------------------------------------------------------------------
// Function prototypes

void printInfo();
void displayMonster(Monster *m);
void displayMonsters(MonsterList *monsters);
int swapNeededName(Monster *a, Monster *b);
int swapNeededHitPoints(Monster *a, Monster *b);
void sortMonsters(MonsterList *monsters, char sortType);
void readDb(MonsterList *monsters, char *fileName);
void writeDb(MonsterList *monsters, char *fileName);
void readDb(MonsterList *monsters, char *fileName);
// -----------------------------------------------------------------------
// Main Program

int main(){
    MonsterList monsters = {0, NULL};
    char fileName[BUFFER_MAX];
    char userIn[BUFFER_MAX];
    char cmd;

    printInfo();

    int done = 0;
    while (!done) {
        printf("\n> ");
        scanf("%s", userIn);
        cmd = userIn[0];

        switch (cmd) {
            case '?':
                printInfo();
                break;
            case 'r':
                printf("DB file name (to read): ");
                scanf("%s",fileName);
                readDb(&monsters,fileName);
                break;
            case 'w':
                if(monsters.size == 0){
                    printf("(no monsters loaded)");
                    break;
                }
                printf("DB file name (to write): ");
                scanf("%s", fileName);
                writeDb(&monsters, fileName);
                break;
            case 'd':
                if(monsters.size == 0){
                    printf("(no monsters loaded)");
                    break;
                }
                displayMonsters(&monsters);
                break;
            case 'n':
                if(monsters.size == 0){
                    printf("(no monsters loaded)");
                    break;
                }
                sortMonsters(&monsters, cmd);
                displayMonsters(&monsters);
                break;
            case 'h':
                if(monsters.size == 0){
                    printf("(no monsters loaded)");
                    break;
                }
                sortMonsters(&monsters, cmd);
                displayMonsters(&monsters);
                break;
            case 'q':
                done = 1;
                break;
            default:
                printf("Unknown command `%c`", cmd);
                break;
        }
    }
    return 0;
}

// -----------------------------------------------------------------------
// Function implementations


void printInfo(){
    printf("\n");
    for(int i =0; i<N_INFO; i++){
        printf("%s\n",info[i]);
    }
}
void displayMonster(Monster *m){
    printf("%10s [a:%d, t:%d, hp:%2d] <%-15s mod:%2d>\n",m->name,m->stats.agility,m->stats.toughness,m->stats.hitpoints,m->weapon.name,m->weapon.damageModifier);
}
void displayMonsters(MonsterList *monsters){
    for(int i = 0; i<monsters->size; i++){
        displayMonster(&(monsters->list[i]));
    }
}
int swapNeededName(Monster *a, Monster *b){
    if(strcmp(a->name, b->name) > 0){
        return 1;
    }
    else{
        return 0;
    }
}
int swapNeededHitPoints(Monster *a, Monster *b){
    if(a->stats.hitpoints < b->stats.hitpoints){
        return 1;
    }
    else{
        return 0;
    }
}
void sortMonsters(MonsterList *monsters, char sortType){
    if(sortType == 'h'){
        Monster temp;
        for (int i = 1; i < monsters->size; ++i) {
            int j = i;
            while (j > 0 &&  swapNeededHitPoints(&monsters->list[j-1],&monsters->list[j])==1){
                temp = monsters->list[j];
                monsters->list[j] = monsters->list[j - 1];
                monsters->list[j - 1] = temp;
                j--;
            }
        }
    }
    if(sortType == 'n'){
        Monster temp;
        for (int i = 1; i < monsters->size; ++i){
            int j = i;
            while (j > 0 &&  swapNeededName(&monsters->list[j-1],&monsters->list[j])==1){
                temp = monsters->list[j];
                monsters->list[j] = monsters->list[j - 1];
                monsters->list[j - 1] = temp;
                j--;
            }
        }
    }
}
void readDb(MonsterList *monsters, char *fileName){
    FILE* inFile = fopen(fileName, "rb");
    if( inFile == NULL )
    {
        printf("Failed to open '%s' for read",fileName);
    }
    fread(&monsters->size, sizeof(int), 1, inFile);
    printf("1 items read from '%s' (size header)\n",fileName);
    printf("Allocating heap for %d Monsters...",monsters->size);
    if(monsters->list != NULL){
        free(monsters->list);
    }
    monsters->list = (Monster*)malloc(monsters->size * sizeof(Monster));
    printf("memory allocated\n");
    size_t numRead = fread(monsters->list, sizeof(Monster), monsters->size, inFile);
    printf("%d items read from '%s' (monster array)\n", (int)numRead, fileName);
    fclose(inFile);
}
void writeDb(MonsterList *monsters, char *fileName){
    FILE* outFile = fopen(fileName, "wb");
    if( outFile == NULL ){
        printf("Failed to open '%s'", fileName);
    }
    int a = fwrite(&monsters->size, sizeof(int),1 ,outFile);
    printf("%d items written to '%s' (size header)\n", a, fileName);
    fwrite(monsters->list, sizeof(Monster), monsters->size, outFile);
    printf("%d items written to '%s' (monster array)\n", monsters->size, fileName);
    fclose(outFile);
}
// -----------------------------------------------------------------------
