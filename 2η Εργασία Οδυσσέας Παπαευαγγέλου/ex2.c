#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define MAX_SEATS 53

struct Passenger
{
	char name[40];
	unsigned int seat;
	char phone[10];
	struct Passenger *next;
}*MyList;


void Initialization(struct Passenger Bus[], int no_seats){

	int i,j;	
		
	for(i=0;i<no_seats;i++)
	{
		for(j=0;j<40;j++)
			Bus[i].name[j]=' ';
		
		for(j=0;j<10;j++)
			Bus[i].phone[j]= ' ';	

			
		Bus[i].phone[10]= '\0';		
		Bus[i].name[40]='\0';
		Bus[i].seat = 0;
	}
}


void ReadFromFile(struct Passenger Bus[],int no_seats, FILE *file)
{
	char FirstName[40];
	char buf[256];
	int i,line=0;
	struct Passenger Tmp_Bus[no_seats];

	while (fgets (buf, sizeof(buf), file))
	{
		sscanf(buf, "%s %s %d %s", Tmp_Bus[line].name, FirstName, &Tmp_Bus[line].seat, Tmp_Bus[line].phone);
		sprintf(Tmp_Bus[line].name, "%s %s",Tmp_Bus[line].name,FirstName);
		line++;
	}
	
	for(i=0;i<line;i++)
	{
		strcpy(Bus[Tmp_Bus[i].seat-1].name,Tmp_Bus[i].name);
		Bus[Tmp_Bus[i].seat-1].seat = Tmp_Bus[i].seat;
		strcpy(Bus[Tmp_Bus[i].seat-1].phone,Tmp_Bus[i].phone);
	}	
}


void PrintSortedList(struct Passenger Bus[],int no_seats)
{
	int i;
	int count_empty = 0;
	
	for(i=0;i<no_seats;i++)
		if(Bus[i].seat == 0)
			count_empty++;
	
	printf("Kenes Theseis : %d\n",count_empty);
	
	for(i=0;i<no_seats;i++)
		if(Bus[i].seat == 0)
			printf("%d, ",i+1);
}


void PrintBookingSeats(struct Passenger Bus[],int no_seats)
{
	int i,j;
	char temp[40]="";
	int choice;
	
	struct Passenger tmp;
	
	printf("--------------------------------------------------------------------\n");
	printf("|                     Init Booking Seats                           |\n");
	printf("--------------------------------------------------------------------\n\n");
	for(i=0;i<no_seats;i++)
		if(Bus[i].seat != 0)
			printf(" Name: %s\t| Phone: %s\t | Seat: %2d \n",Bus[i].name, Bus[i].phone,Bus[i].seat);
			

	printf("\nPliktrologiste -1- gia emfanisi listas sorted by name");
	printf("\nPliktrologiste -2- gia emfanisi listas sorted by seat number");

	printf("\nYour choice is: ");
	scanf("%d",&choice);
	
	
	for (i=0; i<no_seats-1; i++)
    {
       	for (j=i+1; j<no_seats; j++)
       	{	
       		if(Bus[i].seat!=0 && Bus[j].seat!=0)
       		{
				if (strcmp(Bus[i].name, Bus[j].name) > 0)
           		{
               		tmp=Bus[i];
               		Bus[i]= Bus[j];
               		Bus[j] = tmp;
           		}
       		}
    	}
	}
	
	MyList=NULL;
	
    for (i = 0; i < no_seats; i++)
    	if(Bus[i].seat!=0)
       		insert(Bus[i]);

	if(choice == 1)
	{
		printf("\n--------------------------------------------------------------------\n");
		printf("|                  Sorted by Name Booking List                     |\n");
		printf("--------------------------------------------------------------------\n\n");
		
		display(MyList,choice);
	}
	else if (choice == 2)
	{
		printf("\n--------------------------------------------------------------------\n");
		printf("|                Sorted by No Seat Booking List                    |\n");
		printf("--------------------------------------------------------------------\n\n");
		
		display(MyList,choice);
	}
}


void insert(struct Passenger node)
{
    struct Passenger *temp;
    
    temp=MyList;
    if(temp==NULL)
	    add(node);
    else
    {
    	while(temp!=NULL)
        	temp=temp->next;

		append(node);
    }
}


