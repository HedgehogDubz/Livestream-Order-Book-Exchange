#include "order_book_exchange.hpp"

account *order_book_exchange::create_account(std::string name,
                                             long long starting_balance) {
    long long user_id = new_user_id();
    std::unique_ptr<account> acct =
        std::make_unique<account>(this, user_id, name, starting_balance,
                                  std::chrono::system_clock::now());
    account *out = acct.get();
    accounts_[user_id] = std::move(acct);
    return out;
}

order_book *order_book_exchange::create_order_book(std::string name,
                                                   std::string ticker) {
    long long order_book_id = new_order_book_id();
    std::unique_ptr<order_book> ob =
        std::make_unique<order_book>(order_book_id, name, ticker);
    order_book *out = ob.get();
    order_books_[order_book_id] = std::move(ob);
    return out;
}

bool order_book_exchange::create_order(order_key, long long order_book_id,
                                       long long accountId, long long price,
                                       OrderType orderType,
                                       long long quantity) {
    {
        order_books_[order_book_id]->create_order(accountId, price, orderType,
                                                  quantity);
        return true;
    }
}