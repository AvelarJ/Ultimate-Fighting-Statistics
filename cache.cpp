#include "cache.h"

// initializes the static cache
void Cache::init(std::string outputPath) {
    Cache::outputPath = outputPath;

    Cache::updateCacheFromFile();
}

// get cache maps
std::map<int, Fighter*> Cache::getFighters() {


}

std::map<int, Fight*> Cache::getFights() {


}

std::map<int, Event*> Cache::getEvents() {


}

std::map<int, Bet*> Cache::getBets() {


}


// get elements by ID
Fighter* Cache::getFighter(int fighterID) {


}

Fight* Cache::getFight(int fightID) {


}

Event* Cache::getEvent(int eventID) {


}

Bet* Cache::getBet(int betID) {


}


// get or set the sportsdata.io API key
std::string Cache::getSportsDataAPIKey() {


}

void Cache::setSportsDataAPIKey(std::string sportsDataAPIKey) {


}


// get or set the output path of the cache
std::string Cache::getOutputPath() {


}

void Cache::setOutputPath(std::string outputPath) {


}


// read or write to cache
void Cache::writeCacheToFile() {


}

void Cache::updateCacheFromFile() {

    std::string line;
    std::ifstream myfile (Cache::outputPath);

    std::vector<std::string> rawFighters;
    std::vector<std::string> rawFights;
    std::vector<std::string> rawEvents;
    std::vector<std::string> rawBets;


    enum Section {APIkeys, fighters, fights, events, bets};
    Section cacheSection = APIkeys;

    if (myfile.is_open()) {
        getline (myfile,line);
        Cache::sportsDataAPIKey = line;
        while ( getline (myfile,line) ) {

            if (line.compare("[FIGHTERS]")) cacheSection = fighters;
            else if (line.compare("[FIGHTS]")) cacheSection = fights;
            else if (line.compare("[EVENTS]")) cacheSection = events;
            else if (line.compare("[BETS]")) cacheSection = bets;
            else {
                switch (cacheSection) {
                case fighters:
                    rawFighters.push_back(line);
                    break;

                case fights:
                    rawFights.push_back(line);
                    break;

                case events:
                    rawEvents.push_back(line);
                    break;

                case bets:
                    rawBets.push_back(line);
                    break;
                
                default:
                    break;
                }
            }
        }
        myfile.close();

        for(int i = 0; i < rawFighters.size(); i++) {
            Fighter* fighter = parseFighter(rawFighters[i]);
            addFighter(fighter->getFighterID(), fighter);
        }
        for(int i = 0; i < rawFights.size(); i++) {
            Fight* fight = parseFight(rawFights[i]);
            addFight(fight->getFightID(), fight);
        }
        for(int i = 0; i < rawEvents.size(); i++) {
            Event* event = parseEvent(rawEvents[i]);
            addEvent(event->getEventID(), event);
        }
        for(int i = 0; i < rawBets.size(); i++) {
            Bet* bet = parseBet(rawBets[i]);
            addBet(bet->getBetID(), bet);
        }

    } else {
        std::cout << "Error reading from cache file \"" + Cache::outputPath + "\". See README.md for more information on how to use UFS." << std::endl;
        exit(EXIT_FAILURE);
    }

}

// scan cache for invalid data and remove
void Cache::sanitizeCache() {


}

// parse serializable objects
Fighter* Cache::parseFighter(std::string rawFighter) {
    std::vector<std::string> memberVariables = Util::splitString(rawFighter, ",");

    for (int i = 0; i < memberVariables.size(); i++) {
        memberVariables.at(i) = Util::splitString(memberVariables.at(i), ":").at(Util::splitString(memberVariables.at(i), ":").size()-1);
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), '"');
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), ']');
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), '}');
    }

    return new Fighter(
        memberVariables.at(0),
        memberVariables.at(1),
        memberVariables.at(2),
        memberVariables.at(3),
        memberVariables.at(4),
        memberVariables.at(5),
        memberVariables.at(6),
        memberVariables.at(7),
        memberVariables.at(8),
        memberVariables.at(9),
        memberVariables.at(10),
        memberVariables.at(11),
        memberVariables.at(12),
        memberVariables.at(13),
        memberVariables.at(14),
        memberVariables.at(15),
        memberVariables.at(16),
        memberVariables.at(17),
        memberVariables.at(18),
        memberVariables.at(19), 
        memberVariables.at(23), // jump into career stats and append
        memberVariables.at(24),
        memberVariables.at(25),
        memberVariables.at(26),
        memberVariables.at(27),
        memberVariables.at(28),
        memberVariables.at(29)
    );
}

