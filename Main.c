#include<string.h>
#include<stdio.h>
#include<math.h>
#include<math.h>
#include<time.h> //including all the libraries
enum slotname {ground, hill, city}; //using enumerators for better readability

struct slottype //using structures
{
int slotType[20];
};

struct slotnumber
{
int slotNumber[20];
};

typedef struct Player //using structures
{
	char name[20];
	char type[6];
	double life;
	int smartness;
	int strength;
	int magicskills;
	int luck;
	int dexterity;
	int assignedslotnumber;
	
}player;
player players[6];
int main(void) 
{       
	struct slottype ptype;
	struct slotnumber snumber; int c=0;
	srand( time(NULL) );
	for(int i=0;i<20; i++)
	{ 
  		int b=rand()%3; //placing random slots in different positions
        	ptype.slotType[i]=b;
        }
	int input=0, numplayers=0;
	char name[20]; 

   	printf("Please input  number of players 2-6\n"); // asking the user to input a set of players (max 6). 
   	scanf ("%d", &input);
   	while (input <2 || input > 6)
	{
   	printf("Input is invaid, Please input  number of players 2-6\n");
   	scanf ("%d", &input);
        }	


	for(numplayers=0;numplayers<input;numplayers++)
   	{
		printf("Please input name and type for player %d\n", numplayers+1);
		scanf("%s%s", &players[numplayers].name,&players[numplayers].type);
		if(players[numplayers].type[0]=='O' || players[numplayers].type[0]=='o') //checking for the type of the player, and accordingly assigning values
		{
			players[numplayers].magicskills=0;
			players[numplayers].smartness=rand()%20;
			players[numplayers].luck=rand()%(50-players[numplayers].smartness);
			players[numplayers].strength=rand()%(100+1-80)+80;
			players[numplayers].dexterity=rand()%(100+1-80)+80;
		}
		if(players[numplayers].type[0]=='H' || players[numplayers].type[0]=='h') //checking for the type of the player, and accordingly assigning values
		{   do {
			players[numplayers].magicskills=rand()%300;
			players[numplayers].smartness=rand()%(300-players[numplayers].magicskills);
			players[numplayers].luck=rand()%(300-(players[numplayers].magicskills+players[numplayers].smartness));
			players[numplayers].strength=rand()%(300-(players[numplayers].magicskills+players[numplayers].smartness+players[numplayers].luck));
			players[numplayers].dexterity=rand()%(300-(players[numplayers].magicskills+players[numplayers].smartness+players[numplayers].luck+players[numplayers].strength));
		    }
		    while(players[numplayers].magicskills>100 || players[numplayers].smartness>100 || players[numplayers].luck>100 || players[numplayers].strength>100 || players[numplayers].dexterity>100);
		}
		if(players[numplayers].type[0]=='E' || players[numplayers].type[0]=='e') //checking for the type of the player, and accordingly assigning values
		{
			players[numplayers].magicskills=rand()%(80+1-50)+50;
			players[numplayers].smartness=rand()%(100+1-70)+70;
			players[numplayers].luck=rand()%(100+1-60)+60;
			players[numplayers].strength=rand()%51;
			players[numplayers].dexterity=rand()%100;
		}
		if(players[numplayers].type[0]=='W' || players[numplayers].type[0]=='w') //checking for the type of the player, and accordingly assigning values
		{
			players[numplayers].magicskills=rand()%(100+1-80)+80;
			players[numplayers].smartness=rand()%(100+1-90)+90;
			players[numplayers].luck=rand()%(100+1-50)+50;
			players[numplayers].strength=rand()%21;
			players[numplayers].dexterity=rand()%100;
		}
   	}
 	printf("Enter the number of slots you want to play with:\n"); //asking for the number of slots to play with
	int slotamount=0;
	scanf("%d",&slotamount);
	while(slotamount>20)
	{ printf("Invalid input\n");
	scanf("%d",&slotamount);
	}
	int arr[6]={100,101,102,103,104,105}; int i=0; int flag=0; int b=0; int n=0;
	while(i<input)
	{       
		int v=rand()%slotamount; //generating a random slotnumber for a player
		for(int j=0;j<6;j++)
		{
			if(arr[j]==v) //checking whether the slot number has been already assigned or not
			{
				flag++;
			}
		}
		if(flag==0)
		{
			arr[i]=v;
			players[i].assignedslotnumber=v; //assigning slot number to every player
			i++;
		}
		flag=0;
	}
	
	   for(int q=0;q<input;q++)
			{
				players[q].life=100.0;//assigning initial life value to 100 for each player
			}
	
	for(int f=0;f<input;f++) //actual work starts here
	{   
		if(players[f].assignedslotnumber!=0&&players[f].assignedslotnumber!=(slotamount-1)) //checking whether the player is not in the beginning or in the end of the slot list
		{
		for(int l=(players[f].assignedslotnumber)-1;l<(players[f].assignedslotnumber);l++)
		{
			for(int j=0;j<input;j++)
			{
				if(players[j].assignedslotnumber==l)
				{
					b=1; j=input; //checking if there is any intermediate player in the next slot after the current player
				}
			}
		}
		for(int l=(players[f].assignedslotnumber)+1;l<=(players[f].assignedslotnumber)+1;l++)
		{
			for(int j=0;j<input;j++)
			{
				if(players[j].assignedslotnumber==l)
				{
					c=1; j=input; //checking if there is any player in the previous slot of the current player
				}
			}
		}
			    if(b==1&&c==1) //there is a player both in front and behind the player
		{	
				printf("Player %d: Press 2 to attack closest player as moving isn't possible\n",f+1);
				int z=0;
				scanf("%d",&z);
				
				if(z==2) //choose to attack, and values change according to the game criterias 
				{
				int y=-100; int u=0; int p=0; int s=0;
					for(int m=players[f].assignedslotnumber+1;m<slotamount;m++)
					{
						for(int k=0;k<input;k++)
						{   if(k!=f)
							{if(m==players[k].assignedslotnumber)
							{   
								y=k; p++; //slot position for player in front of the current player
							}}
						}
					}
					for(int m=0;m<players[f].assignedslotnumber;m++)
					{
						for(int k=0;k<input;k++)
						{   if(k!=f)
							{if(m==players[k].assignedslotnumber)
							{
								u=k; s++; //slot position for player in the back of the current player
							}}
						}
					}
					 printf("Press 1 to attack front one and 2 to attack back player:\n");
					    int no;
					    scanf("%d",&no);
					    if(no==1)
						{
						if(players[y].strength<=70)
						{
							players[y].life=(players[y].life)*(0.5);
						}
						else
						{
							players[f].life=(players[f].life)*(0.7);
						}
						}
						if(no==2)
						{
						if(players[u].strength<=70)
						{
							players[u].life=(players[u].life)*(0.5);
						}
						else
						{
							players[f].life=(players[f].life)*(0.7);
						}
						}
					}
				}
			
			    if(b==0&&c==1) //there is a player in front of the user, in the very next slot
		{	
				printf("Player %d: Press 0 to go backward or 2 to attack closest player as moving front not possible\n",f+1);
				int z=0;
				scanf("%d",&z);
				if(z==0) //choice o to move behind
				{
					if(ptype.slotType[players[f].assignedslotnumber-1]==ground)
					{
						players[f].assignedslotnumber=players[f].assignedslotnumber-1;
						ptype.slotType[f]=ptype.slotType[f-1];
					}
					if(ptype.slotType[players[f].assignedslotnumber-1]==hill)
					{
						if(players[f].dexterity<50)
						{
							players[f].strength=players[f].strength-10;
						}
						if(players[f].dexterity>=60)
						{
							players[f].strength=players[f].strength+10;
						}
						players[f].assignedslotnumber=players[f].assignedslotnumber-1;
						ptype.slotType[f]=ptype.slotType[f-1];
					}
					if(ptype.slotType[players[f].assignedslotnumber-1]==city)
					{
						if(players[f].smartness>60)
						{
							players[f].magicskills=players[f].magicskills+10;
						}
						players[f].assignedslotnumber=players[f].assignedslotnumber-1;
						ptype.slotType[f]=ptype.slotType[f-1];
					}
				}
				
				if(z==2) //choose to attack
				{   int y=-100; int u=0; int p=0; int s=0;
					
					for(int m=0;m<players[f].assignedslotnumber;m++)
					{
						for(int k=0;k<input;k++)
						{   if(k!=f)
							{if(m==players[k].assignedslotnumber)
							{
								u=k; s++;
							}}
						}
					}
					
					
						if(players[u].strength<=70)
						{
							players[u].life=(players[u].life)*(0.5); 
						}
						else
						{
							players[f].life=(players[f].life)*(0.7); 
						}
					

				}
			}
		if(b==1&&c==0)
		{	
				printf("Player %d: Press 1 to go forward or 2 to attack closest player as moving backward isn't possible\n",f+1);
				int z=0;
				scanf("%d",&z);
				
				if(z==1) //choose 1 to move forward
				{
					if(ptype.slotType[players[f].assignedslotnumber+1]==ground)
					{
						players[f].assignedslotnumber=players[f].assignedslotnumber+1;
						ptype.slotType[f]=ptype.slotType[f+1];
					}
					if(ptype.slotType[players[f].assignedslotnumber+1]==hill)
					{
						if(players[f].dexterity<50)
						{
							players[f].strength=players[f].strength-10;
						}
						if(players[f].dexterity>=60)
						{
							players[f].strength=players[f].strength+10;
						}
						players[f].assignedslotnumber=players[f].assignedslotnumber+1;
						ptype.slotType[f]=ptype.slotType[f+1];
					}
					if(ptype.slotType[players[f].assignedslotnumber+1]==city)
					{
						if(players[f].smartness>60)
						{
							players[f].magicskills=players[f].magicskills+10;
						}
						if(players[f].smartness<=50)
						{
							players[f].dexterity=players[f].dexterity-10;
						}
						players[f].assignedslotnumber=players[f].assignedslotnumber+1;
						ptype.slotType[f]=ptype.slotType[f+1];
					}
				}
				if(z==2) //choose 2 to attack
				{   int y=-100; int u=0; int p=0; int s=0;
					for(int m=players[f].assignedslotnumber+1;m<slotamount;m++)
					{
						for(int k=0;k<input;k++)
						{   if(k!=f)
							{if(m==players[k].assignedslotnumber)
							{   
								y=k; p++;
							}}
						}
					}
					
					
						if(players[y].strength<=70)
						{
							players[y].life=(players[y].life)*(0.5); 
						}
						else
						{
							players[f].life=(players[f].life)*(0.7); 
						}
					
					
				}
			}
	    if(b==0&&c==0) //there is no player in the intermediate behind or in front of the current player
		{	
				printf("Player %d: Press 0 to go backward and 1 to go forward or 2 to attack closest player\n",f+1);
				int z=0;
				scanf("%d",&z);
				if(z==0) //choose 0 to move backward
				{
					if(ptype.slotType[players[f].assignedslotnumber-1]==ground)
					{
						players[f].assignedslotnumber=players[f].assignedslotnumber-1;
						ptype.slotType[f]=ptype.slotType[f-1];
					}
					if(ptype.slotType[players[f].assignedslotnumber-1]==hill)
					{
						if(players[f].dexterity<50)
						{
							players[f].strength=players[f].strength-10;
						}
						if(players[f].dexterity>=60)
						{
							players[f].strength=players[f].strength+10;
						}
						players[f].assignedslotnumber=players[f].assignedslotnumber-1;
						ptype.slotType[f]=ptype.slotType[f-1];
					}
					if(ptype.slotType[players[f].assignedslotnumber-1]==city)
					{
						if(players[f].smartness>60)
						{
							players[f].magicskills=players[f].magicskills+10;
						}
						players[f].assignedslotnumber=players[f].assignedslotnumber-1;
						ptype.slotType[f]=ptype.slotType[f-1];
					}
				}
				if(z==1) //choose 1 to move forward
				{
					if(ptype.slotType[players[f].assignedslotnumber+1]==ground)
					{
						players[f].assignedslotnumber=players[f].assignedslotnumber+1;
						ptype.slotType[f]=ptype.slotType[f+1];
					}
					if(ptype.slotType[players[f].assignedslotnumber+1]==hill)
					{
						if(players[f].dexterity<50)
						{
							players[f].strength=players[f].strength-10;
						}
						if(players[f].dexterity>=60)
						{
							players[f].strength=players[f].strength+10;
						}
						players[f].assignedslotnumber=players[f].assignedslotnumber+1;
						ptype.slotType[f]=ptype.slotType[f+1];
					}
					if(ptype.slotType[players[f].assignedslotnumber+1]==city)
					{
						if(players[f].smartness>60)
						{
							players[f].magicskills=players[f].magicskills+10;
						}
						if(players[f].smartness<=50)
						{
							players[f].dexterity=players[f].dexterity-10;
						}
						players[f].assignedslotnumber=players[f].assignedslotnumber+1;
						ptype.slotType[f]=ptype.slotType[f+1];
					}
				}
				if(z==2) //choose 2 to attack player
				{   int y=-100; int u=0; int p=0; int s=0;
					for(int m=players[f].assignedslotnumber+1;m<slotamount;m++)
					{
						for(int k=0;k<input;k++)
						{   if(k!=f)
							{if(m==players[k].assignedslotnumber)
							{   
								y=k; p++;
							}}
						}
					}
					for(int m=0;m<players[f].assignedslotnumber;m++)
					{
						for(int k=0;k<input;k++)
						{   if(k!=f)
							{if(m==players[k].assignedslotnumber)
							{
								u=k; s++;
							}}
						}
					} 
					if(p>s) //if the front player is closer to the current player
					{   
						if(players[y].strength<=70)
						{
							players[y].life=(players[y].life)*(0.5); 
						}
						else
						{
							players[f].life=(players[f].life)*(0.7); 
						}
					}
					if(s>p) //if the behind player is closer to the current player
					{
						if(players[u].strength<=70)
						{
							players[u].life=(players[u].life)*(0.5); 
						}
						else
						{
							players[f].life=(players[f].life)*(0.7); 
						}
					}
					if(s==p) //if both the players are at the same distance to the current player
					{   printf("Press 1 to attack front one and 2 to attack back player:\n");
					    int no;
					    scanf("%d",&no);
					    if(no==1)
						{
						if(players[y].strength<=70)
						{
							players[y].life=(players[y].life)*(0.5);
						}
						else
						{
							players[f].life=(players[f].life)*(0.7);
						}
						}
						if(no==2)
						{
						if(players[u].strength<=70)
						{
							players[u].life=(players[u].life)*(0.5);
						}
						else
						{
							players[f].life=(players[f].life)*(0.7);
						}
						}
					}
				}
			}
			}
			if(players[f].assignedslotnumber==0) //if current player is in the 1st slot
			{
			
			for(int l=(players[f].assignedslotnumber)+1;l<=(players[f].assignedslotnumber+1);l++)
		{
			for(int j=0;j<input;j++)
			{
				if(players[j].assignedslotnumber==l)
				{
					n++;
				}
			}
		}       if(n==0) //if no player in the intermediate front slot
				{
					printf("Player %d: Press 1 to go forward or 2 to attack closest player as moving backward isn't possible\n",f+1);
				int z=0;
				scanf("%d",&z);
				if(z==2) //choose 2 to attack
				{ 	int u=0;
				for(int m=slotamount-1;m>players[f].assignedslotnumber;m--)
					{
						for(int k=0;k<input;k++)
						{   if(k!=f)
							{if(m==players[k].assignedslotnumber)
							{
								u=k;
							}}
						}
					}
					if(players[u].strength<=70)
						{
							players[u].life=players[u].life*(1/2);
						}
						if(players[u].strength>70)
						{
							players[u].life=players[u].life*(7/10);
						}
				}
				if(z==0) //choose 0 to move backward
				{
					if(ptype.slotType[players[f].assignedslotnumber+1]==ground)
					{
						players[f].assignedslotnumber=players[f].assignedslotnumber-1;
						ptype.slotType[f]=ptype.slotType[f-1];
					}
					if(ptype.slotType[players[f].assignedslotnumber+1]==hill)
					{
						if(players[f].dexterity<50)
						{
							players[f].strength=players[f].strength-10;
						}
						if(players[f].dexterity>=60)
						{
							players[f].strength=players[f].strength+10;
						}
						players[f].assignedslotnumber=players[f].assignedslotnumber+1;
						ptype.slotType[f]=ptype.slotType[f+1];
					}
					if(ptype.slotType[players[f].assignedslotnumber-1]==city)
					{
						if(players[f].smartness>60)
						{
							players[f].magicskills=players[f].magicskills+10;
						}
						players[f].assignedslotnumber=players[f].assignedslotnumber-1;
						ptype.slotType[f]=ptype.slotType[f-1];
					}
				}
				
			}
			if(n!=0)
			{
				printf("Player %d: Press 2 to attack closest player as moving isn't possible\n",f+1);
				int z=0;
				scanf("%d",&z);
				
				
				if(z==2) //choose 2 to attack
				{ 	
					int u=0;
				for(int m=0;m<players[f].assignedslotnumber;m++)
					{
						for(int k=0;k<input;k++)
						{   if(k!=f)
							if(m==players[k].assignedslotnumber)
							{{
								u=k;
							}}
						}
					}
					if(players[u].strength<=70)
						{
							players[u].life=players[u].life*(1/2);
						}
						if(players[u].strength>70)
						{
							players[f].life=players[f].life*(7/10);
						}
				}
			}
			}
			if(players[f].assignedslotnumber==slotamount-1)
			{   int n=0;
			for(int l=(players[f].assignedslotnumber)-1;l<players[f].assignedslotnumber;l++)
		{
			for(int j=0;j<input;j++)
			{
				if(players[j].assignedslotnumber==l)
				{
					n++;
				}
			}
		}       if(n==0) //if no player in the intermediate behind position of the current player
				{
					printf("Player %d: Press 0 to go backward or 2 to attack closest player as moving front isn't possible\n",f+1);
				int z=0;
				scanf("%d",&z);
				if(z==2) //choose 2 to attack closest player
				{ 	int u=0;
				for(int m=0;m<players[f].assignedslotnumber;m++)
					{
						for(int k=0;k<input;k++)
						{   if(k!=f)
							{if(m==players[k].assignedslotnumber)
							{
								u=k;
							}}
						}
					}
					if(players[u].strength<=70)
						{
							players[u].life=(players[u].life)*(0.5);
						}
						if(players[u].strength>70)
						{
							players[f].life=(players[f].life)*(7/10);
						}
				}
				if(z==0) //choose 0 to go backward
				{
					if(ptype.slotType[players[f].assignedslotnumber-1]==ground)
					{
						players[f].assignedslotnumber=players[f].assignedslotnumber-1;
						ptype.slotType[f]=ptype.slotType[f-1];
					}
					if(ptype.slotType[players[f].assignedslotnumber-1]==hill)
					{
						if(players[f].dexterity<50)
						{
							players[f].strength=players[f].strength-10;
						}
						if(players[f].dexterity>=60)
						{
							players[f].strength=players[f].strength+10;
						}
						players[f].assignedslotnumber=players[f].assignedslotnumber-1;
						ptype.slotType[f]=ptype.slotType[f-1];
					}
					if(ptype.slotType[players[f].assignedslotnumber-1]==city)
					{
						if(players[f].smartness>60)
						{
							players[f].magicskills=players[f].magicskills+10;
						}
						players[f].assignedslotnumber=players[f].assignedslotnumber-1;
						ptype.slotType[f]=ptype.slotType[f-1];
					}
				}
				
			}
			if(n!=0) //player in the intermediate behind position
			{
				printf("Player %d: Press 2 to attack closest player as moving isn't possible\n",f+1);
				int z=0;
				scanf("%d",&z);
				if(z==2)
				{   int y=-100; int u=0; int p=0; int s=0;
					for(int m=players[f].assignedslotnumber+1;m<slotamount;m++) //finding slot number of closest player in front for every case
					{
						for(int k=0;k<input;k++)
						{   if(k!=f)
							{if(m==players[k].assignedslotnumber)
							{   
								y=k; p++;
							}}
						}
					}
					for(int m=0;m<players[f].assignedslotnumber;m++) //finding slot number of closest player behind for every case
					{
						for(int k=0;k<input;k++)
						{   if(k!=f)
							{if(m==players[k].assignedslotnumber)
							{
								u=k; s++;
							}}
						}
					}
						printf("Press 1 to attack front one and 2 to attack back player:\n"); //asking user which closest player to attack
					    int no;
					    scanf("%d",&no);
					    if(no==1)
						{
						if(players[y].strength<=70)
						{
							players[y].life=(players[y].life)*(0.5);
						}
						else
						{
							players[f].life=(players[f].life)*(0.7);
						}
						}
						if(no==2)
						{
						if(players[u].strength<=70)
						{
							players[u].life=(players[u].life)*(0.5);
						}
						else
						{
							players[f].life=(players[f].life)*(0.7);
						}
						}
					}
				}
			}	
			
			
			b=0;n=0;
		printf("After chance %d:\n",f+1);
	for(int g=0;g<input;g++) //printing the players with names and all the abilities after every move
	{
		printf("%s (%s, %lf), Smartness: %d, Strength: %d, Magic skills: %d, Luck: %d, Dexterity: %d \n",players[g].name,players[g].type,players[g].life,players[g].smartness,players[g].strength,players[g].magicskills,players[g].luck,players[g].dexterity);
	}
	}
	} //end

				
				
				
			
				
			
					
											
							
					
					
					 
			
		
	

  
   
