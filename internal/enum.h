#ifndef ENUM_H_
#define ENUM_H_

enum header {
    RESET       = 7,

    HEARTBEAT   = 10,
    
    SET_MODE    = 20,
    ACK_MODE    = 21,

    DROP_NOW    = 30,
    
    ARM         = 40,
    ACK_ARM     = 41,

    DISARM      = 50,
    ACK_DISARM  = 51,

    SEND_LATLNG = 60,
    ACK_LATLNG  = 61,

    DROPPING    = 255,
};
typedef enum header header_t;

enum bottle {
    A = 1,
    B, C, D, E
};
typedef enum bottle bottle_t;

enum payload_state {
    
};
typedef enum payload_state payload_state_t;

#endif  // ENUM_H_