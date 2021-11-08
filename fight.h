#pragma once

#include <iostream>

#include "fightstat.h"
// #include "cache.h"

// represents a UFC fight
class Fight {
public: // public methods
    // constructor sets all member variables
    Fight(int fightID,
        int order,
        std::string status,
        std::string weightClass,
        std::string cardSegment,
        std::string referee,
        int rounds,
        int resultClock,
        int resultRound,
        std::string resultType,
        int winnerID,
        bool active,
        FightStat fightStats[2]);
    ~Fight(); // deconstructor

    // get appropriate member variables

    int getFightID();

    int getOrder();

    std::string getStatus(); 
    std::string getWeightClass();
    std::string getCardSegment();
    std::string getReferee();

    int getRounds();
    int getResultClock();
    int getResultRound();
    std::string getResultType();

    int getWinnerID();
    bool isActive();
    
    FightStat* getFightStats();
private: // private member variables
    int fightID;

    int order;

    std::string status; 
    std::string weightClass;
    std::string cardSegment;
    std::string referee;

    int rounds;
    int resultClock;
    int resultRound;

    std::string resultType;
    int winnerID;
    bool active;

    FightStat fightStats[2];
};