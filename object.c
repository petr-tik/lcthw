#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "object.h"
#include <assert.h>

void Object_destroy(void *self)
{
    Object *obj = self;
    // make a pointer of type Object to the object calling this
    // if it exists, free the description and the obj memory addresses
    if(obj) {
        if(obj->description) free(obj->description);
        free(obj);
    }
}

void Object_describe(void *self)
{
    Object *obj = self;
    printf("%s.\n", obj->description);
    // from the memory address of object print its description
}

void Object_init(void *self)
{
    // does nothing
    return 1;
}

void *Object_move(void *self, Direction direction)
{
    printf("You can't go in that direction\n");
    return NULL;
}

int Object_attack(void *self, int damage)
{
    printf("You can't attack that\n");
    return 0;
}

void *Object_new(size_t size, Object proto, char *description)
{
    // setting up the default function in case they haven't been set
    if(!proto.init) proto.init = Object_init;
    if(!proto.describe) proto.describe = Object_describe;
    if(!proto.destroy) proto.destroy = Object_destroy;
    if(!proto.attack) proto.attack = Object_attack;
    if(!proto.move) proto.move = Object_move;

    // this seems weird, but we can make a struct of one size, 
    // then point a different pointer at it to "cast" it

    Object *el = calloc(1, size);
    *el = proto;

    // copy the description
    el->description = strdup(description);

    // initialise it with whatever init we were given
    if(!el-init(el)) {
        // if it didn't initialise properly
        el->destroy(el);
        return NULL;
    } else {
        // it worked
        return el;
    }
}