#ifndef ANIMATIONS_HPP_INCLUDED
#define ANIMATIONS_HPP_INCLUDED
#include <vector>

enum AnimationState{Stop, Once, Loop};

class AnimationPreset
{
public:

    sf::IntRect rect;
    double length;
    unsigned int framesCount;
    unsigned int framesPerRow;

    AnimationPreset(sf::IntRect r, double l=0, unsigned int fc = 1, unsigned int fpr=0)
        : rect(r), length(l), framesCount(fc), framesPerRow(fpr)
    {
    }
};


class Animation
{

    double frameCounter;

public:
    sf::IntRect baseFrame;
    double length;
    unsigned int framesCount;
    unsigned int framesPerRow;

    AnimationState state = Stop;

    void update(double deltaTime)
    {
        if(state == Stop) return;
        frameCounter += deltaTime;
        if(frameCounter > length)
        {
            frameCounter = 0;
            if(state == Once)
                state = Stop;
        }
    }

    void reset()
    {
        frameCounter = 0;
    }

    sf::IntRect get() const
    {
        //std::cout<<framesCount<<" "<<frameCounter<<" "<<length<<std::endl;
        return get(framesCount * frameCounter/length);
    }

    sf::IntRect get(int f) const
    {
        f%=framesCount;
        if(framesPerRow == 0)
        {
            return sf::IntRect(baseFrame.left + f*baseFrame.width,
                               baseFrame.top,
                               baseFrame.width,
                               baseFrame.height);
        }
        else
        {
            int hf = f%framesPerRow;
            int vf = f/framesPerRow;
            return sf::IntRect(baseFrame.left + hf*baseFrame.width,
                               baseFrame.top  + vf*baseFrame.height,
                               baseFrame.width,
                               baseFrame.height);
        }
    }/*
<<<<<<< HEAD

=======

>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957*/
    Animation(const AnimationPreset& a)
        : baseFrame(a.rect), length(a.length), framesCount(a.framesCount), framesPerRow(a.framesPerRow)
    {

    }
    /*
<<<<<<< HEAD

=======

>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
*/
    void setPreset(const AnimationPreset& a)
    {
        reset();
        baseFrame = a.rect;
        length = a.length;
        framesCount = a.framesCount;
        framesPerRow = a.framesPerRow;
    }
    /*
<<<<<<< HEAD

=======

>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
*/
    bool compareWithPreset(const AnimationPreset& ap)
    {
        return baseFrame    == ap.rect         &&
               length       == ap.length       &&
               framesCount  == ap.framesCount  &&
               framesPerRow == ap.framesPerRow;
    }
};


namespace AnimationPresets
{
//<<<<<<< HEAD
    const AnimationPreset PlayerIdle{sf::IntRect(0,0,16,16), 1, 2};
    const AnimationPreset PlayerWalk{sf::IntRect(0,16,16,16), 0.5, 4};
    const AnimationPreset PlayerFly {sf::IntRect(16,16,16,16), 0, 1};
    /*
=======
    AnimationPreset PlayerIdle{sf::IntRect(0,0,16,16), 1, 2};
    AnimationPreset PlayerWalk{sf::IntRect(0,16,16,16), 0.5, 4};
    AnimationPreset PlayerFly {sf::IntRect(16,16,16,16), 0, 1};
>>>>>>> 39ba166d83db2967e509b8e1fc77bc542fb82957
*/
}








#endif // ANIMATIONS_HPP_INCLUDED
