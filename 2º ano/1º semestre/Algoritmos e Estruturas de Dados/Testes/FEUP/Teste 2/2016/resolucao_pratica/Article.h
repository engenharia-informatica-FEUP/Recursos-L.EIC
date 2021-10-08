//
// Created by Tiago on 16/11/2019.
//

#ifndef TESTE_2016_ARTICLE_H
#define TESTE_2016_ARTICLE_H


class Article {
    const long client;
    const long barCode;
    bool present;
    bool deliverHome;
    int presentNumber;
    int arrivalNumber;
public:
    Article(long client, long barCode);
    long getClient() const;
    long getBarCode() const;
    bool getPresent() const;
    void setPresent(bool present);
    bool getDeliverHome() const;
    void setDeliverHome(bool deliverHome);
    int getPresentNumber() const;
    void setPresentNumber(int presentNumber);
    int getArrivalNumber() const;
    void setArrivalNumber(int arrivalNumber);
};



#endif //TESTE_2016_ARTICLE_H
