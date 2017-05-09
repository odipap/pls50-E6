#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define MAX_SEATS 53

struct Passenger
{
	char name[40];
	unsigned int seat;
	char phone[10];	
};

// synartisi gia tin arxikopoihsh tou pinaka Bus, oi kenes 8eseis arxikopoiounte me to 0 kai to onoma, thlefono me to keno
void Initialization(struct Passenger Bus[], int no_seats)
{

	int i,j;	
		
	for(i=0;i<no_seats;i++)
	{
		for(j=0;j<40;j++)
			Bus[i].name[j]=' ';
		
		for(j=0;j<10;j++)
			Bus[i].phone[j]= ' ';	

			
		Bus[i].phone[10]='\0';		
		Bus[i].name[40]	='\0';
		Bus[i].seat 	= 0	 ;
	}
}

// synartisi gia to diabasma apo to arxeio,dexete ws eisodo ton pinaka Bus, to pli8os 8esewn ka8ws kai to arxeio
void ReadFromFile(struct Passenger Bus[],int no_seats, FILE *file)
{
	char FirstName[40]; // voi8itiki metavliti gia to diavasma tou onomatos
	char buf[256];
	int i,line=0;
	struct Passenger Tmp_Bus[no_seats]; // voi8itiko struct typou Passenger gia tin anagnwsi apo to arxeio kai xrisi tou gia to gemisma tou pinaka Bus

	while (fgets (buf, sizeof(buf), file)) // oso to arxeio den exei teleiwsei
	{
		sscanf(buf, "%s %s %d %s", Tmp_Bus[line].name, FirstName, &Tmp_Bus[line].seat, Tmp_Bus[line].phone);	// diavasma tis grammis kai gemisma twn metavlitwn 
		sprintf(Tmp_Bus[line].name, "%s %s",Tmp_Bus[line].name,FirstName);	// synenosi tou epi8etou kai onomatos kai apo8ikeusi se ena string
		line++;
	}
	
	// antigrafi twn timwn tou Tmp_Bus ston pinaka Bus
	for(i=0;i<line;i++)
	{
		strcpy(Bus[Tmp_Bus[i].seat-1].name,Tmp_Bus[i].name);
		Bus[Tmp_Bus[i].seat-1].seat = Tmp_Bus[i].seat;
		strcpy(Bus[Tmp_Bus[i].seat-1].phone,Tmp_Bus[i].phone);
	}	
}

// synartisi gia tin emfanisi tou synolikou pli8ous kenwn 8esewn kai taksinomimenis listas twn ari8mwn tous
void PrintSortedList(struct Passenger Bus[],int no_seats)
{
	int i;
	int count_empty = 0; // metavliti gia tin metrisi kenwn 8esewn
	
	for(i=0;i<no_seats;i++)
		if(Bus[i].seat == 0)
			count_empty++;
	
	printf("Kenes Theseis : %d\n",count_empty);
	
	for(i=0;i<no_seats;i++)	// ektypwsi tis listas  twn kenwn 8esewn
		if(Bus[i].seat == 0)
			printf("%d, ",i+1);
}

// synartisi gia emfanisi tis listas twn kratimenwn 8esewn( onomatepwnymo, tilefwno, 8esi) kratimenwn 8esewn sorted kata ari8no 8esis
void PrintBookingSeats(struct Passenger Bus[],int no_seats)
{
	int i;
	printf("--------------------------------------------------------------------\n");
	printf("|                          Booking Seats                           |\n");
	printf("--------------------------------------------------------------------\n\n");
	for(i=0;i<no_seats;i++)
		if(Bus[i].seat != 0)
			printf(" Name: %s\t| Phone: %s\t | Seat: %2d \n",Bus[i].name, Bus[i].phone,Bus[i].seat);
}

