#pragma once
#ifndef APP_HPP
#define APP_HPP

#include "user_manager.hpp"
#include "household_manager.hpp"
#include <cassert>
#include <format>
#include <iostream> // FOR DEMO
#include <print> // FOR DEMO

namespace App {
    bool logIn(void);
    void signUp(void);

    void startup(void);


} 


#endif