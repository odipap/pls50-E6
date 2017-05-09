#include<stdio.h>
#include<string.h>
#define MAX_SEATS 53

void Start(int **bus,int **no_seats,int size)	// synartisi gia tin arxikopoihsh twn 2 pinakwn
{
	int i, j;
	int metritis = 0;
	
	for(i=0; i<=((size-5)/4); i++)	// gia oles tis seires tou leoforeiou
	{
		for(j=0;j<5;j++)			// gia ka8e 8esi se ka8e seira
		{
			if(i!=(size-5)/4 && j==2)	// elegxos gia tin dimiourgia tou diadromou tote 
				bus[i][j] = 2;			// ston pinaka bus == 2 anaparista ton diadromo
			else						// an den einai thesi pou einai diadromos
			{
				bus[i][j]      = 0;		// arxikopoiw times tou bus = 0
				metritis       = metritis+1;	// metritis pou metraei tis 8esis
				no_seats[i][j] = metritis;		// bazw sto pinaka no_seats stin i seira tou leofwreiou stin j thesi ton ari8mo tis 8esis
			}
		}
	}
}

void printBus(int **bus, int size)	// synartisi pou dexetai ws orismata ton pinaka bus kai to pli8os ton 8esewn (size)				
{									// ektypwnei tin prosomoiwsi tou leofwreiou
	int i,j;

	for(i=0;i<=((size-5)/4);i++)	// gia oles tis seires tou leoforeiou
	{
		for(j=0;j<5;j++)			// gia ka8e 8esi se ka8e seira
		{
			if(bus[i][j]==0)		// an i timi tou pinaka bus einai == 0 
				printf("_");		// ektypwnei to _ ws anaparastasi tis kenis 8esis
			else if(bus[i][j]==1)	// an i timi tou pinaka bus einai == 1
				printf("*");		// ektypwnei to * ws anaparastasi tis kratismenis 8esis
			else if(bus[i][j]==2)	// an i timi tou pinaka bus einai == 2
				printf(" ");		// ektypwnei to keno " " ws anaparastasi tou diadromou

			printf(" ");
		}
		printf("\n");
	}	
}

void printBusToFile(int **bus, int size, FILE *wfile)	// synartisi opou ektypwnei sto arxeio wfile to trexwn sxediagramma tou leoforeiou
{														// dexetai ws orismata to pinaka bus, to pli8os ton 8esewn tou leoforeiou kai to arxeiou pou 8a ektypwsei		
														// to trexon sxediagramma tou
	int i,j;	

	for(i=0; i<=((size-5)/4); i++)	// gia oles tis seire tou leoforeiou
	{
		for(j=0;j<5;j++)			// gia ka8e 8esi se ka8e seira
		{							
			if(bus[i][j]==0)			// an i timi tou pinaka bus einai == 0
				fprintf(wfile, "_");	// ektypwnei to _ ws anaparastasi tis kenis 8esis sto arxeio wfile
			else if(bus[i][j]==1)		// an i timi tou pinaka bus einai == 1
				fprintf(wfile, "*");	// ektypwnei to * ws anaparastasi tis kratimenis 8esis sto arxeio wfile
			else if(bus[i][j]==2)		// an i timi tou pinaka bus einai == 2
				fprintf(wfile, " ");	// ektypwnei to keno " " ws anaparastasi tou diadromou sto arxeiou wfile

			fprintf(wfile, " ");
		}
		fprintf(wfile, "\n");
	}	
}

void count_seats(int **bus, int **no_seats, int size)	// synartisi pou emfanizei ton ari8mo tis ka8e kenis 8esis stin domi tou leoforeiou ka8ws kai to pli8os tou
{														// dexetai ws orisma tous pinakes bus kai no_seats ka8ws kai ton pli8os twn 8esewn tou leoforeiou
	int counter=0, i, j; // i metavliti counter xrisimopoieitai gia tin metrisi twn kenwn 8esewn tou leoforeiou

	for(i=0; i<=((size-5)/4); i++)				// gia ka8e seira tou leoforeiou
	{
		for(j=0; j<5; j++)						// gia ka8e keni 8esi se ka8e seira
		{
			if(bus[i][j]==0)					// an i 8esi einai keni
			{	
				counter++;						// auksanw ton metriti counter kata 1
				printf("%d",no_seats[i][j]);	// ektypwnw ton ari8mo tis 8esis pou einai keni
			}
			printf(" ");
		}
		printf("\n");
	}
	printf("Kenes Theseis : %d \n", counter);
}


