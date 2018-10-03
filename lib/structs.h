#ifndef STRUCTS_H
#define STRUCTS_H
#include <QString>
//общие структуры/енамы/прочая мишура которые могут пригодится различным классам
enum gameHints
{
    hall = 0,call, fiftyfifty
};

//структура призов из БД
struct lootItem
{
    int lootId;
    QString name;
    QString description;
    QString pix;
    int quality;
    int count;
};

const int numberOfQuestions = 15;
const int lvltwo = 5;
const int lvlthree = 10;
const int rand_quality_1 = 90;
const int rand_quality_2 = 98;
#endif // STRUCTS_H
