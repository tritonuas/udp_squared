#ifndef HELPER_H_
#define HELPER_H_

#include <stdint.h>

#include "packet.h"
#include "enum.h"

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

/*
    Takes the payload ID and payload state, and does the bit
    manipulation to fit them in the same byte, according to the schema
    specified above.
*/
uint8_t makeID(bottle_t payloadID, payload_state_t state) {
    return (((uint8_t)(payloadID) << 3) | (uint8_t)(state));
}

/*
    Makes a reset packet to send to a specific bottle.

    Used by the OBC to create a RESET packet
*/
packet_t makeResetPacket(bottle_t bottle) {
    packet_t p;
    p.header = (uint8_t) RESET;
    p.id     = (uint8_t) bottle;
    return p;
}

mode_packet_t makeModePacket(header_t header, bottle_t payloadID,
    payload_state_t state, drop_mode_t mode)
{
    mode_packet_t p;
    p.header  = (uint8_t) header;
    p.id      = makeID(payloadID, state);
    p.mode    = (uint8_t) mode;
    p.version = (uint8_t) PROTOCOL_VERSION;
    return p;
}

// TODO: make more helper functions

#endif HELPER_H_