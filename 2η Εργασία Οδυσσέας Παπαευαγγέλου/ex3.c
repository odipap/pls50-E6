#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <unistd.h>

#define MIN_SCORE 0
#define MAX_SCORE 255

struct Player
{
	char name[17];
	int score;
	char id;
};


struct Card
{
	char color;	
	char shape;
	int number;
	char texture;
};

// synartisi gia tin tyxaia epilogi twn 12 kartwn
void getNextCard(struct Card C[], int size) 
{
	char color[3]   = {'r','b','g'};	// pedio timwn gia to xaraktiristiko 1
	char shape[3]   = {'c','t','r'};	// pedio timwn gia to xaraktiristiko 2
	int number[3]   = {1, 2, 3};		// pedio timwn gia to xaraktiristiko 3
	char texture[3] = {'b','h','e'};	// pedio timwn gia to xaraktiristiko 4
	
	int i,j;
	int flag_same = 0;	// flag_same == 0 diaforetikes kartes, flag_same == 1 yparxei idia
	int counter   = 0;	// voi8itiki metavliti kai tin epsalipsi idiwn kartwn
	
	srand(time(NULL));
	
	// gemisma twn 12 kartwn
	for(i=0;i<size;i++)	
	{
		C[i].color    = color[rand()%3];	// epilogi tou 1ou xaraktiristikou
		C[i].shape    = shape[rand()%3];	// epilogi tou 2ou xaraktiristikou
		C[i].number   = number[rand()%3];	// epilogi tou 3ou xaraktiristikou
		C[i].texture  = texture[rand()%3];	// epilogi tou 4ou xaraktiristikou
	} 
	
	// elegxos an yparxoyn idies kartes
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			if(i!=j)	// an i karta einai diaforetiki apo ton eauto tis
			{
				if( (C[i].color == C[j].color)     &&
					(C[i].shape == C[j].shape)     &&
					(C[i].number == C[j].number)   &&
					(C[i].texture == C[j].texture))
				{
//					printf("\n ==> SAME CARDS <== \n");
//					printf("[%c, %c, %d, %c]\n\n", C[i].color, C[i].shape, C[i].number, C[i].texture);
					counter = counter + 1;	// an vrei idia karta stis 12ada auksisi tou metriti kata 1
				}
			}
		}
	}
	
	if(counter>0)	// an exei vrei idia karta kai o metritis exei auksi8ei
	{
		flag_same = 1;	// 8etw 1 tin metavliti gia na mpei sto while loop kai ksanaepilepsei 12 kartes 
		counter   = 0;	// midenizw ksana ton metriti	
	}
	else if(counter==0)	// an o metritis den exei auksi8ei tote den yparxei idia karta stin 12ada
		flag_same = 0;	// 8etw 0 tin metavliti gia na min mpei sto while loop  
	
			
	while(flag_same)	// oso yparxeoun idies kartes epilogi ksana 12 kartwn
	{
		for(i=0;i<size;i++)
		{		
			C[i].color    = color[rand()%3];	// epilogi tou 1ou xaraktiristikou
			C[i].shape    = shape[rand()%3];	// epilogi tou 2ou xaraktiristikou
			C[i].number   = number[rand()%3];	// epilogi tou 3ou xaraktiristikou
			C[i].texture  = texture[rand()%3];	// epilogi tou 4ou xaraktiristikou
		}
			
		for(i=0;i<size;i++)
		{
			for(j=0;j<size;j++)
			{
				if(i!=j)
				{
					if( (C[i].color == C[j].color)     &&
						(C[i].shape == C[j].shape)     &&
						(C[i].number == C[j].number)   &&
						(C[i].texture == C[j].texture))
					{
//						printf("\n ==> SAME CARDS <== \n");
//						printf("[%c, %c, %d, %c]\n", C[i].color, C[i].shape, C[i].number, C[i].texture);
						counter = counter + 1;
					}
				}
			}
		}	
	
		if(counter>0)	// an exei vrei idia karta kai o metritis exei auksi8ei
		{
			flag_same = 1;	// 8etw 1 tin metavliti gia na mpei sto while loop kai ksanaepilepsei 12 kartes 
			counter   = 0;	// midenizw ksana ton metriti	
		}
		else if(counter==0)	// an o metritis den exei auksi8ei tote den yparxei idia karta stin 12ada
			flag_same = 0;	// 8etw 0 tin metavliti gia na min mpei sto while loop  
	}
}

