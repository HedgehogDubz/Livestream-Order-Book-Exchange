#pragma once

#include "order.hpp"
#include <chrono>
#include <deque>
#include <string>
#include <iostream>
class order_book {
    //--id-- name-- ticker-- buys-- sells
  private:
    long long id_;
    std::string name_;
    std::string ticker_;
    std::deque<order *> buys_;
    std::deque<order *> sells_;

    long long last_order_id_ = 0;
    long long new_order_id() { return last_order_id_++; }

  public:
    order_book(long long id, std::string name, std::string ticker)
        : id_(id), name_(name), ticker_(ticker) {}

    bool create_order(long long accountId, long long price, OrderType orderType,
                      long long quantity);
    
    void print_all_orders();
};