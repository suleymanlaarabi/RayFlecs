#include "modules/raylib_module.h"
#include <raylib.h>
#include <flecs.h>

typedef Vector2 Position;
typedef Vector2 Velocity;

int main()
{
    ecs_world_t *world = ecs_init();

    ImportRaylibModule(world);

    while (!WindowShouldClose()) {
       ecs_progress(world, GetFrameTime());
    }
    ecs_fini(world);
    CloseWindow();
}
