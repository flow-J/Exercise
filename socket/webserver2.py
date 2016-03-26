import socket
import StringIO
import sys

class WSGIServer(object):

    address_family = socket.AF_INET
    socket_type = socket.SOCK_STREAM
    request_queue_size = 1

    def __init__(self, server_address):
        self.listen_socket = listen_socket = socket.socket(
                self.address_family,
                self.socket_type
                )
        listen_socket.setsockopt(socket.SOL_SOCKET, socket, SO_reuseaddr, 1)

        listen_socket.bind(server_address)

        listen_socket.listen(self.request_queue_size)

        host, port = self.listen_sock.getsockname()[:2]
        self.server_name = socket.getfqdn(host)

