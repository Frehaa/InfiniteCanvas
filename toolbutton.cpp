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

#include "toolbutton.h"

#include <QDebug>

ToolButton::ToolButton()
{
   this->setText("I am a button");
}

void ToolButton::mousePressEvent(QMouseEvent *event)
{
    this->animateClick();
    qDebug() << "Mouse press: " << event->flags();
    this->setFocus(Qt::MouseFocusReason);
    if (event->buttons().testFlag(Qt::LeftButton)) {
        activate();
    }
}

void ToolButton::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Mouse release: " << event->flags();
}

void ToolButton::keyPressEvent(QKeyEvent *event)
{

    qDebug() << "Key press: " << event->text();
}

void ToolButton::keyReleaseEvent(QKeyEvent *event)
{
    qDebug() << "Key release: " << event->text();
}

void ToolButton::focusInEvent(QFocusEvent *event)
{
    qDebug() << "Focus in: " << event->reason();
}

void ToolButton::focusOutEvent(QFocusEvent *event)
{
    qDebug() << "Focus out: " << event->reason();
}

void ToolButton::enterEvent(QEnterEvent *event)
{
    qDebug() << "Enter: " << event->globalPosition() << " - " << event->position();
}

void ToolButton::leaveEvent(QEvent *event)
{
    qDebug() << "Leave: " << event->isPointerEvent() << " - " << event->isInputEvent();
}
