#include "collisions.h"
#include "structs.h"

Entity entity[MAX_ENTITIES];
Entity player;
Game game;
Entity *self;

int collision(int, int, int, int, int, int, int, int);

int doPlayerCollisions() {
	int i;
	int errorFound = 0;

	/* Check each entity against the rest, skipping over inactive ones */
	for (i=0;i<MAX_ENTITIES;i++)
	{
		if (entity[i].active == 0)
		{
			continue;
		}
			
		/* test collisions between player and ground wall / fence */
		if(entity[i].type == TYPE_FENCE || entity[i].type == TYPE_WALL || entity[i].type == TYPE_BARRIER) 
		{
			printf("Found ground sprite with collision properties.\n");
			if(collision(entity[i].x, entity[i].y, entity[i].sprite->w, entity[i].sprite->h, player.x, player.y, player.sprite->w, player.sprite->h) == 0)
			{
				errorFound = ERROR;
			}
		}
	}
	
	if(errorFound == ERROR)
	{
		printf("Found collision.\n");
		return ERROR;
	}
	
	return OK;
}

void doCollisions()
{
	int i, j;

	/* Check each entity against the rest, skipping over inactive ones */
	for (i=0;i<MAX_ENTITIES;i++)
	{
		if (entity[i].active == 0)
		{
			continue;
		}

		for (j=0;j<MAX_ENTITIES;j++)
		{
			/* Don't collide with yourself, inactive entities or entities of the same type */			
			if(i == j || entity[j].active == 0 || entity[j].type == entity[i].type)
			{
				continue;
			}
			
			/* Test the collision */
			if(collision(entity[i].x, entity[i].y, entity[i].sprite->w, entity[i].sprite->h, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h) == 1)
			{
				/* If a collision occured, remove both Entities */
				entity[j].active = 0;
				entity[i].active = 0;
				
				/* Add 100 points to the score */
				game.score += 100;
			}
		}
	}
}

/* Very standard 2D collision detection routine */

int collision(int x0, int y0, int w0, int h0, int x2, int y2, int w1, int h1)
{
	int x1 = x0 + w0;
	int y1 = y0 + h0;

	int x3 = x2 + w1;
	int y3 = y2 + h1;

	if(x1<x2 || x3<x0 || y1<y2 || y3<y0)
	{
		return ERROR;
	}
	
	return OK;
}
