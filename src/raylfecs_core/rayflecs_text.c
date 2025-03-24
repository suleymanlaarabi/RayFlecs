
#include "raylib.h"
#include "flecs.h"
#include "modules/rayflecs_module.h"
#include <sys/types.h>

ECS_COMPONENT_DECLARE(Text);

void RayFlecsDrawText(ecs_iter_t *it)
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

void RayFlecsRegisterDrawText(ecs_world_t *world)
{
    ECS_COMPONENT_DEFINE(world, Text);
    ECS_SYSTEM(world, RayFlecsDrawText, EcsOnUpdate, Position, Text, ?Size);
}
