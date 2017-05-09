#include <stdio.h> 
#include <math.h>
# include <stdlib.h>

#define pi 3.14159265359

float perimetros_tetragwnou( float mikos) 	// synartisi pou ypologizei kai epistrefei tin perimetro tou tetragwnou
{										 	// dexetai ws orisma to mikos tis pleuras tou tetragwnou
	float perimetros;
	perimetros = mikos * 4;
	
	return(perimetros);

};

float perimetros_parallilogramou(float mikos_paral, float platos_paral)	// synartisi pou ypologizei kai epistrefei tin perimetro tou parallilogramou
{																		// dexetai ws orismata ta miki twn 2 pleurwn tou parallilogramou
	float perimetros;
	perimetros = 2*mikos_paral + 2*platos_paral;

	return (perimetros);
};



float perimetros_orth_trigwnou(float pleura1, float pleura2) // synartisi pou ypologizei kai epistrefei tin perimetro tou or8ogwniou trigwnou
{															 // dexetai ws orismata ta miki twn 2 ka8etwn pleurwn
	float perimetros;
	float pleura3;											// metavliti gia ton ypologismo tis ypoteinousas
	pleura3 = sqrt(pleura1*pleura1 + pleura2*pleura2);		// ypologismos tis ypoteinousas apo to Py8agorio 8ewrima
	perimetros = pleura1 + pleura2 + pleura3;

	return (perimetros);
};


float perimetros_kyklou(float aktina) 	// synartisi pou ypologizei kai epistrefei tin perimetro tou kyklou
{										// dexetai ws orisma tin aktina tou kyklou 
	float perimetros;
	perimetros = pi*2*aktina;

	return (perimetros);
};

int main(void)		// i kuria synartisi 
{
	int choice;		// metavliti pou krataw tin epilogi 
	float pleura_tetr, mikos_par, platos_par, aktina, mikos_kath_pleur1, mikos_kath_pleur2;
	float apotelesma; 

	while(1)
	{
		printf( "\n-------------------------------------------------\n");
		printf( "| Ypologismos perimetrou twn akolou8wn sximatwn |\n");
		printf( "-------------------------------------------------\n");

		printf( "\nEpilekste -0- gia eksodo \n");
		printf( "Epilekste -1- gia tetragwno\n");
		printf( "Epilekste -2- gia parallilogramo\n");
		printf( "Epilekste -3- gia or8ogwnio trigwno\n");
		printf( "Epilekste -4- gia kyklo\n");

		scanf ("%d" , &choice); // dinw timi stin metavliti choice
		
		if (choice == 1)
		{
			printf("Dwste to mhkos pleuras gia to tetragwno : ");
			scanf("%f", &pleura_tetr);

			apotelesma = perimetros_tetragwnou(pleura_tetr);
			printf("H perimetros einai :  %.3f \n", apotelesma);
		}
		else if (choice == 2) 
		{
			printf("Dwste to mhkos pleuras gia to parallilogrammo : ");
			scanf("%f", &mikos_par);
			printf("Dwste to platos pleuras gia to parallilogrammo : ");
			scanf("%f", &platos_par);

			apotelesma = perimetros_parallilogramou(mikos_par, platos_par);
			printf("H perimetros einai :  %.3f \n", apotelesma);
		}
		else if (choice == 3)
		{
			printf("Dwste to mhkos tis mias ka8etis pleuras gia to orthogonio trigwno : ");
			scanf("%f", &mikos_kath_pleur1);
			printf("Dwste to mhkos tis allis ka8etis pleuras gia to orthogonio trigwno : ");
			scanf("%f", &mikos_kath_pleur2);

			apotelesma = perimetros_orth_trigwnou(mikos_kath_pleur1, mikos_kath_pleur2);
			printf("H perimetros einai :  %.3f \n", apotelesma);
		}
		else if (choice == 4)
		{
			printf("Dwste tin aktina tou kyklou : ");
			scanf("%f", &aktina);

			apotelesma = perimetros_kyklou(aktina);
			printf("H perimetros einai :  %.3f \n", apotelesma);
		}
		else if (choice == 0) // i metavliti choice == 0 tote to programma kleinei
			break;	
	}

	getch();
	return 0;
}
