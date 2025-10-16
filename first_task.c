/* Task description:
The results of a running competition are shown in the table below.
Index	Name	Birthdate	Rank

0	Am, Erica	1984. 05. 06.	1
1	Abnorm, Al	1982. 09. 30.	3
2	Pri, Mary	1988. 08. 25.	2
3	Duck, Ling	1979. 06. 10.	5
4	Mac, Donald	1992. 04. 05.	4

Find an unfinished program below that contains the appropriate types and the above data in an array. Complete the program, step-by-step, according to the comments.

*/

#include <stdio.h>
#include <string.h>

typedef struct Date
{ // Create a stuct definition, not an instance, it is a type. With typedef we give it a new name (struct Date-->Date
    int year, month, day;
} Date;

typedef struct Competitor
{
    char name[31];
    Date birth; // Here we use our fresh type: Date!
    int rank;
} Competitor;

void Date_print(Date d); // Here we declare that there is a function
// that "eats" Date and do not return (poos) anything. You need to write a function at the bottom!

Competitor Competitor_read(); // This function will read data from user store in a stucture
// and return with the new element (to be put into the array later)

void Competitor_print(Competitor c);

int main()
{
    Competitor competitors[6] = {
        // It is an array of Competitor, like array of int!
        // Please note that the individual competitors are not variables,
        // there are no variable name for them, these exists only in the array!
        // 6 competitor to be able to add one more!
        {"Am, Erica", {1984, 5, 6}, 1},
        {"Abnorm, Al", {1982, 9, 30}, 3},
        {"Pri, Mary", {1988, 8, 25}, 2},
        {"Duck, Ling", {1979, 6, 10}, 5},
        {"Mac, Donald", {1992, 4, 5}, 4},
    };
    Competitor_print(competitors[1]);
    printf("%s\n", competitors[0].name);
    printf("%d\n", competitors[4].rank);
    Date_print(competitors[4].birth);
    printf("\n%c\n", competitors[1].name[0]);
    (competitors[1].rank < 4)?
        printf("Yes\n"):
        printf("No\n");
    (competitors[4].rank > competitors[3].rank)?
        printf("Yes\n"):
        printf("No\n");
    (competitors[1].birth.year == competitors[2].birth.year)?
        printf("Yes\n"):
        printf("No\n");
    Competitor_print(competitors[1]);
    for (int i = 0; i < 6;i++){
        if (strcmp(competitors[i].name,"Abnorm, Al") == 0){
            printf("Yes\n");  
        }
       
    }
    competitors[5] = Competitor_read();
    for (int i = 0; i < 6; i++){
        Competitor_print(competitors[i]);
    }
    /* Create a function to add a new competitor according to user's input (using scanf)*/
    /*Add a new competitor as 6th element (index 5)*/
    /* at last print all data of all competitors. */

    return 0;
}
void Date_print(Date d)
{
    printf("%d.%d.%d", d.year, d.month, d.day);
}

void Competitor_print(Competitor c)
{
    printf("%s\t", c.name);
    Date_print(c.birth);
    printf("\t%d\n", c.rank);
}

Competitor Competitor_read()
{
    Competitor a;
    printf("Give competitors name:\n");
    scanf("%s", &a.name);
    printf("Give competitors birth date:\n");
    scanf("%d", &a.birth.year);
    scanf("%d", &a.birth.month);
    scanf("%d", &a.birth.day);
    printf("Give competitors rank:\n");
    scanf("%d", &a.rank);
    return a;
}