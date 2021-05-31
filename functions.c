#include "functions.h"

//this function prints welcome ststaments and finds the name of the user
void getName(void) {
    char name[30];
    printf("Welcome to the solar system\n");
    printf("There are 9 planets to explore\n");
    printf("What is your name?\n");
    scanf("%s", name );
    printf("Nice to meet you, %s. My name is Eliza, I'm an old friend of Alexa\n", name);
    printf("Let's go on an adventure\n");
}

//this function prompts th user to choose between a randomly selected planet
//or a planet of their choosing
void chooseAdventure(struct json_object * name, struct json_object * description, size_t array_len) {
    int flag = 0;
    char input[30], planet[20];
    do {
        printf("Shall I randomly choose a planet for you to visit?\n");
        sleep(1);
        scanf("%s", input);
        if(strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
            random_planet(name, description, array_len);
            flag = 1;
        }
        else if(strcmp(input, "N") == 0 || strcmp(input, "n") == 0) {
            printf("Name the planet you would like to visit...\n");
            scanf("%s", planet);
            flag = is_planet(planet, name, description, array_len);
           /* printf("Traveling to Pluto...\n");
            printf("I don't care what they say, it's still a planet\n");
            flag = 1;*/
        }
        else {
            printf("Sorry, I don't understand..\n");
        }
    } while(flag == 0);

}

//this planet cycles through the array of planet names to see if the name typed by the user matches 
//the name of a planet. Returns 1 if successful, 0 if not
int is_planet(char * planet, struct json_object * name, struct json_object * description, size_t array_len)
{
    int i;
    struct json_object *temp1, *temp2;

    for(i = 0; i < array_len; i++) {
        temp1 = json_object_array_get_idx(name, i);
        temp2 = json_object_array_get_idx(description, i);
        //string = json_object_get_string(temp)
        if(strcmp(planet, json_object_get_string(temp1)) == 0)
        {
            printf("Traveling to %s ...\n", json_object_get_string(temp1));
            printf("%s\n", json_object_get_string(temp2));
            return 1;
        }
    }
    return 0;

}

//this function generates a random number between 0 and the length of
//the planet array and chooses that number to be the random planet
void random_planet(struct json_object * name, struct json_object * description, size_t array_len)
{
    struct json_object *temp1, *temp2;
    int num;
    num = rand() % array_len;
    temp1 = json_object_array_get_idx(name, num);
    temp2 = json_object_array_get_idx(description, num);

    printf("Traveling to %s ...\n", json_object_get_string(temp1));
    printf("%s\n", json_object_get_string(temp2));

}

/*void parse_json(char *filename)
{
    FILE *fd;
    char buffer[4096];
    struct json_object *name = json_object_new_array();
    struct json_object *description = json_object_new_array();
    struct json_object *temp_name;
    struct json_object *temp_description;



    struct json_object *parsed_json;
    struct json_object *planets;
    struct json_object *planet_obj; 

    size_t array_len;
    size_t i = 0;

    fd = fopen(filename, "r");
    fread(buffer, 4096, 1, fd);
    fclose(fd);

    parsed_json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_json, "planets", &planets);

    array_len = json_object_array_length(planets);

    for(i = 0; i < array_len; i++) {
        planet_obj = json_object_array_get_idx(planets, i);
        json_object_object_get_ex(planet_obj, "name", &temp_name);
        json_object_object_get_ex(planet_obj, "description", &temp_description);
        json_object_array_add(name, temp_name);
        json_object_array_add(description, temp_description);
        //printf("Name: %s\n", json_object_get_string(name));
    }
}*/