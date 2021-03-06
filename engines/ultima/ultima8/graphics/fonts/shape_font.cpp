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

#include "ultima/ultima8/misc/pent_include.h"
#include "ultima/ultima8/graphics/fonts/shape_font.h"
#include "ultima/ultima8/graphics/shape.h"
#include "ultima/ultima8/graphics/shape_frame.h"
#include "ultima/ultima8/graphics/fonts/shape_rendered_text.h"

namespace Ultima {
namespace Ultima8 {

DEFINE_RUNTIME_CLASSTYPE_CODE_MULTI2(ShapeFont, Pentagram::Font, Shape)


ShapeFont::ShapeFont(const uint8 *data_, uint32 size_,
                     const ConvertShapeFormat *format,
                     const uint16 flexId_, const uint32 shapeNum_)
	: Font(), Shape(data_, size_, format, flexId_, shapeNum_),
	  height(0), baseline(0), vlead(-1), hlead(0) {

}

ShapeFont::~ShapeFont() {

}


int ShapeFont::getWidth(char c) {
	return getFrame(static_cast<unsigned char>(c))->width;
}

int ShapeFont::getHeight() {
	if (height == 0) {
		for (uint32 i = 0; i < frameCount(); i++) {
			int h = getFrame(i)->height;

			if (h > height) height = h;
		}
	}

	return height;
}

int ShapeFont::getBaseline() {
	if (baseline == 0) {
		for (uint32 i = 0; i < frameCount(); i++) {
			int b = getFrame(i)->yoff;

			if (b > baseline) baseline = b;
		}
	}

	return baseline;
}

int ShapeFont::getBaselineSkip() {
	return getHeight() + getVlead();
}

void ShapeFont::getStringSize(const Std::string &text, int32 &width, int32 &height_) {
	width = hlead;
	height_ = getHeight();

	for (unsigned int i = 0; i < text.size(); ++i) {
		if (text[i] == '\n' || text[i] == '\r') {
			// ignore
		} else {
			width += getWidth(text[i]) - hlead;
		}
	}
}

RenderedText *ShapeFont::renderText(const Std::string &text,
                                    unsigned int &remaining,
                                    int32 width, int32 height_, TextAlign align,
                                    bool u8specials,
                                    Std::string::size_type cursor) {
	int32 resultwidth, resultheight;
	Std::list<PositionedText> lines;
	lines = typesetText<Traits>(this, text, remaining,
	                            width, height_, align, u8specials,
	                            resultwidth, resultheight, cursor);

	return new ShapeRenderedText(lines, resultwidth, resultheight,
	                             getVlead(), this);
}

} // End of namespace Ultima8
} // End of namespace Ultima