int lookForWindowSeat(int **bus, int **no_seats, int size, int *seira)
{
	int i,j;
	int counter = 0;
	
	for(i=0;i<=((size-5)/4);i++)
	{
		if(bus[i][0]==0)
		{
			*seira = i;
			return(0);
		}
		else if(bus[i][4]==0)
		{
			*seira = i;
			return(4);
		}
	}
	
	for(i=0; i<=((size-5)/4); i++)
		for(j=0; j<5; j++)
			if(bus[i][0]==0 || bus[i][4]==0)
				counter++;	// metraw tis kenes 8eseis para8yro
	
	if (counter == 0)  // an den exw metrisei kamia tote o metritis paremeine 0
		return(-1);		// ara epistrefw -1 dld den yparxoyn kenes 8eseis para8yro
}


int lookForSeats(int **bus, int **no_seats, int size, int thesi, int choice)
{

	int i, j;
	int first_par_seat = -1;
	
	if(choice == 1) // kratisi 8esis
	{
		if(thesi>0 && thesi<=size)
		{
			for(i=0; i<=((size-5)/4); i++)
			{	
				for(j=0; j<5; j++)
				{	
					if(no_seats[i][j]==thesi)
					{	
						if(bus[i][j]==0)
							return(1); // ama i 8esi einai keni epistrefei 1 
						else if	(bus[i][j]==1)
							return(2); // ama i 8esi einai idi kratimeni epistrefei 2
					}	
				}
			}
		}
		else
		{	
			return(-1); // ama den yparxei o ari8mos 8esi pou edwsa gia kratisi epistrefei -1
		}
	}
	else if(choice == 3) // akyrwsi kratisis
	{
		if(thesi>0 && thesi<=size)
		{
			for(i=0; i<=((size-5)/4); i++)
			{	
				for(j=0; j<5; j++)
				{	
					if(no_seats[i][j]==thesi)
					{	
						if(bus[i][j]==0)
							return(1); // ama i 8esi einai keni epistrefei 1 
						else if	(bus[i][j]==1)
							return(2); // ama i 8esi einai idi kratimeni epistrefei 2
					}	
				}
			}
		}
		else
		{	
			return(-1); // ama den yparxei o ari8mos 8esi pou edwsa epistrefei -1
		}
	}
}


void Kratisi(int **bus, int **no_seats, int size, int epilogi)
{
	int thesi, msg;
	int i,j,tmp;
	int seira;
	
	if(epilogi == 1) // kratisi 8esis
	{
		printf("Dwste tin 8esi pou 8elete na kratisete : ");
		scanf("%d",&thesi);
	
		msg = lookForSeats(bus,no_seats,size,thesi,epilogi);

		if (msg==1) // ama i 8esi einai keni
		{
			for(i=0; i<=((size-5)/4); i++)
			{
				for(j=0; j<5; j++)
				{
					if(no_seats[i][j]==thesi)
						bus[i][j]=1;
				}
			}
			printf("H kratisi pragmatopoih8ike epityxws \n");
		}
		else if (msg==2) // ama i 8esi einai kratimeni
			printf("H 8esi pou zitisate einai kratimeni \n");
		else if (msg==-1) 
			printf("H thesi pou pliktrologisate den einai egkyri \n");
	
	}
	else if (epilogi == 2) // kratisi thesis para8yro 
	{
		printf("Eyresi kai kratisi tis prwtis kenis 8esis \n");
		msg = lookForWindowSeat(bus,no_seats,size,&seira);

		if(msg!= -1)
		{
			tmp = seira*5 + msg;
			i = tmp / 5;
			j = tmp % 5;
		
			bus[i][j] = 1;
			printf("H 1st 8esi para8yro pou bre8ike kai krati8ike einai i | %d | \n",no_seats[i][j]);
		}
		else
			printf("Den yparxoun eley8eres 8eseis sto para8yro\n");

	}
	else if(epilogi == 3) // akyrwsi kratisis
	{
		printf("Dwste tin 8esi pou 8elete na akyrwsete : ");
		scanf("%d",&thesi);
	
		msg = lookForSeats(bus,no_seats,size,thesi,epilogi);

		if (msg==2) // ama i 8esi einai kratimeni
		{
			for(i=0;i<=((size-5)/4);i++)
			{
				for(j=0;j<5;j++)
				{
					if(no_seats[i][j]==thesi)
						bus[i][j]=0;
				}
			}
			printf("H kratisi akyrw8ike epityxws \n");
		}
		else if (msg==1) // ama i 8esi einai keni
			printf("H 8esi pou zitisate einai idi keni \n");
		else if (msg==-1)
			printf("H thesi pou pliktrologisate den einai egkyri \n");	
	}
}

