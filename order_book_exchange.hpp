#pragma once
#include "accounts.hpp"
#include "order_book.hpp"
#include <chrono>
#include <memory>
#include <unordered_map>
#include <vector>

class order_book_exchange {
  private:
    std::unordered_map<long long, std::unique_ptr<account>> accounts_;
    std::unordered_map<long long, std::unique_ptr<order_book>> order_books_;
    long long last_user_id_ = 0;
    long long last_order_book_id_ = 0;
    long long new_user_id() { return last_user_id_++; }
    long long new_order_book_id() { return last_order_book_id_++; }

  public:
    class order_key {
        friend class account;
        order_key() {}
    };
    class order_book_key {
        order_book_key() {}
    };

    account *create_account(std::string name, long long starting_balance);

    order_book *create_order_book(std::string name, std::string ticker);

    bool create_order(order_key, long long order_book_id, long long accountId,
                      long long price, OrderType orderType,
                      long long quantity);
};