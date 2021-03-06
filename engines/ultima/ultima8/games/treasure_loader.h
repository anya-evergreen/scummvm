/*
Copyright (C) 2004 The Pentagram team

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef ULTIMA8_GAMES_TREASURELOADER_H
#define ULTIMA8_GAMES_TREASURELOADER_H

#include "ultima/ultima8/world/actors/treasure_info.h"
#include "ultima/shared/std/containers.h"
#include "ultima/shared/std/containers.h"

namespace Ultima {
namespace Ultima8 {

typedef Std::map<Pentagram::istring, TreasureInfo, Common::IgnoreCase_Hash> TreasureMap;

class TreasureLoader {
public:
	TreasureLoader();
	~TreasureLoader();

	//! load defaults from 'game' ini section
	void loadDefaults();

	//! parse treasure string into vector of TreasureInfo objects
	bool parse(Std::string, Std::vector<TreasureInfo> &treasure);

private:
	TreasureMap defaultTreasure;

	bool internalParse(Std::string desc, TreasureInfo &ti, bool loadingDefault);

	bool parseUInt32Vector(Std::string val, Std::vector<uint32> &vec);
	bool parseUIntRange(Std::string val, unsigned int &min, unsigned int &max);
	bool parseDouble(Std::string val, double &d);
	bool parseInt(Std::string val, int &i);
};

} // End of namespace Ultima8
} // End of namespace Ultima

#endif
