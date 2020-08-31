//
//  nation.cpp
//  nation_war
//
//  Created by Saturneric on 17/1/16.
//  Copyright © 2017年 Bakantu Eric. All rights reserved.
//

#include "game.h"

list<class nation *> ntn_vec;


nation::nation(int s_id){
    amycst = 1;
    fund = 1000;
    embezzle = 0.5;
    pdteff = 10;
    n_id = s_id;
    plcpeo = 20;
    amypeo = 50;
    amyeqp = 1;
    amyoffcst = 15;
    plcoffcst = 10;
    lndplus = 2;
}

int nation::send_fund(int send){
    fund += send;
    return 0;
}

int nation::set_amy(int sld_num,int mf_num, class land *p_land){
    if (sld_num <= p_land->manpow && p_land->pm_ntn == this){
        new army(this, p_land, mf_num, sld_num);
        p_land->getmpw(sld_num);
    }
    else return -1;
    return 0;
}

int nation::set_fct(int mpw_num, int pf_num,class land *p_land){
    if (mpw_num <= p_land->manpow && p_land->pm_ntn == this){
        if (p_land->fctnum < (p_land->fctinit+this->lndplus)){
            new factory(p_land,this,pf_num,mpw_num);
            p_land->getmpw(mpw_num);
        }
        else return -2;
    }
    else return -1;
    return 0;
}

int pdt_tech_def::upd_fct(class nation *p_ntn){
    if (p_ntn->fund - fctgde * fctgde * 100 >= 0){
        p_ntn->fund -= fctgde * fctgde * 100;
        p_ntn->pdteff = p_ntn->pdteff * fctgde;
    }
    else return -1;
    return 0;
}

int pdt_tech_def::upd_lnd(class nation *p_ntn){
    if (p_ntn->fund - lndgde * lndgde * 100 >= 0){
        p_ntn->fund -= lndgde * lndgde * 100;
        p_ntn->lndplus += 1;
    }
    return 0;
}

int ofc_tech_def::ugd_plc(class nation *p_ntn){
    if (p_ntn->fund - plcgde * plcgde * 150 >= 0){
        p_ntn->fund -= plcgde * plcgde * 150;
        plcgde += 1;
        p_ntn->plcpeo *= plcgde;
    }
    return 0;
}

int ofc_tech_def::ugd_amy(class nation *p_ntn){
    if (p_ntn->fund - amygde * amygde * 100 >= 0) {
        p_ntn->fund -= amygde * amygde * 100;
        p_ntn->amypeo *= amygde * amygde * 0.6;
    }
    return 0;
}

int ofc_tech_def::ugd_spy(class nation *p_ntn){
    if (p_ntn->fund - spygde * spygde * 50){
        p_ntn->fund -= spygde * spygde * 50;
        p_ntn->embezzle *= 0.85;
        
    }
    return 0;
}
