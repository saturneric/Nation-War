//
//  land.h
//  nation_war
//
//  Created by Saturneric on 17/1/16.
//  Copyright © 2017年 Bakantu Eric. All rights reserved.
//

#ifndef land_h
#define land_h

class land {
public:
    int manpow;
    int mpwplus;
    int mpwmax;
    int resource;
    int resplus;
    int resmax;
    int fctnum;
    int fctinit;
    class nation *pm_ntn;
    
    int resrec(void);
    int mpwrec(void);
    int getmpw(int num);
    int getres(int num);
    int cgentn(class nation *p_ntn);
    
    land(void);
    ~land(void);
};

#endif /* land_h */
