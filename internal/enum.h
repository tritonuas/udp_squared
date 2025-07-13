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

enum airdrop {
    UDP2_A = 1,
    UDP2_B = 2,
    UDP2_C = 3,
    UDP2_D = 4, 
    UDP2_ALL = 7
    // note max 3 bits for this value
};
typedef enum airdrop airdrop_t;

enum payload_state {
    OBC_NULL = 0, // Sent by the OBC, does not map to any state on the payload
    STANDBY, // Communication has been initiated with OBC; waiting to receive targets
    TARGET_ACQUIRED, // OBC has identified and sent target coords
    ARMED, // OBC has given OK to drop, waiting to reach drop zone
    DROP // released from aircraft, actively guiding/falling towards target
};
typedef enum payload_state payload_state_t;

#endif  // ENUM_H_