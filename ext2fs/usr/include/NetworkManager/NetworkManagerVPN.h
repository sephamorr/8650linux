/* NetworkManager -- Network link manager
 *
 * Dan Williams <dcbw@redhat.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * (C) Copyright 2004 Red Hat, Inc.
 */

#ifndef NETWORK_MANAGER_VPN_H
#define NETWORK_MANAGER_VPN_H

/*
 * dbus services details
 */
#define	NM_DBUS_PATH_VPN                  "/org/freedesktop/NetworkManager/VPN/Manager"
#define	NM_DBUS_INTERFACE_VPN             "org.freedesktop.NetworkManager.VPN.Manager"

#define	NM_DBUS_PATH_VPN_CONNECTION       "/org/freedesktop/NetworkManager/VPN/Connection"
#define	NM_DBUS_INTERFACE_VPN_CONNECTION  "org.freedesktop.NetworkManager.VPN.Connection"

#define NM_VPN_DBUS_PLUGIN_PATH           "/org/freedesktop/NetworkManager/VPN/Plugin"
#define NM_VPN_DBUS_PLUGIN_INTERFACE      "org.freedesktop.NetworkManager.VPN.Plugin"

/*
 * VPN Errors
 */
#define NM_DBUS_NO_ACTIVE_VPN_CONNECTION	"org.freedesktop.NetworkManager.VPNConnections.NoActiveVPNConnection"
#define NM_DBUS_NO_VPN_CONNECTIONS			"org.freedesktop.NetworkManager.VPNConnections.NoVPNConnections"
#define NM_DBUS_INVALID_VPN_CONNECTION		"org.freedesktop.NetworkManager.VPNConnections.InvalidVPNConnection"

#define NM_DBUS_VPN_STARTING_IN_PROGRESS	"StartingInProgress"
#define NM_DBUS_VPN_ALREADY_STARTED		"AlreadyStarted"
#define NM_DBUS_VPN_STOPPING_IN_PROGRESS	"StoppingInProgress"
#define NM_DBUS_VPN_ALREADY_STOPPED		"AlreadyStopped"
#define NM_DBUS_VPN_WRONG_STATE			"WrongState"
#define NM_DBUS_VPN_BAD_ARGUMENTS			"BadArguments"


/*
 * VPN daemon signals
 */
#define NM_DBUS_VPN_SIGNAL_LOGIN_BANNER		"LoginBanner"
#define NM_DBUS_VPN_SIGNAL_LOGIN_FAILED		"LoginFailed"
#define NM_DBUS_VPN_SIGNAL_LAUNCH_FAILED	"LaunchFailed"
#define NM_DBUS_VPN_SIGNAL_CONNECT_FAILED	"ConnectFailed"
#define NM_DBUS_VPN_SIGNAL_VPN_CONFIG_BAD	"VPNConfigBad"
#define NM_DBUS_VPN_SIGNAL_IP_CONFIG_BAD	"IPConfigBad"
#define NM_DBUS_VPN_SIGNAL_STATE_CHANGE		"StateChange"
#define NM_DBUS_VPN_SIGNAL_IP4_CONFIG		"IP4Config"

/*
 * VPN daemon states
 */
typedef enum NMVPNServiceState
{
	NM_VPN_SERVICE_STATE_UNKNOWN = 0,
	NM_VPN_SERVICE_STATE_INIT,
	NM_VPN_SERVICE_STATE_SHUTDOWN,
	NM_VPN_SERVICE_STATE_STARTING,
	NM_VPN_SERVICE_STATE_STARTED,
	NM_VPN_SERVICE_STATE_STOPPING,
	NM_VPN_SERVICE_STATE_STOPPED
} NMVPNServiceState;


/*
 * VPN connection states
 */
typedef enum NMVPNConnectionState
{
	NM_VPN_CONNECTION_STATE_UNKNOWN = 0,
	NM_VPN_CONNECTION_STATE_PREPARE,
	NM_VPN_CONNECTION_STATE_NEED_AUTH,
	NM_VPN_CONNECTION_STATE_CONNECT,
	NM_VPN_CONNECTION_STATE_IP_CONFIG_GET,
	NM_VPN_CONNECTION_STATE_ACTIVATED,
	NM_VPN_CONNECTION_STATE_FAILED,
	NM_VPN_CONNECTION_STATE_DISCONNECTED
} NMVPNConnectionState;

