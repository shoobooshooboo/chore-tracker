#ifndef BACKEND_H
#define BACKEND_H
#include <QObject>
#include <QtQml>
#include <vector>
#include <QList>
#include <QTextStream>
#include <QFile>
#include "user.hpp"
#include "household.hpp"

class Backend : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString username READ get_user_name NOTIFY userDataChanged)
    Q_PROPERTY(QString curHouseholdName READ get_cur_household_name NOTIFY curHouseholdChanged)
    Q_PROPERTY(QVariantList householdNames READ getHouseholdNames NOTIFY householdNamesChanged)
    Q_PROPERTY(QVariantList householdUsers READ getHouseholdUsers NOTIFY householdUsersChanged)

    Q_PROPERTY(QVariantList choreNames READ getChoreNames NOTIFY curHouseholdChanged)
    Q_PROPERTY(QVariantList choreLocations READ getChoreLocations NOTIFY curHouseholdChanged)
    Q_PROPERTY(QVariantList choreDates READ getChoreDates NOTIFY curHouseholdChanged)
    Q_PROPERTY(QVariantList choreStatuses READ getChoreStatuses NOTIFY curHouseholdChanged)


public:
    Q_INVOKABLE Backend();

    Q_INVOKABLE void set_household(int index);

    QString get_user_name() const;
    QString get_cur_household_name();

    QVariantList getHouseholdNames();
    QVariantList getHouseholdUsers();

    QVariantList getChoreNames();
    QVariantList getChoreLocations();
    QVariantList getChoreDates();
    QVariantList getChoreStatuses();

    Q_INVOKABLE void set_chore_status(int index, bool status);
private:
    int _toggledCount = 0;
    QString _dynamicText;
    std::vector<QString> _choresList;


    User *_user;
    User *_testUser;
    User *_testUser1;
    User *_testUser2;
    User *_testUser3;
    User *_testUser4;
    std::shared_ptr<Household> _houseHold1;
    std::shared_ptr<Household> _houseHold2;
    std::shared_ptr<Household> _houseHold3;
    std::shared_ptr<Household> _curHouseHold;


signals:
    // void toggledCount_changed();
    // void choresList_changed();
    // void dynamicText_changed();
    void userDataChanged();
    void householdNamesChanged();
    void householdUsersChanged();
    void curHouseholdChanged();
};
#endif // BACKEND_H