Fight* Cache::parseFight(std::string rawFight, int eventID) {
    std::vector<std::string> memberVariables = Util::splitString(rawFight, ",");

    for (int i = 0; i < memberVariables.size(); i++) {
        memberVariables.at(i) = Util::splitString(memberVariables.at(i), ":").at(Util::splitString(memberVariables.at(i), ":").size()-1);
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), '"');
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), ']');
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), '}');
    }

    FightStat fightstats[2];

    fightstats[0] = FightStat(
        memberVariables.at(12),
        memberVariables.at(13),
        memberVariables.at(14),
        memberVariables.at(15),
        memberVariables.at(16),
        memberVariables.at(17),
        memberVariables.at(18),
        memberVariables.at(19),
        memberVariables.at(20),
        memberVariables.at(21),
        memberVariables.at(22),
        memberVariables.at(23),
        memberVariables.at(24),
        memberVariables.at(25),
        memberVariables.at(26),
        memberVariables.at(27),
        memberVariables.at(28),
        memberVariables.at(29),
        memberVariables.at(30),
        memberVariables.at(31),
        memberVariables.at(32),
        memberVariables.at(33),
        memberVariables.at(34),
        memberVariables.at(35),
        memberVariables.at(36),
        memberVariables.at(37),
        memberVariables.at(67), // jump down to "Fighters" in JSON
        memberVariables.at(68),
        memberVariables.at(69),
        memberVariables.at(70),
        memberVariables.at(72), // line 71 of json is repeating
        memberVariables.at(73)
    );

    fightstats[0] = FightStat(
        memberVariables.at(38),
        memberVariables.at(39),
        memberVariables.at(40),
        memberVariables.at(41),
        memberVariables.at(42),
        memberVariables.at(43),
        memberVariables.at(44),
        memberVariables.at(45),
        memberVariables.at(46),
        memberVariables.at(47),
        memberVariables.at(48),
        memberVariables.at(49),
        memberVariables.at(50),
        memberVariables.at(51),
        memberVariables.at(52),
        memberVariables.at(53),
        memberVariables.at(54),
        memberVariables.at(55),
        memberVariables.at(56),
        memberVariables.at(57),
        memberVariables.at(58),
        memberVariables.at(59),
        memberVariables.at(60),
        memberVariables.at(61),
        memberVariables.at(62),
        memberVariables.at(63),
        memberVariables.at(77), // jump down to "Fighters" in JSON
        memberVariables.at(78),
        memberVariables.at(79),
        memberVariables.at(80),
        memberVariables.at(82), // line 81 of json is repeating
        memberVariables.at(83)
    );

    return new Fight(
        memberVariables.at(0),
        memberVariables.at(1),
        memberVariables.at(2),
        memberVariables.at(3),
        memberVariables.at(4),
        memberVariables.at(5),
        memberVariables.at(6),
        memberVariables.at(7),
        memberVariables.at(8),
        memberVariables.at(9),
        memberVariables.at(10),
        memberVariables.at(11),
        fightstats,
        eventID
    );
}

Event* Cache::parseEvent(std::string rawEvent) {
    std::vector<std::string> memberVariables = Util::splitString(rawEvent, ",");

    std::vector<int> fightIDsVec;

    for (int i = 0; i < memberVariables.size(); i++) {

        if (memberVariables.at(i).find("FighterId")) {
            fightIDsVec.push_back(Util::splitString(memberVariables.at(i), ":").at(Util::splitString(memberVariables.at(i), ":").size()-1));
        }

        memberVariables.at(i) = Util::splitString(memberVariables.at(i), ":").at(Util::splitString(memberVariables.at(i), ":").size()-1);
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), '"');
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), ']');
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), '}');
    }

    // int len = static_cast<int> fightIDsVec.size();
    // int fightIDs[len];
    // std::copy(fightIDsVec.begin(), fightIDsVec.end(), fightIDs);
    

    return new Event(
        memberVariables.at(0),
        memberVariables.at(1),
        memberVariables.at(2),
        memberVariables.at(3),
        memberVariables.at(4),
        memberVariables.at(5),
        memberVariables.at(6),
        memberVariables.at(7),
        memberVariables.at(8),
        fightIDsVec.data()
    );
}

// add, remove or replace fighters 
void Cache::addFighter(int fighterID, Fighter* fighter) {
    fighters.insert(std::pair<int, Fighter*>(fighterID, fighter));
}

void Cache::removeFighter(int fighterID) {
    fighters.erase(fighterID);
}

void Cache::replaceFighter(int fighterID, Fighter* fighter) {
    if (fighters.count(fighterID) == 0) fighters.insert(std::pair<int, Fighter*>(fighterID, fighter));
    else fighters.at(fighterID) = fighter;
}


// add, remove or replace fights 
void Cache::addFight(int fightID, Fight* fight) {
    fights.insert(std::pair<int, Fight*>(fightID, fight));
}

void Cache::removeFight(int fightID) {
    fights.erase(fightID);
}

void Cache::replaceFight(int fightID, Fight* fight) {
    if (fights.count(fightID) == 0) fights.insert(std::pair<int, Fight*>(fightID, fight));
    else fights.at(fightID) = fight;
}


// add, remove or replace events 
void Cache::addEvent(int eventID, Event* event) {
    events.insert(std::pair<int, Event*>(eventID, event));
}

void Cache::removeEvent(int eventID) {
    events.erase(eventID);
}

void Cache::replaceEvent(int eventID, Event* event) {
    if (events.count(eventID) == 0) events.insert(std::pair<int, Event*>(eventID, event));
    else events.at(eventID) = event;
}


// add, remove or replace bets 
void Cache::addBet(int betID, Bet* bet) {
    bets.insert(std::pair<int, Bet*>(betID, bet));
}

void Cache::removeBet(int betID) {
    bets.erase(betID);
}

void Cache::replaceBet(int betID, Bet* bet) {
    if (bets.count(betID) == 0) bets.insert(std::pair<int, Bet*>(betID, bet));
    else bets.at(betID) = bet;
}

