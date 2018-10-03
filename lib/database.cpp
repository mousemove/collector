#include "database.h"
#include "QTime"

/* Функции класса */
bool database::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("millionaregame");

    db.setUserName("user");
    db.setHostName("hostname");
    db.setPassword("password");
    if (!db.open()) {
        qDebug() << "Cannot open database:" << db.lastError();
        return false;
    }
    QStringList lst = db.tables();
    foreach (QString str,lst){

    }
    return true;
}


database::database(QObject *parent) : QObject(parent)
{
    create_tables();//Создаем таблицы если они отсутствуют
}


void database::create_tables()
{
    if ( !createConnection( ) ) {
        qDebug() << "SQL connect error!"; // ошибка соединения с базой данных
    }
    QSqlQuery query;

    QString   str  = "CREATE TABLE questions ( "
                     "q_id INTEGER PRIMARY KEY NOT NULL, "
                     "q_question   TEXT, "
                     "q_pix  VARCHAR(64), "
                     "q_first  VARCHAR(64),"
                     "q_second  VARCHAR(64),"
                     "q_third  VARCHAR(64),"
                     "q_fourth  VARCHAR(64),"
                     "q_lvl  INTEGER,"
                     "q_correct  INTEGER"
                     ");";
    if (!query.exec(str)) {
        qDebug() << "DB created OR unable to create a table";
    }
    else
    {

        fill_questions();

    }

    str  = "CREATE TABLE loot ( "
           "loot_id INTEGER PRIMARY KEY NOT NULL, "
           "loot_name   TEXT, "
           "loot_desc   TEXT, "
           "loot_pix  VARCHAR(64), "
           "loot_quality  INTEGER,"
           "loot_count  INTEGER"

           ");";
    if (!query.exec(str)) {
        //qDebug() << "DB created OR unable to create a table";
    }
    else
    {
        fill_loot();
    }



}

void database::fill_questions()
{

    QFile file(":/data/data/q.db");
    QSqlQuery query;
    if(file.open(QIODevice::ReadOnly |QIODevice::Text))
    {
        while(!file.atEnd())
        {
            //читаем строку
            QString str = file.readLine().trimmed();
            //Делим строку на слова разделенные пробелом
            QStringList lst = str.split("| ");
            // выводим первых три слова
            // qDebug() << lst;

            QString sql = "INSERT INTO questions(q_question,q_pix,q_first,q_second,q_third,q_fourth,q_lvl,q_correct)"
                          " VALUES('"+lst.at(0)+"','"+lst.at(1)+"','"+lst.at(2)+"','"+lst.at(3)+"','"+lst.at(4)+"','"+lst.at(5)+"',"+lst.at(6).trimmed()+","+lst.at(7).trimmed()+")";
            qDebug() << sql;
            query.exec(sql);//toDo уязвимое место, преполагается что если успешно создалась база -> нужно все равно генерировать исключения здесь

        }

    }
    else
    {
        qDebug()<< "don't open file";
    }


}

void database::fill_loot()
{

    QFile file(":/data/data/l.db");
    QSqlQuery query;
    if(file.open(QIODevice::ReadOnly |QIODevice::Text))
    {
        while(!file.atEnd())
        {
            //читаем строку
            QString str = file.readLine().trimmed();
            //Делим строку на слова разделенные пробелом
            QStringList lst = str.split("| ");
            // выводим первых три слова
            // qDebug() << lst;

            QString sql = "INSERT INTO loot(loot_name,loot_desc,loot_pix,loot_quality,loot_count)"
                          " VALUES('"+lst.at(0)+"','"+lst.at(1)+"','"+lst.at(2)+"',"+lst.at(3).trimmed()+","+lst.at(4).trimmed()+")";
            qDebug() << sql;
            query.exec(sql);//toDo уязвимое место, преполагается что если успешно создалась база -> нужно все равно генерировать исключения здесь

        }

    }
    else
    {
        qDebug()<< "don't open file";
    }



}




