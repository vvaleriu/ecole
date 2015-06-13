#ifndef FTP_SERVER_ERROR_H
# define FTP_SERVER_ERROR_H

/*
**			STATUS
*/

# define SV_STARTED				"Server is running and waiting for connections."

/*
**			ERRORS
*/
# undef ERR_USAGE
# define ERR_USAGE				"<port>"
# define ERR_UNKNOWN_PROTOCOL	"Protocol is unknown"
# define ERR_EMPTY_ENV			"env not found."
# define ERR_EMPTY_PATH			"path env variable not found."
# define ERR_CMD_NOT_FOUND		"Command not available on the server. \
								Please type help to display a list of available commands."
# define ERR_MAX_CONNECTIONS	"Maximum connections reached, no more slots available. Go fuck yoursefl. Thanks."
# define ERR_ACCEPT_FAILURE		"Accept function failure."
# define ERR_RECV				"Recv function error."

#endif