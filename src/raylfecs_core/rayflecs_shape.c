

#include "modules/rayflecs_module.h"
#include "flecs.h"
#include "raylib.h"

ECS_COMPONENT_DECLARE(Circle);

void DrawCircleShapeSystem(ecs_iter_t *it)
{
    Position *positions = ecs_field(it, Position, 0);
    Circle *circles = ecs_field(it, Circle, 1);
    Color *colors = ecs_field(it, Color, 2);

    for (int i = 0; i < it->count; i++) {
        DrawCircle(positions[i].x, positions[i].y, circles[i], colors[i]);
    }
}

void RayFlecsRegisterDrawCircleShape(ecs_world_t *world)
{
    ECS_COMPONENT_DEFINE(world, Circle);

    ECS_SYSTEM(world, DrawCircleShapeSystem, EcsOnUpdate, [in] Position, Circle, Color);
}
