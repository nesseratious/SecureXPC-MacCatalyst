//
//  MacCatalystBridge.c
//  SecureXPC
//
//  Created by Denis Esie on 19.02.2026.
//

#include "MacCatalystBridge.h"

pid_t xpc_connection_get_pid_bridged(xpc_connection_t connection) {
    return xpc_connection_get_pid_original(connection);
}

OSStatus SecCodeCreateWithXPCMessage_bridged(xpc_object_t message, SecCSFlags flags, SecCodeRef * CF_RETURNS_RETAINED target) {
    return SecCodeCreateWithXPCMessage_original(message, flags, target);
}
