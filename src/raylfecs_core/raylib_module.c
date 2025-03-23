
#include "raylib.h"
#include "flecs.h"
#include "modules/raylib_module.h"
#include "flecs_macro.h"

void begindrawing_window(ecs_iter_t *it)
{
    ClearColor *clear_color = ecs_field(it, ClearColor, 0);

    BeginDrawing();
    ClearBackground(*clear_color);
}

void end_drawing_window()
{
    EndDrawing();
}

void ImportRaylibModule(ecs_world_t *world)
{
    ECS_MODULE(world, RaylibModule);

    ECS_COMPONENT(world, ClearColor);

    rayflecs_set_singleton(world, ClearColor, BLACK);
    InitWindow(1920, 1080, "game");
    ECS_SYSTEM(world, begindrawing_window, EcsPreUpdate,[in] ClearColor($));
    ECS_SYSTEM(world, end_drawing_window, EcsPostUpdate);
}
