#include "event.h"

// constructor sets all member variables
Event::Event(int eventID,
        int leagueID,
        std::string name,
        std::string shortName,
        int season,
        std::string day,
        std::string dateTime,
        std::string status,
        bool active,
        std::vector<int> fightIDs) {
    
    this->eventID = eventID;
    this->leagueID = leagueID;
    this->name = name;
    this->shortName = shortName;
    this->season = season;
    this->day = day;
    this->dateTime = dateTime;
    this->status = status;
    this->active = active;

    // CAN PROBABLY BE REPLACES WITH SIMPLE ASSIGNMENT, CODE LEFTOVER FROM WHEN FIGHTIDS WAS ARRAY
    for (long unsigned int i = 0; i < fightIDs.size(); i++) { // loop through fights and add
        this->fightIDs.at(i) = fightIDs.at(i);
    }
}

// deconstructor
Event::~Event() {
    // Cache::removeEvent(eventID);
}

// get appropriate member variable

int Event::getEventID() {
    return eventID;
}

int Event::getLeagueID() {
    return leagueID;
}

std::string Event::getName() {
    return name;
}

std::string Event::getShortName() {
    return shortName;
}

int Event::getSeason() {
    return season;
}

std::string Event::getDay() {
    return day;
}

std::string Event::getDateTime() {
    return dateTime;
}

std::string Event::getStatus() {
    return status;
}

bool Event::isActive() {
    return active;
}

std::vector<int> Event::getFightIDs() {
    return fightIDs;
}
