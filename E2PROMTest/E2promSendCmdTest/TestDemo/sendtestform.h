#ifndef SENDTESTFORM_H
#define SENDTESTFORM_H

#include <QWidget>

namespace Ui {
class SendTestForm;
}

class SendTestForm : public QWidget
{
    Q_OBJECT

public:
    explicit SendTestForm(QWidget *parent = nullptr);
    ~SendTestForm();

private:
    Ui::SendTestForm *ui;
};

#endif // SENDTESTFORM_H
