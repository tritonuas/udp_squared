#ifndef HELPER_H_
#define HELPER_H_

#include <stdint.h>

/*
    Extracts the payload ID and payload state from the single "id" byte in a packet.

    Byte format:
    [7:6] -> Reserved (0)
    [5:3] -> Payload ID
    [2:0] -> Payload state

    @param id: The raw "id" field in a packet.
    @param payloadID: The address where you want to store the extracted payload ID.
    @param state: The address where you want to store the extracted payload state.
*/
void parseID(uint8_t id, uint8_t* payloadID, uint8_t* state) {
    *payloadID = (id & 0b00111000) >> 3;
    *state  = (id & 0b00000111);
}

#endif HELPER_H_