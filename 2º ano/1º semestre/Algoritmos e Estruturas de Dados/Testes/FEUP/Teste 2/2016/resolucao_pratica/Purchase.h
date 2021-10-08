//
// Created by Tiago on 16/11/2019.
//

#ifndef TESTE_2016_PURCHASE_H
#define TESTE_2016_PURCHASE_H


#include <stack>
#include <list>
#include <vector>
#include "Article.h"

class Purchase {
    const long client;
    std::list< std::stack<Article*> > bags;
public:
    static const std::stack<Article*>::size_type BAG_SIZE = 5;
    Purchase(long client);
    Purchase(long c, std::list< std::stack<Article*> >& b) : client(c), bags(b) {};
    long getClient() const;
    std::list< std::stack<Article*> > getBags() const;

    //--- TO IMPLEMENT
    Article* createArticle(long barCode, bool present, bool deliverHome);
    void putInBag(Article* article);
    std::vector<Article*> popPresents();
};


#endif //TESTE_2016_PURCHASE_H
