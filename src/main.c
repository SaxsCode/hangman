#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {

char greeting[] = "Hallo";

char names[][10] = {"Max", "Kato", "Tijn"};

int length = sizeof(names) / sizeof(names[0]);
int i;

FILE *fptr;
fptr = fopen("C:/Users/maxsa/Documents/projects/C/textfiles/hello.txt", "w");

if (fptr == NULL) {
    printf("Error opening file!");
    exit(1);
}

for (int i = 0; i < length; i++) 
{
    if (strcmp(names[i], "Tijn") == 0)
    {
        continue;
    }  

    fprintf(fptr, "%s %s\n", greeting, names[i]);

}

fclose(fptr);

printf("File created successfully!");
return 0;

}