
#ifndef RAYFLECS_MODULE
    #define RAYFLECS_MODULE
    #include "flecs.h"
    #include <raylib.h>

typedef struct Color ClearColor;
typedef struct Position { float x, y; } Position;
typedef struct Velocity { float x, y; } Velocity;
typedef struct Scale { float x, y; } Scale;
typedef float Size;
typedef const char* Text;

extern ECS_COMPONENT_DECLARE(ClearColor);
extern ECS_COMPONENT_DECLARE(Position);
extern ECS_COMPONENT_DECLARE(Velocity);
extern ECS_COMPONENT_DECLARE(Text);
extern ECS_COMPONENT_DECLARE(Scale);
extern ECS_COMPONENT_DECLARE(Size);


void RaylibModuleImport(ecs_world_t *world);

#endif
