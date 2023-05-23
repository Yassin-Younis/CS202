/**
* Author : Yassin Younis
* ID: 22101310
* Section : 002
* Homework : 3
* Description : Contains various methods to simulate and load data values.
*/

#include <fstream>
#include <algorithm>
#include <valarray>
#include "SimulationMgr.h"

SimulationMgr::SimulationMgr(std::string dataFilePath) {
    std::ifstream data(dataFilePath); // open the file for reading

    int numOfCreatures = 0;
    data >> numOfCreatures;

    std::string line;
    getline(data, line);

    for (int i = 0; i < numOfCreatures; i++) {
        getline(data, line);
        std::istringstream ss(line); // create a string stream to parse the line
        std::string num;
        getline(ss, num, ',');
        int id = stod(num);
        getline(ss, num, ',');
        double x = stod(num);
        getline(ss, num, ',');
        double y = stod(num);
        getline(ss, num, ',');
        int health = stod(num);
        Creature new_creature(id, x, y, health);
        creatures.push_back(new_creature);
        std::sort(creatures.begin(), creatures.end());
    }
    while (getline(data, line)) { // read the file line by line
        std::istringstream ss(line); // create a string stream to parse the line
        std::string num;

        getline(ss, num, ',');
        int id = stod(num);
        getline(ss, num, ',');
        double x = stod(num);
        getline(ss, num, ',');
        double y = stod(num);
        getline(ss, num, ',');
        int quality = stod(num);
        getline(ss, num, ',');
        int spawnTime = stod(num);
        Food new_food(id, x, y, quality, spawnTime);
        queued_food.insert(new_food);
    }
    data.close(); // close the file

    while (areCreaturesAlive()) {
        advance();
    }
}

void SimulationMgr::advance() {
    printState();
    spawnFood();
    for (int i = 0; i < creatures.size(); i++) {
        if (creatures[i].alive) {
            killSurroundings(creatures[i]);
        }
    }
    for (int i = 0; i < creatures.size(); i++) {
        if (creatures[i].alive) {
            eatSurroundings(creatures[i]);
        }
    }
    for (int i = 0; i < creatures.size(); i++) {
        if (creatures[i].alive) {
            move(creatures[i]);
        }
    }

    for (int i = 0; i < creatures.size(); i++) {
        if (creatures[i].alive) {
            creatures[i].healthDeduct();
        }
    }
    current_time++;

}


void SimulationMgr::spawnFood() {
    if (queued_food.current_size > 0) {
        while (queued_food.peek().spawnTime == current_time && queued_food.current_size > 0) {
            Food temp = queued_food.pop();
            temp.sortByQuality();
            current_food.insert(temp);
        }
    }
}

void SimulationMgr::printState() {
    for (int i = 0; i < creatures.size(); i++) {
        std::cout << creatures[i];
    }
}

void SimulationMgr::killSurroundings(Creature &creature) {
    for (int i = 0; i < creatures.size(); i++) {
        if (creatures[i].id != creature.id && euclideanDistance(creature, creatures[i]) < 2 &&
            creatures[i].alive && creatures[i].health <= creature.health) {
            creatures[i].kill();
        }
    }
}

double SimulationMgr::euclideanDistance(Creature &first, Creature &second) {
    double dx = second.x - first.x;
    double dy = second.y - first.y;
    return sqrt(dx * dx + dy * dy);
}

double SimulationMgr::euclideanDistance(Creature &first, Food &second) {
    double dx = second.x - first.x;
    double dy = second.y - first.y;
    return sqrt(dx * dx + dy * dy);
}

void SimulationMgr::eatSurroundings(Creature &creature) {
    Food best_food = current_food.peek();
    if (current_food.current_size > 0 && euclideanDistance(creature, best_food) < 1) {
        creature.health += best_food.quality;
        current_food.remove();
    }
}

void SimulationMgr::move(Creature &creature) {
    if (current_food.current_size > 0) {
        double moveUnits = 1;
        if (creature.health>10) moveUnits = 10.0/creature.health;
        Food best_food = current_food.peek();
        double dx = best_food.x - creature.x;
        double dy = best_food.y - creature.y;
        double magnitude = sqrt ((dx*dx)+(dy*dy));
        dx /= magnitude;
        dy /= magnitude;
        dx *= moveUnits;
        dy *= moveUnits;
        creature.x += dx;
        creature.y += dy;
    }
}

bool SimulationMgr::areCreaturesAlive() {
    for (int i =0; i<creatures.size(); i++) {
        if (creatures[i].alive) return true;
    }
    return false;
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Please provide a file name as a command-line argument.\n e.g: ./hw3 data.txt";
        return 1;
    }
    SimulationMgr mgr(argv[1]);
    return 0;
}
