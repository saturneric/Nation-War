//
//  factory.cpp
//  nation_war
//
//  Created by Saturneric on 17/1/16.
//  Copyright © 2017年 Bakantu Eric. All rights reserved.
//


#include "game.h"

list<class factory *> ftc_vec;

factory::factory(class land *p_lnd, class nation *p_ntn, int t_plcnum, int num){
    pm_ntn = p_ntn;
    pm_lnd = p_lnd;
    plcnum = t_plcnum;
    mpw = num;
    pdt = p_ntn->pdteff;
    ftc_vec.push_back(this);
}

factory::~factory(void){
    remove(ftc_vec.begin(),ftc_vec.end(),this);
    delete this;
}

int factory::setmpw(int num){
    if(num < plcnum*pdt){
        mpw = num;
    }
    return 0;
}

int factory::upgrade(void){
    pdt = pm_ntn->pdteff;
    return 0;
}

int factory::setplc(int num){
    if (num < 0) return -1;
    if (num * pm_ntn->plcpeo < mpw){
        mpw = num * pm_ntn->plcpeo;
    }
    plcnum = num;
    return 0;
}

int factory::getpdt(void){
    return (mpw * pdt * (1 - pm_ntn->embezzle)) - (plcnum * pm_ntn->plcoffcst);
}

