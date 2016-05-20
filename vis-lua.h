#ifndef VIS_LUA_H
#define VIS_LUA_H

#if CONFIG_LUA
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#else
typedef struct lua_State lua_State;
#endif

#include "vis.h"

/* add a directory to consider when loading lua files */
bool vis_lua_path_add(Vis*, const char *path);
/* get semi colon separated list of paths to load lua files */
const char *vis_lua_paths_get(Vis*);

/* various event handlers, triggered by the vis core */
void vis_lua_init(Vis*);
void vis_lua_start(Vis*);
void vis_lua_quit(Vis*);
void vis_lua_file_open(Vis*, File*);
void vis_lua_file_save(Vis*, File*);
void vis_lua_file_close(Vis*, File*);
void vis_lua_win_open(Vis*, Win*);
void vis_lua_win_close(Vis*, Win*);
void vis_lua_win_highlight(Vis*, Win*);
bool vis_lua_win_syntax(Vis*, Win*, const char *syntax);

#endif
