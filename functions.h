#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <json-c/json.h>

struct json_object *name;
struct json_object *description;

//function declarations
void getName(void);
void chooseAdventure(void);
void parse_json(char *filename);
