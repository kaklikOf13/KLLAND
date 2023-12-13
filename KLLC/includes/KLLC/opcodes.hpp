#ifndef kllc_opcodes_h
#define kllc_opcodes_h
#include "types.hpp"
namespace kllc{
    const OPCODE STOP=0;
    const OPCODE LOAD_GLOBAL=1;
    const OPCODE LOAD_LOCAL=2;
    const OPCODE EXIT_SCOPE=3;
    const OPCODE RESET_SCOPE=4;
    const OPCODE ENTER_SCOPE=5;
    const OPCODE EXECUTE_LOCAL=6;
    const OPCODE EXECUTE_GLOBAL=7;
    const OPCODE MOVE_TO_GLOBAL=8;
    const OPCODE MOVE_TO_LOCAL=9;
    const OPCODE MOVE_TO_REG=10;
    const OPCODE MOVE_LOCAL_TO_GLOBAL=11;
    const OPCODE MOVE_LOCAL_TO_LOCAL=12;
    const OPCODE MOVE_GLOBAL_TO_LOCAL=13;
    const OPCODE MOVE_GLOBAL_TO_GLOBAL=14;
    const OPCODE SUM1=15;
    const OPCODE SUM2=16;
    const OPCODE SUM3=17;
    const OPCODE SUM4=18;
    const OPCODE SUB1=19;
    const OPCODE SUB2=20;
    const OPCODE SUB3=21;
    const OPCODE SUB4=22;
    const OPCODE MULT1=23;
    const OPCODE MULT2=24;
    const OPCODE MULT3=25;
    const OPCODE MULT4=26;
    const OPCODE DIV1=27;
    const OPCODE DIV2=28;
    const OPCODE DIV3=29;
    const OPCODE DIV4=30;
    const OPCODE RETURN1=31;
    const OPCODE RETURN2=32;
    const OPCODE RETURN3=33;
    const OPCODE MOVE_64_TO_REG=34;
    const OPCODE MOVE_VALUE_TO_GLOBAL=35;
    const OPCODE MOVE_VALUE_TO_LOCAL=36;
}
#endif