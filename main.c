#include "functions.h"

int main(int argc, char *argv[])
{
    struct json_object *description;
    parse_json("planetarySystem.json");
    getName();
    chooseAdventure();
    printf("%s\n",json_object_get_string(description));
    return 0;
}
