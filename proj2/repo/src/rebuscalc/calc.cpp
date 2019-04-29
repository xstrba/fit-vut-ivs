/** @mainpage RebusCalculator
* \section intro_sec Introduction
* RebusCalculator is 2nd project for course "Practical Aspects of Software Design".
* \subsection  Header_Files
* <p>
* Link for mathematical library header file. It consists of
* functions needed to perform calculations & string manipulation.
* </p>
* @link
* math_lib.h
* @endlink
* <p>Link for main window header file, which is for Graphical user interface. It consists of
* abstract groups of functions for manipulation with GUI calculator.</p>
* @link
* mainwindow.h
* @endlink
* \subsection  Additional_information
* @version 1.2
* @date 2019/04/08
* @author
*          Branislav Dubec <xdubec01>\n
*          Andrej Jezik <xjezik03>\n
*          Tibor Kubik <xkubik34>\n
*          Boris Strbak <xstrba05>
*
*
* ======== Copyright (c) 2019, Rebus Calc, Inc. , All rights reserved. ============
*/
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::setlocale(LC_ALL, "en_US.UTF-8");
    MainWindow w;
    w.show();
    return a.exec();
}
