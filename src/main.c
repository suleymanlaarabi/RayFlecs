#include "flecs_macro.h"
#include "modules/rayflecs_module.h"
#include <raylib.h>
#include <flecs.h>

int main()
{
    ecs_world_t *world = ecs_init();

    ECS_IMPORT(world, RaylibModule);
    ECS_IMPORT(world, FlecsStats);
    ecs_singleton_set(world, EcsRest, {0});

    ecs_entity_t e = ecs_new(world);
    ecs_set(world, e, Position, {10, 20});
    ecs_set(world, e, Text, {"coucou"});
    rayflecs_set_raw_component(world, e, Color, BLUE);
    ecs_set(world, e, Size, {3});

    ecs_entity_t b = ecs_new(world);
    ecs_set(world, b, Position, {100, 200});
    ecs_set(world, b, Size, {10});
    rayflecs_set_raw_component(world, b, RayFlecsTexture, LoadTexture("assets/duck.png"));

    ecs_entity_t c = ecs_new(world);
    ecs_set(world, c, Position, {200, 100});
    rayflecs_set_raw_component(world, c, Color, RAYWHITE);
    rayflecs_set_raw_component(world, c, Circle, 10);

    SetTargetFPS(120);
    while (!WindowShouldClose()) {
       ecs_progress(world, GetFrameTime());
    }
    ecs_fini(world);
    CloseWindow();
}
