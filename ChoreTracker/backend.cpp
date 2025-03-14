#include "backend.h"

Backend::Backend() {
    for(int i = 0; i < 100; i++){
        this->_choresList.push_back("Chore: " + QString::number(i));
    }
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
