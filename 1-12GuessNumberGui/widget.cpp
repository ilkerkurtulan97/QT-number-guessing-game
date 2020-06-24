#include "widget.h"
#include "ui_widget.h"
#include <stdlib.h>
#include <time.h>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    srand(time(NULL));

    secretNumber = rand() %10 + 1;
    qDebug() <<"Secret Number generated : "<<QString::number(secretNumber);

    ui->startOverButton->setDisabled(true);

    ui->messageLabel->setText("");

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_guessButton_clicked()
{
    guessNumber = ui->spinBox->value();
    qDebug()<<"The guess number is :"<<QString::number(guessNumber);

    if (guessNumber == secretNumber)
    {
        ui->messageLabel->setText("Congratulations, your number is : "+QString::number(secretNumber));

        //Disabling the guess button
        ui->guessButton->setDisabled(true);
        ui->startOverButton->setDisabled(false);
    }
    else
    {
        if(secretNumber < guessNumber)
        {
            ui->messageLabel->setText("Number is higher than that");
        }

        if(secretNumber > guessNumber)
        {
            ui->messageLabel->setText("Number is lower than that");
        }
    }
}

void Widget::on_startOverButton_clicked()
{
    ui->guessButton->setDisabled(false);

    ui->startOverButton->setDisabled(true);

    ui->spinBox->setValue(1);

    secretNumber = rand() % 10 +1;

    ui->messageLabel->setText("");
}
