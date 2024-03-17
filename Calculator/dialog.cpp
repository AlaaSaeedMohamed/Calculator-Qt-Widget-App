#include "dialog.h"
#include "./ui_dialog.h"

double sumSoFar = 0.0;
double factorSoFar= 0.0;  //for multiplication and division
QString pendingAdditiveOperator;
QString pendingMultiplicativeOperator;
bool waitingForOperand = true;


double fNum;

QString res = "";

bool is_equal_pressed = false;


bool Dialog::calculate(double rightOperand, const QString &pendingOperator)
{
    if (pendingOperator == "+") {
        sumSoFar += rightOperand;
    } else if (pendingOperator == "-") {
        sumSoFar -= rightOperand;
    } else if (pendingOperator == "*") {
        factorSoFar *= rightOperand;
    } else if (pendingOperator == "/") {
        if (rightOperand == 0.0)
        {
            QMessageBox::critical(this, "Error", "Can't divide by zero!!");
            return false;
        }
        factorSoFar /= rightOperand;
    }
    return true;
}

void Dialog::abortOperation()
{
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    pendingAdditiveOperator.clear();
    pendingMultiplicativeOperator.clear();
    ui->label->setText("0");
    waitingForOperand = true;
    ui->label->setText(tr("####"));
}

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnClear_clicked()
{

    ui->String_Label->clear();
    ui->label->clear();

}


void Dialog::on_btnZero_clicked()
{
    if(is_equal_pressed)
    {
        ui->label->clear();
        ui->String_Label->clear();
        is_equal_pressed = false;
    }

    if (waitingForOperand) {
        ui->label->clear();
        waitingForOperand = false;
    }

    ui->String_Label->setText(ui->String_Label->text().append(ui->btnZero->text()));
    ui->label->setText(ui->label->text().append(ui->btnZero->text()));
}


void Dialog::on_btnOne_clicked()
{
    if(is_equal_pressed)
    {
        ui->label->clear();
        ui->String_Label->clear();
        is_equal_pressed = false;
    }

    if (waitingForOperand) {
        ui->label->clear();
        waitingForOperand = false;
    }
    ui->String_Label->setText(ui->String_Label->text().append(ui->btnOne->text()));
    ui->label->setText(ui->label->text().append(ui->btnOne->text()));
}


void Dialog::on_btnTwo_clicked()
{
    if(is_equal_pressed)
    {
        ui->label->clear();
        ui->String_Label->clear();
        is_equal_pressed = false;
    }

    if (waitingForOperand) {
        ui->label->clear();
        waitingForOperand = false;
    }
    ui->String_Label->setText(ui->String_Label->text().append(ui->btnTwo->text()));
    ui->label->setText(ui->label->text().append(ui->btnTwo->text()));
}


void Dialog::on_btnThree_clicked()
{
    if(is_equal_pressed)
    {
        ui->label->clear();
        ui->String_Label->clear();
        is_equal_pressed = false;
    }

    if (waitingForOperand) {
        ui->label->clear();
        waitingForOperand = false;
    }
    ui->String_Label->setText(ui->String_Label->text().append(ui->btnThree->text()));
    ui->label->setText(ui->label->text().append(ui->btnThree->text()));
}

void Dialog::on_btnFour_clicked()
{
    if(is_equal_pressed)
    {
        ui->label->clear();
        ui->String_Label->clear();
        is_equal_pressed = false;
    }

    if (waitingForOperand) {
        ui->label->clear();
        waitingForOperand = false;
    }
    ui->String_Label->setText(ui->String_Label->text().append(ui->btnFour->text()));
    ui->label->setText(ui->label->text().append(ui->btnFour->text()));
}


void Dialog::on_btnFive_clicked()
{
    if(is_equal_pressed)
    {
        ui->label->clear();
        ui->String_Label->clear();
        is_equal_pressed = false;
    }

    if (waitingForOperand) {
        ui->label->clear();
        waitingForOperand = false;
    }
    ui->String_Label->setText(ui->String_Label->text().append(ui->btnFive->text()));
    ui->label->setText(ui->label->text().append(ui->btnFive->text()));
}


void Dialog::on_btnSix_clicked()
{
    if(is_equal_pressed)
    {
        ui->label->clear();
        ui->String_Label->clear();
        is_equal_pressed = false;
    }

    if (waitingForOperand) {
        ui->label->clear();
        waitingForOperand = false;
    }
    ui->String_Label->setText(ui->String_Label->text().append(ui->btnSix->text()));
    ui->label->setText(ui->label->text().append(ui->btnSix->text()));
}


void Dialog::on_btnSeven_clicked()
{
    if(is_equal_pressed)
    {
        ui->label->clear();
        ui->String_Label->clear();
        is_equal_pressed = false;
    }

    if (waitingForOperand) {
        ui->label->clear();
        waitingForOperand = false;
    }
    ui->String_Label->setText(ui->String_Label->text().append(ui->btnSeven->text()));
    ui->label->setText(ui->label->text().append(ui->btnSeven->text()));
}


