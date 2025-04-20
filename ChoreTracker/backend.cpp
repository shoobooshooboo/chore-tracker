#include "backend.h"

Backend::Backend() {

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
    _houseHold2->handleUserJoining(*_testUser3);
    _houseHold2->handleUserJoining(*_testUser2);
    _houseHold2->handleUserJoining(*_testUser);
    _houseHold3->handleUserJoining(*_testUser4);
    _houseHold3->handleUserJoining(*_testUser);




    _user->addHousehold(_houseHold1);
    _user->addHousehold(_houseHold2);
    _user->addHousehold(_houseHold3);




    for(int i = 0; i < 100; i++){
        this->_choresList.push_back("Chore: " + QString::number(i));
    }


}


QString Backend::get_dynamicText() {
    return _dynamicText;
}


QString Backend::get_toggledCount(){
    return "Times toggled: " + QString::number(this->_toggledCount);
}

std::vector<QString> Backend::get_choresList(){
    return this->_choresList;
}

void Backend:: increment_toggledCount(){
    this->_toggledCount++;
    emit toggledCount_changed();
}

int Backend::get_chores_count(){
    return this->_choresList.size();
}

QString Backend::get_chore(int index){
    return this->_choresList[index];
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





void Backend::set_dynamicText(QString &newText) {
    if (_dynamicText != newText) {
        _dynamicText = newText;
        QFile file("dynamicTextLog.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << newText;
            file.close();
        }

        emit dynamicText_changed();
    }

}


