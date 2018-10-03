#include "router.h"

router::router(QWidget *parent)
    : QStackedWidget (parent)
{


    /* Инициализация базы данных */
    db = new database(this);
    /* Инициализация и загрузка персональной даты */
    personalData = new personal(this);

    /* Инициализация первоначальных графических виджетов */
    loadWidget = new loadingWidget(this);
    mainMenuWidget = new mainwidget(this);
    gameMainWidget = new gamewidget(this);
    gameResultWidget = new resultwidget(this);
    gamelCallWidget = new callwidget(this);
    gameHallWidget = new hallwidget(this);
    LootWidget = new lootwidget(this);
    statWidget = new widgetstatistics(this);
    aboutMeWidget = new aboutWidget(this);
    /* СС соединения */
    connect(loadWidget,SIGNAL(animation_end()),this,SLOT(slot_set_main_menu_widget()));
    connect(mainMenuWidget,SIGNAL(signal_new_game()),this,SLOT(slot_set_new_game()));


    connect(gameMainWidget,SIGNAL(signal_ready()),this,SLOT(slot_question_ready()));
    connect(gameResultWidget,SIGNAL(signal_show_result()),this,SLOT(slot_set_result_widget()));
    connect(gameResultWidget,SIGNAL(signal_end_game(int)),this,SLOT(slot_game_over(int)));
    connect(gameResultWidget,SIGNAL(signal_next_question()),this,SLOT(slot_back_to_game()));

    connect(gameMainWidget,SIGNAL(signal_call_hint(int)),this,SLOT(slot_call_hint(int)));
    connect(gameMainWidget,SIGNAL(signal_hall_hint(int)),this,SLOT(slot_hall_hint(int)));
    connect(gamelCallWidget,SIGNAL(signal_exit_call()),this,SLOT(slot_back_to_game_after_hint()));
    connect(gameHallWidget,SIGNAL(signal_exit_hall()),this,SLOT(slot_back_to_game_after_hint()));
    connect(mainMenuWidget,SIGNAL(signal_go_to_loot()),this,SLOT(slot_set_loot_widget()));
    connect(LootWidget,SIGNAL(signal_refresh_loot(QVector<lootItem> * )),db,SLOT(slot_refresh_loot_vector(QVector<lootItem> * )));
    connect(db,SIGNAL(signal_loot_refresh()),LootWidget,SLOT(   slot_loot_refresh_from_db()));
    connect(LootWidget,SIGNAL(signal_query_loot_box()),db,SLOT(slot_query_open_lootbox()));
    connect(db,SIGNAL( signal_send_loot_box(lootItem)),LootWidget,SLOT(slot_read_opened_lootboox(lootItem)));
    connect(LootWidget,SIGNAL(signal_refresh_money(int)),this,SLOT(slot_refresh_money(int)));
    connect(db,SIGNAL(signal_send_stats(int)),this,SLOT(slot_refresh_stats(int)));
    connect(LootWidget,SIGNAL(signal_go_back()),this,SLOT(  slot_set_main_menu_widget()  ));
    connect(mainMenuWidget,SIGNAL(signal_go_to_stat()),this,SLOT(slot_set_stat()));
    connect(statWidget,SIGNAL(signal_go_back()),this,SLOT(slot_set_main_menu_widget()));
    connect(aboutMeWidget,SIGNAL(signal_go_back()),this,SLOT(slot_set_main_menu_widget()) );
    connect(mainMenuWidget,SIGNAL(signal_go_to_about()),this,SLOT(slot_set_about()));
    addWidget(mainMenuWidget);
    addWidget(loadWidget);
    addWidget(gameMainWidget);
    addWidget(gameResultWidget);
    addWidget(gamelCallWidget);
    addWidget(gameHallWidget);
    addWidget(LootWidget);
    addWidget(statWidget);
    addWidget(aboutMeWidget);
    setCurrentWidget(loadWidget);

}


router::~router()
{

}



void router::slot_set_main_menu_widget()
{

    setCurrentWidget(mainMenuWidget);

}


