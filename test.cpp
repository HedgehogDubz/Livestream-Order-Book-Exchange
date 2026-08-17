

#include "order_book_exchange.hpp"
#include <chrono>
#include <iostream>
#include <ratio>

int main() {
    std::cout << __cplusplus << '\n';

    order_book_exchange *obe = new order_book_exchange();
    account *acct = obe->create_account("Hedgehog", 100);
    acct->hello();
    order_book *ob = obe->create_order_book("Hedgehog Inc.", "HDGH");

    auto start = std::chrono::high_resolution_clock::now();
    for (int i{0}; i < 20000; i++) {

        acct->create_order(0, 100, OrderType::Buy, 2);
        acct->create_order(0, 102, OrderType::Buy, 1);
        acct->create_order(0, 103, OrderType::Buy, 3);
        acct->create_order(0, 101, OrderType::Buy, 1);
        acct->create_order(0, 104, OrderType::Buy, 1);
        acct->create_order(0, 105, OrderType::Buy, 5);
        acct->create_order(0, 105, OrderType::Buy, 1);
        acct->create_order(0, 101, OrderType::Buy, 17);
        acct->create_order(0, 100, OrderType::Sell, 6);
        acct->create_order(0, 106, OrderType::Sell, 8);
        acct->create_order(0, 108, OrderType::Sell, 3);
        acct->create_order(0, 110, OrderType::Sell, 6);
        acct->create_order(0, 106, OrderType::Sell, 1);
        acct->create_order(0, 108, OrderType::Sell, 1);
        acct->create_order(0, 107, OrderType::Sell, 10);
        acct->create_order(0, 106, OrderType::Sell, 7);
        acct->create_order(0, 103, OrderType::Sell, 2);
        acct->create_order(0, 108, OrderType::Buy, 12);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << (elapsed.count()) << std::endl;
}