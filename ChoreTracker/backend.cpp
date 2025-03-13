#include "backend.h"

Backend::Backend() {}


QString Backend::get_toggledCount(){
    return "Times toggled: " + QString::number(this->_toggledCount);
}

void Backend:: increment_toggledCount(){
    this->_toggledCount++;
    emit toggledCount_changed();
}



