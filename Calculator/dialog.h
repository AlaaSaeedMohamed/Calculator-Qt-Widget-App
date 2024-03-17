#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT
    bool calculate(double rightOperand, const QString &pendingOperator);
    void abortOperation();

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_btnClear_clicked();

    void on_btnZero_clicked();

    void on_btnOne_clicked();

    void on_btnTwo_clicked();

    void on_btnThree_clicked();

    void on_btnFour_clicked();

    void on_btnFive_clicked();

    void on_btnSix_clicked();

    void on_btnSeven_clicked();

    void on_btnEight_clicked();

    void on_btnNine_clicked();

    void on_btnPlus_clicked();

    void on_btnMinus_clicked();

    void on_btnDivide_clicked();

    void on_btnMultiply_clicked();

    void on_btnEqual_clicked();


    void on_pushButton_2_released();

    void on_Unary_Operator_pressed();


    void on_btnPercent_pressed();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
