#include "functions.h"

//this is the main function where all function call are made
//the parser function is temporailiy in here while i figure out how to make json objects 
//accesible to other functions;
int main(int argc, char *argv[])
{
    //set randdom time seed for random function
    srand((unsigned)time(NULL));
    //the general methods used for this parser function are based on those found here: https://progur.com/2018/12/how-to-parse-json-in-c.html
    FILE *fd;
    char buffer[4096];
    struct json_object *name = json_object_new_array();
    struct json_object *description = json_object_new_array();
    struct json_object *temp_name, *temp_description, *parsed_json, *planets, *planet_obj;
    
    size_t array_len;
    size_t i = 0;

    fd = fopen(argv[2], "r");
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

    //function calls
    getName();
    chooseAdventure(name, description, array_len);
    return 0;
}
