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

#include "path.h"

#include <QDebug>

void Path::addPoint(QPoint point) {
    this->points.append(point);
}

void Path::draw(QPainter* painter) {
    QPainterPath qpath = this->toQPainterPath();
    painter->drawPath(qpath);
}


QPainterPath Path::toQPainterPath() {
    QPainterPath result(points.at(0));
    qDebug() << "Testing" << points.at(0);
    for (QPoint p : this->points) {
        result.lineTo(p);
    }

    return result;
}

bool Path::isEmpty() {
    return this->points.isEmpty();
}