void database::slot_get_query_for_question(int level, QVector<int> &answered)
{
    QSqlQuery query;
    QString additionalQuery = "";
    // qDebug() << "questions id ====";
    for(auto it = answered.begin(); it != answered.end(); ++it)
    {
        qDebug() << *it;
        additionalQuery = additionalQuery + " AND q_id != "+QString().setNum(*it);
    }

    QString str = "SELECT * FROM questions WHERE q_lvl ="+QString().setNum(level)+additionalQuery+ "   ORDER BY RANDOM() LIMIT 1; ";
    QString str2 = "SELECT * FROM questions WHERE q_lvl ="+QString().setNum(level)+"   ORDER BY RANDOM() LIMIT 1; ";
    // qDebug() << str;
    if (!query.exec(str)) {

    }
    else
    {
        QSqlRecord rec = query.record();
        if (!query.next())
        {
            query.exec(str2);
            rec = query.record();
            query.next();
        }
        emit signal_send_question(query.value(rec.indexOf("q_id")).toInt(),
                                  query.value(rec.indexOf("q_question")).toString(),
                                  query.value(rec.indexOf("q_pix")).toString(),
                                  query.value(rec.indexOf("q_first")).toString(),
                                  query.value(rec.indexOf("q_second")).toString(),
                                  query.value(rec.indexOf("q_third")).toString(),
                                  query.value(rec.indexOf("q_fourth")).toString(),
                                  query.value(rec.indexOf("q_correct")).toInt());


    }
}

void database::slot_refresh_loot_vector( QVector<lootItem> * lootVector )
{
    QSqlQuery query;
    QString str = "SELECT * FROM loot ; ";
    lootVector->clear();//По всей видимости очищать каждый раз - не очень круто.
    if (!query.exec(str)) {

    }
    else
    {

        QSqlRecord rec = query.record();

        while(query.next()){

            int lootId = query.value(rec.indexOf("loot_id")).toInt();
            QString name = query.value(rec.indexOf("loot_name")).toString();
            QString description = query.value(rec.indexOf("loot_desc")).toString();
            QString pix = query.value(rec.indexOf("loot_pix")).toString();
            int quality = query.value(rec.indexOf("loot_quality")).toInt();
            int count = query.value(rec.indexOf("loot_count")).toInt();


            lootVector->push_back({lootId,name,description,pix,quality,count});
            //  qDebug() << lootId <<name <<description <<pix <<quality<<count;

        }
    }


    emit signal_loot_refresh();
}

void database::slot_query_open_lootbox()
{
    QTime midnight(0,0,0);
    srand(midnight.secsTo(QTime::currentTime() )   * ( rand() % 100 ) + (rand() % 18) );

    QSqlQuery query;
    //qDebug() << "vyborka lb" << midnight.secsTo(QTime::currentTime() );
    int random = rand () % 100;
    qDebug () << "rand" << random;
    random = random < rand_quality_1 ? 1 : random < rand_quality_2 ? 2 : 3;//
    QString str = "SELECT * FROM loot WHERE loot_quality ="+QString().setNum(random)+"   ORDER BY RANDOM() LIMIT 1; ";
    if (!query.exec(str)) {

    }
    else
    {
        QSqlRecord rec = query.record();
        query.next();

        int lootId = query.value(rec.indexOf("loot_id")).toInt();
        QString name = query.value(rec.indexOf("loot_name")).toString();
        QString description = query.value(rec.indexOf("loot_desc")).toString();
        QString pix = query.value(rec.indexOf("loot_pix")).toString();
        int quality = query.value(rec.indexOf("loot_quality")).toInt();
        int count = query.value(rec.indexOf("loot_count")).toInt();
        QString str = "UPDATE loot SET loot_count = "+QString().setNum(count+1)+" WHERE loot_id ="+QString().setNum(lootId)+" ; ";

        query.exec(str);
        emit signal_send_stats(quality);
        emit signal_send_loot_box({lootId,name,description,pix,quality,count});
    }


}
