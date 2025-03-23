
#ifndef RAYFLECS_MODULE
    #define RAYFLECS_MODULE
    #include "flecs.h"
    #include <raylib.h>

typedef Color ClearColor;

extern ECS_COMPONENT_DECLARE(ClearColor);

void ImportRaylibModule(ecs_world_t *world);

#endif
