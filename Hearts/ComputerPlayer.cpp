#include "ComputerPlayer.hpp"

static int count = 1;
// Count if to keep track of how many computer players there is

ComputerPlayer::ComputerPlayer() : Player("Computer " + std::to_string(count++)) {}

