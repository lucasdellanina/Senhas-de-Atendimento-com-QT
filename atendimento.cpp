#include "atendimento.h"
#include "ui_atendimento.h"

atendimento::atendimento(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::atendimento)
{
    ui->setupUi(this);
    contador_global = 0;
    contador = 0;
}

atendimento::~atendimento()
{
    delete ui;
}

void atendimento::on_normal_clicked()
{
    ticket temp;
    temp.data = QDate::currentDate();
    temp.time = QTime::currentTime();
    temp.tipo = 0;
    contador_global = contador_global + 1;
    temp.sequencial = contador_global;
    ui->novaFicha->setText(QString("%1").arg(contador_global));
    fila_normal.enqueue(temp);
}

void atendimento::on_prioritario_clicked()
{
    ticket temp3;
    temp3.data = QDate::currentDate();
    temp3.time = QTime::currentTime();
    temp3.tipo = 0;
    contador_global = contador_global + 1;
    temp3.sequencial = contador_global;
    ui->novaFicha->setText(QString("%1").arg(contador_global));
    fila_prioritaria.enqueue(temp3);

}

void atendimento::on_atender_clicked()
{

    ticket temp2;
    if ((!fila_prioritaria.isEmpty())&&(contador < 2)){
        temp2 = fila_prioritaria.dequeue();
        ui->tipo->setText(QString("Prioritario"));
        contador ++;
    }else{
        contador = 0;
        if (!fila_normal.isEmpty()){
            temp2 = fila_normal.dequeue();
            ui->tipo->setText(QString("Normal"));
        }else{

            if (!fila_prioritaria.isEmpty()){
                temp2 = fila_prioritaria.dequeue();
                contador ++;
                ui->tipo->setText(QString("Prioritario"));
            }else{
               temp2.sequencial = 999;
               ui->tipo->setText(QString("ERRO"));

            }
        }


    }

    ui->numero->setText(QString("%1").arg(temp2.sequencial));


        ui->dataM->setText(temp2.data.toString("dd/MM/yyyy"));
        ui->horaM->setText(temp2.time.toString("hh:mm:ss"));


}
