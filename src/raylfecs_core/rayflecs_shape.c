

#include "modules/rayflecs_module.h"
#include "flecs.h"
#include "raylib.h"
#include <stdio.h>

ECS_COMPONENT_DECLARE(RayFlecsCircle);
ECS_COMPONENT_DECLARE(RayFlecsRectangle);
ECS_COMPONENT_DECLARE(Triangle);

void DrawCircleShapeSystem(ecs_iter_t *it)
{
    Position *positions = ecs_field(it, Position, 0);
    RayFlecsCircle *circles = ecs_field(it, RayFlecsCircle, 1);
    Color *colors = ecs_field(it, Color, 2);

    for (int i = 0; i < it->count; i++)
        DrawCircleV(positions[i], circles[i].diameter, colors[i]);
}

void DrawRectangleShapeSystem(ecs_iter_t *it)
{
    Position *positions = ecs_field(it, Position, 0);
    Scale *scales = ecs_field(it, Scale, 1);
    Color *colors = ecs_field(it, Color, 2);

    for (int i = 0; i < it->count; i++) {
        DrawRectangleV(positions[i], scales[i], colors[i]);
    }
}


void DrawTriangleShapeSystem(ecs_iter_t *it)
{
    Triangle *triangle = ecs_field(it, Triangle, 0);
    Color *colors = ecs_field(it, Color, 1);

    for (int i = 0; i < it->count; i++) {
        puts("ok");
        DrawTriangle(triangle[i].p1, triangle[i].p2, triangle[i].p3, colors[i]);
    }
}

void RayFlecsRegisterDrawCircleShape(ecs_world_t *world)
{
    ECS_COMPONENT_DEFINE(world, RayFlecsCircle);
    ECS_COMPONENT_DEFINE(world, RayFlecsRectangle);
    ECS_COMPONENT_DEFINE(world, Triangle);

    ECS_SYSTEM(
        world,
        DrawCircleShapeSystem,
        EcsOnUpdate,
            [in] Position,
            RayFlecsCircle,
            Color
    );
    ECS_SYSTEM(
        world,
        DrawTriangleShapeSystem,
        EcsOnUpdate,
            [in] Triangle,
            Color
    );
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
