#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<bits/stdc++.h>
#include "math_lib.cpp"
#include <limits.h>
#include <float.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   connect(ui->pushButton_0, SIGNAL(released()), this, SLOT(digit_pressed()));
   connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(digit_pressed()));
   connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(digit_pressed()));
   connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(digit_pressed()));
   connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(digit_pressed()));
   connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(digit_pressed()));
   connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(digit_pressed()));
   connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(digit_pressed()));
   connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(digit_pressed()));
   connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(digit_pressed()));
}

MainWindow::~MainWindow()
{
   delete ui;
}

bool MainWindow::areParanthesisBalanced(QString expr)
{
    int nmb = 0;

    for (int i=0; i<expr.length(); i++)
    {
        if (expr[i]=='('){
            nmb++;
            continue;
        }

        if (expr[i]==')') {
            nmb--;
        }
    }
    if(nmb > 0)
        return true;
        else
            return false;
}

void MainWindow::digit_pressed() {
    lastPressedEquals = false;
    if(ui->temp_text->text().length() > 28)
        return;
   QPushButton * button = (QPushButton*)sender(); //returns pointer to qObject

   //double labelNumber;
   //QString nLabel;

   //labelNumber = (ui->temp_text->text() + button->text()); //reads text from button[digit] and displays it

   //nLabel = QString::number(labelNumber, 'g', 15);
   if(ui->temp_text->text() == "0"){
     ui->temp_text->setText(button->text());
   }
   else{
     ui->temp_text->setText(ui->temp_text->text() + button->text());
   }
}

void MainWindow::on_pushButton_comma_released() {
    lastPressedEquals = false;
    if(ui->temp_text->text().length() > 30)
        return;
    ui->temp_text->setText(ui->temp_text->text() + ".");
}

void MainWindow::on_pushButton_br_left_released() {
    lastPressedEquals = false;
    if(ui->temp_text->text().length() > 30)
        return;

    if(ui->temp_text->text() == "0"){
        ui->temp_text->setText("(");
    }
    else {
        ui->temp_text->setText(ui->temp_text->text() + "(");
    }
}

void MainWindow::on_pushButton_br_right_released() {
    lastPressedEquals = false;
    if(ui->temp_text->text().length() > 30)
        return;
    if(areParanthesisBalanced(ui->temp_text->text()) == true){
        ui->temp_text->setText(ui->temp_text->text() + ")");
    }
}

void MainWindow::on_pushButton_C_released(){
    lastPressedEquals = false;
    ui->temp_text->setText("0");
    ui->result->setText("0");
}

void MainWindow::on_pushButton_fact_released() {
    lastPressedEquals = false;
    if(ui->temp_text->text().length() > 30)
        return;
    ui->temp_text->setText(ui->temp_text->text() + "!");
}

void MainWindow::on_pushButton_mod_released() {
    lastPressedEquals = false;
    if(ui->temp_text->text().length() > 30)
        return;
    if(ui->temp_text->text() == "0") {
        return;
    }
    ui->temp_text->setText(ui->temp_text->text() + "%");
}

void MainWindow::on_pushButton_div_released() {
    lastPressedEquals = false;
    if(ui->temp_text->text().length() > 30)
        return;
    if(ui->temp_text->text() == "0") {
        return;
    }
    ui->temp_text->setText(ui->temp_text->text() + "/");
}

void MainWindow::on_pushButton_mul_released() {
    lastPressedEquals = false;
    if(ui->temp_text->text().length() > 30)
        return;
    if(ui->temp_text->text() == "0") {
        return;
    }
    ui->temp_text->setText(ui->temp_text->text() + "*");
}

void MainWindow::on_pushButton_plus_released() {
    lastPressedEquals = false;
    if(ui->temp_text->text().length() > 30)
        return;
    if(ui->temp_text->text() == "0") {
        return;
    }
    ui->temp_text->setText(ui->temp_text->text() + "+");
}

