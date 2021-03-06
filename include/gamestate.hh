#ifndef GAMESTATE_HH
#define GAMESTATE_HH

#include <string>

namespace MyGame {
  struct GameState {

    virtual void update() = 0;
    virtual void render() = 0;

    virtual bool onEnter() = 0;
    virtual bool onExit() = 0;

    virtual std::string stateId() const = 0;
  };
}

#endif
