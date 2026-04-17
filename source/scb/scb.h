/* descrition: meta program, build tool
   author: Abdellah El Morabit */
#define BASE_UNITY
#include "../base/base_include.h"

#define  scbdef static

typedef struct config config;

struct config {
    string8 compiler;
    string8 output;
    string8 flags[];
};

typedef struct file_metad file_metad;
struct file_metad
{
    string8     name;
    u32         time;
};

internal b32
is_file_modified(const char *path)
{
    struct stat scb_bstats;
    s8 err = lstat(path, &scb_bstats);
    assert_msg((err), "lstat failed.");

    if(scb_bstats.st_mtime)
    {

    }
    return 0;
}

//@documentatie: hebfjlberln
internal void
init(int argument_count, char **argument, char **env)
{
    mem_arena *global_arena = arena_create(KiB(2));
    assert_msg(argument_count > 2, "no program passed");

    string8 command = PushString(global_arena, Len(*argument[2]));

    command.data = (u8 *) *argument;
    command.size = Len(*argument[2]);

    //- load files into buffer
    {
        if(is_file_modified)
        {
            self_rebuild();
        }

        //- TODO(nasr): ...
    }

    if(string8_cmp(command, StringCastUTF8("doc", 3)))
    {
        //- run meta program that builds tool documentation
        //- hmmm how do i store the documentation
        {
        }
    }
    else if(string8_cmp(command, StringCast("build", 5)))
    {


        //- search for the binary in PATH
        {
            for(s32 index = 0; *env[index]; ++index)
            {

            }
        }

        //- run the simple build tool
        pid_t pid = fork();
        assert_msg(pid == -1, "failed to start fork process");


        if(pid == 0) {

        }
    }
    else if(string8_cmp(command, StringCast("meta", 5)))
    {
        //- run the meta program
    }

    return;
}
