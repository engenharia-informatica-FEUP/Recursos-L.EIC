//
// Created by Tiago on 16/11/2019.
//

#include "Purchase.h"
#include <stack>

using namespace std;

Purchase::Purchase(long cli) : client (cli) {
}

long Purchase::getClient() const {
    return client;
}

list< stack<Article*> > Purchase::getBags() const {
    return bags;
}

/**
 * Create an Article associated with the client of this purchase.
 */
Article* Purchase::createArticle(long barCode, bool present, bool deliverHome) {

    Article* article = new Article(client, barCode);
    article->setPresent(present);
    article->setDeliverHome(deliverHome);

    return article;
}

/**
 * Add an Article to the bags of this purchase. A new bag is added when the last bag is full.
 */
void Purchase::putInBag(Article* article) {

    if ((bags.back().size() < BAG_SIZE) && (bags.size() != 0)) {
        bags.back().push(article);
    }
    else {
        stack<Article*> s;
        s.push(article);
        bags.push_back(s);
    }
}

/**
 * Pop from the bags all articles that are presents.
 * All other articles are pushed back into the bags where they were, maintaining order.
 */
vector<Article*> Purchase::popPresents() {

    vector<Article*> presents;
    stack<Article*> auxStack;

    for (auto it = bags.begin(); it != bags.end(); it++) {

        while (!(*it).empty()) {
            if ((*it).top()->getPresent())
                presents.push_back((*it).top());
            else
                auxStack.push((*it).top());
            (*it).pop();
        }

        while (!auxStack.empty()) {
            (*it).push(auxStack.top());
            auxStack.pop();
        }

    }
    return presents;
}

