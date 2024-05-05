#ifndef HELPER_H_
#define HELPER_H_

#include <stdint.h>
#include <assert.h>

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

packet_t makeDropNowPacket(bottle_t bottle) {
    packet_t p;
    p.header = (uint8_t) DROP_NOW;
    p.id     = (uint8_t) bottle;
    return p;
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

packet_t makeModePacket(header_t header, bottle_t payloadID,
    payload_state_t state, drop_mode_t mode)
{
    assert(header == ACK_MODE || header == SET_MODE);

    packet_t p;
    mode_packet_t* p_mode = (mode_packet_t*)(&p);
    p_mode->header  = (uint8_t) header;
    p_mode->id      = makeID(payloadID, state);
    p_mode->mode    = (uint8_t) mode;
    p_mode->version = (uint8_t) PROTOCOL_VERSION;
    return (p);
}

packet_t makeHeartbeatPacket(bottle_t payloadID, payload_state_t state,
    float payload_lat, float payload_lng, uint16_t volts, uint16_t altitude_m)
{
    packet_t p;
    heartbeat_packet_t* p_hb = (heartbeat_packet_t*)(&p);
    p_hb->header = (uint8_t) HEARTBEAT;
    p_hb->id = makeID(payloadID, state);
    p_hb->payload_lat = payload_lat;
    p_hb->payload_lng = payload_lng;
    p_hb->volts = volts;
    p_hb->altitude_m = altitude_m;
    return p;
}

packet_t makeLatLngPacket(header_t header, bottle_t payloadID, payload_state_t state,
    float drop_lat, float drop_lng, uint32_t curr_alt_m)
{
    assert(header == SEND_LATLNG || header == ACK_LATLNG);

    packet_t p;
    latlng_packet_t* p_ll = (latlng_packet_t*)(&p);
    p_ll->header = (uint8_t) header;
    p_ll->id = makeID(payloadID, state);
    p_ll->drop_lat = drop_lat;
    p_ll->drop_lng = drop_lng;
    p_ll->curr_alt_m = curr_alt_m;
    return p;
}

packet_t makeArmPacket(header_t header, bottle_t payloadID, payload_state_t state, uint32_t curr_alt_m) {
    assert(header == ACK_ARM || header == ACK_DISARM ||
        header == ARM || header == DISARM);

    packet_t p;
    arm_packet_t* p_arm = (arm_packet_t*)(&p);
    p_arm->header = (uint8_t) header;
    p_arm->id = makeID(payloadID, state);
    p_arm->curr_alt_m = curr_alt_m;
    return p;
}


#endif  // HELPER_H_