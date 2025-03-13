#include "backend.h"

Backend::Backend() {}


QString Backend::get_text(){
    return _text;
}

void Backend:: change_text(int x){
    _text = "Times toggled: " + QString::number(x);
    emit text_changed();
}



