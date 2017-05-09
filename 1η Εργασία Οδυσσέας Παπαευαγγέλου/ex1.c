#include <stdio.h>  
#include <stdlib.h>

int main(void)
{
	float number1, number2;		// metavlites pou apo8ikeuw tous 2 ari8mous
	char praksi;				// metavliti pou krataw tin praksi pou 8elw na kanw

	printf("Dwse (arithmo) (praksi) (arithmo)\n");		// ektupwnw stin o8oni to mnm
	scanf ("%f %c %f", &number1, &praksi, &number2);	// dinw times stis 2 metavlites kai tin praksi pou 8elw na kanw	 
	
	if(praksi=='+')											// an i praksi einai +
		printf("apotelesma = %.2f \n", number1+number2);	// kanw tin praksi kai ektypwnw to apotelesma
	else if (praksi=='-')									// an i praksi einai -
		printf("apotelesma = %.2f \n", number1-number2);	// kanw tin praksi kai ektypwnw to apotelesma	
	else if (praksi=='*')									// an i praksi einai *
		printf("apotelesma = %.2f \n", number1*number2);	// kanw tin praksi kai ektypwnw to apotelesma
	else if (praksi=='/')									// an i praksi einai /
	{
		if (number2 != 0)										// an o diairetis einai diaforetikos tou 0
			printf("apotelesma = %.2f \n", number1/number2);	// i diairesi pragmatopoieitai kanonika	
		else													// alliws
			printf("Diairesi me to mhden !!!! \n" );			// ektypwnw mnm la8ous
	}
	else														// an i praksi diaforetiki apo + - * /		
		printf("Mh apodekti ma8imatiki praksi !!!! \n");		// emfanizw mnm gia mi apodekti ma8imatiki praksi

	getch();
	return 0;
}
