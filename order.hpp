#pragma once

#include <chrono>

enum OrderType { Buy, Sell };

class order {
    //--id-- timestamp_created-- quantity-- type(buy / sell)-- account_id
    //    -- status(open / closed)

    long long id_;
    std::chrono::system_clock::time_point timestamp_created_;
    long long account_id_;

    long long price_;
    OrderType orderType_;
    long long quantity_;

    bool isOpen_;

  public:
    order(long long id, std::chrono::system_clock::time_point timestamp_created,
          long long account_id, long long price, OrderType orderType,
          long long quantity, bool isOpen)
        : id_(id), timestamp_created_(timestamp_created),
          account_id_(account_id), price_(price), orderType_(orderType),
          quantity_(quantity), isOpen_(isOpen) {}

    long long get_price() { return price_; }
    OrderType get_orderType() { return orderType_; }
    long long get_quantity() { return quantity_; }
    void set_quantity(long long quantity) { quantity_ = quantity; }
};