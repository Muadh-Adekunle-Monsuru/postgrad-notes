
**Program Statement:**
Write a program that reads athlete performance and demographic data from a data file (max. 50 records, data belonging to athletes) named `DSE501_Practice_Athletes.csv` and inserts them into arrays in a sorted manner (or sorting can be done after all insertions) with respect to the athlete's **Score** in descending order. Then print the whole data to the screen.

Reading data from a file line by line, breaking every line into pieces (parsing CSV comma delimiters), inserting the pieces to the relevant array structures, sorting the data, and finally printing the data shall all be done by separate functions. Your main program is expected to be as short as possible. To this end, you are required to develop a library file (.h file) called `NameLastname_DSE501_Practice_Library.h` as well. Only the use of arrays is permitted (no structs).

Please name your practice code file as `NameLastname_DSE501_Practice.c` and ensure both the library file and your C file compile together successfully.

**Notes:**

1. This practice requires a good understanding of the topics below:
a. Strings and character manipulation (specifically splitting by commas)
b. Parallel Arrays
c. File I/O
2. Ensure you handle the header row of the CSV file appropriately so it does not get sorted as an athlete's record.

---

**Sample Data (`DSE501_Practice_Athletes.csv`)**

```csv
First_Name,Last_Name,Score,Gender,Team_Name,Jersey_Number,City,Country
Lionel,Messi,95,M,Inter Miami,10,Miami,USA
Serena,Williams,98,F,Aces,1,Compton,USA
Usain,Bolt,99,M,Racers Track Club,9,Kingston,Jamaica
Katarina,Johnson,88,F,Liverpool Harriers,7,Liverpool,UK
Luka,Doncic,92,M,Mavericks,77,Dallas,USA
Mia,Hamm,91,F,Freedom,9,Washington,USA
Giannis,Antetokounmpo,94,M,Bucks,34,Milwaukee,USA
Marta,Vieira,90,F,Pride,10,Orlando,USA
Eliud,Kipchoge,97,M,NN Running Team,1,Kaptagat,Kenya
Katie,Ledecky,96,F,Gators,15,Bethesda,USA

```


```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "practice_assignment_header.h"

FILE *parse_file(int argc, char *argv[]);
void parse_data(FILE file,char data_array[]);

int main(int argc, char *argv[]){
	char data_array[50][8][50] = {0};
	
	FILE *file = parse_file(argc, argv);
	parse_data(file, data_array[]);


	return 0;
}
```


```C
FILE *parse_file(int argc, char *argv[]){
	if(argc < 2){
		fprintf(stderr,"Usage: %s <data-filename>",argc[0]);
		exit(-1);
	}
	
	file = fopen(argv[1],"r");
	
	if(file == NULL){
		fprintf(stderr,"File is empty");
		exit(-1);
	}
	
	return file;
}

void parse_data(FILE file, char data_array[]){
char first_name[50],last_name[50],gender[50],team_name[50],city[50],country[50];
int score,jersey_number;

printf("%7s %7s %7s %7s %7s %7s %7s %7s \n\n ","first_name","last_name","score","gender","team_name","jersey_number","city","country");
};

while(fscanf(file," [^,], [^,], %d, [^,], [^,], %d, [^,], [^,] \n",first_name, last_name, &score, gender, team_name, &jersey_number, city, country )==8){
printf("%7s %7s %5d %7s %7s %5d %7s %7s \n ",first_name,last_name,score,gender,team_name,jersey_number,city,country);
}

fclose(file);
}
```