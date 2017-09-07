//
// Created by vladimir khotyakov on 07/09/2017.
//

#ifndef BREAKINGBAD_ACTIONS_H
#define BREAKINGBAD_ACTIONS_H

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
};

#endif //BREAKINGBAD_ACTIONS_H
