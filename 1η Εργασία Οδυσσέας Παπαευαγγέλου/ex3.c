#include <stdio.h>
#include<stdlib.h>


int main( void)
{
	
	int decimalNumber, currentNumber, quotient; // metavlites opou krataw demicalNumber ton dekadiko ari8mo, currentNumber ton trexon ari8mo meta apo ka8e
    int binaryNumber[20], i=1, j;				// diairesi me to 2 kai quotient to phliko tis diairesi me to 2, binaryNumber einai pinakas pou apo8ikeuw ton diadiko
												// ari8mo pou prokyptei etsi wste meta na ton anastrepsw

    printf("Dwse 8etiko akeraio ari8mo: ");
    scanf("%d",&decimalNumber);					// dinw ton ari8mo pou 8elw na ypologisw ton diadiko tou 

	while(decimalNumber<0)						// an o ari8mos einai arnitikos tote se ena loop epanalamvanw tin diadikasia mexri o ari8mos pou 8a dwsw na einai > 0
	{
	    printf("Dwse 8etiko akeraio ari8mo: ");
    	scanf("%d",&decimalNumber);
	}

	currentNumber = decimalNumber;				// ekxwrw ton dekadiko ari8mo pou exwsa stin metavliti currentNumber

    while(currentNumber!=0)						// oso to current number den einai 0
	{

         binaryNumber[i++]= currentNumber % 2;	// vazw stin i thesi to akeraio ypoloipo tou trexwn ari8mou me to 2
         quotient = currentNumber / 2;			// ypologizw to piliko tis diaresi tou idiou ari8mo me to 2
         currentNumber = quotient;				// ekxwrw stin metabliti currentNumber to piliko gia na synexisw tin diadikasia

    }


    printf("H diadiki anaparastasi tou %d einai: ",decimalNumber); // ektypwnw tin diadiki anaparastasi tou dekadikou ari8mou pou edwsa ws eisodo
    for(j=i-1; j>0; j--)
         printf("%d", binaryNumber[j]);

    printf("\nH antistrofi diadiki anaparastasi tou %d einai: ",decimalNumber); // ektypwnw tin antistrofi diadiki anaparastasi tou dekadikou ari8mou pou edwsa ws eisodo
    for(j=1; j<i; j++)
         printf("%d", binaryNumber[j]);
	
	getch();
	return 0;
}