// synartisi gia na elegxw an i 3ada kartwn pou epeleksa einai SET i OXI. epistrefei 1 an einai SET, 0 an den einai
int CheckSET(int rows, int cols, struct Card Grid[rows][cols], int x[], int y[], int size)
{
	int i;
	int flag_color   = -1;	// 0 = idio xrwma 	, 1 = diaforetiko xrwma
	int flag_shape   = -1;	// 0 = idio sxima 	, 1 = diaforetiko sxima
	int flag_number  = -1;	// 0 = idio ari8mo 	, 1 = diaforetiko ari8mo
	int flag_texture = -1;	// 0 = idia yfi 	, 1 = diaforetiki yfi	
	
	for(i=0; i<size; i++)	// ektypwsi twn kartwn pou exw epileksei
		printf("[%c, %c, %d, %c] \t", Grid[x[i]][y[i]].color, Grid[x[i]][y[i]].shape, Grid[x[i]][y[i]].number, Grid[x[i]][y[i]].texture);	
	
	// elegxos gia oles idio xrwma (1o xaraktiristiko)  (Card1 == Card2) && (Card2 == Card3) && (Card1 == Card3)
	if(Grid[x[0]][y[0]].color == Grid[x[1]][y[1]].color &&
	   Grid[x[1]][y[1]].color == Grid[x[2]][y[2]].color &&
	   Grid[x[0]][y[0]].color == Grid[x[2]][y[2]].color )
	{
		printf("\n-- Same Color -- \n");
		flag_color = 0;
	}
	
	// elegxos gia oles diaforetiko xrwma (1o xaraktiristiko)  (Card1 != Card2) && (Card2 != Card3) && (Card1 != Card3)
	if(Grid[x[0]][y[0]].color != Grid[x[1]][y[1]].color &&
	   Grid[x[1]][y[1]].color != Grid[x[2]][y[2]].color &&
	   Grid[x[0]][y[0]].color != Grid[x[2]][y[2]].color )
	{
		printf("\n-- Different Color -- \n");
		flag_color = 1;
	}
	
	// elegxos gia oles idio sximaa (2o xaraktiristiko)  (Card1 == Card2) && (Card2 == Card3) && (Card1 == Card3)	
	if(Grid[x[0]][y[0]].shape == Grid[x[1]][y[1]].shape &&
	   Grid[x[1]][y[1]].shape == Grid[x[2]][y[2]].shape &&
	   Grid[x[0]][y[0]].shape == Grid[x[2]][y[2]].shape )
	{
		printf("\n-- Same Shape -- \n");
		flag_shape = 0;
	}
	
	// elegxos gia oles diaforetiko sximaa (2o xaraktiristiko)  (Card1 != Card2) && (Card2 != Card3) && (Card1 != Card3)	
	if(Grid[x[0]][y[0]].shape != Grid[x[1]][y[1]].shape &&
	   Grid[x[1]][y[1]].shape != Grid[x[2]][y[2]].shape &&
	   Grid[x[0]][y[0]].shape != Grid[x[2]][y[2]].shape )
	{
		printf("\n-- Different Shape -- \n");
		flag_shape = 1;
	}
	
	// elegxos gia oles idio ari8mo (3o xaraktiristiko)  (Card1 == Card2) && (Card2 == Card3) && (Card1 == Card3)	
	if(Grid[x[0]][y[0]].number == Grid[x[1]][y[1]].number &&
	   Grid[x[1]][y[1]].number == Grid[x[2]][y[2]].number &&
	   Grid[x[0]][y[0]].number == Grid[x[2]][y[2]].number )
	{
		printf("\n-- Same Number -- \n");
		flag_number = 0;
	}
	
	// elegxos gia oles diaforetiko ari8mo (3o xaraktiristiko)  (Card1 != Card2) && (Card2 != Card3) && (Card1 != Card3)	
	if(Grid[x[0]][y[0]].number != Grid[x[1]][y[1]].number &&
	   Grid[x[1]][y[1]].number != Grid[x[2]][y[2]].number &&
	   Grid[x[0]][y[0]].number != Grid[x[2]][y[2]].number )
	{
		printf("\n-- Different number -- \n");
		flag_number = 1;
	}
	
	// elegxos gia oles idia yfi (4o xaraktiristiko)  (Card1 == Card2) && (Card2 == Card3) && (Card1 == Card3)	
	if(Grid[x[0]][y[0]].texture == Grid[x[1]][y[1]].texture &&
	   Grid[x[1]][y[1]].texture == Grid[x[2]][y[2]].texture &&
	   Grid[x[0]][y[0]].texture == Grid[x[2]][y[2]].texture )
	{
		printf("\n-- Same Texture -- \n");
		flag_texture = 0;
	}
	
	// elegxos gia oles diaforetiki yfi (4o xaraktiristiko)  (Card1 != Card2) && (Card2 != Card3) && (Card1 != Card3)	
	if(Grid[x[0]][y[0]].texture != Grid[x[1]][y[1]].texture &&
	   Grid[x[1]][y[1]].texture != Grid[x[2]][y[2]].texture &&
	   Grid[x[0]][y[0]].texture != Grid[x[2]][y[2]].texture )
	{
		printf("\n-- Different Texture -- \n");
		flag_texture = 1;
	}
	
	if(flag_color == -1 || flag_shape == -1 || flag_number == -1 || flag_texture == -1)
	{	
		printf("\n--> NOT SET \n");
		return 0;
	}
	if( (flag_color == 0 && flag_shape == 0 && flag_number == 0 && flag_texture == 0) ||
		(flag_color == 0 && flag_shape == 0 && flag_number == 0 && flag_texture == 1) ||
		(flag_color == 0 && flag_shape == 0 && flag_number == 1 && flag_texture == 0) ||
		(flag_color == 0 && flag_shape == 0 && flag_number == 1 && flag_texture == 1) ||
		(flag_color == 0 && flag_shape == 1 && flag_number == 0 && flag_texture == 0) ||
		(flag_color == 0 && flag_shape == 1 && flag_number == 0 && flag_texture == 1) ||
		(flag_color == 0 && flag_shape == 1 && flag_number == 1 && flag_texture == 0) ||
		(flag_color == 0 && flag_shape == 1 && flag_number == 1 && flag_texture == 1) ||
		(flag_color == 1 && flag_shape == 0 && flag_number == 0 && flag_texture == 0) ||
		(flag_color == 1 && flag_shape == 0 && flag_number == 0 && flag_texture == 1) ||
		(flag_color == 1 && flag_shape == 0 && flag_number == 1 && flag_texture == 0) ||
		(flag_color == 1 && flag_shape == 0 && flag_number == 1 && flag_texture == 1) ||
		(flag_color == 1 && flag_shape == 1 && flag_number == 0 && flag_texture == 0) ||
		(flag_color == 1 && flag_shape == 1 && flag_number == 0 && flag_texture == 1) ||
		(flag_color == 1 && flag_shape == 1 && flag_number == 1 && flag_texture == 0) ||
		(flag_color == 1 && flag_shape == 1 && flag_number == 1 && flag_texture == 1) )	// elegxos olwn twn periptwsewn gia tin yparksi SET
	{
		printf("\n--> SET \n");
		return 1;
	}
}


