//
//  game.cpp
//  nation_war
//
//  Created by Saturneric on 17/1/21.
//  Copyright © 2017年 Bakantu Eric. All rights reserved.
//


#include "game.h"

list<class route *> route_vec;
list<class armymove *> armymove_vec;


route::route(class land *f_lnd, class land *t_lnd, int distance){
    this->f_lnd = f_lnd;
    this->t_lnd = t_lnd;
    this->distance = distance;
    route_vec.push_back(this);
}

int mdistance;
list<class route *> dway;

list<class route *> findway(class land *f_lnd, class land *t_lnd){
    dway.clear();
    mdistance = 0;
    list<class route *>ntway;
    getway(f_lnd, t_lnd, 0, ntway);
    return dway;
}

int getway(class land *f_lnd, class land *t_lnd,int tdistance, list<class route *>tway){
    class land *pt_lnd;
    while (pt_lnd == t_lnd){
        for(list<class route *>::iterator lit = route_vec.begin(); lit != route_vec.end(); lit++){
            if ((*lit)->f_lnd == f_lnd){
                tdistance += (*lit)->distance;
                tway.push_back(*lit);
                if ((*lit)->t_lnd == t_lnd){
                    if (mdistance == 0){
                        dway = tway;
                        mdistance = tdistance;
                        tway.pop_back();
                    }
                    else {
                        if (tdistance < mdistance){
                            dway = tway;
                            mdistance = tdistance;
                        }
                        tway.pop_back();
                        tdistance -= (*lit)->distance;
                    }
                }
                else{
                    list<class route *>ntway;
                    copy(tway.begin(), tway.end(), back_inserter(ntway));
                    if (mdistance != 0){
                        if (tdistance > mdistance){
                            tway.pop_back();
                            tdistance -= (*lit)->distance;
                        }
                        else{
                            getway((*lit)->f_lnd, t_lnd, tdistance, ntway);
                        }
                    }
                    else{
                        getway((*lit)->f_lnd, t_lnd, tdistance, ntway);
                    }
                }
            }
        }
    }
    tway.clear();
    return  0;
}

armymove::armymove(class land *templand, class land *toland, list<class route *>way, class army *parmy){
    armymove_vec.push_back(this);
    this->templnd = templand;
    this->tolnd = toland;
    this->way = way;
    proute = way.begin();
    lastdistance = (*proute)->distance;
    this->parmy = parmy;
}

int armymove::golnd(void){
    lastdistance -= parmy->armyv;
    if (lastdistance <= 0){
        templnd = (*proute)->t_lnd;
        parmy->pm_lnd = templnd;
        if (proute != way.end()){
            proute++;
            lastdistance = (*proute)->distance;
        }
        else{
            return -1;
        }
    }
    return 0;
}

int addarmymove(class land *templand, class land *toland, class army *parmy){
    list<class route *> way =  findway(templand, toland);
    armymove *tam = new armymove(templand, toland, way, parmy);
    armymove_vec.push_back(tam);
    return 0;
}

int engine(void){
    
    return 0;
}