void append(struct Passenger node)
{
    struct Passenger *temp,*right;
    temp= (struct Passenger *)malloc(sizeof(struct Passenger));
    
    strcpy(temp->name,node.name);
	temp->seat=node.seat;
	strcpy(temp->phone,node.phone);
    
	right=(struct Passenger *)MyList;
    while(right->next != NULL)
    right=right->next;
    right->next =temp;
    right=temp;
    right->next=NULL;
}
 
 
void add( struct Passenger node )
{
    struct Passenger *temp;
    temp=(struct Passenger *)malloc(sizeof(struct Passenger));
	
	strcpy(temp->name,node.name);
    temp->seat=node.seat;
    strcpy(temp->phone,node.phone);
    
	if (MyList== NULL)
    {
    	MyList=temp;
    	MyList->next=NULL;
    }
    else
    {
    	temp->next=MyList;
    	MyList=temp;
    }
}

 
void  display(struct Passenger *List, int choice)
{
    List=MyList;
 
    if(List==NULL)
    	return;
 	
	if(choice == 1)
 	{
		while(List!=NULL)
   		{
    		printf(" Name: %s\t| Phone: %s\t | Seat: %2d \n",List->name, List->phone,List->seat);
    		List=List->next;
   		}
	}
	else if(choice == 2)
 	{

    	struct Passenger *tmpPtr = List;
    	struct Passenger *tmpNxt = List->next;

    	unsigned int tmps;
    	char tname[40];
    	char phone[10];

    	while(tmpNxt != NULL)
		{
           while(tmpNxt != tmpPtr)
		   {
                if(tmpNxt->seat < tmpPtr->seat)
				{
                    tmps = tmpPtr->seat;
                    strcpy(tname,tmpPtr->name);
                    
                    tmpPtr->seat = tmpNxt->seat;
                    strcpy(tmpPtr->name ,tmpNxt->name);

                    tmpNxt->seat = tmps;
                    strcpy(tmpNxt->name,tname);
                }
                tmpPtr = tmpPtr->next;
            }
            tmpPtr = List;
            tmpNxt = tmpNxt->next;
    	}

 		
		while(List!=NULL)
   		{
    		printf(" Name: %s\t| Phone: %s\t | Seat: %2d \n",List->name, List->phone,List->seat);
    		List=List->next;
   		}
	}
}


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
			if(strcmp(Bus[i].name,search)==0)
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
			if(strcmp(Bus[i].phone,search)==0)
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


void PrintToFile(struct Passenger Bus[],int no_seats, FILE *file)
{
	int i,j;
	char temp[40]="";
	int choice;
	
	struct Passenger tmp;
	
	for (i=0; i<no_seats-1; i++)
    {
       	for (j=i+1; j<no_seats; j++)
       	{	
       		if(Bus[i].seat!=0 && Bus[j].seat!=0)
       		{
				if (strcmp(Bus[i].name, Bus[j].name) > 0)
          		{
               		tmp=Bus[i];
               		Bus[i]= Bus[j];
               		Bus[j] = tmp;
           		}
       		}
   		}
	}
	
	MyList=NULL;
	
    for (i = 0; i < no_seats; i++)
    	if(Bus[i].seat!=0)
       		insert(Bus[i]);

	display(MyList,1);

	while(MyList!=NULL)
   	{
    	fprintf(file,"%s %d %s\n",MyList->name,MyList->seat, MyList->phone);
    	MyList=MyList->next;
   	}
   	
	fclose(file);
}


main (void)
{
	struct Passenger *Bus;
	char buf[256];
	char *token;
	char pinakida[7];
	int no_seats,i;
	int menu;
	
	FILE *file = fopen("bus.txt","r");
	fgets (buf, sizeof(buf), file);
    
	token = strtok(buf," ");
    strcpy(&pinakida,token);
    
    token = strtok(NULL," ");
    no_seats = atoi(token);

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

	Bus = (struct Passenger *)malloc(no_seats*sizeof(struct Passenger));

	Initialization(Bus,no_seats);
	ReadFromFile(Bus,no_seats,file);
	
	fclose(file);
	
	while(1) 
	{
		printf("\n--------------------------------------------------------------------------------");
		printf( "|  Epilekste -0- gia termatismo tou programmatos\n");
		printf( "|  Epilekste -1- gia emfanisi twn kenwn 8esewn + sort list me tous numbers tous\n");
		printf( "|  Epilekste -2- gia na kanete kratisi\n");
		printf( "|  Epilekste -3- gia anazitisi an einai i oxi kratimeni sygkekrimeni thesi\n");		
		printf( "|  Epilekste -4- gia na akyrwsi kratisis\n");
		printf( "|  Epilekste -5- gia emfanisi listas krathmenwn 8esewn\n");	
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
			fprintf(file,"%s %d",pinakida,no_seats);
			fprintf(file, "\n");

			PrintToFile(Bus,no_seats,file);

			break;
		}
	}	
}

