#include "modules/raylib_module.h"
#include <raylib.h>
#include <flecs.h>

int main()
{
    ecs_world_t *world = ecs_init();

    ECS_IMPORT(world, RaylibModule);
    ecs_entity_t e = ecs_new(world);

    ecs_set(world, e, Position, {10, 20});
    ecs_set(world, e, Text, {"coucou"});
    ecs_set(world, e, Size, {3});

    while (!WindowShouldClose()) {
       ecs_progress(world, GetFrameTime());
    }
    ecs_fini(world);
    CloseWindow();
}
