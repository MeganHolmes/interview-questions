// Model an elevator as a state machine. Close and open doors, move between
// 21 floors in response to button presses, buttons depress after input.
// Arrays are not allowed

/* Design

Inputs:
call buttons on each floor
floor buttons for each floor inside the elevator

State of the elevator consists of 3 pieces of information
1. Moving up, down, or stationary
2. Current floor of the elevator (neglecting in between floors for simplicity)
3. floors requested
4. last moving direction

*/

// Includes
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

// Defines
#define NUM_FLOORS 21

// Enums
enum elevator_movement
{
    UP,
    DOWN,
    STOPPED
};

// Structs
struct elevator_state
{
    enum elevator_movement movement;
    enum elevator_movement previous_movement;
    uint32_t current_floor;
    uint32_t floors_requested;
};

struct buttons
{
    uint32_t floor_buttons;
    uint32_t elevator_buttons;
};

// Helper function to visualize where the elevator is and what floors are
// requested
void print_binary(uint32_t input, uint32_t num_bits)
{

    while (num_bits > 0)
    {
        uint32_t bit_val = 1 << num_bits - 1;

        if (input >= bit_val)
        {
            printf("1");
            input = input - bit_val;
        }
        else
        {
            printf("0");
        }

        num_bits--;
    }
}

// This is to simulate new buttons being pressed during operations
struct buttons check_buttons(int itr)
{
    struct buttons inputs;
    inputs.elevator_buttons = 0;
    inputs.floor_buttons = 0;

    switch (itr)
    {
    case 1:
    {
        inputs.floor_buttons = 1 << 17;
        break;
    }
    case 2:
    {
        inputs.elevator_buttons = 1 << 4;
        break;
    }
    case 4:
    {
        inputs.floor_buttons = 1 << 10;
        break;
    }
    case 10:
    {
        inputs.elevator_buttons = 1 << 11;
        inputs.floor_buttons = 1 << 20;
        break;
    }
    default:
    {
        // nop
    }
    }

    return inputs;
}

void display_building(struct elevator_state *state)
{
    printf("Elevator: ");
    print_binary(state->current_floor, NUM_FLOORS);
    printf("\nFloors:   ");
    print_binary(state->floors_requested, NUM_FLOORS);
    printf("\n");
}

// Generates a mask of all ones below end_pos. ie if end_pos == 0100 the mask
// will be 0011.
uint32_t generate_bit_mask(uint32_t* end_pos)
{
    uint32_t mask = 0;

    while (mask < *end_pos)
    {
        mask = mask << 1;
        mask = mask | 1;
    }

    return mask;
}

bool determine_if_floors_below(uint32_t requested, uint32_t *current)
{
    uint32_t mask = generate_bit_mask(current);

    requested = requested & mask; // Removes all ones above current

    if (requested > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void determine_direction(struct elevator_state *state)
{
    if (state->floors_requested != 0)
    {
        switch (state->previous_movement)
        {
        case STOPPED: // Stopped could be optmized to go the nearest floor.
        case UP:
        {
            if (state->current_floor < state->floors_requested)
            {
                state->movement = UP;
            }
            else
            {
                state->movement = DOWN;
            }
            break;
        }
        case DOWN:
        {
            if (state->current_floor < state->floors_requested)
            {
                if (determine_if_floors_below(state->floors_requested,
                                              &state->current_floor))
                {
                    state->movement = DOWN;
                }
                else
                {
                    state->movement = UP;
                }
            }
            else
            {
                state->movement = DOWN;
            }
            break;
        }
        default:
        {
            printf("ERROR: INVALID PREVIOUS MOVEMENT");
        }
        }
    }
    else
    {
        state->movement = STOPPED;
    }

    state->previous_movement = state->movement;
}

void move_elevator(struct elevator_state *state)
{
    switch (state->movement)
    {
    case UP:
    {
        state->current_floor = state->current_floor << 1;
        break;
    }
    case DOWN:
    {
        state->current_floor = state->current_floor >> 1;
        break;
    }
    default:
    {
        printf("Elevator did not move\n");
    }
    }
}

void run_elevator()
{
    struct elevator_state state;
    state.movement = STOPPED;
    state.current_floor = 1 << 12;
    state.floors_requested = 0;
    state.previous_movement = STOPPED;

    // This was a while(true) loop but i want to use the iterations to simulate
    // new buttons being pressed while the elevator is moving
    for (int itr = 0; itr < 45; itr++)
    {

        struct buttons new_inputs = check_buttons(itr);

        state.floors_requested = state.floors_requested |
                                 new_inputs.elevator_buttons |
                                 new_inputs.floor_buttons;

        display_building(&state);

        if (state.movement == STOPPED)
        {
            determine_direction(&state);
        }

        if ((state.current_floor & state.floors_requested) != 0)
        {
            printf("Doors open, people enter / exit, doors close\n");
            state.movement = STOPPED;
            state.floors_requested = state.current_floor ^
                                     state.floors_requested;
        }
        else
        {
            move_elevator(&state);
        }
    }
}

void main()
{
    run_elevator();
}
