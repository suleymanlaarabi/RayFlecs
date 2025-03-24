#ifndef FLEC_MACRO_H
    #define FLEC_MACRO_H
    #define rayflecs_set_singleton(world, component, value) ecs_set_id(world, ecs_id(component), ecs_id(component), sizeof(component), &(value));
    #define rayflecs_set_component(world, entity, component, value)    \
      ecs_set_id(world, entity, ecs_id(component), sizeof(component), value)
    #define rayflecs_set_raw_component(world, entity, component, value) \
        component _b##entity##_component = value; \
        rayflecs_set_component(world, entity, component, &_b##entity##_component);

#endif
