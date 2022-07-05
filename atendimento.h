#ifndef ATENDIMENTO_H
#define ATENDIMENTO_H

#include <QMainWindow>
#include <QLineEdit>
#include <QQueue>
#include <ticket.h>
#include <QString>


namespace Ui {
class atendimento;
}

class atendimento : public QMainWindow
{
    Q_OBJECT

public:
    explicit atendimento(QWidget *parent = 0);
    ~atendimento();

private slots:
    void on_normal_clicked();

    void on_prioritario_clicked();

    void on_atender_clicked();

private:
    Ui::atendimento *ui;
    QQueue <ticket> fila_normal;
    QQueue <ticket> fila_prioritaria;
    int contador_global;
    int contador;

};

#endif // ATENDIMENTO_H
