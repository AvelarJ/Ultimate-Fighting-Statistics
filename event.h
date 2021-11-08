#pragma once

#include <iostream>
#include <vector>

// #include "cache.h"

class Event {
public:
    Event(int eventID,
        int leagueID,
        std::string name,
        std::string shortName,
        int season,
        std::string day,
        std::string dateTime,
        std::string status,
        bool active,
        std::vector<int> fightIDs);
    ~Event();

    int getEventID();

    int getLeagueID();
    std::string getName();
    std::string getShortName();

    int getSeason();
    std::string getDay();
    std::string getDateTime();

    std::string getStatus();
    bool isActive();

    std::vector<int> getFightIDs();
private:
    int eventID;

    int leagueID;
    std::string name;
    std::string shortName;

    int season;
    std::string day;
    std::string dateTime;

    std::string status;
    bool active;

    std::vector<int> fightIDs;
};