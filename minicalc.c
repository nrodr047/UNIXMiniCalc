/*
Student Name: Natalie Rodriguez
Panther ID: 2919853

Program description: Program uses the getop function to retrieve information
from the command line to make a mini calculator. Based on the input from the
command line, the program will do addition, multiplication, and the power of
2 according to the order of operations. Program will also print specific error
messages if the inputs are out of range and will display the usage message.

Affirmation of originality: I affirm that I wrote this program myself without
any help from other people or sources on the internet.



*/

#include <stdio.h>
#include <stdlib.h>


//function prints out error if the value is a negative or larger than 50
void ValueError()
{
	printf("Error: Starting value must be between 1 and 50.\n");
}

//function prints out error if value is a negative or greater than 500
void AdditionError()
{
	printf("Error: Addition value needs to be between 1 and 500.\n");

}

//function prints out an error if value is a negative or greater than 10
void MultiError()
{
	printf("Error: Multiplication value must be between 1 and 10.\n");
}

	

int main(int argc, char **argv)
{
	extern char *optarg;
	extern int optind;
	int option =0; 
	float anum = 0; //add-by value
	float mnum = 0; //multiply-by value
	int flaga =0; //flag for addition
	int flagx =0; //flag for exponent
	int flagm =0; //flag for multiplication
	static char usage[] = "usage: minicalc [-a num] [-m num] [-x num] value\n";
	float value = atof(argv[argc - 1]); //starting value
	
	//condition if starting value is in range, else exit
	if((value < 1) || (value > 50)){
		ValueError();
		printf("%s", usage);
		exit(EXIT_FAILURE);
	}

	while((option = getopt(argc, argv, "a:m:x")) !=-1)
	{
		switch (option){
			case 'a':
				flaga = 1;
				anum = atof(optarg); //collects add-by number
				//condition if range is accepted, else exit
				if((anum < 1) || (anum > 500)){
					AdditionError();
					printf("%s", usage);
					exit(EXIT_FAILURE);
				}	
				break;
			case 'm':
				flagm = 1;
				mnum = atof(optarg); //collect multiply-by number
				//condition if range is accepted, else exit
				if((mnum < 1) || (mnum > 10)){
					MultiError();
					printf("%s", usage);
					exit(EXIT_FAILURE);
				}
				break;
			case 'x':
				flagx = 1; //flag for exponent
				break;
			case '?':
				break;
		}

	}
	//calculates value by power of two if indicated
	if(flagx == 1){
		value *= value;
	}
	//calculates value by multiplication if indicated
	if(flagm == 1){
		value *= mnum;
	}
	//calculates value by addition if indication
	if(flaga == 1){
		value += anum;
	}
	

	//prints results and formats with two decimal places
	printf("Result = %0.2f\n", value);


	
return 0;
}
