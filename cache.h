#pragma once

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include <QObject>

#include "fighter.h"
#include "fight.h"
#include "event.h"
#include "bet.h"
#include "util.h"
#include "apihandler.h"

/**
 * \brief Represents all the data in the program
 * \details A static singleton class responsible for serializing/deserializing, reading/writing itself to a file and
 * updating itself from APIHandler when needed
 * \author Paul Scoropan
 */
class Cache {
public: // public methods
    /**
     * \brief Initialize the static cache
     * @param outputPath String holding the outputPath to be written to
     * @return bool true for success, error if else
     */
    static bool init(std::string outputPath);

    static void setAPIHandlersParent(QObject *parent);
    static QObject* getAPIHandlersParent();

    // get cache maps
    static std::map<int, Fighter*> getFighters();
    static std::map<int, Fight*> getFights();
    static std::map<int, Event*> getEvents();
    static std::map<int, Bet*> getBets();

    // get elements by ID
    static Fighter* getFighter(int fighterID);
    static Fight* getFight(int fightID);
    static Event* getEvent(int eventID);
    static Bet* getBet(int betID);

    // get or set the sportsdata.io API key
    static std::string getSportsDataAPIKey();
    static void setSportsDataAPIKey(std::string sportsDataAPIKey);

    // get or set the output path of the cache
    static std::string getOutputPath();
    static void setOutputPath(std::string outputPath);

    // read or write to cache
    static void writeCacheToFile();
    static void updateCacheFromFile();

    // scan cache for invalid data and remove
    static void sanitizeCache();

    // destroy the cache
    static void destroy();

private: // private member methods
    static Fighter* parseFighter(std::string rawFighter);
    static Fight* parseFight(std::string rawFight);
    static Event* parseEvent(std::string rawEvent);
    static Bet* parseBet(std::string rawBet);

    // add, remove or replace fighters 
    static void addFighter(int fighterID, Fighter* fighter);
    static void removeFighter(int fighterID);
    static void replaceFighter(int fighterID, Fighter* fighter);

    // add, remove or replace fights 
    static void addFight(int fightID, Fight* fight);
    static void removeFight(int fightID);
    static void replaceFight(int fightID, Fight* fight);

    // add, remove or replace events 
    static void addEvent(int eventID, Event* event);
    static void removeEvent(int eventID);
    static void replaceEvent(int eventID, Event* event);

    // add, remove or replace bets 
    static void addBet(int betID, Bet* bet);
    static void removeBet(int betID);
    static void replaceBet(int betID, Bet* bet);

private: // member variables
    static std::map<int, Fighter*> fighters;
    static std::map<int, Fight*> fights;
    static std::map<int, Event*> events;
    static std::map<int, Bet*> bets;

    static std::string sportsDataAPIKey;
    static std::string outputPath;
    static QObject* apiHandlersParent;

};