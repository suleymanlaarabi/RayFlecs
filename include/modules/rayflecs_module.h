
#ifndef RAYFLECS_MODULE
    #define RAYFLECS_MODULE
    #include "flecs.h"
    #include <raylib.h>

typedef Color ClearColor;
typedef struct RayFlecsCircle { float diameter; } RayFlecsCircle;
typedef Vector2 Position;
typedef Vector2 Velocity;
typedef Vector2 Scale;
typedef float Size;
typedef const char* Text;
typedef Texture2D RayFlecsTexture;
typedef struct RayFlecsRectangle { bool enabled; } RayFlecsRectangle;
typedef struct Triangle {
    Vector2 p1;
    Vector2 p2;
    Vector2 p3;
} Triangle;

extern ECS_COMPONENT_DECLARE(Triangle);
extern ECS_COMPONENT_DECLARE(ClearColor);
extern ECS_COMPONENT_DECLARE(Color);
extern ECS_COMPONENT_DECLARE(Position);
extern ECS_COMPONENT_DECLARE(Velocity);
extern ECS_COMPONENT_DECLARE(Text);
extern ECS_COMPONENT_DECLARE(Scale);
extern ECS_COMPONENT_DECLARE(RayFlecsRectangle);
extern ECS_COMPONENT_DECLARE(Size);
extern ECS_COMPONENT_DECLARE(RayFlecsTexture);
extern ECS_COMPONENT_DECLARE(RayFlecsCircle);

void RayflecsModuleImport(ecs_world_t *world);
void RayFlecsRegisterDrawText(ecs_world_t *world);
void RayFlecsRegisterTexture(ecs_world_t *world);
RayFlecsTexture LoadRayFlecsTexture(const char *path);
void RayFlecsRegisterDrawCircleShape(ecs_world_t *world);

void RayflecsMetaImport(ecs_world_t *world);

#endif
