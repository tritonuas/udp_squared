#ifndef INCLUDE_PACKET_H_
#define INCLUDE_PACKET_H

#include <stdint.h>

#define PROTOCOL_VERSION 1
#define PACKET_SIZE_B 14

/*
    Generic packet to be sent over UDP.
    The data field should be parsed according to the specific packet that is expected.
    Note that a reset packet will take this form directly.

    More specific packet definitions 
*/
typedef struct {
    uint8_t header;
    uint8_t id;
    uint8_t data[PACKET_SIZE_B - 2];
} __attribute__((packed)) packet_t;

typedef struct {
    uint8_t  header;
    uint8_t  id;
    float    payload_lat;
    float    payload_lng;
    uint16_t volts;
    uint16_t altitude_m;
} __attribute__((packed)) heartbeat_packet_t;

typedef struct {
    uint8_t  header;
    uint8_t  id;
    uint8_t  mode;
    uint8_t  version;
    uint8_t  _RESERVED[PACKET_SIZE_B - 4];
} __attribute__((packed)) mode_packet_t;

typedef struct {
    uint8_t  header;
    uint8_t  id;
    float    drop_lat;
    float    drop_lng;
    uint32_t curr_alt_m;
} __attribute__((packed)) latlng_packet_t;

typedef struct {
    uint8_t  header;
    uint8_t  id;
    uint8_t  _RESERVED[PACKET_SIZE_B - 6];
    uint32_t curr_alt_m;
} __attribute__((packed)) arm_packet_t;

#endif  // INCLUDE_PACKET_H_