
#include "modules/rayflecs_module.h"
#include "flecs_macro.h"
#include "flecs.h"

void ImportRayflecsReflect(ecs_world_t *world)
{
    rayflect_component(world, Scale,
        rayflect_field(x, f32),
        rayflect_field(y, f32),
    );
    rayflect_component(world, Color,
        rayflect_field(r, u8),
        rayflect_field(g, u8),
        rayflect_field(b, u8),
        rayflect_field(a, u8)
    );
    rayflect_component(world, Position,
        rayflect_field(x, f32),
        rayflect_field(y, f32)
    );
    rayflect_primitive(world, RayFlecsRectangle, EcsPrimitiveType);
    rayflect_component(world, RayFlecsCircle,
        rayflect_field(diameter, f32)
    );
}
