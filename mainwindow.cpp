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

#include "path.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);
    this->currentPath = new Path();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons().testFlag(Qt::LeftButton)) {
        qDebug() << "Move to " << event->pos() << " flags: " << event->flags();
        this->currentPath->addPoint(event->pos());
        this->repaint();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        qDebug() << "Press - " << event->pos() << " flags: " << event->flags();
        this->currentPath->addPoint(event->pos());
        this->repaint();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        qDebug() << "Release - " << event->pos() << " flags: " << event->flags();
        this->currentPath->addPoint(event->pos());
        this->drawables.append(this->currentPath);
        this->currentPath = new Path();
        this->repaint();
    }
}

void MainWindow::paintEvent(QPaintEvent *event) {
    qDebug() << "paint " << event->rect();

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::blue, 12, Qt::SolidLine, Qt::RoundCap));

    for (auto d : this->drawables) {
        d->draw(&painter);
    }

    if (this->currentPath->isEmpty() == false) {
        qDebug() << this->currentPath->isEmpty();
        this->currentPath->draw(&painter);
    }

}

void MainWindow::resizeEvent(QResizeEvent *event) {
    qDebug() << "resize - old size:" << event->oldSize() << " New size: " << event->size();

}

void MainWindow::wheelEvent(QWheelEvent *event) {
    qDebug() << "Wheel - angleDelta:" << event->angleDelta() << " nverted: " << event->inverted() << " phase: " << event->phase() << " pixelDelta: " << event->pixelDelta();
}
