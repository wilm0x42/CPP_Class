#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QShortcut>
#include <QProcess>
#include <QTime>
#include <QTimer>
#include "disp.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void showText();
    void showImg(QPixmap pic);
    void toggleFullscreen();
    void takeScreenshot();
    void screenshotReady(int,QProcess::ExitStatus);
    void showTime();
    void killScreenshot();

private:
    Ui::MainWindow *ui;
    Disp* display;
    bool dispFullscreen;
    QShortcut* ctrlEnter;
    QShortcut* escape;
};

#endif // MAINWINDOW_H
