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
#include "ultima/ultima8/kernel/delay_process.h"
#include "ultima/ultima8/filesys/idata_source.h"
#include "ultima/ultima8/filesys/odata_source.h"
#include "ultima/ultima8/misc/p_dynamic_cast.h"
#include "ultima/shared/std/string.h"

namespace Ultima {
namespace Ultima8 {

DEFINE_RUNTIME_CLASSTYPE_CODE(DelayProcess, Process)



DelayProcess::DelayProcess(int count_)
	: Process(), count(count_) {

}

DelayProcess::~DelayProcess() {

}

void DelayProcess::run() {
	if (--count == 0)
		terminate();
}

void DelayProcess::dumpInfo() {
	Process::dumpInfo();
	pout << "Frames left: " << count << Std::endl;
}


bool DelayProcess::loadData(IDataSource *ids, uint32 version) {
	if (!Process::loadData(ids, version)) return false;

	count = static_cast<int>(ids->read4());

	return true;
}

void DelayProcess::saveData(ODataSource *ods) {
	Process::saveData(ods);
	ods->write4(static_cast<uint32>(count));
}

} // End of namespace Ultima8
} // End of namespace Ultima
