#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main() {

char cwd[1024];
if (getcwd(cwd, sizeof(cwd)) != NULL) {
    printf("Current working directory: %s\n", cwd);
} else {
    perror("getcwd() error");
    return 1;
}


char greeting[] = "Hallo";

char names[][10] = {"Max", "Kato", "Tijn"};

int length = sizeof(names) / sizeof(names[0]);
int i;

FILE *fptr;
fptr = fopen("hello.txt", "w");

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

    fprintf(fptr, greeting); 
    fprintf(fptr, " "); 
    fprintf(fptr, names[i]); 
    fprintf(fptr, "\n"); 

}

fclose(fptr);

printf("File created successfully!");
return 0;

}