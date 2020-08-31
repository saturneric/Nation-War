//
//  land.cpp
//  nation_war
//
//  Created by Saturneric on 17/1/16.
//  Copyright © 2017年 Bakantu Eric. All rights reserved.
//

#include "game.h"

list<class land *> land_vec;

land::land(){
    srand((unsigned int)time(NULL));
    manpow = rand()%500;
    mpwmax = rand()%2500 + 800;
    mpwplus = rand()%15;
    resource = rand()%1000;
    resmax = rand()%8000;
    resplus = rand()%50;
    pm_ntn = NULL;
    fctinit = rand()%4;
    fctnum = 0;
    land_vec.push_back(this);
}


land::~land(void){
    remove(land_vec.begin(),land_vec.end(),this);
    delete this;
}
int land::resrec(void){
    if (resource + resplus < resmax){
        resource += resplus;
    }
    else{
        resource = resmax;
    }
    return 0;
}

int land::mpwrec(void){
    if (manpow + mpwplus < mpwmax){
        manpow += mpwplus;
    }
    else {
        manpow = mpwmax;
    }
    return 0;
}

int land::getmpw(int num){
    if (num <= manpow){
        manpow -= num;
    }
    else return -1;
    return 0;
}

int land::getres(int num){
    if (num <= resource){
        resource -= num;
    }
    else return -1;
    return 0;
}

class nation *target_ntn = NULL;

bool ntn_fct(const class factory *p_fct) {
    if (p_fct->pm_ntn == target_ntn){
        return true;
    }
    return false;
}

int land::cgentn(class nation *p_ntn){
    if (p_ntn != NULL){
        target_ntn = pm_ntn;
        remove_if(ftc_vec.begin(),ftc_vec.end(),ntn_fct);
        target_ntn = NULL;
        pm_ntn = p_ntn;
        fctnum = 0;
    }
    else return -1;
    return 0;
}

