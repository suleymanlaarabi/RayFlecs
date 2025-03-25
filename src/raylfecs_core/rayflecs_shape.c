

#include "modules/rayflecs_module.h"
#include "flecs.h"
#include "raylib.h"

ECS_COMPONENT_DECLARE(RayFlecsCircle);
ECS_COMPONENT_DECLARE(RayFlecsRectangle);

void DrawCircleShapeSystem(ecs_iter_t *it)
{
    Position *positions = ecs_field(it, Position, 0);
    RayFlecsCircle *circles = ecs_field(it, RayFlecsCircle, 1);
    Color *colors = ecs_field(it, Color, 2);

    for (int i = 0; i < it->count; i++) {
        DrawCircle(positions[i].x, positions[i].y, circles[i].diameter, colors[i]);
    }
}

void DrawRectangleShapeSystem(ecs_iter_t *it)
{
    Position *positions = ecs_field(it, Position, 0);
    Scale *scales = ecs_field(it, Scale, 1);
    Color *colors = ecs_field(it, Color, 2);

    for (int i = 0; i < it->count; i++) {
        DrawRectangle(positions[i].x, positions[i].y, scales[i].x, scales[i].y, colors[i]);
    }
}

void RayFlecsRegisterDrawCircleShape(ecs_world_t *world)
{
    ECS_COMPONENT_DEFINE(world, RayFlecsCircle);
    ECS_COMPONENT_DEFINE(world, RayFlecsRectangle);

    ECS_SYSTEM(world, DrawCircleShapeSystem, EcsOnUpdate, [in] Position, RayFlecsCircle, Color);
    ECS_SYSTEM(
        world,
        DrawRectangleShapeSystem,
        EcsOnUpdate,
            [in] Position,
            [in] Scale,
            Color,
            RayFlecsRectangle
    );

}