typedef enum NMVPNConnectionStateReason
{
	NM_VPN_CONNECTION_STATE_REASON_UNKNOWN = 0,
	NM_VPN_CONNECTION_STATE_REASON_NONE,
	NM_VPN_CONNECTION_STATE_REASON_USER_DISCONNECTED,
	NM_VPN_CONNECTION_STATE_REASON_DEVICE_DISCONNECTED,
	NM_VPN_CONNECTION_STATE_REASON_SERVICE_STOPPED,
	NM_VPN_CONNECTION_STATE_REASON_IP_CONFIG_INVALID,
	NM_VPN_CONNECTION_STATE_REASON_CONNECT_TIMEOUT,
	NM_VPN_CONNECTION_STATE_REASON_SERVICE_START_TIMEOUT,
	NM_VPN_CONNECTION_STATE_REASON_SERVICE_START_FAILED,
	NM_VPN_CONNECTION_STATE_REASON_NO_SECRETS,
	NM_VPN_CONNECTION_STATE_REASON_LOGIN_FAILED,
	NM_VPN_CONNECTION_STATE_REASON_CONNECTION_REMOVED
} NMVPNConnectionStateReason;

typedef enum {
	NM_VPN_PLUGIN_FAILURE_LOGIN_FAILED,
	NM_VPN_PLUGIN_FAILURE_CONNECT_FAILED,
	NM_VPN_PLUGIN_FAILURE_BAD_IP_CONFIG
} NMVPNPluginFailure;


/* uint32: IP address of the public external VPN gateway (network byte order) */
#define NM_VPN_PLUGIN_IP4_CONFIG_EXT_GATEWAY "gateway"

/* uint32: IP address of the internal gateway of the subnet the VPN interface is
 *         on, if the VPN uses subnet configuration (network byte order)
 */
#define NM_VPN_PLUGIN_IP4_CONFIG_INT_GATEWAY "internal-gateway"

/* uint32: internal IP address of the local VPN interface (network byte order) */
#define NM_VPN_PLUGIN_IP4_CONFIG_ADDRESS     "address"

/* uint32: IP address of the other side of Point-to-Point connection if the VPN
 *         uses Point-to-Point configuration. (network byte order)
 */
#define NM_VPN_PLUGIN_IP4_CONFIG_PTP         "ptp"

/* uint32: IP prefix of the VPN interface; 1 - 32 inclusive */
#define NM_VPN_PLUGIN_IP4_CONFIG_PREFIX      "prefix"

/* array of uint32: IP addresses of DNS servers for the VPN (network byte order) */
#define NM_VPN_PLUGIN_IP4_CONFIG_DNS         "dns"

/* array of uint32: IP addresses of NBNS/WINS servers for the VPN (network byte order) */
#define NM_VPN_PLUGIN_IP4_CONFIG_NBNS        "nbns"

/* uint32: Message Segment Size that the VPN interface should use */
#define NM_VPN_PLUGIN_IP4_CONFIG_MSS         "mss"

/* uint32: Maximum Transfer Unit that the VPN interface should use */
#define NM_VPN_PLUGIN_IP4_CONFIG_MTU         "mtu"

/* string: VPN interface name (tun0, tap0, etc) */
#define NM_VPN_PLUGIN_IP4_CONFIG_TUNDEV      "tundev"

/* string: DNS domain name */
#define NM_VPN_PLUGIN_IP4_CONFIG_DOMAIN      "domain"

/* array of strings: DNS domain names */
#define NM_VPN_PLUGIN_IP4_CONFIG_DOMAINS     "domains"

/* string: Login message */
#define NM_VPN_PLUGIN_IP4_CONFIG_BANNER      "banner"

/* array of array of uint32: custom routes the client should apply.  NOTE: NM
 *     expects the D-Bus argument signature "aau" here.  i.e., an array of
 *     routes, where each route is a 4-element array of uint32 values.
 *
 *     Each route consists of the following 4 uint32 values, in this order:
 *              1: destination IP address (network byte order)
 *              2: destination prefix (1 - 32 inclusive)
 *              3: IP address of next hop (network byte order)
 *              4: route metric
 */
#define NM_VPN_PLUGIN_IP4_CONFIG_ROUTES      "routes"

/* boolean: prevent this VPN connection from ever getting the default route */
#define NM_VPN_PLUGIN_IP4_CONFIG_NEVER_DEFAULT "never-default"

/* Deprecated */
#define NM_VPN_PLUGIN_IP4_CONFIG_GATEWAY   NM_VPN_PLUGIN_IP4_CONFIG_EXT_GATEWAY


#endif /* NETWORK_MANAGER_VPN_H */
