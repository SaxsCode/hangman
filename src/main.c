#include <stdio.h>
#include <string.h>

int main() {

char greeting[] = "Hallo";

char names[][10] = {"Max", "Kato", "Tijn"};

int length = sizeof(names) / sizeof(names[0]);
int i;

for (int i = 0; i < length; i++) 
{
    if (strcmp(names[i], "Tijn") == 0)
    {
        continue;
    }  

    printf("%s %s\n", greeting, names[i]); 
}
    return 0;
}