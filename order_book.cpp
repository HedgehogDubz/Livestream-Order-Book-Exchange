#include "order_book.hpp"
bool order_book::create_order(long long accountId, long long price,
                              OrderType orderType, long long quantity) {
    order *created_order =
        new order(new_order_id(), std::chrono::system_clock::now(), accountId,
                  price, orderType, quantity, true);

    if (orderType == OrderType::Buy) {
        // ->9,-> 8, ->(7), 5, 2
        while (sells_.size() > 0 && price >= sells_[0]->get_price()) {
            const long long sell_quantity = sells_[0]->get_quantity();
            if (sell_quantity > quantity) {
                sells_[0]->set_quantity(sell_quantity - quantity);
                //payout assets and balance
                return true;
            }
            if (sell_quantity == quantity) {
                sells_.pop_front();
                //payout assets and balance
                return true;
            }
            if (sell_quantity < quantity) {
                sells_.pop_front();
                //payout assets and balance
                quantity -= sell_quantity;
            }
        }
        for (size_t i{0}; i < buys_.size(); ++i) {
            if (buys_[i]->get_price() < price) {
                buys_.emplace(buys_.begin() + i, created_order);
                return true;
            }
        }
        buys_.push_back(created_order);
    }
    if (orderType == OrderType::Sell) {
        // ->9,-> 10, ->(12), 15, 22
        while (buys_.size() > 0 && price <= buys_[0]->get_price()) {
            const long long buy_quantity = buys_[0]->get_quantity();
            if (buy_quantity > quantity) {
                buys_[0]->set_quantity(buy_quantity - quantity);
                // payout assets and balance
                return true;
            }
            if (buy_quantity == quantity) {
                buys_.pop_front();
                // payout assets and balance
                return true;
            }
            if (buy_quantity < quantity) {
                buys_.pop_front();
                // payout assets and balance
                quantity -= buy_quantity;
            }
        }
        for (size_t i{0}; i < sells_.size(); ++i) {
            if (sells_[i]->get_price() > price) {
                sells_.emplace(sells_.begin() + i, created_order);
                return true;
            }
        }
        sells_.push_back(created_order);
    }
    return true;
}
void order_book::print_all_orders() {
    for(size_t i = sells_.size(); i-- > 0;){
        std::cout << sells_[i]->get_price() << " | " << sells_[i]->get_quantity() << '\n';

    }
    std::cout << ".........." << '\n';
    for (size_t i {0}; i < buys_.size(); ++i) {
        std::cout << buys_[i]->get_price() << " | " << buys_[i]->get_quantity() << '\n';
    }
}