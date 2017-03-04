#include<string.h>
#include<stdio.h>
#include<math.h>
#include<math.h>
enum slotname {ground, hill, city};

struct slottype
{
char slotType[20];
};

struct slotnumber
{
int slotNumber[20];
};

typedef struct Player{
	char name[20];
	char type[6];
	int life=100;
}player;
player players[6];
int main(void) 
{
	struct slottype ptype;
	struct slotnumber snumber;
	srand( time(NULL) );
	for(int i=0;i<20; i++)
	{ 
  		int b=rand()%3;
        ptype.slotType[i]=b;
        printf("%d\n",b);
        }
	int input=0, numplayers=0;
	char name[20];
// Hannah Asks the user to input a set of players (max 6). 
   printf("Please input  number of players 2-6");
   scanf ("%d", &input);
   while (input <2 || input > 6){
   printf("Input is invaid, Please input  number of players 2-6");
   scanf ("%d", &input);
   }	

//input a name.
for (numplayers=0;numplayers<input;numplayers++)
   {
	printf("Please input name for player %d", numplayers+1);
	scanf("%s", &players[numplayers].name);
   }
//For each player the user has to select a type (Elf, Human, Ogre, Wizard) 
  // Hannah Each player will be represented as a struct characterised by the fields identifying the player (player type and player name), life points, and the fields characterising the player capabilities (Smartness, Strength, Magic Skills, Luck and Dexterity). 
  // Hannah The life points are represented as an integer initially set to 100. 
 
 // Anant Subsequently the program asks the user to select the number of slots (max 20).
   
// Anant The type of the slot is selected randomly. The type of a slot could be: Level Ground, Hill or City. Slots are stored in an array.
   // Anant Subsequently the players are placed in a slot randomly. Note that only one player can be assigned to a slot. 
   // Anant After all the slots are created, the program asks each users whether s/he wants to move to the next or the previous slot - if possible - or whether s/he wants to attack the closest player.
    // Anant If a player decides to move to a slot it loses or gains capabilities according to the criteria described in Section C.
	
	//Hannah Asks a player to attack another player without placing them on the slots. Implement the functionality to attack players
	return 0;
}

// Hannah The capabilities are represented as integers that can assume values in [0, 100] and are randomly assigned to each player following the criteria indicated in section B.

// Hannah  Ramdom assign vaules Elf  Human, Ogre, Wizard

// Hannah If a player decides to perform an attack and there are two closest players, s/he should be able to choose between the two of them. The attacked and attacker players can lose or gain points according to the criteria described in Section D.

// Both at end After each player has chosen an action, the program prints the name and type of each player and its life points and terminates. These should be formatted as follows: <Player Name>(<Player Type>, <Life Points>. For example: 
