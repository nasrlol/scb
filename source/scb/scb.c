#include "scb.h"

s32 main(s32 argument_count, char **argument, char **env) 
{
    assert_msg(argument_count < 2, "no arguments passed to scb");
    init(argument_count, argument, env);

}
