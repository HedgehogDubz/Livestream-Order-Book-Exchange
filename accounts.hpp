#pragma once

#include <chrono>
#include <string>
#include <vector>
#include <iostream>
#include "order.hpp"

class order_book_exchange;

class account {

    //--id-- name-- balance-- timestamp_created-- assets-- orders
    private:
    long long id_;
    std::string name_;
    long long balance_;
    std::chrono::system_clock::time_point timestamp_created_;
    std::vector<long long> assetIds_;
    std::vector<long long> orderIds_;
    
    order_book_exchange* exchange_;

    public:
      account(order_book_exchange *exchange, long long id, std::string name,
              long long starting_balance,
              std::chrono::system_clock::time_point timestamp_created)
          : id_(id), name_(name), balance_(starting_balance),
            timestamp_created_(timestamp_created), exchange_(exchange) {
          std::cout << "Account Created!" << std::endl;
      }

    void hello() {
        std::cout << "Hello I'm: " << name_ << std::endl;
    }

    bool create_order(long long order_book_id,
                      long long price, OrderType orderType,
                      long long quantity);
};