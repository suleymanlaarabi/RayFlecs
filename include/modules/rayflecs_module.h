
#ifndef RAYFLECS_MODULE
    #define RAYFLECS_MODULE
    #include "flecs.h"
    #include <raylib.h>


typedef Color ClearColor;
typedef Vector2 Position;
typedef Vector2 Velocity;
typedef Vector2 Scale;
typedef float Size;
typedef const char* Text;
typedef Texture2D RayFlecsTexture;

extern ECS_COMPONENT_DECLARE(ClearColor);
extern ECS_COMPONENT_DECLARE(Color);
extern ECS_COMPONENT_DECLARE(Position);
extern ECS_COMPONENT_DECLARE(Velocity);
extern ECS_COMPONENT_DECLARE(Text);
extern ECS_COMPONENT_DECLARE(Scale);
extern ECS_COMPONENT_DECLARE(Size);
extern ECS_COMPONENT_DECLARE(RayFlecsTexture);

void RaylibModuleImport(ecs_world_t *world);
void RayFlecsRegisterDrawText(ecs_world_t *world);
void RayFlecsRegisterTexture(ecs_world_t *world);
RayFlecsTexture LoadRayFlecsTexture(const char *path);

#endif
