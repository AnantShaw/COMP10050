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
	int smartness=0;
	int strength=0;
	int magicskills=0;
	int luck=0;
	int dexterity=0;
	int assignedslotnumber;
	
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
   	while (input <2 || input > 6)
	{
   	printf("Input is invaid, Please input  number of players 2-6");
   	scanf ("%d", &input);
        }	

//input a name.
	for(numplayers=0;numplayers<input;numplayers++)
   	{
		printf("Please input name and type for player %d", numplayers+1);
		scanf("%s%s", &players[numplayers].name,&players[numplayers].type);
		if(players[numplayers].type[0]=='O' || players[numplayers].type[0]=='o')
		{
			players[numplayers].magicskills=0;
			players[numplayers].smartness=rand()%20;
			players[numplayers].luck=rand()%(50-players[numplayers].smartness);
			players[numplayers].strength=rand()%(100+1-80)+80;
			players[numplayers].dexterity=rand()%(100+1-80)+80;
		}
		if(players[numplayers].type[0]=='H' || players[numplayers].type[0]=='h')
		{
			players[numplayers].magicskills=rand()%300;
			players[numplayers].smartness=rand()%(300-players[numplayers].magicskills);
			players[numplayers].luck=rand()%(300-(players[numplayers].magicskills+players[numplayers].smartness));
			players[numplayers].strength=rand()%(300-(players[numplayers].magicskills+players[numplayers].smartness+players[numplayers].luck));
			players[numplayers].dexterity=rand()%(300-(players[numplayers].magicskills+players[numplayers].smartness+players[numplayers].luck+players[numplayers].strength));
		}
		if(players[numplayers].type[0]=='E' || players[numplayers].type[0]=='e')
		{
			players[numplayers].magicskills=rand()%(80+1-50)+50;
			players[numplayers].smartness=rand()%(100+1-70)+70;
			players[numplayers].luck=rand()%(100+1-60)+60;
			players[numplayers].strength=rand()%51;
			players[numplayers].dexterity=rand()%100;
		}
   	}
 	printf("Enter the number of slots you want to play with:\n");
	int slotamount=0;
	scanf("%d",&slotamount);
	int arr={100,101,102,103,104,105}; int i=0; int flag=0; int b=0;
	while(i<input)
	{       
		int v=rand()%slotamount;
		for(int j=0;j<6;j++)
		{
			if(arr[j]==v)
			{
				flag++;
			}
		}
		if(flag==0)
		{
			arr[i]=v;
			players[i].assignedslotnumber=v;
			i++;
		}
		flag=0;
	}
	for(int f=0;f<input;f++)
	{
		for(int l=(players[f].assignedslotnumber)-1;l<=(players[j].assignedslotnumber)+1;l++)
		{
			for(int j=0;j<input;j++)
			{
				if(players[j].assignedslotnumber==l)
				{
					b++;
				}
			}
		}
	        if(b==0)
		{	if(players[f].assignedslotnumber!=0)
			{
				printf("Press 0 to go backward and 1 to go forward or 2 to attack closest player\n"); 
			
		
	
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
