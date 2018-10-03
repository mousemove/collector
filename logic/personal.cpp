#include "personal.h"

personal::personal(QObject *parent) : QObject(parent)
{

    update_settings();
}

int personal::getCurrentMoney() const
{
    return currentMoney;
}

void personal::setCurrentMoney(int value)
{
    QSettings settings("settings.ini", QSettings::IniFormat);

    settings.beginGroup("/data");
    settings.setValue("/currentMoney",currentMoney+value);

    settings.endGroup();
    settings.sync();
    update_settings();
}

int personal::getLootOpen() const
{
    return lootOpen;
}

void personal::setLootOpen(int value)
{
        QSettings settings("settings.ini", QSettings::IniFormat);
    settings.beginGroup("/data");
    settings.setValue("/lootOpen",lootOpen+value);

    settings.endGroup();
      settings.sync();
    update_settings();
}

int personal::getLootDefault() const
{
    return lootDefault;
}

void personal::setLootDefault(int value)
{
        QSettings settings("settings.ini", QSettings::IniFormat);
    settings.beginGroup("/data");
    settings.setValue("/lootDefault",lootDefault+value);

    settings.endGroup();
     settings.sync();
    update_settings();
}

int personal::getLootRare() const
{
    return lootRare;
}

void personal::setLootRare(int value)
{
        QSettings settings("settings.ini", QSettings::NativeFormat);
    settings.beginGroup("/data");
    settings.setValue("/lootRare",lootRare+value);

    settings.endGroup();
         settings.sync();
    update_settings();
}

int personal::getLootLegendary() const
{
    return lootLegendary;
}

void personal::setLootLegendary(int value)
{
        QSettings settings("settings.ini", QSettings::IniFormat);
    settings.beginGroup("/data");
    settings.setValue("/lootLegendary",lootLegendary+value);

    settings.endGroup();
      settings.sync();
    update_settings();
}

void personal::update_settings()
{
        QSettings settings("settings.ini", QSettings::IniFormat);
    settings.beginGroup("/data");
    currentMoney = settings.value("/currentMoney",0).toInt();
    lootOpen = settings.value("/lootOpen",0).toInt();
    lootDefault = settings.value("/lootDefault",0).toInt();
    lootRare = settings.value("/lootRare",0).toInt();
    lootLegendary = settings.value("/lootLegendary",0).toInt();

    settings.endGroup();
}
