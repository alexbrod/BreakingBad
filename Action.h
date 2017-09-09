//
// Created by vladimir khotyakov on 07/09/2017.
//

#ifndef BREAKINGBAD_ACTIONS_H
#define BREAKINGBAD_ACTIONS_H

#include <ostream>

class Action{
protected:
    int duration;
    float teamp;
    int score;

public:
    Action(int duration, float teamp, int score) : duration(duration), teamp(teamp), score(score) {

    }

    int getDuration() const {
        return duration;
    }

    void setDuration(int duration) {
        Action::duration = duration;
    }

    float getTeamp() const {
        return teamp;
    }

    void setTeamp(float teamp) {
        Action::teamp = teamp;
    }

    int getScore() const {
        return score;
    }

    void setScore(int score) {
        Action::score = score;
    }

    bool operator==(const Action &rhs) const {
        return duration == rhs.duration &&
               teamp == rhs.teamp &&
               score == rhs.score;
    }

    bool operator!=(const Action &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const Action &rhs) const {
        if (duration < rhs.duration)
            return true;
        if (rhs.duration < duration)
            return false;
        if (teamp < rhs.teamp)
            return true;
        if (rhs.teamp < teamp)
            return false;
        return score < rhs.score;
    }

    bool operator>(const Action &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Action &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Action &rhs) const {
        return !(*this < rhs);
    }

    friend ostream &operator<<(ostream &os, const Action &action) {
        os << "duration: " << action.duration << " teamp: " << action.teamp << " score: " << action.score;
        return os;
    }
};

#endif //BREAKINGBAD_ACTIONS_H
