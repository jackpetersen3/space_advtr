#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <json-c/json.h>

 json_object *name;
struct json_object *description;

//function declarations
void getName(void);
void chooseAdventure(struct json_object *, struct json_object *, size_t);
int is_planet(char *, struct json_object *, struct json_object *, size_t);
//void parse_json(char *filename);
