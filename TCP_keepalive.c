#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){

	int s; /* our socket */
	int optval; 
	socklen_t optlen = sizeof(optval); /* makes available a type, socklen_t, which is an unsigned opaque integral type of length of at least 32 bits */


	/*Create the socket using --> int socket(int domain, int type, int protocol);. DESCRIPTION. The socket() function shall create an unbound socket in a communications domain, and return a file descriptor that can be used in later function call*/


	/* Handle the error */
	
	
	if((s= socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
			perror("socket()");
			exit(EXIT_FAILURE);
			}


	/* Check the status of keepalive */
	/* The getsockopt function retrieves the current value for a socket option associated with a socket of any type, in any state, and stores the result in optval.
	 * Options can exist at multiple protocol levels, but they are always present at the uppermost socket level. 
	 * Options affect socket operations, such as the packet routing and OOB data transfer. 
	 *
	 *int getsockopt( SOCKET s, int level, int  optname, char *optval, int  *optlen );
	 *
	 *  --> s [in] : A descriptor identifying the socket.
	 *  --> level [in] : The level at which the option is defined. Use SOL_SOCKET for this operation.
	 *  --> optname [in] : The socket option for which the value is to be set. Use SO_KEEPALIVE for this operation.
	 *  --> optval [out] : A pointer to the buffer containing the value for the option to set. This parameter should point to buffer equal to or larger than the size of a DWORD value.
	 *  This value is treated as a boolean value with 0 used to indicate FALSE (disabled) and a nonzero value to indicate TRUE (enabled).
	 *  --> optlen [in, out] - A pointer to the size, in bytes, of the optval buffer. This size must be equal to or larger than the size of a DWORD value.
	 *
	 * */

	if((getsockopt (s, SOL_SOCKET, SO_KEEPALIVE, &optval, &optlen)) < 0) {
		perror("getsockopt()");
		close(s);
		exit(EXIT_FAILURE);
	}

	printf("SO_KEEPALIVE is %s\n", (optval ? "ON" : "OFF"));

	/* Set the option active */


	optval = 1;
	optlen = sizeof(optval);
	if (setsockopt (s, SOL_SOCKET, SO_KEEPALIVE, &optval, optlen) < 0) {
		perror("setsockopt()");
		close(s);
		exit(EXIT_FAILURE);
	}

	printf("SO_KEEPALIVE set on socket\n");

	/* Check the status again */
	if(getsockopt(s, SOL_SOCKET, SO_KEEPALIVE, &optval, &optlen) < 0) {
	       	perror("getsockopt()");
		close(s);
		exit(EXIT_FAILURE);
	}
	
	printf("SO_KEEPALIVE is %s\n", (optval ? "ON" : "OFF"));
	
	
	close(s);
	exit(EXIT_SUCCESS);
}



	








