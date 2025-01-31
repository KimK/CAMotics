/******************************************************************************\

  CAMotics is an Open-Source simulation and CAM software.
  Copyright (C) 2011-2019 Joseph Coffland <joseph@cauldrondevelopment.com>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

\******************************************************************************/

#pragma once

#include "MachinePart.h"

#include <cbang/SmartPointer.h>

#include <map>
#include <string>


namespace CAMotics {
  class MachineModel : public cb::JSON::Serializable {
    std::string name;
    cb::Vector3D tool;
    cb::Vector3D workpiece;

    cb::Rectangle3D bounds;

    typedef std::map<std::string, cb::SmartPointer<MachinePart> > parts_t;
    parts_t parts;

  public:
    const std::string &getName() const {return name;}
    const cb::Rectangle3D &getBounds() const {return bounds;}
    const cb::Vector3D &getTool() const {return tool;}
    const cb::Vector3D &getWorkpiece() const {return workpiece;}

    typedef parts_t::const_iterator iterator;
    iterator begin() const {return parts.begin();}
    iterator end() const {return parts.end();}

    void add(const cb::SmartPointer<MachinePart> &part);

    // From cb::JSON::Serializable
    void read(const cb::JSON::Value &value);
    void write(cb::JSON::Sink &sink) const;
    using cb::JSON::Serializable::read;
    using cb::JSON::Serializable::write;
  };
}
