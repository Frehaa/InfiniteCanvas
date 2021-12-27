// This is a drawing application with the goal of making it easy to create
// clean looking illustrations for didactic purposes.
// Copyright (C) 2021  Frederik Haagensen

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "linetool.h"

void LineTool::mouseMoveEvent(QPoint point)
{
    path->popPoint();
    path->addPoint(point);
    window.repaint();
}

void LineTool::mousePressEvent(QPoint point)
{
    path = new Path();
    path->addPoint(point);
    path->addPoint(point);
    window.addDrawable(path);
}
