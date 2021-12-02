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

#ifndef LINETOOL_H
#define LINETOOL_H

#include "tool.h"
#include "Drawables/path.h"
#include "mainwindow.h"

class LineTool : public Tool
{
public:
    LineTool(MainWindow &w) : window(w){}
    void mouseMoveEvent(QPoint);
    void mousePressEvent(QPoint);
    void mouseReleaseEvent(QPoint) {}
    QString getName();

private:
    MainWindow& window;
    Path *path;

    // Tool interface
public:
};

#endif // LINETOOL_H
