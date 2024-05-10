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
void parseID(uint8_t id, uint8_t* payloadID, uint8_t* state);

/*
    Takes the payload ID and payload state, and does the bit
    manipulation to fit them in the same byte, according to the schema
    specified above.
*/
extern "C" uint8_t makeID(bottle_t payloadID, payload_state_t state);

/*
    Makes a packet to tell a payload to drop all now
*/
packet_t makeDropNowPacket(bottle_t bottle);

/*
    Makes a reset packet to send to a specific bottle.

    Used by the OBC to create a RESET packet
*/
packet_t makeResetPacket(bottle_t bottle);

packet_t makeModePacket(header_t header, bottle_t payloadID,
    payload_state_t state, drop_mode_t mode);

packet_t makeHeartbeatPacket(bottle_t payloadID, payload_state_t state,
    float payload_lat, float payload_lng, uint16_t volts, uint16_t altitude_m);

packet_t makeLatLngPacket(header_t header, bottle_t payloadID, payload_state_t state,
    float drop_lat, float drop_lng, uint32_t curr_alt_m);

packet_t makeArmPacket(header_t header, bottle_t payloadID, payload_state_t state, uint32_t curr_alt_m);

#endif  // HELPER_H_