void router::slot_set_new_game()
{
    gameLogic = new game(this);
    /* СС соединения между игрой и базой данных*/
    connect(gameLogic,SIGNAL(signal_send_query_for_question(int , QVector<int> & )),
            db,SLOT(slot_get_query_for_question(int , QVector<int> & )));

    connect(db,SIGNAL(signal_send_question(int,QString ,QString ,QString , QString , QString, QString, int )),
            gameLogic,SLOT(slot_get_question(int,QString ,QString,QString , QString , QString , QString , int )));

    connect(gameLogic,SIGNAL(signal_to_GUI(QString ,QString ,QString * , int,bool * ,int,int)),
            gameMainWidget,SLOT(slot_from_logic(QString ,QString ,QString* , int, bool *,int,int)));

    connect(gameMainWidget,SIGNAL(signal_ready()),this,SLOT(slot_question_ready()));

    connect(gameMainWidget,SIGNAL(signal_result(bool)),gameLogic,SLOT(slot_reaction_answer(bool)));

    connect(gameLogic,SIGNAL(signal_to_result_GUI(bool,bool,int)),gameResultWidget,SLOT(slow_show_result(bool,bool,int)));


    connect(gameMainWidget,SIGNAL(signal_activate_hint(gameHints)),gameLogic,SLOT(slot_activate_hint(gameHints)));
    connect(gameMainWidget,SIGNAL(signal_took()),gameLogic,SLOT(slot_took()));



    gameLogic->emit_quest();

}

void router::slot_question_ready()
{
    gameMainWidget->refresh_data();//возможно вынести отсюда
    setCurrentWidget(gameMainWidget);
}

void router::slot_game_over(int money)
{
    personalData->setCurrentMoney(money);
    personalData->update_settings();
    setCurrentWidget(mainMenuWidget);
    disconnect(gameLogic,SIGNAL(signal_send_query_for_question(int , QVector<int> & )),
               db,SLOT(slot_get_query_for_question(int , QVector<int> & )));

    disconnect(db,SIGNAL(signal_send_question(int,QString ,QString ,QString , QString , QString, QString, int )),
               gameLogic,SLOT(slot_get_question(int,QString ,QString,QString , QString , QString , QString , int )));

    disconnect(gameLogic,SIGNAL(signal_to_GUI(QString ,QString ,QString * , int,bool * ,int,int)),
               gameMainWidget,SLOT(slot_from_logic(QString ,QString ,QString* , int, bool *,int,int)));

    disconnect(gameMainWidget,SIGNAL(signal_ready()),this,SLOT(slot_question_ready()));

    disconnect(gameMainWidget,SIGNAL(signal_result(bool)),gameLogic,SLOT(slot_reaction_answer(bool)));

    disconnect(gameLogic,SIGNAL(signal_to_result_GUI(bool,bool,int)),gameResultWidget,SLOT(slow_show_result(bool,bool,int)));


    disconnect(gameMainWidget,SIGNAL(signal_activate_hint(gameHints)),gameLogic,SLOT(slot_activate_hint(gameHints)));
    disconnect(gameMainWidget,SIGNAL(signal_took()),gameLogic,SLOT(slot_took()));
    delete gameLogic;
}

void router::slot_back_to_game()
{
    gameLogic->emit_quest();
}

void router::slot_back_to_game_after_hint()
{
    setCurrentWidget(gameMainWidget);
}

void router::slot_call_hint(int num)
{
    gamelCallWidget->setCorrectNumber(num);
    setCurrentWidget(gamelCallWidget);
}

void router::slot_hall_hint(int num)
{
    gameHallWidget->setCorrectNumber(num);
    setCurrentWidget(gameHallWidget);
}

void router::slot_set_loot_widget()
{
    LootWidget->refresh_items(personalData->getCurrentMoney());
    setCurrentWidget(LootWidget);
}

void router::slot_refresh_money(int money)
{
    personalData->setCurrentMoney(-1*money);
    LootWidget->refresh_items(personalData->getCurrentMoney());
}

void router::slot_refresh_stats(int quality)
{
    personalData->setLootOpen(1);
    if (quality == 1) personalData->setLootDefault(1);
    else if (quality == 2) personalData->setLootRare(1);
    else personalData->setLootLegendary(1);


}

void router::slot_set_stat()
{
    statWidget->set_stat(personalData->getCurrentMoney(),personalData->getLootOpen(),personalData->getLootDefault(),personalData->getLootRare(),personalData->getLootLegendary());
    setCurrentWidget(statWidget);
}

void router::slot_set_about()
{
    setCurrentWidget(aboutMeWidget);
}


void router::slot_set_result_widget()
{
    setCurrentWidget(gameResultWidget);
}
