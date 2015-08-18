#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 480

#define MAX_ENTITIES 975
#define MAX_RELOAD_TIME 20

#define PLAYER_SPEED 3
#define BULLET_SPEED 10

#define ANIM_SPEED 3

/* Yaw definitions */
#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4

/* Map chunk types */
#define DIRT_CHUNK 2
#define GRASS_CHUNK 3
#define TOP_DIRT_EDGE_CHUNK 4
#define BOT_DIRT_EDGE_CHUNK 5

#define RETURN_CHUNK 0

#define ERROR 1

enum
{
	PLAYER_RIGHT_SPRITE,
	PLAYER_LEFT_SPRITE,
	PLAYER_UP_SPRITE,
	PLAYER_DOWN_SPRITE,
 	BULLET_SPRITE,
  	UFO_SPRITE,
  	DIRT_SPRITE,
  	GRASS_SPRITE,
  	TOP_DIRT_EDGE_SPRITE,
  	BOT_DIRT_EDGE_SPRITE,
	MAX_SPRITES
};

enum
{
	BULLET_SOUND,
 	MAX_SOUNDS
};

enum
{
	TYPE_BULLET,
 	TYPE_ENEMY,
 	TYPE_GROUND
};
