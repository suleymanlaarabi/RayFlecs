#include "flecs_macro.h"
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
    RayflecsMetaImport(world);

    ECS_IMPORT(world, FlecsStats);
    ECS_IMPORT(world, FlecsScript);
    ecs_singleton_set(world, EcsRest, {0});

    // ecs_entity_t b = ecs_new(world);
    // ecs_set(world, b, Triangle, {
    //     {100, 100},
    //     {100, 200},
    //     {200, 150}
    // });
    // rayflecs_set_raw_component(world, b, Color, BLUE);

    const char *code = file_to_string("./rayflecs_scripts/default.flecs");

    ecs_script_t *script = ecs_script_parse(world, "default.flecs", code, NULL);

    ecs_script_eval(script, NULL);

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
       ecs_progress(world, GetFrameTime());
    }
    ecs_fini(world);
    CloseWindow();
}
