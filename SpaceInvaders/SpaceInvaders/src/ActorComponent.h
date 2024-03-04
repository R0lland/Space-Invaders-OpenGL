#pragma once

class ActorComponent
{
public:
    //virtual ~ActorComponent() = default;
    //ActorComponent();
    virtual void Initialize();
    virtual void Update(const float deltaTime);
};
