/*
Copyright © 2011-2012 Clint Bellanger
Copyright © 2013-2014 Henrik Andersson
Copyright © 2013 Kurt Rinnert

This file is part of FLARE.

FLARE is free software: you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation,
either version 3 of the License, or (at your option) any later version.

FLARE is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
FLARE.  If not, see http://www.gnu.org/licenses/
*/

/**
SharedResources

"Global" sort of system resources that are used by most game classes.
Only one instance of these classes are needed by the engine.
Generic objects only. Game-specific objects don't belong here.
Created and destroyed by main.cpp
**/

#ifndef SHARED_RESOURCES_H
#define SHARED_RESOURCES_H

#include "CommonIncludes.h"
#include "AnimationManager.h"
#include "CombatText.h"
#include "CursorManager.h"
#include "FontEngine.h"
#include "InputState.h"
#include "MessageEngine.h"
#include "ModManager.h"
#include "SoundManager.h"
#include "RenderDevice.h"

extern SDL_Joystick *joy;

extern AnimationManager *anim;
extern CombatText *comb;
extern CursorManager *curs;
extern FontEngine *font;
extern InputState *inpt;
extern MessageEngine *msg;
extern ModManager *mods;
extern SoundManager *snd;
extern Sprite *icons;
extern int textures_count;
extern RenderDevice *render_device;

class SharedResources {
public:
	static void loadIcons() {
		Image *graphics;

		if (!render_device)
			return;

		if (icons) {
			delete icons;
			icons = NULL;
		}

		graphics = render_device->loadImage("images/icons/icons.png", "Couldn't load icons", false);
		if (graphics) {
			icons = graphics->createSprite();
			graphics->unref();
		}
	}
};

#endif
