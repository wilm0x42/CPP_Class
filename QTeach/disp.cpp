#include "disp.h"
#include "ui_disp.h"

#include <iostream>

Disp::Disp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Disp)
{
    ui->setupUi(this);
    setWindowTitle("Pay no attention to this window toolbar");
}

Disp::~Disp()
{
    delete ui;
}

void Disp::setText(QString text)
{
    this->ui->label->setText(text);
}

void Disp::setImg(QPixmap pic)
{
    //SDL_GetWindowSize(presentWindow, &ww, &wh);
    int ww = this->window()->width();
    int wh = this->window()->height();

    std::cout << pic.height() << " - " << pic.width() << "\n";
    this->ui->label->setPixmap(pic);

    if (pic.width() >= pic.height())
    {
        int height = ww * ((double)pic.height()/(double)pic.width());
        //scrShotRect = {0, (wh/2)-(height/2), ww, height};
        this->ui->label->setGeometry(0, (wh/2)-(height/2), ww, height);
    }
    else
    {
        int width = wh * ((double)pic.width()/(double)pic.height());
        //scrShotRect = {(ww/2)-(width/2), 0, width, wh};
        this->ui->label->setGeometry((ww/2)-(width/2), 0, width, wh);
        this->ui->label->resize(width, wh);
        this->resize(ww, wh);
    }
}

void Disp::setFullscreen(bool onoff)
{
    if (onoff == true)
        this->showFullScreen();
    else
        this->showNormal();
}
