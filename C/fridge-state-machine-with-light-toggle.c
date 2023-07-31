// Model a fridge as a state machine. If a toggle is set the light should stay
// on all the time. Must be an event-driven machine

// Includes
#include <stdio.h>

// Defines

// Enums
enum toggle {OFF, ON};
enum door {OPEN, CLOSED};

enum event{
    DOOR_OPEN,
    DOOR_CLOSED,
    ALWAYS_ON_PRESSED,
    ALWAYS_ON_UNPRESSED};

// structs
struct state{
    enum toggle light;
    enum toggle always_on;
};



void door_open_handler(struct state* state)
{
    state->light = ON;
}

void door_closed_handler(struct state* state)
{
    if (state->always_on != ON)
    {
        state->light = OFF;
    }
}

void always_on_pressed(struct state* state)
{
    state->always_on = ON;
    state->light = ON;
}

void always_on_unpressed(struct state* state)
{
    state->always_on = OFF;
    state->light = OFF; // User error if they press the button while door open
}

void event_handler(struct state* state, enum event* ev)
{
    if (*ev == DOOR_OPEN)
    {
        door_open_handler(state);
    }
    else if (*ev == DOOR_CLOSED)
    {
        door_closed_handler(state);
    }
    else if (*ev == ALWAYS_ON_PRESSED)
    {
        always_on_pressed(state);
    }
    else if (*ev == ALWAYS_ON_UNPRESSED)
    {
        always_on_unpressed(state);
    }
}

void main ()
{
    struct state fridge;
    fridge.light = OFF;
    fridge.always_on = OFF;

    enum event ev;
    ev = ALWAYS_ON_PRESSED;

    event_handler(&fridge, &ev);

    printf("Light on = %d\n", fridge.light);
}
