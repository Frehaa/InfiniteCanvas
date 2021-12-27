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
#include "rulelines.h"

RuleLines::RuleLines(QWidget *parent)
{
    this->parent = parent;
}

void RuleLines::draw(QPainter *painter)
{
    painter->setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::RoundCap));
    painter->drawLine(30, 0, 30, parent->height());
    painter->setPen(QPen(Qt::blue, 0.3, Qt::SolidLine, Qt::RoundCap));
    for (int i = 0; i < parent->height(); i += 30) {
        painter->drawLine(0, i, parent->width(), i);
    }

}
