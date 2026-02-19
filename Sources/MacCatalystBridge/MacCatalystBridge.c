//
//  MacCatalystBridge.c
//  SecureXPC
//
//  Created by Denis Esie on 19.02.2026.
//

#include "MacCatalystBridge.h"

#include <dlfcn.h>

typedef pid_t (*xpc_connection_get_pid_fn)(xpc_connection_t);
typedef OSStatus (*SecCodeCreateWithXPCMessage_fn)(xpc_object_t, SecCSFlags, SecCodeRef *);

pid_t xpc_connection_get_pid_bridged(xpc_connection_t connection) {
    static xpc_connection_get_pid_fn fn = NULL;
    if (!fn) {
        fn = (xpc_connection_get_pid_fn)dlsym(RTLD_DEFAULT, "xpc_connection_get_pid");
    }
    return fn ? fn(connection) : -1;
}

OSStatus SecCodeCreateWithXPCMessage_bridged(xpc_object_t message, SecCSFlags flags, SecCodeRef *target) {
    static SecCodeCreateWithXPCMessage_fn fn = NULL;
    if (!fn) {
        fn = (SecCodeCreateWithXPCMessage_fn)dlsym(RTLD_DEFAULT, "SecCodeCreateWithXPCMessage");
    }
    return fn ? fn(message, flags, target) : errSecUnimplemented;
}
