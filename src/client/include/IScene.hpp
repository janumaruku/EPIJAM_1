//
// Created by kotti on 08/02/2026.
//

#ifndef EPIJAM_1_ISCENE_HPP
#define EPIJAM_1_ISCENE_HPP

class IScene {
public:
    virtual ~IScene() = default;
    virtual void update(float dt) = 0;
    virtual void draw() = 0;
};


#endif //EPIJAM_1_ISCENE_HPP