void Dialog::on_btnEight_clicked()
{
    if(is_equal_pressed)
    {
        ui->label->clear();
        ui->String_Label->clear();
        is_equal_pressed = false;
    }

    if (waitingForOperand) {
        ui->label->clear();
        waitingForOperand = false;
    }
    ui->String_Label->setText(ui->String_Label->text().append(ui->btnEight->text()));
    ui->label->setText(ui->label->text().append(ui->btnEight->text()));
}


void Dialog::on_btnNine_clicked()
{
    if(is_equal_pressed)
    {
        ui->label->clear();
        ui->String_Label->clear();
        is_equal_pressed = false;
    }

    if (waitingForOperand) {
        ui->label->clear();
        waitingForOperand = false;
    }
    ui->String_Label->setText(ui->String_Label->text().append(ui->btnNine->text()));
    ui->label->setText(ui->label->text().append(ui->btnNine->text()));
}


void Dialog::on_btnPlus_clicked()
{
    // ui->btnPlus->setChecked(true);

        ui->String_Label->setText(ui->String_Label->text().append(ui->btnPlus->text()));


    double operand = ui->label->text().toDouble();


    if (!pendingMultiplicativeOperator.isEmpty()) {  // to calculate multiplication or division first
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        ui->label->setText(QString::number(factorSoFar));
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }


    if (!pendingAdditiveOperator.isEmpty()) {
        if (!calculate(operand, pendingAdditiveOperator)) {  // if there is no pending additive operator then sum_so_far is the text in label
            abortOperation();
            return;
        }
        ui->label->setText(QString::number(sumSoFar));
    }
    else
    {
        sumSoFar = operand;  //else if the pending additive operator is not empty then sum_so_far is the left operand and we are aiting for another operand
    }

    pendingAdditiveOperator = '+';
    waitingForOperand = true;
    // ui->label->setText("");
}


void Dialog::on_btnMinus_clicked()
{

        ui->String_Label->setText(ui->String_Label->text().append(ui->btnMinus->text()));


    double operand = ui->label->text().toDouble();


    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        ui->label->setText(QString::number(factorSoFar));
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }


    if (!pendingAdditiveOperator.isEmpty()) {
        if (!calculate(operand, pendingAdditiveOperator)) {
            abortOperation();
            return;
        }
        ui->label->setText(QString::number(sumSoFar));
    }
    else
    {
        sumSoFar = operand;
    }

    pendingAdditiveOperator = '-';
    waitingForOperand = true;
}


void Dialog::on_btnDivide_clicked()
{

        ui->String_Label->setText(ui->String_Label->text().append(ui->btnDivide->text()));

    double operand = ui->label->text().toDouble();

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        ui->label->setText(QString::number(factorSoFar));
    } else {
        factorSoFar = operand;
    }

    pendingMultiplicativeOperator = '/';
    waitingForOperand = true;
}


void Dialog::on_btnMultiply_clicked()
{

        ui->String_Label->setText(ui->String_Label->text().append(ui->btnMultiply->text()));


    double operand = ui->label->text().toDouble();

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        ui->label->setText(QString::number(factorSoFar));
    } else {
        factorSoFar = operand;
    }

    pendingMultiplicativeOperator = '*';
    waitingForOperand = true;
}


void Dialog::on_btnEqual_clicked()
{
    is_equal_pressed = true;

    ui->String_Label->setText(ui->String_Label->text().append(ui->btnEqual->text()));


    double operand = ui->label->text().toDouble();

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }
    if (!pendingAdditiveOperator.isEmpty()) {
        if (!calculate(operand, pendingAdditiveOperator)) {
            abortOperation();
            return;
        }
        pendingAdditiveOperator.clear();
    } else {
        sumSoFar = operand;
    }

    ui->label->setText(QString::number(sumSoFar));
    sumSoFar = 0.0;
    waitingForOperand = true;

}


void Dialog::on_pushButton_2_released()
{
    if(!ui->label->text().contains('.'))
    {
        ui->label->setText(ui->label->text().append("."));
        ui->String_Label->setText(ui->String_Label->text().append("."));
    }
}


void Dialog::on_Unary_Operator_pressed()
{
    double number;
    QString newNumber;

    number = ui->label->text().toDouble();
    number = number * -1;
    newNumber = QString :: number(number, 'g', 15);
    ui->label->setText(newNumber);
}


void Dialog::on_btnPercent_pressed()
{
    double number;
    QString newNumber;

    number = ui->label->text().toDouble();
    number = number * 0.01;
    newNumber = QString :: number(number, 'g', 15);
    ui->label->setText(newNumber);
}

