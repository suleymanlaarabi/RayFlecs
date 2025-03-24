
#include "flecs.h"
#include "raylib.h"
#include "modules/rayflecs_module.h"

ECS_COMPONENT_DECLARE(RayFlecsTexture);

void RayFlecsDrawTextureSystem(ecs_iter_t *it)
{
    Position *positions = ecs_field(it, Position, 0);
    RayFlecsTexture *textures = ecs_field(it, RayFlecsTexture, 1);
    Size *sizes = ecs_field(it, Size, 2);

    for (int i = 0; i < it->count; i++) {
        Size size = 1;
        if (ecs_field_is_set(it, 2)) {
            size *= sizes[i];
        }
        DrawTextureEx(textures[i], positions[i], 0, size, RAYWHITE);
    }
}

void RayFlecsRegisterTexture(ecs_world_t *world)
{
    ECS_COMPONENT_DEFINE(world, RayFlecsTexture);
    ECS_SYSTEM(world, RayFlecsDrawTextureSystem, EcsPostUpdate, [in] Position, RayFlecsTexture, [in] ?Size);
}
