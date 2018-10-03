#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QVector>
#include <QtWidgets>
#include "lib/structs.h"

class game : public QObject
{
    Q_OBJECT
private:
    int currentQuestion = 0;
    int money[numberOfQuestions] = {100,200,400,500,1000,
                     2000,4000,8000,16000,32000,
                     60000,100000,250000,500000,1000000};
    bool hints[3] = {true,true,true};
    QVector<int> answered;
    /* Данные текущего вопроса */
    int     qNumber;
    QString qQuestion;
    QString qPix;
    QString qAnswers[4];
    int qCorrect;

public:
    explicit game(QObject *parent = nullptr);
    void emit_quest();
signals:
    void signal_send_query_for_question(int level, QVector<int> & answered);

    void signal_to_GUI(QString question,QString pix,QString * list, int correct,bool * hint,int money,int currentQuestion);\
    void signal_to_result_GUI(bool QResult,bool finish,int money);
public slots:
    void slot_get_question(int number,QString question,QString pix,QString one, QString two, QString three, QString four, int correct);
    void slot_reaction_answer(bool answered);
     void slot_activate_hint(gameHints hint);
     void slot_took();
};

#endif // GAME_H
