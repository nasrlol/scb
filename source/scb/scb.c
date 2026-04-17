#include "scb.h"

int main(s32 argument_count, char **argument, char **env)
{
    mem_arena *global_arena = arena_create(MiB(10));
    assert_msg(argument_count < 2, "no arguments passed to scb");
    init(argument_count, argument, env);

    arena_destroy(global_arena);
    return 0;
}
