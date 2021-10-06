//
// Created by Tiago on 16/11/2019.
//

#ifndef TESTE_2016_AFTERSALESSERVICE_H
#define TESTE_2016_AFTERSALESSERVICE_H


#include <vector>
#include <queue>
#include <vector>
#include "Article.h"

class AfterSalesService {
    std::vector<Article*> presentsTable;
    const std::queue<Article*>::size_type toWrapQueueSize;
    std::queue<Article*> toWrap;
    std::queue<Article*> toDeliver;
public:
    static int tableOrdinal;
    AfterSalesService(int toWrapQueueSize);
    AfterSalesService(int twqs, std::queue<Article*> tw) : toWrapQueueSize(twqs), toWrap(tw) {};
    std::vector<Article*> getPresentsTable() const;
    std::queue<Article*> getToWrap() const;
    std::queue<Article*> getToDeliver() const;
    void dropPresentsOnTable(std::vector<Article*> presents);

    //--- TO IMPLEMENT
    std::vector<Article*> pickPresentsFromTable(long client);
    void sortArticles();
    void enqueueArticles();
    Article* wrapNext();
};


#endif //TESTE_2016_AFTERSALESSERVICE_H
