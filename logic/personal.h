#ifndef PERSONAL_H
#define PERSONAL_H

#include <QObject>
#include <QSettings>
#include <QDebug>
class personal : public QObject
{
    Q_OBJECT

public:
    explicit personal(QObject *parent = nullptr);

    int getCurrentMoney() const;
    void setCurrentMoney(int value);

    int getLootOpen() const;
    void setLootOpen(int value);

    int getLootDefault() const;
    void setLootDefault(int value);

    int getLootRare() const;
    void setLootRare(int value);

    int getLootLegendary() const;
    void setLootLegendary(int value);
      void update_settings();

private:


    //cами сеттинги
    int currentMoney;
    int lootOpen;
    int lootDefault;
    int lootRare;
    int lootLegendary;

signals:

public slots:
};

#endif // PERSONAL_H
