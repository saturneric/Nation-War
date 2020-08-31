//
//  event.h
//  nation_war
//
//  Created by Saturneric on 17/1/16.
//  Copyright © 2017年 Bakantu Eric. All rights reserved.
//

#ifndef event_h
#define event_h

class war{
    class army *f_amy;
    class army *s_amy;
    int f_rand;
    int s_rand;
    
public:
    war(class army *pf_amy, class army *ps_amy);
    class army *fight(void);
    
};

class move{
    class army *p_amy;
    class land *f_lnd;
    class land *t_lnd;
    
public:
    move(class army *p_amy, class land *f_lnd, class land *t_lnd);
    int go(void);
};

class event{
    int time;
    void *(func());
    void *value;
public:
    event(int time, void *(func()), void *value);
};

#endif /* event_h */
