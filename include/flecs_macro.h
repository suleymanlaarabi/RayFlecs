#ifndef FLEC_MACRO_H
    #define FLEC_MACRO_H
    #define rayflecs_set_singleton(world, component, value) ecs_set_id(world, ecs_id(component), ecs_id(component), sizeof(component), &(value));

#endif
