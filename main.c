//this is the main file for my code for a text based space exploration project
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void getName(void);
void planetLoop(void);
int main(int argc, char *argv[])
{
    getName();
    planetLoop();
    return 0;
}

void getName(void) {
    char name[30];
    printf("Welcome to the solar system\n");
    printf("There are 9 planets to explore\n");
    printf("What is your name?\n");
    scanf("%s", name );
    printf("Nice to meet you, %s. My name is Eliza, I'm an old friend of Alexa\n", name);
    printf("Let's go on an adventure\n");
}

void planetLoop(void) {
    int flag = 0;
    char input[30], planet[20];
    do {
        printf("Shall I randomly choose a planet for you to visit?\n");
        sleep(1);
        scanf("%s", input);
        if(strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
            printf("Traveling to Pluto...\n");
            printf("I don't care what they say, it's still a planet\n");
            flag = 1;
        }
        else if(strcmp(input, "N") == 0 || strcmp(input, "n") == 0) {
            printf("Name the planet you would like to visit...\n");
            scanf("%s", planet);
            printf("Traveling to Pluto...\n");
            printf("I don't care what they say, it's still a planet\n");
            flag = 1;
        }
        else {
            printf("Sorry, I don't understand..\n");
        }
    } while(flag == 0);

}