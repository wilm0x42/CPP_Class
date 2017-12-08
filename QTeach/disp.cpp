#include "disp.h"
#include "ui_disp.h"

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
    this->ui->label->setPixmap(pic);
}

void Disp::setFullscreen(bool onoff)
{
    if (onoff == true)
        this->showFullScreen();
    else
        this->showNormal();
}
