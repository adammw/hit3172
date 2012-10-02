/*
* Generated by SGWrapperGen - DO NOT EDIT!
*
* SwinGame wrapper for C - Networking
*
* Wrapping sgNetworking.pas
*/

#include "SGSDK.h"
#include "Networking.h"

#include "Types.h"

int32_t accept_tcpconnection()
{
    return sg_Networking_AcceptTCPConnection();
}

void broadcast_tcpmessage(const char *aMsg)
{
    sg_Networking_BroadcastTCPMessage(aMsg);
}

void broadcast_udpmessage(const char *aMsg)
{
    sg_Networking_BroadcastUDPMessage(aMsg);
}

void clear_message_queue(connection aConnection)
{
    sg_Networking_ClearMessageQueue(aConnection);
}

void close_all_connections()
{
    sg_Networking_CloseAllConnections();
}

void close_all_sockets()
{
    sg_Networking_CloseAllSockets();
}

void close_all_tcphost_sockets()
{
    sg_Networking_CloseAllTCPHostSockets();
}

void close_all_udpsockets()
{
    sg_Networking_CloseAllUDPSockets();
}

#ifdef __cplusplus

bool close_connection(connection &aConnection)
{
    return sg_Networking_CloseConnection(&aConnection) != 0;
}

#endif

bool close_connection(connection *aConnection)
{
    return sg_Networking_CloseConnection(aConnection) != 0;
}

bool close_tcphost_socket(int32_t aPort)
{
    return sg_Networking_CloseTCPHostSocket(aPort) != 0;
}

bool close_udpsocket(int32_t aPort)
{
    return sg_Networking_CloseUDPSocket(aPort) != 0;
}

int32_t connection_count()
{
    return sg_Networking_ConnectionCount();
}

uint32_t connection_ip(connection aConnection)
{
    return sg_Networking_ConnectionIP(aConnection);
}

int32_t connection_port(connection aConnection)
{
    return sg_Networking_ConnectionPort(aConnection);
}

int32_t connection_queue_size()
{
    return sg_Networking_ConnectionQueueSize();
}

#ifdef __cplusplus

connection create_tcpconnection(const char *aIP, int32_t aPort)
{
    return sg_Networking_CreateTCPConnection(aIP, aPort);
}

#endif

connection create_tcpconnection_to_host(const char *aIP, int32_t aPort)
{
    return sg_Networking_CreateTCPConnection(aIP, aPort);
}

bool create_tcphost(int32_t aPort)
{
    return sg_Networking_CreateTCPHost(aPort) != 0;
}

connection create_udpconnection(const char *aDestIP, int32_t aDestPort, int32_t aInPort)
{
    return sg_Networking_CreateUDPConnection(aDestIP, aDestPort, aInPort);
}

int32_t create_udphost(int32_t aPort)
{
    return sg_Networking_CreateUDPHost(aPort);
}

void dec_to_hex(uint32_t aDec, char *result)
{
    sg_Networking_DecToHex(aDec, result);
}

void enqueue_message(const char *aMsg, connection aConnection)
{
    sg_Networking_EnqueueMessage(aMsg, aConnection);
}

void enqueue_new_connection(connection aConnection)
{
    sg_Networking_EnqueueNewConnection(aConnection);
}

connection fetch_connection()
{
    return sg_Networking_FetchConnection();
}

#ifdef __cplusplus

void free_connection(connection &aConnection)
{
    sg_Networking_FreeConnection(&aConnection);
}

#endif

void free_connection(connection *aConnection)
{
    sg_Networking_FreeConnection(aConnection);
}

void hex_str_to_ipv4(const char *aHex, char *result)
{
    sg_Networking_HexStrToIPv4(aHex, result);
}

void hex_to_dec_string(const char *aHex, char *result)
{
    sg_Networking_HexToDecString(aHex, result);
}

uint32_t ipv4_to_dec(const char *aIP)
{
    return sg_Networking_IPv4ToDec(aIP);
}

int32_t message_count(connection aConnection)
{
    return sg_Networking_MessageCount(aConnection);
}

void my_ip(char *result)
{
    sg_Networking_MyIP(result);
}

void read_last_message(connection aConnection, char *result)
{
    sg_Networking_ReadLastMessage(aConnection, result);
}

void read_message(connection aConnection, char *result)
{
    sg_Networking_ReadMessage(aConnection, result);
}

void release_all_connections()
{
    sg_Networking_ReleaseAllConnections();
}

connection retreive_connection(int32_t aConnectionAt)
{
    return sg_Networking_RetreiveConnection(aConnectionAt);
}

connection send_tcpmessage(const char *aMsg, connection aConnection)
{
    return sg_Networking_SendTCPMessage(aMsg, aConnection);
}

bool send_udpmessage(const char *aMsg, connection aConnection)
{
    return sg_Networking_SendUDPMessage(aMsg, aConnection) != 0;
}

bool tcpmessage_received()
{
    return sg_Networking_TCPMessageReceived() != 0;
}

bool udpmessage_received()
{
    return sg_Networking_UDPMessageReceived() != 0;
}
