/*
    HyperRoam - CybeRoam client with automatic account switching
    Copyright (C) 2009-10  Ravi Vagadia

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
//Qt
#include <QtGui/QApplication>
#include <QIcon>
#include <QPixmap>
//HypeRoam
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QIcon icon(":/icons/app");
    Widget w;
    w.setWindowTitle("HypeRoam");
    w.show();
    a.setApplicationName("HypeRoam");
    a.setWindowIcon(icon);
    a.setApplicationVersion("0.2 PreBeta");
    a.setOrganizationName("Invalid Technologies");
    a.setQuitOnLastWindowClosed(false);
    return a.exec();
}
