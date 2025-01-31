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

#include "GLObject.h"
#include "VBO.h"

#include <vector>


namespace CAMotics {
  class Mesh : public GLObject {
    unsigned triangles;

    VBO vertices = GL_ATTR_POSITION;
    VBO normals  = GL_ATTR_NORMAL;

  public:
    Mesh(unsigned triangles);

    bool empty() const {return !triangles;}

    void reset(unsigned triangles);

    void add(unsigned count, const float *vertices, const float *normals);
    void add(const std::vector<float> &vertices,
             const std::vector<float> &normals);

    // From GLObject
    void glDraw(GLContext &gl);
  };
}
