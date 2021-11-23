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

#include "circle.h"

#include <QtDebug>

Circle::Circle(QPoint position, qreal radius)
{
    this->position = position;
    this->radius = radius;
}

void Circle::draw(QPainter *painter)
{
    QRect rect(position.x()-radius, position.y()-radius, radius * 2, radius * 2);
    painter->drawArc(rect, 0, 5760);
}
