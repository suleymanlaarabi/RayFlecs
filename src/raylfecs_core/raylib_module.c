
#include "raylib.h"
#include "flecs.h"
#include "modules/raylib_module.h"
#include "flecs_macro.h"
#include <sys/types.h>

ECS_COMPONENT_DECLARE(ClearColor);
ECS_COMPONENT_DECLARE(Position);
ECS_COMPONENT_DECLARE(Velocity);
ECS_COMPONENT_DECLARE(Scale);
ECS_COMPONENT_DECLARE(Text);
ECS_COMPONENT_DECLARE(Size);

void begindrawing_window(ecs_iter_t *it)
{
    ClearColor *clear_color = ecs_field(it, ClearColor, 0);

    BeginDrawing();
    ClearBackground(*clear_color);
}

void draw_text(ecs_iter_t *it)
{
    Position *positions = ecs_field(it, Position, 0);
    Text *texts = ecs_field(it, Text, 1);
    Size *scales = ecs_field(it, Size, 2);

    for (int i = 0; i < it->count; i++) {
        int scale = 16.;

        if (ecs_field_is_set(it, 2)) {
            scale *= scales[i];
        }
        DrawText(texts[i], positions[i].x, positions[i].y, scale, RAYWHITE);
    }
}

void end_drawing_window()
{
    EndDrawing();
}

void RaylibModuleImport(ecs_world_t *world)
{
    ECS_MODULE(world, RaylibModule);

    ECS_COMPONENT_DEFINE(world, ClearColor);
    ECS_COMPONENT_DEFINE(world, Velocity);
    ECS_COMPONENT_DEFINE(world, Position);
    ECS_COMPONENT_DEFINE(world, Text);
    ECS_COMPONENT_DEFINE(world, Scale);
    ECS_COMPONENT_DEFINE(world, Size);

    rayflecs_set_singleton(world, ClearColor, BLACK);
    InitWindow(1920, 1080, "game");
    ECS_SYSTEM(world, begindrawing_window, EcsPreUpdate,[in] ClearColor($));
    ECS_SYSTEM(world, draw_text, EcsOnUpdate, Position, Text, ?Size);
    ECS_SYSTEM(world, end_drawing_window, EcsPostUpdate);
}