void MakeCardsGrid(struct Card C[], int rows, int cols, struct Card Grid[rows][cols]) // sunartisi gia tin dimiourgia tou grid 3x4 me tis kartes
{
	int i,j;
	int counter=0;
	
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			Grid[i][j] = C[counter];
			counter = counter + 1;
		}
	}	
}


void PrintGrid(int rows, int cols, struct Card Grid[rows][cols]) // emfanisi tou plegmatos 3x4
{
	int i,j;
	
	
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
			printf("[%c, %c, %d, %c] \t", Grid[i][j].color, Grid[i][j].shape, Grid[i][j].number, Grid[i][j].texture);
		
		printf("\n");
	}
}

void main()
{
	struct Card C[12];		// pinakas 1D 12 8esewn typou Card gia tin apo8ikeusi twn 12 kartwn
	struct Card Grid[3][4];	// pinakas 2D 3x4 gia tin apo8ikeusi twn kartwn gia to plegma
	char menu;				// metavliti xrisimi gia tin epilogi tou menu apo ton xrhsth
	int x[3];				// pinakas 1D gia tin apo8ikeusi twn triwn syntetagmenwn x gia tis 3 epilegmenes kartes apo ton xrhsth
	int y[3];				// pinakas 1D gia tin apo8ikeusi twn triwn syntetagmenwn y gia tis 3 epilegmenes kartes apo ton xrhsth
	int i;
	int SET;				// i epistrefomeni timi tis CheckSET apo8ikeuetai stin metavliti auti
	
	printf("======================== \n");
	printf("||      SET GAME      ||  \n");
	printf("======================== \n");
	
	// arxikopoihsh tou struct twn 3 paiktwn
	struct Player P1 = {"Marina Andreou"   , 0 , "a"};	
	struct Player P2 = {"Kostas Grammenos" , 0 , "g"};
	struct Player P3 = {"Maria Perdika"    , 0 , "p"};
	
	getNextCard(&C,12);
	MakeCardsGrid(C,3,4,&Grid);
	PrintGrid(3,4,Grid);
			
	while(1) 
	{
		printf("\n---------------------------------------------------------------\n");
		printf( "|  Epilekste  to id {a, g, p} tou paikti pou 8elete na paiksei \n");
		printf( "|  Epilekste  -0-  gia eksodo \n");
		printf("---------------------------------------------------------------\n");

		printf("\nYour choice is : ");
		scanf (" %c" , &menu);

		if(menu == 'a')
		{
			printf("Dwste syntetagmenes twn triwn kartwn pou 8elete na epileksete\n\n");
			
			for(i=0;i<3;i++)
			{
				printf("x[%d] : ",i);
				scanf("%d",&x[i]);
				
				while(x[i]<0 || x[i]>2)
				{
					printf("x[%d] : ",i);
					scanf("%d",&x[i]);
				}				
				
				printf("y[%d] : ",i);
				scanf("%d",&y[i]);
				
				while(y[i]<0 || y[i]>3)
				{
					printf("y[%d] : ",i);
					scanf("%d",&y[i]);
				}
				printf("\n");

			}
			
			SET = CheckSET(3,4,Grid,x,y,3);
			
			if (SET)
			{
				P1.score = P1.score + 2;
				
				if (P1.score>=10)
				{
					printf(" **************** WINNER **************** \n");
					printf("     O nikitis einai o %s \n",P1.name);
					printf(" **************************************** \n");
					break;
					getch();					
				}
				
				getNextCard(&C,12);
				MakeCardsGrid(C,3,4,&Grid);
				PrintGrid(3,4,Grid);	
			}
			else
			{
				P1.score = P1.score - 1;
			
				if(P1.score < MIN_SCORE )
					P1.score = MIN_SCORE;
				
				PrintGrid(3,4,Grid);	
			}
		}
		else if(menu == 'g')
		{
			printf("Dwste syntetagmenes twn triwn kartwn pou 8elete na epileksete\n\n");
			
			for(i=0;i<3;i++)
			{
				printf("x[%d] : ",i);
				scanf("%d",&x[i]);
				
				while(x[i]<0 || x[i]>2)
				{
					printf("x[%d] : ",i);
					scanf("%d",&x[i]);
				}				
				
				printf("y[%d] : ",i);
				scanf("%d",&y[i]);
				
				while(y[i]<0 || y[i]>3)
				{
					printf("y[%d] : ",i);
					scanf("%d",&y[i]);
				}
				printf("\n");

			}
			
			SET = CheckSET(3,4,Grid,x,y,3);
			
			if (SET)
			{
				P2.score = P2.score + 2;
				
				if (P2.score>=10)
				{
					printf(" **************** WINNER **************** \n");
					printf("     O nikitis einai o %s \n",P2.name);
					printf(" **************************************** \n");
					break;
					getch();					
				}
				
				getNextCard(&C,12);
				MakeCardsGrid(C,3,4,&Grid);
				PrintGrid(3,4,Grid);	
			}
			else
			{
				P2.score = P2.score - 1;
			
				if(P2.score < MIN_SCORE )
					P2.score = MIN_SCORE;
				
				PrintGrid(3,4,Grid);	
			}
		}
		else if(menu == 'p')
		{
			printf("Dwste syntetagmenes twn triwn kartwn pou 8elete na epileksete\n\n");
			
			for(i=0;i<3;i++)
			{
				printf("x[%d] : ",i);
				scanf("%d",&x[i]);
				
				while(x[i]<0 || x[i]>2)
				{
					printf("x[%d] : ",i);
					scanf("%d",&x[i]);
				}				
				
				printf("y[%d] : ",i);
				scanf("%d",&y[i]);
				
				while(y[i]<0 || y[i]>3)
				{
					printf("y[%d] : ",i);
					scanf("%d",&y[i]);
				}
				printf("\n");

			}
			
			SET = CheckSET(3,4,Grid,x,y,3);
			
			if (SET)
			{
				P3.score = P3.score + 2;
				
				if (P3.score>=10)
				{
					printf(" **************** WINNER **************** \n");
					printf("     O nikitis einai o %s \n",P3.name);
					printf(" **************************************** \n");
					break;
					getch();					
				}
				
				getNextCard(&C,12);
				MakeCardsGrid(C,3,4,&Grid);
				PrintGrid(3,4,Grid);	
			}
			else
			{
				P3.score = P3.score - 1;
			
				if(P3.score < MIN_SCORE )
					P3.score = MIN_SCORE;
				
				PrintGrid(3,4,Grid);	
			}
		}
		else if(menu == '0')
		{
			
			printf("\n ========== GAME RESULTS ========== \n");
			printf(" - Name: %s    Score: %d \n",P1.name,P1.score);
			printf(" - Name: %s  Score: %d \n",P2.name,P2.score);
			printf(" - Name: %s     Score: %d \n",P3.name,P3.score);
			printf(" ================================== \n");
			break;
			getch();
		}
		else
		{
			getNextCard(&C,12);
			MakeCardsGrid(C,3,4,&Grid);
			PrintGrid(3,4,Grid);					
		}
	}
}