void MainWindow::on_pushButton_minus_released() {
    lastPressedEquals = false;
    if(ui->temp_text->text().length() > 30)
        return;
    if(ui->temp_text->text() == "0") {
        ui->temp_text->setText("-");
    }
    else{
        ui->temp_text->setText(ui->temp_text->text() + "-");
    }
}

void MainWindow::on_pushButton_sin_released() {
    lastPressedEquals = false;
    if(ui->temp_text->text().length() > 28)
        return;
    if(ui->temp_text->text() == "0") {
        ui->temp_text->setText("sin(");
    }
    else{
        ui->temp_text->setText(ui->temp_text->text() + "sin(");
    }
}

void MainWindow::on_pushButton_cos_released() {
    lastPressedEquals = false;
    if(ui->temp_text->text().length() > 28)
        return;
    if(ui->temp_text->text() == "0") {
        ui->temp_text->setText("cos(");
    }
    else{
        ui->temp_text->setText(ui->temp_text->text() + "cos(");
    }
}

void MainWindow::on_pushButton_sqrt_released() {
    lastPressedEquals = false;
    if(ui->temp_text->text().length() > 27)
        return;
    if(ui->temp_text->text() == "0") {
        ui->temp_text->setText("sqrt(");
    }
    else {
        ui->temp_text->setText(ui->temp_text->text() + "sqrt(");
    }
}

void MainWindow::on_pushButton_del_released() {
    lastPressedEquals = false;
    QString s = ui->temp_text->text();
    QString modified = s;
    modified.chop(1);
    if(modified.endsWith('n') || modified.endsWith('s')) {
        s.chop(4);
        if(s.length() == 0) {
            ui->temp_text->setText("0");
        }
    }
    else if(modified.endsWith('t')){
        s.chop(5);
        if(s.length() == 0) {
            ui->temp_text->setText("0");
        }
    }
    else{
        s.chop(1);
    }

    if(ui->temp_text->text().length() > 1) {
        ui->temp_text->setText(s);
    }
    else {
        ui->temp_text->setText("0");
    }
}

void MainWindow::on_pushButton_pow_released() {
    lastPressedEquals = false;
    if(ui->temp_text->text().length() > 30)
        return;
    if(ui->temp_text->text() == "0") {
        return;
    }
    ui->temp_text->setText(ui->temp_text->text() + "^");

}

void MainWindow::on_pushButton_equals_released() {

    QString a = ui->temp_text->text();
    QByteArray inBytes = a.toLocal8Bit();
    const char* cStrData = inBytes.data();
    lastPressedEquals = true;
    int aca = isValidInput(cStrData);
    if(aca == -1){
        ui->result->setText("error");
    }
    else{
        if(result(cStrData) == MAXFLOAT){
            ui->result->setText("error");
        }
       else{
//        std::cout << "num is " << num << "\n";
        QString valueAsString = QString::number(result(cStrData));
        ui->result->setText(valueAsString);
       }
    }
}

