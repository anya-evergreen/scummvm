/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef DIRECTOR_CACHEDMACTEXT_H
#define DIRECTOR_CACHEDMACTEXT_H

#include "graphics/font.h"

namespace Graphics {
class ManagedSurface;
class MacText;
class MacWindowManager;
}

namespace Director {

class TextCast;

class CachedMacText {
private:
	int _width;
	const TextCast *_textCast;
	Graphics::MacWindowManager *_wm;
	Graphics::MacText *_macText;
	Graphics::TextAlign _align;
	bool _dirty;
	Graphics::ManagedSurface *_surface;
	void makeMacText();

public:
	CachedMacText(TextCast *const textCast,
					int version,
					int defaultWidth = -1,
					Graphics::MacWindowManager *const wm = NULL);
	void setWm(Graphics::MacWindowManager *wm);
	void clip(int width);
	void forceDirty();
	const Graphics::ManagedSurface *getSurface();
	int getLineCount();

	void setStxt(const TextCast *stxt) { _textCast = stxt; forceDirty(); }
};

} // End of namespace Director

#endif
