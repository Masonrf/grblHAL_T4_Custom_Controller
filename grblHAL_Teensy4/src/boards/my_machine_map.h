#define BOARD_NAME "Masonrf_CNC"
#define BOARD_URL "https://github.com/Masonrf/grblHAL_T4_Custom_Controller"

#define X_STEP_PIN          (28u)
#define X_DIRECTION_PIN     (27u)
#define X_ENABLE_PIN        (26u)
#define X_LIMIT_PIN         (9u)

#define Y_STEP_PIN          (32u)
#define Y_DIRECTION_PIN     (31u)
#define Y_ENABLE_PIN        (30u)
#define Y_LIMIT_PIN         (10u)

#define Z_STEP_PIN          (14u)
#define Z_DIRECTION_PIN     (15u)
#define Z_ENABLE_PIN        (16u)
#define Z_LIMIT_PIN         (11u)

// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 0
#define M3_AVAILABLE
#define M3_STEP_PIN         (37u)
#define M3_DIRECTION_PIN    (38u)
#define M3_ENABLE_PIN       (39u)
#define M3_LIMIT_PIN        (12u)
#endif

// Define ganged axis or B axis step pulse and step direction output pins.
#if N_ABC_MOTORS == 2
#define M4_AVAILABLE
#define M4_STEP_PIN         (33u)
#define M4_DIRECTION_PIN    (34u)
#define M4_ENABLE_PIN       (35u)
#define M4_LIMIT_PIN        (24u)
#endif

// Define auxiliary out pins
#define AUXOUTPUT0_PIN      (20u) // AUX0
#define AUXOUTPUT1_PIN      (13u) // AUX1
#define AUXOUTPUT2_PIN      (41u) // AUX2
#define AUXOUTPUT3_PIN      (23u) // Coolant flood
#define AUXOUTPUT4_PIN      (22u) // Coolant mist
#define AUXOUTPUT5_PIN      (21u) // Vacuum
// #define AUXOUTPUT6_PIN      (21u) // 
// #define AUXOUTPUT7_PIN      (21u) // 

// Define aux input pins
#define AUXINPUT0_PIN       (25u) // ALARM1
#define AUXINPUT1_PIN       (29u) // ALARM2
#define AUXINPUT2_PIN       (17u) // ALARM3
#define AUXINPUT3_PIN       (40u) // ALARM4
#define AUXINPUT4_PIN       (36u) // ALARM5
#define AUXINPUT5_PIN       (4u)  // Safety door
#define AUXINPUT6_PIN       (2u)  // Probe
#define AUXINPUT7_PIN       (3u)  // Reset/Estop
#define AUXINPUT8_PIN       (6u)  // Feed hold
#define AUXINPUT9_PIN       (5u)  // Cycle start

// Define flood and mist coolant enable output pins.
#if COOLANT_ENABLE & COOLANT_FLOOD
#define COOLANT_FLOOD_PIN       AUXOUTPUT3_PIN
#endif
#if COOLANT_ENABLE & COOLANT_MIST
#define COOLANT_MIST_PIN        AUXOUTPUT4_PIN
#endif

#if PROBE_ENABLE
#define PROBE_PIN           AUXINPUT6_PIN
#endif

#if SAFETY_DOOR_ENABLE
#define SAFETY_DOOR_PIN     AUXINPUT5_PIN
#endif

// Define user-control controls (cycle start, reset, feed hold) input pins.
#if CONTROL_ENABLE & CONTROL_HALT
#define RESET_PIN           AUXINPUT7_PIN
#endif
#if CONTROL_ENABLE & CONTROL_FEED_HOLD
#define FEED_HOLD_PIN       AUXINPUT8_PIN
#endif
#if CONTROL_ENABLE & CONTROL_CYCLE_START
#define CYCLE_START_PIN     AUXINPUT9_PIN
#endif

#ifdef NETWORK_HOSTNAME
    #undef NETWORK_HOSTNAME
    #define NETWORK_HOSTNAME BOARD_NAME
#endif

#if I2C_ENABLE
#define I2C_PORT            0   // SCL = 19, SDA = 18
#endif