// synartisi gia tin kratisi 8esis 
void MakeBooking(struct Passenger Bus[],int no_seats)
{
	int i,seat;
	printf("Dwste tin 8esi pou 8elete na kratisete: ");
	scanf("%d",&seat);
	
	while(seat>no_seats || Bus[seat-1].seat >0)
	{
		if(seat>no_seats)
			printf("H 8esi pou dwsate gia kratisi einai > apo max pli8os 8esewn tou lewforeiou !!\n",no_seats);

		if(Bus[seat-1].seat != 0)
			printf("H 8esi pou dwsate gia kratisi einai idi kratimeni !!\n",no_seats);
		
		printf("Dwste nea 8esi pou 8elete na kratisete: ");
		scanf("%d",&seat);
	}
	
	Bus[seat-1].seat = seat;
	
	printf("\nEnter Passenger FullName: ");
	scanf(" %[^\n]s",Bus[seat-1].name);
	
	printf("Enter Passenger Phone: ")	;
	scanf(" %[^\n]s",Bus[seat-1].phone);

	printf("\n===== BOOKING INFORMATION =====\n");
	printf(" Name: %s\n Phone: %s\n No Seat: %d\n",Bus[seat-1].name,Bus[seat-1].phone,Bus[seat-1].seat);
	printf("===============================\n");
}

// synartisi gia akyrwsi tis kratisis 8esis me sygkekrimeno ari8mo pou dinei o xristis
void CancelBooking(struct Passenger Bus[],int no_seats)
{
	int delete_seat;
	int j;
	
	printf("\nPliktrologiste ton ari8mo 8esis pou 8elete na akyrwsete: ");
	scanf("%d",&delete_seat);
	
	Bus[delete_seat-1].seat = 0;
	
	for(j=0;j<40;j++)
			Bus[delete_seat-1].name[j]=' ';
		
		for(j=0;j<10;j++)
			Bus[delete_seat-1].phone[j]= ' ';	

			
		Bus[delete_seat-1].phone[10]= '\0';		
		Bus[delete_seat-1].name[40]='\0';
}

// synartisi gia anazitis an mia 8esi einai kratimeni me sygkekrimeno  ari8mo
void SearchBooking(struct Passenger Bus[],int no_seats)
{
	int choice,i;
	char search[40];
	int search_flag = 0;
	
	printf("\nPliktrologiste -1- gia anazitisi me sygkekrimeno onomatepwnymo\n");
	printf("Pliktrologiste -2- gia anazitisi me sygkekrimeno tilefwno\n");
	printf("Your choice is: ");
	scanf("%d",&choice);
	
	if(choice == 1)
	{
		printf("\nDwste to onoma pou 8elete na anazitisete: ");
		scanf(" %[^\n]s",search);
		
		for(i=0;i<no_seats;i++)
		{
			if(strcmp(Bus[i].name,search)==0) // an to onoma pou edwsa tairiazei me kapoio pou yparxei ston pinaka Bus
				if(Bus[i].seat==0)
				{
					printf("H 8esi einai keni\n");
					search_flag = 1;
				}
				else
				{
					printf("H 8esi einai kratimeni\n");
					search_flag = 1;
				}
		}
		if(search_flag==0)
			printf("\nDen yparxei kratimeni 8esi sto sygkekrimeno onoma\n");
	}
	else if(choice == 2)
	{
		printf("\nDwste to tilefwno pou 8elete na anazitisete: ");
		scanf(" %[^\n]s",search);
		
		for(i=0;i<no_seats;i++)
		{
			if(strcmp(Bus[i].phone,search)==0)	// an to phone pou edwsa tairiazei me kapoio pou yparxei ston pinaka Bus
				if(Bus[i].seat==0)
				{
					printf("H 8esi einai keni\n");
					search_flag = 1;
				}
				else
				{
					printf("H 8esi einai kratimeni\n");
					search_flag = 1;
				}
		}
		if(search_flag==0)
			printf("\nDen yparxei kratimeni 8esi sto sygkekrimeno tilefwno\n");
	}	

}

