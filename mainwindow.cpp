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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "QPainter"
#include "QPaintEvent"
#include "QResizeEvent"
#include "QRect"
#include "QBrush"
#include <QTransform>

#include "Drawables/path.h"
#include "Tools/circletool.h"
#include "rulelines.h"
#include "gridlines.h"
#include "colorbackground.h"
#include "Tools/pentool.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);
    // this->background = new ColorBackground(this, Qt::white);
    this->background = new GridLines(this);
    // this->background = new RuleLines(this);
    this->transform = QTransform();
    // this->activeTool = new PenTool(this);
    this->activeTool = new CircleTool(this);
}

void MainWindow::addDrawable(Drawable *drawable)
{
    this->drawables.append(drawable);
    this->repaint();
}

void MainWindow::setActiveTool(Tool *tool)
{
    this->activeTool = tool;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    auto buttons = event->buttons();
    auto pos = event->pos();
    pos.setX(pos.x() - transform.dx());
    pos.setY(pos.y() - transform.dy());
    if (buttons.testFlag(Qt::LeftButton)) {
        this->activeTool->mouseMoveEvent(pos);
    } else if (buttons.testFlag(Qt::MiddleButton)) {
        auto diff = lastMousePosition - event->pos();
        lastMousePosition = event->pos();
        // qDebug() << lastMousePosition << " diff: " << diff << " flags: " << event->flags();
        transform.translate(diff.x(), diff.y());
        this->repaint();
   }

}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    auto button = event->button();
    auto pos = event->pos();
    pos.setX(pos.x() - transform.dx());
    pos.setY(pos.y() - transform.dy());

    if (button == Qt::LeftButton) {
        this->activeTool->mousePressEvent(pos);
    } else if (button == Qt::MiddleButton) {
        this->lastMousePosition = event->pos();
    }

    // } else if (button == Qt::RightButton) {
        // auto circle = new Circle(pos, 100.0);
        // this->drawables.append(circle);
        // this->repaint();
    // }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
     auto button = event->button();
    auto pos = event->pos();
    pos.setX(pos.x() - transform.dx());
    pos.setY(pos.y() - transform.dy());

    if (button == Qt::LeftButton) {
        this->activeTool->mouseReleaseEvent(pos);
    }
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setTransform(this->transform);
    this->background->draw(&painter);

    for (auto d : this->drawables) {
        d->draw(&painter);
    }

    // this->activeTool->draw(&painter);
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    // qDebug() << "resize - old size:" << event->oldSize() << " New size: " << event->size();

}

void MainWindow::wheelEvent(QWheelEvent *event) {
    qreal scaleValue = event->angleDelta().y()/1200.0;
    // qDebug() << "Wheel - angleDelta:" << event->angleDelta() << " nverted: " << event->inverted() << " phase: " << event->phase() << " pixelDelta: " << event->pixelDelta();
    // qDebug() << "scaleValue: " << scaleValue;
    transform.scale(1 + scaleValue, 1 + scaleValue);
    this->repaint();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key: " << event->key() << " - isAutoRepeat: " << event->isAutoRepeat();
    if (event->key() == Qt::Key_B) {
        qDebug() << "B pressed";
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    // qDebug() << "Key: " << event->key() << " - isAutoRepeat: " << event->isAutoRepeat();
}
