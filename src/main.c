#include "modules/rayflecs_module.h"
#include <raylib.h>
#include <flecs.h>
#include <stdlib.h>

char* file_to_string(const char* filename) {
    FILE* f = fopen(filename, "rb");
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    rewind(f);
    char* buffer = malloc(size + 1);
    fread(buffer, 1, size, f);
    buffer[size] = 0;
    fclose(f);
    return buffer;
}

int main()
{

    SetTraceLogLevel(LOG_NONE);

    ecs_world_t *world = ecs_init();

    ECS_IMPORT(world, RayflecsModule);
    ECS_IMPORT(world, FlecsStats);
    ECS_IMPORT(world, FlecsScript);
    ecs_singleton_set(world, EcsRest, {0});

    // ecs_entity_t b = ecs_new(world);
    // ecs_set(world, b, Position, {100, 200});
    // ecs_set(world, b, Size, {10});
    // rayflecs_set_raw_component(world, b, RayFlecsTexture, LoadTexture("assets/duck.png"));


    // ecs_entity_t d = ecs_new(world);
    // ecs_set(world, d, Position, {400, 300});
    // rayflecs_set_raw_component(world, d, Color, RAYWHITE);
    // ecs_set(world, d, Scale, {20, 100});
    // ecs_set(world, d, RayFlecsRectangle, {});


    // ecs_entity_t e = ecs_new(world);
    // ecs_set(world, e, Position, {10, 20});
    // ecs_set(world, e, Text, {"coucou"});
    // rayflecs_set_raw_component(world, e, Color, BLUE);
    // ecs_set(world, e, Size, {3});
    SetTargetFPS(60);


    // ecs_entity_t c = ecs_new(world);
    // ecs_set(world, c, Position, {200, 100});
    // rayflecs_set_raw_component(world, c, Color, RAYWHITE);
    // ecs_set(world, c, RayFlecsCircle, {.diameter = 10});

    const char *code = file_to_string("./rayflecs_scripts/default.flecs");

    ecs_script(world, {
        .code = code,
        .filename = "default.flecs"
    });

    while (!WindowShouldClose()) {
       ecs_progress(world, GetFrameTime());
    }
    ecs_fini(world);
    CloseWindow();
}