main (void)
{
	struct Passenger *Bus;
	char buf[256];		
	char *token;		// voi8itiki metavliti gia to diavasma tis pinakidas kai twn 8esewn apo to arxeio
	char pinakida[7];	// metavliti gia apo8ikeusi tis pinakidas
	int no_seats,i;		// no_seats metavliti gia apo8ikeusi tou pli8ous twn 8esewn 
	int menu;			// voi8itiki metavliti gia to menu epilogwn
	
	FILE *file = fopen("bus.txt","r");	// anoigma tou arxeiou 
	fgets (buf, sizeof(buf), file);		// diavasma tis prwtis grammis
    		
	token = strtok(buf," ");	// kopsimo tis grammis pou diabasa an lekseis symfwna me to white spaces pou yparxoun metaksi tous
    strcpy(&pinakida,token);	// apo8ikeusi tis pinakidas
    
    token = strtok(NULL," ");	// antistoixi douleia me panw
    no_seats = atoi(token);		// apo8ikeusi tou pli8ous twn 8esewn

    printf("%s\t",pinakida);	
	printf("%d\n",no_seats);

	if (no_seats>MAX_SEATS)
	{
		printf("O arithmos twn thesewn pou dwsate einai > apo to 53 ");
		exit(1);
	}
	else if(((no_seats-5)%4)!=0)
	{
	 	printf("O arithmos_thesewn pou dwsate den symvadizei me tin protinomeni katanomi thesewn");
	 	exit(1);
	}

	Bus = (struct Passenger *)malloc(no_seats*sizeof(struct Passenger));	// dimiourgia tou pinaka typoy struct Passenger oso to pli8os twn 8esewn (dynamika)

	Initialization(Bus,no_seats);	// synartisi gia arxikopoihsh tou pinaka Bus, dexetai ws eisodo ton pinaka Bus kai to pli8os twn 8esewn
	ReadFromFile(Bus,no_seats,file);// synartisi i opoia kata tin klisi tis diavazei apo to arxeio kai gemizei ton pinaka Bus, 	
	
	fclose(file);	// klisimo tou arxeiou
	
	while(1) 
	{
		printf("\n--------------------------------------------------------------------------------");
		printf( "|  Epilekste -0- gia termatismo tou programmatos\n");
		printf( "|  Epilekste -1- gia emfanisi twn kenwn 8esewn + sort list me tous numbers tous\n");
		printf( "|  Epilekste -2- gia na kanete kratisi\n");
		printf( "|  Epilekste -3- gia anazitisi an einai i oxi kratimeni sygkekrimeni thesi\n");		
		printf( "|  Epilekste -4- gia na akyrwsi kratisis\n");
		printf( "|  Epilekste -5- gia emfanisi listas krathmenwn 8esewn sorted kata ari8mo 8esis\n");	
		printf("--------------------------------------------------------------------------------\n");

		printf("Menu: ");
		scanf (" %d" , &menu);
		printf("\n");
	
		if (menu == 1)
			PrintSortedList(Bus,no_seats);
		else if(menu == 2)
			MakeBooking(Bus,no_seats);
		else if(menu == 3)
			SearchBooking(Bus,no_seats);			
		else if(menu == 4)
			CancelBooking(Bus,no_seats);		
		else if( menu == 5)
			PrintBookingSeats(Bus,no_seats);	
		else if (menu == 0)
		{	
			file = fopen("bus.txt","w");
			fprintf(file,"%s %d",pinakida,no_seats); // apo8ikeusi sto arxeio tin pinakida kai to pli8os 8esewn
			fprintf(file, "\n");

			for(i=0;i<no_seats;i++)	// apo8ikeusi ek neou sto arxeio oti exei o pinakas Bus
				if(Bus[i].seat!=0)
					fprintf(file,"%s %d %s\n",Bus[i].name,Bus[i].seat,Bus[i].phone);	

			printf("The file was saved successfully !!! Bye...\n");
			break;
		}
	}	
	
}
