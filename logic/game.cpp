#include "game.h"

game::game(QObject *parent) : QObject(parent)
{
    // Инициализация первого вопроса

    //    answered.push_back(1);
    //    answered.push_back(2);

}

void game::emit_quest()
{
    emit signal_send_query_for_question(currentQuestion < lvltwo? 1 : currentQuestion < lvlthree ? 2 : 3, answered);
}

void game::slot_get_question(int number,QString question, QString pix, QString one, QString two, QString three, QString four, int correct)
{
    qNumber = number;
    qQuestion = question;
    qPix = pix;
    qAnswers[0] = one;
    qAnswers[1] = two;
    qAnswers[2] = three;
    qAnswers[3] = four;
    qCorrect = correct;
    answered.push_back(qNumber);
    emit signal_to_GUI(qQuestion,qPix,qAnswers,qCorrect,hints,money[currentQuestion],currentQuestion);
}

void game::slot_reaction_answer(bool answered)
{
    if (answered == true)
    {

        if (currentQuestion+1 == numberOfQuestions)
        {
        emit signal_to_result_GUI(true,true,money[currentQuestion]);

        }
        else
        {

            emit signal_to_result_GUI(true,false,money[currentQuestion  ]);
        }

    }
    else  emit signal_to_result_GUI(false,false,currentQuestion < lvltwo ? 0 : currentQuestion < lvlthree ? money[lvltwo-1] : money[lvlthree-1]);
currentQuestion++;

}

void game::slot_activate_hint(gameHints hint)
{
    hints[hint] = false;
}

void game::slot_took()
{
     emit signal_to_result_GUI(false,true, currentQuestion == 0 ? 0 : money[currentQuestion-1] );
}
