#ifndef FLEC_MACRO_H
    #define FLEC_MACRO_H
    #define rayflecs_set_singleton(world, component, value) ecs_set_id(world, ecs_id(component), ecs_id(component), sizeof(component), &(value));
    #define rayflecs_set_component(world, entity, component, value)    \
      ecs_set_id(world, entity, ecs_id(component), sizeof(component), value)
      #define rayflecs_set_raw_component(world, entity, component, value) \
          component _b_##entity##_##component = value; \
          rayflecs_set_component(world, entity, component, &_b_##entity##_##component);
    #define rayflect_component(world, component, ...) \
        ecs_struct(world, { \
            .entity = ecs_id(component), \
            .members = { \
                __VA_ARGS__ \
            } \
        });
    #define rayflect_field(fname, ftype) { .name = #fname, .type = ecs_id(ecs_##ftype##_t) }
    #define rayflect_primitive(world, component, type) \
        ecs_primitive(world, { .entity = ecs_id(component), .kind = type });

#endif