void search(int **bus, int **no_seats, int size)
{
	int i,j, thesi; // metavliti gia na kratisw tin anazitoumeni 8esi

	printf("Parakalw pliktrologiste tin 8esi pou thelete na anazeitisete: ");
	scanf("%d",&thesi);
	
	if(thesi>0 && thesi<=size)
	{	
		for(i=0; i<=((size-5)/4); i++)
		{
			for(j=0; j<5; j++)
			{
				if(no_seats[i][j]==thesi) // an o ari8mos tis 8esis einai i zitoumeni thesi
				{
					if(bus[i][j]==0)
						printf("H 8esi | %d | poy pliktrologisate einai ELEY8ERH \n",thesi);
					else if(bus[i][j]==1)
						printf("H 8esi | %d | poy pliktrologisate einai KRATHMENH \n",thesi);	
				}
			}
		}
	}
	else
		printf("H thesi pou pliktrologisate den einai egkyri \n");
}


void listThesewn(int **bus, int **no_seats, int size)	// synartisi gia emfanisi tis taksinomimenis listas kratimenwn 8esewn
{														// dexetai ws eisodo tous pinakes bus, no_seats ka8ws kai to pli8os twn 8esewn
	int i,j;
	printf("|");
	for(i=0; i<=((size-5)/4); i++)	// gia ka8e seira tou leoforeiou
	{
		for(j=0; j<5; j++)			// gia ka8e 8esi tis ka8e seiras
		{
			if(bus[i][j]==1)		// an i 8esi einai kratimeni
			{
				printf(" %d |", no_seats[i][j]);	// ektypwnei ton ari8mo tis 8esis
			}
		}
	}
}

