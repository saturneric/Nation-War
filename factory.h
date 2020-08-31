//
//  factory.h
//  nation_war
//
//  Created by Saturneric on 17/1/16.
//  Copyright © 2017年 Bakantu Eric. All rights reserved.
//

#ifndef factory_h
#define factory_h

class factory {
public:
    int mpw;
    int plcnum;
    int pdt;
    class land *pm_lnd;
    class nation *pm_ntn;
    
    int setmpw(int num);
    int getpdt(void);
    int upgrade(void);
    int setplc(int num);
    
    factory(class land *p_lnd, class nation *p_ntn, int t_plcnum, int num);
    ~factory(void);
};

#endif /* factory_h */
