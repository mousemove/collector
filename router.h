#ifndef ROUTER_H
#define ROUTER_H

#include <QWidget>
#include <QtWidgets>
#include <QDebug>
#include "gui/loadingwidget.h"
#include "gui/mainwidget.h"
#include "gui/gamewidget.h"
#include "gui/resultwidget.h"
#include "gui/callwidget.h"
#include "gui/hallwidget.h"
#include "gui/widgetstatistics.h"
#include "gui/aboutwidget.h"
#include "logic/game.h"
#include "logic/personal.h"
#include "lib/database.h"
#include "lib/structs.h"
#include "gui/lootwidget.h"
#include "QTime"
#include <QSettings>
class router : public QStackedWidget
{
    Q_OBJECT
private:
    /* Графические виджеты */
    loadingWidget * loadWidget;
    mainwidget * mainMenuWidget;
    gamewidget * gameMainWidget;
    resultwidget * gameResultWidget;
    callwidget * gamelCallWidget;
    hallwidget * gameHallWidget;
    lootwidget * LootWidget;
    widgetstatistics * statWidget;
    aboutWidget * aboutMeWidget;
    /* Классы игры */
    game * gameLogic;
    personal * personalData;
    /* Библиотечные классы */
    database * db;
    //Сохраненки из сеттингов хранящиеся в роутере


public:
    router(QWidget *parent   = nullptr);
    ~router();
public slots:
    void    slot_set_main_menu_widget();
    void    slot_set_new_game();
    void    slot_question_ready();
    void    slot_set_result_widget();
    void    slot_game_over(int money);
    void    slot_back_to_game();
    void slot_back_to_game_after_hint();
    void slot_call_hint(int num);
    void slot_hall_hint(int num);
    void slot_set_loot_widget();
    void slot_refresh_money(int money);
    void slot_refresh_stats(int quality);
    void slot_set_stat();
    void slot_set_about();
};



#endif // ROUTER_H
