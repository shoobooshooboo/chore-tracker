#include "backend.h"
#include <QDebug>
using namespace std::chrono_literals;
using timepoint_t = std::chrono::time_point<std::chrono::system_clock>;

Backend::Backend() {
    // hardCodedConstructor();
    _user = UserManager::loadUser(12345);
    qInfo() << std::format("name: {}, id: {}", _user->getName(), _user->getID());
    for(auto& hh :HouseholdManager::getLocalHouseholds(_user->getID())){
        _user->addHousehold(hh);
    }
}

QString Backend::get_user_name() const {
    if (_user) {
        return QString::fromStdString(_user->getName());  // Convert std::string to QString
    }
    return "No user assigned";  // Return this if no user is set
}


QVariantList Backend::getHouseholdNames(){
    QVariantList list;
    if (!_user) return list;

    for (const auto& hh : _user->getHouseholds()) {
        list.append(QString::fromStdString(std::string(hh->getName())));
    }
    return list;
}


QVariantList Backend::getHouseholdUsers() {
    QVariantList allUsers;
    if (!_user) return allUsers;

    for (const auto& hh : _user->getHouseholds()) {
        QStringList usersList;
        QString temp;
        const auto& users = hh->getUsers();
        for (auto it = users.begin(); it != users.end(); ++it) {
            const auto& userRef = *it;
            temp = QString::fromStdString(userRef.get().getName());
            bool isLast = (std::next(it) == users.end());
            if(!isLast){
                temp.append(",");
            }
            usersList.append(temp);

            // use isLast as needed
        }
        allUsers.append(usersList);
    }
    return allUsers;
}

void Backend::set_household(int index){
    this->_curHouseHold = _user->getHouseholds()[index];
    this->_curHouseHold->sortChores(Household::SortType::DATE);
    emit curHouseholdChanged();
}

QString Backend::get_cur_household_name(){
    if(this->_curHouseHold)
        return QString::fromStdString(std::string(this->_curHouseHold->getName()));
    return QString("household not found");
}

QVariantList Backend::getChoreNames(){
    QVariantList list;
    if(!_curHouseHold)
        return list;

    for(const auto& chore : _curHouseHold->getChores()){
        list.append(QString::fromStdString(chore.mName));
    }

    return list;
}

QVariantList Backend::getChoreLocations(){
    QVariantList list;
    if(!_curHouseHold)
        return list;

    for(const auto& chore : _curHouseHold->getChores()){
        list.append(QString::fromStdString(chore.mLocation));
    }

    return list;
}

QVariantList Backend::getChoreDates(){
    QVariantList list;
    if(!_curHouseHold)
        return list;

    for(const auto& chore : _curHouseHold->getChores()){
        std::string date = std::format("{:%m/%d/%Y}", chore.mDateAndTime);
        if(chore.mRecurrenceInterval.has_value()){
            unsigned long long days = std::chrono::duration_cast<std::chrono::days>(*chore.mRecurrenceInterval).count();
            if (days % 30 == 0)
                date += std::format(" (every {} month{})", days / 30, days / 30 > 1 ? "s" : "");
            else if (days % 7 == 0)
                date += std::format(" (every {} week{})", days / 7, days / 7 > 1 ? "s" : "");
            else
                date += std::format(" (every {} day{})", days, days > 1 ? "s" : "");

            //date += " (recurrs)";
        }
        list.append(QString::fromStdString(date));
    }

    return list;
}

QVariantList Backend::getChoreStatuses(){
    QVariantList list;
    if(!_curHouseHold)
        return list;

    for(const auto& chore : _curHouseHold->getChores()){
        list.append(chore.mCompletionStatus);
    }

    return list;
}

void Backend::set_chore_status(int index, bool status){
    if(!_curHouseHold || _curHouseHold->getChores()[index].mCompletionStatus == status)
        return;

    _curHouseHold->setChoreStatus(index, status);

    emit curHouseholdChanged();
}

void Backend::hardCodedConstructor(){
    _user = new User(01,"Parteek");

    _houseHold1 = std::make_shared<Household>(01, "Noel's Tavern");
    _houseHold2 = std::make_shared<Household>(01, "Dylan's Saloon");
    _houseHold3 = std::make_shared<Household>(01, "Krusty Krab");

    _testUser = new User(02, "Noel");
    _testUser2 = new User(03, "Dylan P.");
    _testUser3 = new User(04, "Dylan S.");
    _testUser4 = new User(05, "Omni-man");

    _houseHold1->handleUserJoining(*_testUser2);
    _houseHold1->handleUserJoining(*_testUser);
    _houseHold1->handleUserJoining(*_testUser3);
    //std::string&& name, timepoint_t dateTime, bool completionStatus, Priority priority, std::string&& location, timepoint_t::duration interval

    _houseHold2->handleUserJoining(*_testUser3);
    _houseHold2->handleUserJoining(*_testUser2);
    _houseHold2->handleUserJoining(*_testUser);
    _houseHold3->handleUserJoining(*_testUser4);
    _houseHold3->handleUserJoining(*_testUser);

    _user->addHousehold(_houseHold1);
    _user->addHousehold(_houseHold2);
    _user->addHousehold(_houseHold3);

    _user->getHouseholds()[0]->addChore(Chore("dishes",
                                              std::chrono::system_clock::now() + 24h,
                                              false,
                                              Priority::IMMINENT,
                                              "kitchen",
                                              timepoint_t::duration::zero() + 24h));
    _user->getHouseholds()[0]->addChore(Chore("beat up david",
                                              std::chrono::system_clock::now() + 36h,
                                              true,
                                              Priority::MEDIUM,
                                              "david's room",
                                              timepoint_t::duration::zero() + 168h));
    _user->getHouseholds()[0]->addChore(Chore("Chore3",
                                              std::chrono::system_clock::now() + 36h,
                                              false,
                                              Priority::LOW,
                                              "Location3",
                                              timepoint_t::duration::zero() + 730h));
    _user->getHouseholds()[0]->addChore(Chore("chore4",
                                              std::chrono::system_clock::now() + 48h,
                                              false,
                                              Priority::LOW,
                                              "Location4",
                                              timepoint_t::duration::zero() + 48h));
    _user->getHouseholds()[0]->addChore(Chore("Chore5",
                                              std::chrono::system_clock::now() + 48h,
                                              false,
                                              Priority::LOW,
                                              "Location5",
                                              timepoint_t::duration::zero() + 336h));
    _user->getHouseholds()[0]->addChore(Chore("Usurp the throne of god",
                                              std::chrono::system_clock::now() + 8760h,
                                              false,
                                              Priority::IMMINENT,
                                              "heaven",
                                              timepoint_t::duration::zero()));
    _user->getHouseholds()[0]->addChore(Chore("chore6",
                                              std::chrono::system_clock::now() + 168h,
                                              false,
                                              Priority::LOW,
                                              "Location6",
                                              timepoint_t::duration::zero() + 1460h));

}
