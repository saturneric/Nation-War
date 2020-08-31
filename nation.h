//
//  nation.h
//  nation_war
//
//  Created by Saturneric on 17/1/16.
//  Copyright © 2017年 Bakantu Eric. All rights reserved.
//

#ifndef nation_h
#define nation_h


class pdt_tech_def {
    int pdtgde;
    int fctgde;
    int lndgde;
public:
    int upd_fct(class nation *p_ntn);
    int upd_lnd(class nation *p_ntn);
};

class ofc_tech_def {
    int plcgde;
    int amygde;
    int emogde;
    int spygde;
public:
    int ugd_plc(class nation *p_ntn);
    int ugd_amy(class nation *p_ntn);
    int ugd_spy(class nation *p_ntn);
};

class amy_tech_def {
    int maxgde;
    int eqpgde;
    
public:
    int upd_eqp(class nation *p_ntn);
};

class nation {
public:
    int fund;
    double embezzle;
    double pdteff;
    int amyeqp;
    int n_id;
    int plcpeo;
    int amypeo;
    int amycst;
    int plcoffcst;
    int amyoffcst;
    int lndplus;

    class pdt_tech_def m_ptd;
    class ofc_tech_def m_otd;
    class amy_tech_def m_atd;
    
    int send_fund(int send);
    int set_amy(int sld_num,int mf_num, class land *p_land);
    int set_fct(int mpw_num, int pf_num,class land *p_land);
    nation(int s_id);
    ~nation(void);
    
};




#endif /* nation_h */
