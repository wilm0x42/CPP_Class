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

void Disp::setText(QString text, int tsize)
{
    this->ui->label->setText(text);
    QFont font = this->ui->label->font();
    font.setPointSize(tsize);
    this->ui->label->setFont(font);
}

void Disp::setImg(QPixmap pic)
{
    int w = this->ui->label->width();
    int h = this->ui->label->height();

    this->ui->label->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));
}

void Disp::setFullscreen(bool onoff)
{
    if (onoff == true)
        this->showFullScreen();
    else
        this->showNormal();
}
