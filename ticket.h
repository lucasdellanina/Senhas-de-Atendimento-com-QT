#ifndef TICKET_H
#define TICKET_H

#include <QDate>
#include <QTime>


class ticket
{
public:
    ticket();
    QDate data;
    QTime time;
    int sequencial;
    int tipo;

};

#endif // TICKET_H
