
#include "widget.h"
#include "./ui_widget.h"
#include<QDebug>
#include<cstdlib>
#include<ctime>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Set up the seed
    std::srand(std::time(nullptr));

    //Generate Number (1-10)
    secret_number = std::rand() % 10 + 1;
    qDebug() << "Secret Number Generated: " << QString::number(secret_number);

    //Desable the Start Over Button
    ui->startOverButton->setDisabled(true);

    ui->messageLabel->setText("");
}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_guessButton_clicked()
{
    guess_number = ui->numberSpinbox->value();
    qDebug() << "User Guessed: " << QString::number(guess_number);

    //Check if the User guessed right
    if(guess_number == secret_number)
    {
        //Show the congratulations message
        ui->messageLabel->setText("Congratulations, the number is " + QString::number(guess_number));

        //Button Housekeeping
        ui->guessButton->setDisabled(true);
        ui->startOverButton->setDisabled(false);
    }
    else
    {
        if(secret_number < guess_number)
        {
            ui->messageLabel->setText("Number is lower than that.");
        }
        if(secret_number > guess_number)
        {
            ui->messageLabel->setText("Number is greater than that.");
        }
    }
}


void Widget::on_startOverButton_clicked()
{
    //Enable the Guess Button
    ui->guessButton->setDisabled(false);

    //Disable the Start Over Button
    ui->startOverButton->setDisabled(true);

    //Put the spin box back to 1
    ui->numberSpinbox->setValue(1);

    //Regenerate the Random Number
    secret_number = std::rand() % 10 + 1;

    //Clear the message label
    ui->messageLabel->setText("");
}

