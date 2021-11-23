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

#include "gridlines.h"

GridLines::GridLines(QWidget *parent)
{
    this->parent = parent;
}

void GridLines::draw(QPainter *painter)
{
    painter->setPen(QPen(Qt::black, 0.3, Qt::SolidLine, Qt::RoundCap));

    // Columns
    for (int i = lineDistance; i < parent->width(); i += lineDistance) {
        painter->drawLine(i, 0, i, parent->height());
    }
    // Rows
    for (int i = lineDistance; i < parent->height(); i += lineDistance) {
        painter->drawLine(0, i, parent->width(), i);
    }


}
