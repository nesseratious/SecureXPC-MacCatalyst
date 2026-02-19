//
//  MacCatalystBridge.h
//  SecureXPC
//
//  Created by Denis Esie on 19.02.2026.
//

#ifndef MacCatalystBridge_h
#define MacCatalystBridge_h

#import <CoreFoundation/CoreFoundation.h>
#import <Security/Security.h>
#import <xpc/xpc.h>
#import <MacTypes.h>

pid_t xpc_connection_get_pid_original(xpc_connection_t connection) __asm__("xpc_connection_get_pid");

pid_t xpc_connection_get_pid_bridged(xpc_connection_t connection);

OSStatus SecCodeCreateWithXPCMessage_original(xpc_object_t message, SecCSFlags flags, SecCodeRef * CF_RETURNS_RETAINED target) __asm__("SecCodeCreateWithXPCMessage");

OSStatus SecCodeCreateWithXPCMessage_bridged(xpc_object_t message, SecCSFlags flags, SecCodeRef * CF_RETURNS_RETAINED target);

#endif /* MacCatalystBridge_h */
