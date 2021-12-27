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
#include "Tools/pentool.h"
#include "Tools/circletool.h"
#include "Tools/linetool.h"

#include <QApplication>
#include <QPushButton>
#include <QBoxLayout>
#include <QLayout>
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
#include <QMenuBar>
#include <QMenu>
#include <QMetaMethod>

#include <functional>

void test() {
    QColorDialog colorDialog(Qt::black, nullptr);
    QColor color;
    if (colorDialog.exec() == QColorDialog::Accepted) {
        color = colorDialog.currentColor();
    }
    qDebug() << color;
}

void addButton(MainWindow &window, QBoxLayout &layout, std::shared_ptr<Tool>& tool, const std::function <void ()>& onClick) {
    QPushButton *button = new QPushButton(&window);
    button->setFixedSize(40, 40);
    button->setText(tool->getName());
    button->connect(button, &QPushButton::clicked, &layout, onClick);
    layout.addWidget(button);
}

#include <memory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow window;
    // window.menuBar()->hide();
    // QMenuBar menubar(&window);
    // QMenu fileMenu("File", &menubar);

    window.setContextMenuPolicy(Qt::CustomContextMenu);

    QWidget toolbox(&window);

    toolbox.setWindowTitle("Toolbox");
    toolbox.setWindowFlags(Qt::Tool);
    toolbox.setMinimumSize(QSize(100,100));


    QBoxLayout toolboxLayout = QBoxLayout(QBoxLayout::Direction::LeftToRight, &toolbox);
    toolboxLayout.setAlignment(Qt::AlignLeft | Qt::AlignTop);
    toolboxLayout.setDirection(QBoxLayout::LeftToRight);

    std::shared_ptr<Tool> tools[3];
    // Tool* tools[3];
    tools[0] = std::shared_ptr<Tool>(new PenTool(window));
    tools[1] = std::shared_ptr<Tool>(new CircleTool(window));
    tools[2] = std::shared_ptr<Tool>(new LineTool(window));

    for (int i = 0; i < 3; ++i) {
        addButton(window, toolboxLayout, tools[i], [&window, &tools, i]() -> void {
            window.setActiveTool(tools[i]);
        });
    }

    QWidget toolOptionWindow(&window);
    toolOptionWindow.setWindowTitle("Tool Options");
    toolOptionWindow.setWindowFlags(Qt::Tool);

    QBoxLayout toolOptionLayout = QBoxLayout(QBoxLayout::Direction::TopToBottom, &toolOptionWindow);
    toolOptionLayout.setAlignment(Qt::AlignLeft | Qt::AlignTop);
    QSlider slider(Qt::Orientation::Horizontal, &toolOptionWindow);
    slider.setTickInterval(1);
    slider.setTickPosition(QSlider::TickPosition::NoTicks);
    slider.connect(&slider, &QSlider::valueChanged, &toolOptionWindow, [&]() {
        qDebug() << slider.value();
    });
    toolOptionLayout.addWidget(&slider);
    QPushButton b = QPushButton(&toolOptionWindow);
    b.setMinimumHeight(20);
    QColor buttonColor(0, 0, 0);

    b.setStyleSheet("QPushButton { background-color:" + QVariant(buttonColor).toString() + "; border: none; }");
    toolOptionLayout.addWidget(&b);

    b.connect(&b, &QAbstractButton::clicked, &toolOptionWindow, [&]() {
        QColorDialog colorDialog(buttonColor, nullptr);
        if (colorDialog.exec() == QColorDialog::Accepted) {
            buttonColor = colorDialog.currentColor();
        }
        b.setStyleSheet("QPushButton { background-color:" + QVariant(buttonColor).toString() + "; border: none; }");
     });

    window.show();
    toolbox.show();
    toolOptionWindow.show();

    toolbox.move(window.pos() - QPoint(toolbox.width() + 50, 0));
    toolOptionWindow.move(window.pos() + QPoint(window.width() + 50, 0));

    return a.exec();
}

