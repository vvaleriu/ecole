#ifndef FTP_CLIENT_ERROR_H
#define FTP_CLIENT_ERROR_H

# undef ERR_USAGE
# define ERR_USAGE				"<server_address> <port>"
# define ERR_UNKNOWN_PROTOCOL	"Protocol is unknown."
# define ERR_CONNECT			"Connection error."
# define ERR_RECV				"Error with received data."

# define ERR_SV_CLOSED			"Server closed, client will be interrupt."

#endif