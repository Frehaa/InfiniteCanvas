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
#include "pentoolbutton.h"
#include "circletoolbutton.h"

#include <QApplication>
#include <QPushButton>
#include <QBoxLayout>
#include <QSlider>
#include <QColorDialog>

/*
QTranslator translator;
const QStringList uiLanguages = QLocale::system().uiLanguages();
for (const QString &locale : uiLanguages) {
    const QString baseName = "QtHelloWorld_" + QLocale(locale).name();
    if (translator.load(":/i18n/" + baseName)) {
        a.installTranslator(&translator);
        break;
    }
}
*/

#include <QPushButton>
#include <QObject>

void test() {
    QColorDialog colorDialog(Qt::black, nullptr);
    colorDialog.show();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow window;
    QWidget toolbox;
    QWidget toolOptionWindow;

    QLayout *layout = new QBoxLayout(QBoxLayout::Direction::LeftToRight, &toolbox);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    PenToolButton penButton = PenToolButton(&window);
    layout->addWidget(&penButton);
    CircleToolButton circleButton = CircleToolButton(&window);
    layout->addWidget(&circleButton);

    QPushButton b = QPushButton(&toolOptionWindow);

    QSlider slider(Qt::Orientation::Horizontal, &toolOptionWindow);


    window.show();
    toolbox.show();
    toolOptionWindow.show();
    return a.exec();
}

