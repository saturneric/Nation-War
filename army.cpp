//
//  army.cpp
//  nation_war
//
//  Created by Saturneric on 17/1/16.
//  Copyright © 2017年 Bakantu Eric. All rights reserved.
//

#include "game.h"
#include "event.h"

list<class army *> amy_vec;

army::army(class nation *p_ntn, class land *p_lnd, int t_amyofe, int num){
    pm_lnd = p_lnd;
    pm_ntn = p_ntn;
    amyofe = t_amyofe;
    sldmun = num;
    sldeqp = p_ntn->amyeqp;
    amycst = p_ntn->amycst;
    amy_vec.push_back(this);
}

army::~army(void){
    remove(amy_vec.begin(), amy_vec.end(), this);
    delete this;
}

int army::upgrade(void){
    sldmun = amyofe * (pm_ntn->amypeo);
    sldeqp = pm_ntn->amyeqp;
    amycst = pm_ntn->amycst;
    return 0;
}

int army::fight(void){
    return sldmun*sldeqp;
}

int army::kill(int num){
    if (num <= sldmun){
        sldmun -= num;
    }
    else return -1;
    return 0;
}

int army::add(int num){
    if ((sldmun + num) <= (pm_ntn->amypeo * amyofe)){
        if (pm_lnd->manpow >= num){
            sldmun += num;
        }
        else return -1;
    }
    else return  -1;
    return  0;
}

int army::move(class land *toland){
    addarmymove(pm_lnd, toland, this);
    return 0;
}

int army::amy_cost(void){
    return (sldmun * (1+pm_ntn->embezzle) * amycst) + (amyofe * pm_ntn->amyoffcst);
}

int army::del(void){
    remove(amy_vec.begin(), amy_vec.end(), this);
    return 0;
}

