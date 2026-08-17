#include "accounts.hpp"
#include "order_book_exchange.hpp"

bool account::create_order(long long order_book_id, long long price,
                           OrderType orderType, long long quantity) {
    exchange_->create_order(order_book_exchange::order_key{}, order_book_id,
                            id_, price, orderType, quantity);
    return true;
}