void MainWindow::on_pushButton_ans_released() {
    if(ui->result->text() != "error"){
        if(lastPressedEquals){
            ui->temp_text->setText(ui->result->text());
        }
        else{
            ui->temp_text->setText(ui->temp_text->text() + ui->result->text());
        }
    }
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    if(checked){
        ui->temp_text->setProperty("light_theme", true);
        ui->temp_text->style()->unpolish(ui->temp_text);
        ui->temp_text->style()->polish(ui->temp_text);

        ui->result->setProperty("light_theme", true);
        ui->result->style()->unpolish(ui->result);
        ui->result->style()->polish(ui->result);

        ui->eq->setProperty("light_theme", true);
        ui->eq->style()->unpolish(ui->eq);
        ui->eq->style()->polish(ui->eq);

        ui->pushButton_C->setProperty("light_theme", true);
        ui->pushButton_C->style()->unpolish(ui->pushButton_C);
        ui->pushButton_C->style()->polish(ui->pushButton_C);

        ui->pushButton_del->setProperty("light_theme", true);
        ui->pushButton_del->style()->unpolish(ui->pushButton_del);
        ui->pushButton_del->style()->polish(ui->pushButton_del);

        ui->pushButton_mod->setProperty("light_theme", true);
        ui->pushButton_mod->style()->unpolish(ui->pushButton_mod);
        ui->pushButton_mod->style()->polish(ui->pushButton_mod);

        ui->pushButton_br_left->setProperty("light_theme", true);
        ui->pushButton_br_left->style()->unpolish(ui->pushButton_br_left);
        ui->pushButton_br_left->style()->polish(ui->pushButton_br_left);

        ui->pushButton_br_right->setProperty("light_theme", true);
        ui->pushButton_br_right->style()->unpolish(ui->pushButton_br_right);
        ui->pushButton_br_right->style()->polish(ui->pushButton_br_right);

        ui->pushButton_sqrt->setProperty("light_theme", true);
        ui->pushButton_sqrt->style()->unpolish(ui->pushButton_sqrt);
        ui->pushButton_sqrt->style()->polish(ui->pushButton_sqrt);

        ui->pushButton_pow->setProperty("light_theme", true);
        ui->pushButton_pow->style()->unpolish(ui->pushButton_pow);
        ui->pushButton_pow->style()->polish(ui->pushButton_pow);

        ui->pushButton_sin->setProperty("light_theme", true);
        ui->pushButton_sin->style()->unpolish(ui->pushButton_sin);
        ui->pushButton_sin->style()->polish(ui->pushButton_sin);

        ui->pushButton_cos->setProperty("light_theme", true);
        ui->pushButton_cos->style()->unpolish(ui->pushButton_cos);
        ui->pushButton_cos->style()->polish(ui->pushButton_cos);

        ui->pushButton_fact->setProperty("light_theme", true);
        ui->pushButton_fact->style()->unpolish(ui->pushButton_fact);
        ui->pushButton_fact->style()->polish(ui->pushButton_fact);

        ui->pushButton_ans->setProperty("light_theme", true);
        ui->pushButton_ans->style()->unpolish(ui->pushButton_ans);
        ui->pushButton_ans->style()->polish(ui->pushButton_ans);

        ui->pushButton_0->setProperty("light_theme", true);
        ui->pushButton_0->style()->unpolish(ui->pushButton_0);
        ui->pushButton_0->style()->polish(ui->pushButton_0);

        ui->pushButton_1->setProperty("light_theme", true);
        ui->pushButton_1->style()->unpolish(ui->pushButton_1);
        ui->pushButton_1->style()->polish(ui->pushButton_1);

        ui->pushButton_2->setProperty("light_theme", true);
        ui->pushButton_2->style()->unpolish(ui->pushButton_2);
        ui->pushButton_2->style()->polish(ui->pushButton_2);

        ui->pushButton_3->setProperty("light_theme", true);
        ui->pushButton_3->style()->unpolish(ui->pushButton_3);
        ui->pushButton_3->style()->polish(ui->pushButton_3);

        ui->pushButton_4->setProperty("light_theme", true);
        ui->pushButton_4->style()->unpolish(ui->pushButton_4);
        ui->pushButton_4->style()->polish(ui->pushButton_4);

        ui->pushButton_5->setProperty("light_theme", true);
        ui->pushButton_5->style()->unpolish(ui->pushButton_5);
        ui->pushButton_5->style()->polish(ui->pushButton_5);

        ui->pushButton_6->setProperty("light_theme", true);
        ui->pushButton_6->style()->unpolish(ui->pushButton_6);
        ui->pushButton_6->style()->polish(ui->pushButton_6);

        ui->pushButton_7->setProperty("light_theme", true);
        ui->pushButton_7->style()->unpolish(ui->pushButton_7);
        ui->pushButton_7->style()->polish(ui->pushButton_7);

        ui->pushButton_8->setProperty("light_theme", true);
        ui->pushButton_8->style()->unpolish(ui->pushButton_8);
        ui->pushButton_8->style()->polish(ui->pushButton_8);

        ui->pushButton_9->setProperty("light_theme", true);
        ui->pushButton_9->style()->unpolish(ui->pushButton_9);
        ui->pushButton_9->style()->polish(ui->pushButton_9);

        ui->pushButton_div->setProperty("light_theme", true);
        ui->pushButton_div->style()->unpolish(ui->pushButton_div);
        ui->pushButton_div->style()->polish(ui->pushButton_div);

        ui->pushButton_mul->setProperty("light_theme", true);
        ui->pushButton_mul->style()->unpolish(ui->pushButton_mul);
        ui->pushButton_mul->style()->polish(ui->pushButton_mul);

        ui->pushButton_plus->setProperty("light_theme", true);
        ui->pushButton_plus->style()->unpolish(ui->pushButton_plus);
        ui->pushButton_plus->style()->polish(ui->pushButton_plus);

        ui->pushButton_minus->setProperty("light_theme", true);
        ui->pushButton_minus->style()->unpolish(ui->pushButton_minus);
        ui->pushButton_minus->style()->polish(ui->pushButton_minus);

        ui->pushButton_comma->setProperty("light_theme", true);
        ui->pushButton_comma->style()->unpolish(ui->pushButton_comma);
        ui->pushButton_comma->style()->polish(ui->pushButton_comma);

        ui->pushButton_equals->setProperty("light_theme", true);
        ui->pushButton_equals->style()->unpolish(ui->pushButton_equals);
        ui->pushButton_equals->style()->polish(ui->pushButton_equals);
    }
    else{
        ui->temp_text->setProperty("light_theme", false);
        ui->temp_text->style()->unpolish(ui->temp_text);
        ui->temp_text->style()->polish(ui->temp_text);

        ui->result->setProperty("light_theme", false);
        ui->result->style()->unpolish(ui->result);
        ui->result->style()->polish(ui->result);

        ui->eq->setProperty("light_theme", false);
        ui->eq->style()->unpolish(ui->eq);
        ui->eq->style()->polish(ui->eq);

        ui->pushButton_C->setProperty("light_theme", false);
        ui->pushButton_C->style()->unpolish(ui->pushButton_C);
        ui->pushButton_C->style()->polish(ui->pushButton_C);

        ui->pushButton_del->setProperty("light_theme", false);
        ui->pushButton_del->style()->unpolish(ui->pushButton_del);
        ui->pushButton_del->style()->polish(ui->pushButton_del);

        ui->pushButton_mod->setProperty("light_theme", false);
        ui->pushButton_mod->style()->unpolish(ui->pushButton_mod);
        ui->pushButton_mod->style()->polish(ui->pushButton_mod);

        ui->pushButton_br_left->setProperty("light_theme", false);
        ui->pushButton_br_left->style()->unpolish(ui->pushButton_br_left);
        ui->pushButton_br_left->style()->polish(ui->pushButton_br_left);

        ui->pushButton_br_right->setProperty("light_theme", false);
        ui->pushButton_br_right->style()->unpolish(ui->pushButton_br_right);
        ui->pushButton_br_right->style()->polish(ui->pushButton_br_right);

        ui->pushButton_sqrt->setProperty("light_theme", false);
        ui->pushButton_sqrt->style()->unpolish(ui->pushButton_sqrt);
        ui->pushButton_sqrt->style()->polish(ui->pushButton_sqrt);

        ui->pushButton_pow->setProperty("light_theme", false);
        ui->pushButton_pow->style()->unpolish(ui->pushButton_pow);
        ui->pushButton_pow->style()->polish(ui->pushButton_pow);

        ui->pushButton_sin->setProperty("light_theme", false);
        ui->pushButton_sin->style()->unpolish(ui->pushButton_sin);
        ui->pushButton_sin->style()->polish(ui->pushButton_sin);

        ui->pushButton_cos->setProperty("light_theme", false);
        ui->pushButton_cos->style()->unpolish(ui->pushButton_cos);
        ui->pushButton_cos->style()->polish(ui->pushButton_cos);

        ui->pushButton_fact->setProperty("light_theme", false);
        ui->pushButton_fact->style()->unpolish(ui->pushButton_fact);
        ui->pushButton_fact->style()->polish(ui->pushButton_fact);

        ui->pushButton_ans->setProperty("light_theme", false);
        ui->pushButton_ans->style()->unpolish(ui->pushButton_ans);
        ui->pushButton_ans->style()->polish(ui->pushButton_ans);

        ui->pushButton_0->setProperty("light_theme", false);
        ui->pushButton_0->style()->unpolish(ui->pushButton_0);
        ui->pushButton_0->style()->polish(ui->pushButton_0);

        ui->pushButton_1->setProperty("light_theme", false);
        ui->pushButton_1->style()->unpolish(ui->pushButton_1);
        ui->pushButton_1->style()->polish(ui->pushButton_1);

        ui->pushButton_2->setProperty("light_theme", false);
        ui->pushButton_2->style()->unpolish(ui->pushButton_2);
        ui->pushButton_2->style()->polish(ui->pushButton_2);

        ui->pushButton_3->setProperty("light_theme", false);
        ui->pushButton_3->style()->unpolish(ui->pushButton_3);
        ui->pushButton_3->style()->polish(ui->pushButton_3);

        ui->pushButton_4->setProperty("light_theme", false);
        ui->pushButton_4->style()->unpolish(ui->pushButton_4);
        ui->pushButton_4->style()->polish(ui->pushButton_4);

        ui->pushButton_5->setProperty("light_theme", false);
        ui->pushButton_5->style()->unpolish(ui->pushButton_5);
        ui->pushButton_5->style()->polish(ui->pushButton_5);

        ui->pushButton_6->setProperty("light_theme", false);
        ui->pushButton_6->style()->unpolish(ui->pushButton_6);
        ui->pushButton_6->style()->polish(ui->pushButton_6);

        ui->pushButton_7->setProperty("light_theme", false);
        ui->pushButton_7->style()->unpolish(ui->pushButton_7);
        ui->pushButton_7->style()->polish(ui->pushButton_7);

        ui->pushButton_8->setProperty("light_theme", false);
        ui->pushButton_8->style()->unpolish(ui->pushButton_8);
        ui->pushButton_8->style()->polish(ui->pushButton_8);

        ui->pushButton_9->setProperty("light_theme", false);
        ui->pushButton_9->style()->unpolish(ui->pushButton_9);
        ui->pushButton_9->style()->polish(ui->pushButton_9);

        ui->pushButton_div->setProperty("light_theme", false);
        ui->pushButton_div->style()->unpolish(ui->pushButton_div);
        ui->pushButton_div->style()->polish(ui->pushButton_div);

        ui->pushButton_mul->setProperty("light_theme", false);
        ui->pushButton_mul->style()->unpolish(ui->pushButton_mul);
        ui->pushButton_mul->style()->polish(ui->pushButton_mul);

        ui->pushButton_plus->setProperty("light_theme", false);
        ui->pushButton_plus->style()->unpolish(ui->pushButton_plus);
        ui->pushButton_plus->style()->polish(ui->pushButton_plus);

        ui->pushButton_minus->setProperty("light_theme", false);
        ui->pushButton_minus->style()->unpolish(ui->pushButton_minus);
        ui->pushButton_minus->style()->polish(ui->pushButton_minus);

        ui->pushButton_comma->setProperty("light_theme", false);
        ui->pushButton_comma->style()->unpolish(ui->pushButton_comma);
        ui->pushButton_comma->style()->polish(ui->pushButton_comma);

        ui->pushButton_equals->setProperty("light_theme", false);
        ui->pushButton_equals->style()->unpolish(ui->pushButton_equals);
        ui->pushButton_equals->style()->polish(ui->pushButton_equals);
    }
}