void main()
{
	FILE *file;			// arxeio pou exw grammeno mesa ton ari8mo pinakidas kai ton ari8mo 8esewn tou lewforeiou
	FILE *writeFile;	// arxeio pou grafw to teliko sxediagramma tou leofwreiou 
  	char pinakida[8];	// pinakas pou apo8ikeuw ta alfari8mitika tis pinakidas
	int arithmos_thesewn;	// metavliti pou apo8ikeuw ton ari8mo 8esewn tou leoforeiou
	int i, j, menu;			// i metavliti menu xrisimopoieitai gia na epileksoume apo to menu tou programmatos ti 8eloume na kanoume analoga me tin timi pou 8a dwsoume
	int **bus;				// 2D pinakas pou dimiourgeitai dynamika analoga me to pli8os  ton 8esewn, periexei ta symvola _ * gia tin prosopoiwsi twn 8eswn tou leoforeiou
	int **no_seats;			// 2D pinakas pou dimiourgeitai dynamika analoga me to pli8os ton 8esewn, periexei tous ari8mous twn 8esewn gia tin prosopoiwsi tou leoforeiou
    
	file=fopen("bus.txt","r");											// anoigw to arxeio bus.txt
	while ( fscanf ( file, "%s%d", &pinakida, &arithmos_thesewn)!=EOF)  // diavazw to periexomeno tou kai to apodikeuw stis metavlites pinakida kai ari8mo_thesewn
	fclose(file);														// kleinw to arxeio
	
	if (arithmos_thesewn>MAX_SEATS)		// an o ari8mos 8esewn megalyteros apo to MAX_SEATS (53)
	{
		printf("O arithmos twn thesewn pou dwsate einai > apo to 53 ");
		exit(1);						// kleinei to programma
	}
	else if(((arithmos_thesewn-5)%4)!=0)	// an oi ari8mos 8esewn den ikanopoiei tin anagrafomeni parastasi
	{
	 	printf("O arithmos_thesewn pou dwsate den symvadizei me tin protinomeni katanomi thesewn");
	 	exit(1);							// kleinei to programma
	}

	bus 	 = (int **)malloc((((arithmos_thesewn-5)/4))* sizeof(int*));	// desmeyw mnimi kai dimiourgw ton 2D pinaka bus
	no_seats = (int **)malloc((((arithmos_thesewn-5)/4))* sizeof(int*));	// desmeyw mnimi kai dimiourgw ton 2D pinaka no_seats

   	for(i=0; i<=((arithmos_thesewn-5)/4); i++)
	{
		bus[i]      = (int *)malloc(5*sizeof(int));
		no_seats[i] = (int *)malloc(5*sizeof(int));
	}
	
	Start(bus,no_seats,arithmos_thesewn);	// synartisi pou pernaw ws orisma tou 2 pinakes, ton ari8mo thesewn
											// kai tous arxikopoiw me vasi tis times pou zitaei i ekfwnisi

	while(1) 
	{
		printf("\n----------------------------------------------------------------------------\n");
		printf( "|  Epilekste  -0-   gia eksodo \n");
		printf( "|  Epilekste  -1-   gia tin emfanisi twn kenwn 8esewn kai ton ari8mo tous \n");
		printf( "|  Epilekste  -2-   gia na kanete kratisi \n");
		printf( "|  Epilekste  -3-   gia euresi kai kratisi tis 1st kenis thesis para8yro  \n");
		printf( "|  Epilekste  -4-   gia na akyrwsi kratisis \n");
		printf( "|  Epilekste  -5-   gia na anazitisi pliroforiwn sygkekrimenis 8esis \n");
		printf( "|  Epilekste  -6-   gia emfanisi tis taksinomimenis listas kratimenwn 8esewn \n");
		printf( "|  Epilekste  -7-   gia emfanisi tou diagrammatos tou lewforeiou \n");
		printf( "|  Epilekste  -8-   gia apo8ikeusi tou diagrammatos tou bus sto layout.txt\n");
		printf("----------------------------------------------------------------------------\n");


		scanf ("%d" , &menu);
		printf("\n");
		if (menu == 1)
			count_seats(bus,no_seats,arithmos_thesewn);
		else if (menu == 2)
			Kratisi(bus,no_seats,arithmos_thesewn,1);
		else if (menu == 3)
			Kratisi(bus,no_seats,arithmos_thesewn,2);
		else if (menu == 4)
			Kratisi(bus,no_seats,arithmos_thesewn,3);
		else if (menu == 5)
			search(bus,no_seats,arithmos_thesewn);		
		else if (menu == 6)
			listThesewn(bus,no_seats,arithmos_thesewn);
		else if (menu == 7)
		{
			printf("%s",pinakida);
			printf("\t%d\n", arithmos_thesewn );
			printBus(bus,arithmos_thesewn);
		}
		else if (menu == 8)
		{
			writeFile = fopen("layout.txt", "w");
			fprintf(writeFile, "%s\n",pinakida);
			printBusToFile(bus, arithmos_thesewn, writeFile);
			fclose(writeFile);
			printf("Pragmatopoih8hke apo8ikeusi tou diagrammatos tou bus sto arxeio layout.txt \n");
		}
		else if (menu == 0)
			break;
	}	
}
