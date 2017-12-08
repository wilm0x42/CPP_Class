#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("QTeach");

    display = new Disp();
    dispFullscreen = false;
    display->show();

    connect(ui->textButton, SIGNAL (released()), this,SLOT(showText()));
    connect(ui->imgButton, SIGNAL (released()), this, SLOT(takeScreenshot()));
    connect(ui->fullscreenButton, SIGNAL (released()), this, SLOT (toggleFullscreen()));

    ctrlEnter = new QShortcut(QKeySequence("Ctrl+Return"), this);
    connect(ctrlEnter, SIGNAL(activated()), SLOT(showText()));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showText()
{
   display->setText(ui->textEdit->toPlainText());
}

void MainWindow::showImg(QPixmap pic)
{
    display->setImg(pic);
}

void MainWindow::takeScreenshot()
{
    QProcess* process = new QProcess();
    process->start("bash", QStringList() << "-c" << "xfce4-screenshooter -r -o cat > screenshot.png");
    connect(process, SIGNAL (finished(int,QProcess::ExitStatus)), this, SLOT (screenshotReady(int,QProcess::ExitStatus)));
}
void MainWindow::screenshotReady(int ret,QProcess::ExitStatus stat)
{
    if (ret == 0 && stat == QProcess::NormalExit)
    {
        QPixmap pic("screenshot.png");
        showImg(pic);
    }
}

void MainWindow::toggleFullscreen()
{
    dispFullscreen = !dispFullscreen;
    display->setFullscreen(dispFullscreen);
}
