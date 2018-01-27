#ifndef DISP_H
#define DISP_H

#include <QDialog>
#include <QPixmap>
#include <QFont>

namespace Ui {
class Disp;
}

class Disp : public QDialog
{
    Q_OBJECT

public:
    explicit Disp(QWidget *parent = 0);
    ~Disp();

    void setText(QString text, int tsize);
    void setImg(QPixmap pic);
    void setFullscreen(bool onoff);

private:
    Ui::Disp *ui;
};

#endif // DISP_H
