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

enum drop_mode {
    GUIDED = 1,
    UNGUIDED = 2
};
typedef enum drop_mode drop_mode_t;

enum bottle {
    UDP2_A = 1,
    UDP2_B, 
    UDP2_C, 
    UDP2_D, 
    UDP2_E
};
typedef enum bottle bottle_t;

enum payload_state {
    OBC_NULL = 0 // Sent by the OBC, does not map to any state on the payload
};
typedef enum payload_state payload_state_t;

#endif  // ENUM_H_